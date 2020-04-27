#pragma once
#include "ErrorMessage.h"
#include <optional>

#define DEFAULT_BUFFER_SIZE 16

//DynamicArray {a,b,c,d,e,f,g} approximate scheme:
//[][][][][][][] [a][b][c][d][e][f][g] [][][][][][][][]
//_l_additional__________count___________r_additional__ } - capacity
//______=7________________=7__________________=8_______       =22

template<typename T>
class DynamicArray
{
public:
	DynamicArray(size_t size = 0);
	DynamicArray(size_t size, const T& default_element);
	DynamicArray(const T* const arr, size_t count, size_t start = 0);
	DynamicArray(const DynamicArray<T>& arr);
	std::optional<T> Get(size_t index) const;
	void Set(size_t index, const T& value);
	void Resize(size_t new_size);
	size_t Size() const;
	size_t Capacity() const;
	DynamicArray<T>& operator=(const DynamicArray<T>& arr);
	std::optional<T>& operator[](const size_t index);
	const std::optional<T>& operator[](const size_t index) const;
	~DynamicArray() { delete[] this->data; }
private:
	std::optional<T>* data;
	size_t l_additional;
	size_t r_additional;
	size_t count;
};

template<typename T>
DynamicArray<T>::DynamicArray(size_t size)
{
	this->l_additional = this->r_additional = DEFAULT_BUFFER_SIZE;
	this->count = size;
	try
	{
		this->data = new std::optional<T>[this->Capacity()];
	}
	catch (const std::bad_alloc &exc)
	{
		throw exc.what();
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(size_t size, const T& default_element) : DynamicArray(size)
{
	for (size_t i = 0; i < this->count; i++)
		this->data[i + this->l_additional] = default_element;
}

template<typename T>
DynamicArray<T>::DynamicArray(const T* const arr, size_t count, size_t start) : DynamicArray(count)
{
	for (size_t i = 0; i < this->count; i++)
	{
		this->data[i + this->l_additional] = arr[i + start];
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& arr) : DynamicArray(arr.count) 
{
	for (size_t i = 0; i < this->count; i++)
	{
		this->data[i + this->l_additional] = arr.data[i + arr.l_additional];
	}
}

template<typename T>
std::optional<T> DynamicArray<T>::Get(size_t index) const
{
	return index < this->count ? this->data[index + this->l_additional] : std::nullopt;
}

template<typename T>
void DynamicArray<T>::Set(size_t index, const T& value)
{
	index < this->count ? this->data[index + this->l_additional] = value : std::nullopt;
}

template<typename T>
void DynamicArray<T>::Resize(size_t new_size)
{
	if (new_size > this->Capacity())
	{
		std::optional<T>* new_array;
		//Выделение памяти под новый массив
		try
		{
			new_array = new std::optional<T>[new_size + this->l_additional + this->r_additional];
		}
		catch (const std::bad_alloc & exc)
		{
			throw exc.what();
		}
		//Заполнение нового массива значениями из старого
		for (size_t i = 0; i < this->count; i++)
			new_array[i + this->l_additional] = this->data[i + this->l_additional];
		//Удаление старого массива
		delete[] this->data;
		//Присвоение нового массива старому
		this->data = new_array;
	}
	else
	{
		for (size_t i = new_size; i < this->count; i++)
			this->data[i + this->l_additional] = std::nullopt;
		this->r_additional += this->count - new_size;
	}
	this->count = new_size;
}

template<typename T>
size_t DynamicArray<T>::Size() const
{
	return this->count;
}

template<typename T>
size_t DynamicArray<T>::Capacity() const
{
	return this->count + this->l_additional + this->r_additional;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& arr)
{
	if (this == &arr)
		return *this;
	if (this->Capacity() < arr.count)
	{
		delete[] this->data;
		try
		{
			this->data = new std::optional<T>[arr.count + this->r_additional + this->l_additional];
		}
		catch (const std::bad_alloc & exc)
		{
			throw exc.what();
		}
	}
	else
	{
		size_t l_additional_new = (this->Capacity() - arr.count) / 2;
		size_t r_additional_new = this->Capacity() - arr.count - l_additional_new;

		for (size_t i = 0; i < this->Capacity(); i++)
			this->data[i] = std::nullopt;
	}
	for (size_t i = 0; i < arr.count; i++)
		this->data[i + this->l_additional] = arr.data[i + arr.l_additional];
	this->count = arr.count;
	return *this;
}

template<typename T>
std::optional<T>& DynamicArray<T>::operator[](const size_t index)
{
	if(index >= this->count)
		throw "Invalid index";
	return this->data[index + this->l_additional];
}

template<typename T>
const std::optional<T>& DynamicArray<T>::operator[](const size_t index) const
{
	if (index >= this->count)
		throw "Invalid index";
	return this->data[index + this->l_additional];
}

