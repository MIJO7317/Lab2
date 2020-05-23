#pragma once
#include<iterator>

template<typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	Node* head; //Первый элемент списка
	Node* tail; //Элемент следующий за последним элементом списка
	size_t size;

	//Класс итератора:
	template<class Iter>
	class LinkedListIterator : public std::iterator<std::random_access_iterator_tag, Iter>
	{
		friend class LinkedList;
		Iter* value;
	private:
		LinkedListIterator(Iter* value) : value(value) {}
	public:
		LinkedListIterator(const LinkedListIterator& it) : value(it.value) {}
		bool operator==(const LinkedListIterator& other) const;
		bool operator!=(const LinkedListIterator& other) const;
		T& operator*();
		LinkedListIterator<Iter>& operator++();
	};

public:
	//Для работы итератора со стандартными алгоритмами:
	typedef LinkedListIterator<Node> iterator;
	typedef LinkedListIterator<const Node> const_iterator;
	
	//Конструкторы:
	LinkedList();
	LinkedList(const T* const array, size_t count, size_t start = 0);

	LinkedList<T>& PushBack(const T& element);

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	~LinkedList();
};

//Методы итератора:

template<typename T>
template<class Iter>
bool LinkedList<T>::LinkedListIterator<Iter>::operator==(const LinkedListIterator& other) const
{
	return this->value == other.value;
}

template<typename T>
template<class Iter>
bool LinkedList<T>::LinkedListIterator<Iter>::operator!=(const LinkedListIterator& other) const
{
	return this->value != other.value;
}

template<typename T>
template<class Iter>
T& LinkedList<T>::LinkedListIterator<Iter>::operator*()
{
	if (this->value->next == nullptr)
		throw "Can't dereference out of range LinkedList iterator";
	return this->value->data;
}

template<typename T>
template<class Iter>
LinkedList<T>::LinkedListIterator<Iter>& LinkedList<T>::LinkedListIterator<Iter>::operator++()
{
	if(this->value->next == nullptr)
		throw "Can't increment LinkedList iterator past end";
	this->value = this->value->next;
	return *this;
}

//Методы LinkedList

template<typename T>
LinkedList<T>::LinkedList() : size(0)
{
	this->head = this->tail = new Node;
	this->tail->next = nullptr;
	this->tail->prev = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(const T* const array, size_t count, size_t start)
{

}

template<typename T>
LinkedList<T>& LinkedList<T>::PushBack(const T& element)
{
	this->size++;
	Node* new_node = new Node;
	new_node->data = element;
	new_node->next = this->tail;
	new_node->prev = this->tail->prev;
	if (this->tail == this->head)
		this->head = new_node;
	else
		this->tail->prev->next = new_node;
	this->tail->prev = new_node;
	return *this;
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
	return iterator(head);
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
	return iterator(tail);
}

template<typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::begin() const
{
	return const_iterator(head);
}

template<typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::end() const
{
	return const_iterator(tail);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node* current = this->head;
	while (current != this->tail)
	{
		current = current->next;
		delete current->prev;
	}
	delete current;
}
