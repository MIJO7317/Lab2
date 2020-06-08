#pragma once
#include "ArraySequence.h"
#include "StringBuilder.h"

class CString
{
	friend class StringBuilder;
public:
	CString(const char* str);
	CString(const std::string& str) : CString(str.c_str()) {};
	CString(const CString& str);
	CString(CString&& str);
	char CharAt(size_t index) const;
	void SetCharAt(size_t index, char ch);
	CString SubString(size_t index, size_t count);
	size_t FindSubString(char ch);
	size_t FindSubString(const char* str);
	size_t FindSubString(const std::string& str);
	size_t FindSubString(const CString& str);
	size_t Size() const;
	~CString() { delete str; }
private:
	Sequence<char>* str;
};

CString::CString(const char* str)
{
	size_t length = 0;
	while (str[length] != '\0')
		length++;
	this->str = new ArraySequence<char>(length);
	for (size_t i = 0; i < length; i++)
		this->str->Set(str[i], i);
}

CString::CString(const CString& str)
{
	this->str = new ArraySequence<char>(str.Size());
	for (size_t i = 0; i < str.Size(); i++)
		this->str->Set(str.CharAt(i), i);
}

CString::CString(CString&& str)
{
	this->str = str.str;
	str.str = nullptr;
}

char CString::CharAt(size_t index) const
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

void CString::SetCharAt(size_t index, char ch)
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

CString CString::SubString(size_t index, size_t count)
{
	CString sub_string = "";
	delete sub_string.str;
	Sequence<char>* str = new ArraySequence<char>(count);
	try
	{
		for (size_t i = index; i < index + count; i++)
			str->Set(this->str->Get(i), i-index);
	}
	catch (std::exception & ex)
	{
		throw std::exception("Invalid index");
	}
	sub_string.str = str;
	return sub_string;
}

size_t CString::FindSubString(char ch)
{
	for (size_t i = 0; i < this->Size(); i++)
		if(this->CharAt(i) == ch)
			return i;
	return this->Size();
}

size_t CString::FindSubString(const char* str)
{
	size_t check = 0;
	bool prev = false;
	size_t index = this->Size();
	for (size_t i = 0; i < this->Size(); i++)
	{
		if (str[check] == '\0')
			return index;
		if (this->CharAt(i) == str[check])
		{
			if (prev)
				check++;
			else
				check = 1, index = i;
			prev = true;
		}
		else
		{
			prev = false;
			check = 0;
		}
	}
	return this->Size();
}

size_t CString::FindSubString(const std::string& str)
{
	return this->FindSubString(str.c_str());
}

size_t CString::FindSubString(const CString& str)
{
	size_t check = 0;
	bool prev = false;
	size_t index = this->Size();
	for (size_t i = 0; i < this->Size(); i++)
	{
		if (check == str.Size())
			return index;
		if (this->CharAt(i) == str.CharAt(check))
		{
			if (prev)
				check++;
			else
				check = 1, index = i;
			prev = true;
		}
		else
		{
			prev = false;
			check = 0;
		}
	}
	return this->Size();
}

size_t CString::Size() const
{
	return this->str->GetLength();
}