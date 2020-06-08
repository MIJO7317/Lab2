#include "Lab2.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "ArraySequence.h"
//#include "ErrorMessage.h"
#include "StringBuilder.h"
#include "CString.h"
#include <string>
#include <vector>
#include <list>
#include <optional>
#include <iostream>
#include "vld.h"

Lab2::Lab2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	std::string str = "";
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	//struct Point
	//{
	//	float x;
	//	float y;
	//};
	std::vector<int> arr2(2);
	std::list<int> ls;// = {0,1,2,3,4,5};
	//ls.back();
	//ls.erase(ls.end());
	//auto it = ls.begin();
	//it++;
	//ls.erase(it);
	//Point p{};
	//for (size_t i = 0; i < arr2.size(); i++)
	//{
	//	arr2[i] = i;
	//}
	//for (size_t i = 0; i < arr2.size(); i++)
	//{
	//	/*str += std::to_string(arr2[i]);*/
	//}
	//vec->push_back(10);
	DynamicArray<int> *dyn = new DynamicArray<int>();
	delete dyn;
	DynamicArray<int> dm(arr,5,1);
	dm.Insert(2, 9, 5);
	dm.Erase(7,3);
	dm.Clear();
	for (size_t i = 0; i < dm.Size(); i++)
	{
		str+= std::to_string(dm[i].value());
	}
	DynamicArray<int> dm2(2);
	DynamicArray<int> dm3(10, 1);
	//const DynamicArray<int> dm4(10, 5);
    dm3=dm2=dm3=dm;
	dm3 = DynamicArray(10, 1);
	dm3.At(2)=3;
	std::optional<int> op = 3;
	dm3.operator[](3) = op;
	//try 
	//{
	//	dm3[2] = dm4[1];
	//}
	//catch(const char* str)
	//{
	//	OutputError(str);
	//}
	dm3.Resize(6);
	//for (size_t i = 0; i < 16; i++)
	//{
	//	dm3.PushBack(9).PushFront(1);
	//}
	dm3.PushBack(7);
	dm3.PopFront();
	dm3.PopBack();
	/*for (size_t i = 0; i < dm3.Size(); i++)
	{
		if (dm3[i])
			str += std::to_string(dm3[i].value());
		else
			str += std::to_string(0);
	}*/
	/*try
	{
		arr2.begin()--;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what();
	}*/
	DynamicArray<char> dm_char;
	for (size_t i = 0; i < 100; i++)
		dm_char.PushBack('a');
	LinkedList<int> list;
	//list.PopBack();
	list.Insert(list.begin(), 0);
	list.PushBack(5);
	list.Insert(list.end(),7);
	LinkedList<int> list2 = LinkedList<int>(2,9);
	list = list2;
	list = LinkedList<int>(4,6);
	LinkedList<double> list3 = {1.4, 3.1415, 1.8, 0.0001};
	list3 = {1.6, 0.1, 4, 6.8, 23456};
	for (auto el : list3)
	{
		str += std::to_string(el);
	}
	Sequence<int>* seq1 = new ArraySequence(4,5);
	Sequence<int>* seq2 = new ListSequence{1,1,1,1,5,1,1,3,1};
	seq1->Concat(seq1);
	seq1->Set(8, 1);
	int a = seq1->Get(2);
	seq1->RemoveAll(5);
	delete seq1;
	delete seq2;
	StringBuilder str_build = "Stas124";
	char ch = str_build.CharAt(3);
	str_build.Insert(4, "Julia");
	str_build.Remove(0, 4);
	CString str_string = str_build.ToString();
	char ch1 = str_string.CharAt(0);
	CString sub_str = str_string.SubString(1, 2);
	size_t index = str_string.FindSubString(sub_str);
	ui.lineEdit->setText(str.c_str());
}
