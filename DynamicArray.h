#pragma once
#include "ErrorMessage.h"
#include <optional>

#define DEFAULT_BUFFER_SIZE 16

template<typename T>
class DynamicArray
{
public:
	//DynamicArray();
	DynamicArray(size_t size = 0);
	DynamicArray(size_t size, const T& default_element);
	DynamicArray(const T* const arr, size_t count, size_t start = 0);
	DynamicArray(const DynamicArray<T>& arr);
	std::optional<T> Get(size_t index) const;
	void Set(size_t index, const T& value);
	void Resize(size_t new_size);
	size_t Size() const;
	DynamicArray<T>& operator=(const DynamicArray<T>& arr);
	std::optional<T>& operator[](size_t index);
	const std::optional<T>& operator[](size_t index) const;
	~DynamicArray() { delete[] this->data; }
private:
	std::optional<T>* data;
	size_t capacity;
	size_t count;
};

template<typename T>
DynamicArray<T>::DynamicArray(size_t size)
{
	this->capacity = size + DEFAULT_BUFFER_SIZE;
	this->count = size;
	try
	{
		this->data = new std::optional<T>[this->capacity];
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
	{
		this->data[i] = default_element;
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const T* const arr, size_t count, size_t start) : DynamicArray(count)
{
	for (size_t i = 0; i < this->count; i++)
	{
		this->data[i] = arr[i + start];
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& arr) : DynamicArray(arr.count) 
{
	for (size_t i = 0; i < this->count; i++)
	{
		this->data[i] = arr.data[i];
	}
}

template<typename T>
std::optional<T> DynamicArray<T>::Get(size_t index) const
{
	return index < this->count ? this->data[index] : std::nullopt;
}

template<typename T>
void DynamicArray<T>::Set(size_t index, const T& value)
{
	this->data[index] = index < this->count ? std::optional(value) : std::nullopt;
}

template<typename T>
void DynamicArray<T>::Resize(size_t new_size)
{
	if (new_size > this->capacity)
	{
		delete[] this->data;

	}
}

template<typename T>
size_t DynamicArray<T>::Size() const
{
	return this->count;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& arr)
{
	if (this == &arr)
		return *this;
	if (this->capacity < arr.count)
	{
		delete[] this->data;
		this->capacity = arr.capacity;
		try
		{
			this->data = new std::optional<T>[this->capacity];
		}
		catch (const std::bad_alloc & exc)
		{
			throw exc.what();
		}
	}
	//ƒл€ более оптимальной работы с пам€тью, использу€ capacity
	for (size_t i = 0; i < arr.count; i++)
		this->data[i] = arr.data[i];
	if(this->count > arr.count)
		for(size_t i=0; i<(this->count-arr.count); i++)
			this->data[i] = std::nullopt;
	this->count = arr.count;
	return *this;
}

template<typename T>
std::optional<T>& DynamicArray<T>::operator[](size_t index)
{
	return index < this->count ? this->data[index] : std::nullopt;
}

template<typename T>
const std::optional<T>& DynamicArray<T>::operator[](size_t index) const
{
	return index < this->count ? this->data[index] : std::nullopt;
}

