#pragma once

#include <QtWidgets/QWidget>
#include "ui_Lab2.h"

class Lab2 : public QWidget
{
	Q_OBJECT

public:
	Lab2(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab2Class ui;
};
