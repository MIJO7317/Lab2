#pragma once
#include <QWidget>
#include "ui_Lab2Test.h"

class Lab2Test : public QWidget
{
	friend class Lab2;

	Q_OBJECT

public:
	Lab2Test(QWidget *parent = Q_NULLPTR);
	~Lab2Test();

private:
	Ui::Lab2Test ui;
};
