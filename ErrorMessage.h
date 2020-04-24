#pragma once
#include <QMessageBox>

void OutputError(const char* msg)
{
	QMessageBox::critical(0, "Error", msg);
}