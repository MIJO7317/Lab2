#include "Lab2.h"
#include "ui_Lab2.h"
#include <QtWidgets/QApplication>
#include <vld.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab2 w;
	w.show();
	return a.exec();
}
