#pragma once
#include "CString.h"
#include "StringBuilder.h"

bool TestAppend()
{
	std::string result_string = "qwerty123";
	StringBuilder str = "qwerty";
	str.Append('1');
	str.Append("23");
	if (str.Size() != result_string.size())
		return false;
	for (size_t i = 0; i < result_string.size(); i++)
		if (result_string[i] != str.CharAt(i))
			return false;
	return true;
}

bool TestPrepend()
{
	std::string result_string = "231qwerty";
	StringBuilder str = "qwerty";
	str.Prepend('1');
	str.Prepend("23");
	if (str.Size() != result_string.size())
		return false;
	for (size_t i = 0; i < result_string.size(); i++)
		if (result_string[i] != str.CharAt(i))
			return false;
	return true;
}

bool TestInsert()
{
	std::string result_string = "qwe123rty";
	StringBuilder str = "qwerty";
	str.Insert(3,'1');
	str.Insert(4,"23");
	if (str.Size() != result_string.size())
		return false;
	for (size_t i = 0; i < result_string.size(); i++)
		if (result_string[i] != str.CharAt(i))
			return false;
	return true;
}

bool TestRemove()
{
	std::string result_string = "qwerty";
	StringBuilder str = "qwe123rty";
	str.Remove(3,3);
	if (str.Size() != result_string.size())
		return false;
	for (size_t i = 0; i < result_string.size(); i++)
		if (result_string[i] != str.CharAt(i))
			return false;
	return true;
}

bool TestReplace()
{
	std::string result_string = "123qwerty4";
	StringBuilder str = "4qwerty123";
	str.Replace(0, 1, "123");
	str.Replace(9, 3, "4");
	if (str.Size() != result_string.size())
		return false;
	for (size_t i = 0; i < result_string.size(); i++)
		if (result_string[i] != str.CharAt(i))
			return false;
	return true;
}

bool TestToString()
{
	CString result_string = "qwerty";
	StringBuilder str = "qwerty";
	CString cstr = str.ToString();
	if (cstr.Size() != result_string.Size())
		return false;
	for (size_t i = 0; i < result_string.Size(); i++)
		if (result_string.CharAt(i) != cstr.CharAt(i))
			return false;
	return true;
}

bool TestSubString()
{
	CString result_string = "qwerty";
	StringBuilder str = "qwerty123";
	CString sub_str = str.ToString().SubString(0,6);
	if (sub_str.Size() != result_string.Size())
		return false;
	for (size_t i = 0; i < result_string.Size(); i++)
		if (result_string.CharAt(i) != sub_str.CharAt(i))
			return false;
	return true;
}

bool TestFindSubString()
{
	CString sub_str = "ty1";
	size_t result_index = 4;
	StringBuilder str = "qwerty123";
	size_t index = str.ToString().FindSubString(sub_str);
	return index == result_index ? true : false;
}

