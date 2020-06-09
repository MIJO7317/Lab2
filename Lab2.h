#pragma once
#include <QtWidgets/QWidget>
#include "ui_Lab2.h"
#include "Lab2Test.h"

class Lab2 : public QWidget
{

	Q_OBJECT

public:
	Lab2(QWidget *parent = Q_NULLPTR);
	void UpdateValidator(QLineEdit* line_edit, int count);
	
public slots:
	void SetSubSequence();
	void SetIndexFind();
	void UpdateValidatorIndex();
	void UpdateValidatorCount();
	void StartTest();
private:
	Ui::Lab2Class ui;
	Lab2Test test_window;
};


