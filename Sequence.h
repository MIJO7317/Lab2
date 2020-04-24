#pragma once
template <typename T>
class Sequence
{
public:
	virtual void Set(const T element, const size_t index) = 0;
	virtual T Get(const size_t index) const = 0;
	virtual void Prepend(const T element) = 0;
	virtual void Append(const T element) = 0;
	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;
	virtual void InsertAt(const T element, const size_t index) = 0;
	virtual void Remove(const size_t index) = 0;
	virtual void Remove(const T element) = 0;
	virtual void RemoveAll(const T element) = 0;
	virtual size_t GetLength() const = 0;
	virtual Sequence<T>* GetSubsequence(const size_t start, const size_t end) const = 0;
	virtual Sequence<T>* Concat(Sequence<T>* other) = 0;
	virtual ~Sequence() {}
};

