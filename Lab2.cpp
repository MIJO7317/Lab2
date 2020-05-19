#include "Lab2.h"
#include "DynamicArray.h"
#include "ErrorMessage.h"
#include <string>
#include <vector>
#include <optional>
#include <iostream>

Lab2::Lab2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	std::string str = "";
	int* arr = new int[10]{0,1,2,3,4,5,6,7,8,9};
	//struct Point
	//{
	//	float x;
	//	float y;
	//};
	std::vector<int> arr2(10);
	//Point p{};
	//for (size_t i = 0; i < arr2.size(); i++)
	//{
	//	arr2[i] = i;
	//}
	arr2.erase(arr2.begin() + 2);
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
	for (size_t i = 0; i < dm3.Size(); i++)
	{
		if (dm3[i])
			str += std::to_string(dm3[i].value());
		else
			str += std::to_string(0);
	}
	//try
	//{
	//
	//}
	//catch (std::exception & ex)
	//{
	//	std::cout << ex.what();
	//}
	ui.lineEdit->setText(str.c_str());
}
