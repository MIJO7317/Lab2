#pragma once
#include"ListSequence.h"
#include "ArraySequence.h"
#include "CString.h"

class StringBuilder
{
public:
	StringBuilder();
	StringBuilder(const std::string& str);
	StringBuilder(const char* str);
	StringBuilder(const StringBuilder& str);
	StringBuilder(StringBuilder&& str);
	StringBuilder(const CString& str);
	char CharAt(size_t index) const;
	void SetCharAt(size_t index, char ch);
	void Append(char ch);
	void Append(const char* str);
	void Append(const std::string& str);
	void Append(const StringBuilder& str);
	void Append(const CString& str);
	void Prepend(char ch);
	void Prepend(const char* str);
	void Prepend(const std::string& str);
	void Prepend(const StringBuilder& str);
	void Prepend(const CString& str);
	void Insert(size_t index, char ch);
	void Insert(size_t index, const char* str);
	void Insert(size_t index, const std::string& str);
	void Insert(size_t index, const StringBuilder& str);
	void Insert(size_t index, const CString& str);
	void Remove(size_t index, size_t count = 1);
	void Replace(size_t index, size_t count, const char* str);
	void Replace(size_t index, size_t count, const std::string& str);
	void Replace(size_t index, size_t count, const StringBuilder& str);
	void Replace(size_t index, size_t count, const CString& str);
	CString ToString();
	size_t Size() const;
	~StringBuilder();
private:
	Sequence<char>* str;
};


StringBuilder::StringBuilder()
{
	this->str = new ListSequence<char>();
}

StringBuilder::StringBuilder(const std::string& str)
{
	this->str = new ListSequence<char>();
	for (auto ch : str)
		this->str->Append(ch);
}

StringBuilder::StringBuilder(const char* str)
{
	this->str = new ListSequence<char>();
	for (size_t i = 0; str[i] != '\0'; i++)
		this->str->Append(str[i]);
}

StringBuilder::StringBuilder(const StringBuilder& str)
{
	this->str = new ListSequence<char>();
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Append(str.CharAt(i));
}

StringBuilder::StringBuilder(StringBuilder&& str)
{
	this->str = str.str;
	str.str = nullptr;
}

StringBuilder::StringBuilder(const CString& str)
{
	this->str = new ListSequence<char>();
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Append(str.CharAt(i));
}

char StringBuilder::CharAt(size_t index) const
{
	try
	{
		return this->str->Get(index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

void StringBuilder::SetCharAt(size_t index, char ch)
{
	try
	{
		this->str->Set(ch, index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

void StringBuilder::Append(char ch)
{
	this->str->Append(ch);
}

void StringBuilder::Append(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		this->str->Append(str[i]);
}

void StringBuilder::Append(const std::string& str)
{
	for (auto ch : str)
		this->str->Append(ch);
}

void StringBuilder::Append(const StringBuilder& str)
{
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Append(str.CharAt(i));
}

void StringBuilder::Append(const CString& str)
{
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Append(str.CharAt(i));
}

void StringBuilder::Prepend(char ch)
{
	this->str->Prepend(ch);
}

void StringBuilder::Prepend(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		this->str->Prepend(str[i]);
}

void StringBuilder::Prepend(const std::string& str)
{
	for (auto ch : str)
		this->str->Prepend(ch);
}

void StringBuilder::Prepend(const StringBuilder& str)
{
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Prepend(str.CharAt(i));
}

void StringBuilder::Prepend(const CString& str)
{
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Prepend(str.CharAt(i));
}

void StringBuilder::Insert(size_t index, char ch)
{
	try
	{
		this->str->InsertAt(ch, index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

void StringBuilder::Insert(size_t index, const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		this->Insert(index++, str[i]);
}

void StringBuilder::Insert(size_t index, const std::string& str)
{
	this->Insert(index, str.c_str());
}

void StringBuilder::Insert(size_t index, const StringBuilder& str)
{
	for (size_t i = 0; i < str.Size(); i++)
		this->Insert(index++, str.CharAt(i));
}

void StringBuilder::Insert(size_t index, const CString& str)
{
	for (size_t i = 0; i < str.Size(); i++)
		this->Insert(index++, str.CharAt(i));
}

void StringBuilder::Remove(size_t index, size_t count)
{
	try
	{
		for (size_t i = 0; i < count; i++)
			this->str->Remove(index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
}

void StringBuilder::Replace(size_t index, size_t count, const char* str)
{
	this->Remove(index, count);
	this->Insert(index, str);
}

void StringBuilder::Replace(size_t index, size_t count, const std::string& str)
{
	this->Remove(index, count);
	this->Insert(index, str);
}

void StringBuilder::Replace(size_t index, size_t count, const StringBuilder& str)
{
	this->Remove(index, count);
	this->Insert(index, str);
}

void StringBuilder::Replace(size_t index, size_t count, const CString& str)
{
	this->Remove(index, count);
	this->Insert(index, str);
}

CString StringBuilder::ToString()
{
	CString s("");
	Sequence<char>* new_str = new ArraySequence<char>(this->Size());
	for (size_t i = 0; i < this->Size(); i++)
		new_str->Set(this->CharAt(i), i);
	delete s.str;
	s.str = new_str;
	return s;
}

size_t StringBuilder::Size() const
{
	return this->str->GetLength();
}

StringBuilder::~StringBuilder()
{
	delete this->str;
}