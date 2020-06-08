#pragma once
#include"LinkedList.h"
#include "Sequence.h"

template<typename T>
class ListSequence : public Sequence<T>
{
public:
	//Конструкторы:
	ListSequence() {} //linked_list по умолчанию инициализируется пустым списком
	ListSequence(size_t count, const T& value) : linked_list(count, value) {}
	ListSequence(const ListSequence<T>& other) : linked_list(other.linked_list) {}
	ListSequence(ListSequence<T>&& other) : linked_list(std::move(other.linked_list)) {}
	ListSequence(std::initializer_list<T> init) : linked_list(init) {}
	//Методы:
	void Set(const T& element, size_t index);
	T Get(size_t index) const;
	void Prepend(const T& element);
	void Append(const T& element);
	T GetFirst() const;
	T GetLast() const;
	void InsertAt(const T& element, size_t index);
	void Remove(size_t index);
	void Remove(const T& element);
	void RemoveAll(const T& element);
	void Clear();
	size_t GetLength() const;
	Sequence<T>* GetSubsequence(size_t start, size_t end) const;
	Sequence<T>* Concat(Sequence<T>* other);
private:
	LinkedList<T> linked_list;
};

template<typename T>
void ListSequence<T>::Set(const T& element, size_t index)
{
	auto it = this->linked_list.begin();
	try
	{
		std::advance(it, index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
	*it = element;
}

template<typename T>
T ListSequence<T>::Get(size_t index) const
{
	auto it = const_cast<LinkedList<T>&>(this->linked_list).begin(); //Нет const_iterator
	try
	{
		std::advance(it, index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
	return *it;
}

template<typename T>
void ListSequence<T>::Prepend(const T& element)
{
	this->linked_list.PushFront(element);
}

template<typename T>
void ListSequence<T>::Append(const T& element)
{
	this->linked_list.PushBack(element);
}

template<typename T>
T ListSequence<T>::GetFirst() const
{
	try 
	{
		return this->linked_list.Front();
	}
	catch (std::exception & ex)
	{
		throw std::exception("ListSequence is empty");
	}
}

template<typename T>
T ListSequence<T>::GetLast() const
{
	try
	{
		return this->linked_list.Back();
	}
	catch (std::exception & ex)
	{
		throw std::exception("ListSequence is empty");
	}
}

template<typename T>
void ListSequence<T>::InsertAt(const T& element, size_t index)
{
	auto it = this->linked_list.begin();
	try
	{
		std::advance(it, index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
	this->linked_list.Insert(it, element);
}

template<typename T>
void ListSequence<T>::Remove(size_t index)
{
	auto it = this->linked_list.begin();
	try
	{
		std::advance(it, index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
	try
	{
		this->linked_list.Erase(it);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

template<typename T>
void ListSequence<T>::Remove(const T& element)
{
	auto it = std::find(this->linked_list.begin(), this->linked_list.end(), element);
	if (it != this->linked_list.end())
		this->linked_list.Erase(it);
}

template<typename T>
void ListSequence<T>::RemoveAll(const T& element)
{
	size_t count = std::count(this->linked_list.begin(), this->linked_list.end(), element);
	for (size_t i = 0; i < count; i++)
		this->Remove(element);
}

template<typename T>
void ListSequence<T>::Clear()
{
	this->linked_list.Clear();
}

template<typename T>
size_t ListSequence<T>::GetLength() const
{
	return this->linked_list.Size();
}

template<typename T>
Sequence<T>* ListSequence<T>::GetSubsequence(size_t start, size_t end) const
{
	if (end < start)
		throw std::exception("Start must be less then end");
	Sequence<T>* sub_sequence = new ListSequence<T>();
	for (size_t i = start; i < end; i++)
		sub_sequence->Append(this->Get(i));//Get кидает Invalid index
	return sub_sequence;
}

template<typename T>
Sequence<T>* ListSequence<T>::Concat(Sequence<T>* other)
{
	size_t length = other->GetLength();
	for (size_t i = 0; i < length; i++)
		this->Append(other->Get(i));
	return this;
}


