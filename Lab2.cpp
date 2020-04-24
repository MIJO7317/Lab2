#include "Lab2.h"
#include "DynamicArray.h"
#include <string>
#include <vector>
#include <optional>

Lab2::Lab2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	int* arr = new int[10]{0,1,2,3,4,5,6,7,8,9};
	std::vector<int> arr2;
	//vec->push_back(10);
	DynamicArray<int> *dyn = new DynamicArray<int>();
	delete dyn;
	DynamicArray<int> dm(arr, 4, 4);
	DynamicArray<int> dm2(2);
	DynamicArray<int> dm3(5);
	dm3=dm2=dm3=dm;
	//dm3.Set(2, 3);
	dm3[2] = std::optional<int>{ 3 };
	std::string str;
	for (int i = 0; i < dm3.Size(); i++)
	{
		str += std::to_string(*dm3.Get(i));
	}
	ui.lineEdit->setText(str.c_str());
}
