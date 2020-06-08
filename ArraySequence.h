#pragma once
#include"DynamicArray.h"
#include"Sequence.h"

template<typename T>
class ArraySequence : public Sequence<T>
{
public:
	// онструкторы:
	ArraySequence() {} //dynamic_array по умолчанию инициализируетс€ пустым массивом
	ArraySequence(size_t count) : dynamic_array(count) {}
	ArraySequence(size_t count, const T& value) : dynamic_array(count, value) {}
	ArraySequence(const ArraySequence<T>& other) : dynamic_array(other.linked_list) {}
	ArraySequence(ArraySequence<T>&& other) : dynamic_array(std::move(other.linked_list)) {}
	ArraySequence(std::initializer_list<T> init) : dynamic_array(init) {}
	//ћетоды:
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
	DynamicArray<T> dynamic_array;
};

template<typename T>
void ArraySequence<T>::Set(const T& element, size_t index)
{
	try 
	{
		this->dynamic_array[index] = element;
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

template<typename T>
T ArraySequence<T>::Get(size_t index) const
{
	try
	{
		return this->dynamic_array[index].value();
	}
	catch(std::exception &ex)
	{
		throw std::exception("Invalid index");
	}
}

template<typename T>
void ArraySequence<T>::Prepend(const T& element)
{
	this->dynamic_array.PushFront(element);
}

template<typename T>
void ArraySequence<T>::Append(const T& element)
{
	this->dynamic_array.PushBack(element);
}

template<typename T>
T ArraySequence<T>::GetFirst() const
{
	try
	{
		return this->dynamic_array.Front().value();
	}
	catch (std::exception & ex)
	{
		throw std::exception("ArraySequence is empty");
	}
}

template<typename T>
T ArraySequence<T>::GetLast() const
{
	try
	{
		return this->dynamic_array.Back().value();
	}
	catch (std::exception & ex)
	{
		throw std::exception("ArraySequence is empty");
	}
}

template<typename T>
void ArraySequence<T>::InsertAt(const T& element, size_t index)
{
	try 
	{
		this->dynamic_array.Insert(index, element);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

template<typename T>
void ArraySequence<T>::Remove(size_t index)
{
	try
	{
		this->dynamic_array.Erase(index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

template<typename T>
void ArraySequence<T>::Remove(const T& element)
{
	for (size_t i = 0; i < this->dynamic_array.Size(); i++)
		if (this->dynamic_array[i] == element)
		{
			this->dynamic_array.Erase(i);
			break;
		}
}

template<typename T>
void ArraySequence<T>::RemoveAll(const T& element)
{
	size_t count = 0;
	for (size_t i = 0; i < this->dynamic_array.Size(); i++)
		if (this->dynamic_array[i] == element)
			count++;
	for (size_t i = 0; i < count; i++)
		this->Remove(element);
}

template<typename T>
void ArraySequence<T>::Clear()
{
	this->dynamic_array.Clear();
}

template<typename T>
size_t ArraySequence<T>::GetLength() const
{
	return this->dynamic_array.Size();
}

template<typename T>
Sequence<T>* ArraySequence<T>::GetSubsequence(size_t start, size_t end) const
{
	if (end < start)
		throw std::exception("Start must be less then end");
	Sequence<T>* sub_sequence = new ArraySequence<T>();
	for (size_t i = start; i < end; i++)
		sub_sequence->Append(this->Get(i));//Get кидает Invalid index
	return sub_sequence;
}

template<typename T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T>* other)
{
	size_t length = other->GetLength();
	for (size_t i = 0; i < length; i++)
		this->Append(other->Get(i));
	return this;
}
