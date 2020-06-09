#include "Lab2.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "StringBuilder.h"
#include "CString.h"
#include "Tests.h"
#include <string>
#include "StringValidator.h"
#include "vld.h"

Lab2::Lab2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	test_window.setWindowTitle("Tests");
	UpdateValidator(ui.Index, 0);
	UpdateValidator(ui.Count, 1);
	QObject::connect(ui.GetButton, SIGNAL(clicked()), this, SLOT(SetSubSequence()));
	QObject::connect(ui.String, SIGNAL(editingFinished()), this, SLOT(UpdateValidatorIndex()));
	QObject::connect(ui.Index, SIGNAL(editingFinished()), this, SLOT(UpdateValidatorCount()));
	QObject::connect(ui.FindButton, SIGNAL(clicked()), this, SLOT(SetIndexFind()));
	QObject::connect(ui.TestButton, SIGNAL(clicked()), this, SLOT(StartTest()));
}

void Lab2::SetSubSequence()
{
	if (ui.Index->text() == "" || ui.String->text() == "" || ui.Count->text() == "")
		return;
	StringBuilder str = ui.String->text().toStdString();
	CString sub_cstr = str.ToString().SubString(ui.Index->text().toInt(), ui.Count->text().toInt());
	QString sub_qstr;
	for (size_t i = 0; i < sub_cstr.Size(); i++)
		sub_qstr.append(sub_cstr.CharAt(i));
	ui.SubstringGet->setText(sub_qstr);
}

void Lab2::UpdateValidator(QLineEdit* line_edit, int count)
{
	line_edit->setValidator(new StringValidator(count,line_edit));
}

void Lab2::SetIndexFind()
{
	StringBuilder str = ui.String->text().toStdString();
	size_t first_index = str.ToString().FindSubString(ui.SubstringFind->text().toStdString());
	QString index_str = first_index == str.Size() ? "Not found" : std::to_string(first_index).c_str();
	ui.FirstIndex->setText(index_str);
}

void Lab2::UpdateValidatorIndex()
{
	UpdateValidator(ui.Index, ui.String->text().size());
	if (ui.Index->text().toInt() >= ui.String->text().size())
		ui.Count->setText(""), ui.Index->setText("");
	else if(ui.Count->text().toInt() >= ui.String->text().size() - ui.Index->text().toInt() + 1)
		ui.Count->setText("");
	UpdateValidatorCount();
}

void Lab2::UpdateValidatorCount()
{
	if(ui.Index->text() == "")
		UpdateValidator(ui.Count, 1);
	else
		UpdateValidator(ui.Count, ui.String->text().size() - ui.Index->text().toInt() + 1);
	if(ui.Count->text().toInt() >= ui.String->text().size() - ui.Index->text().toInt() + 1)
		ui.Count->setText("");
}

void Lab2::StartTest()
{
	test_window.show();
	test_window.ui.TestAppendLable->setText(TestAppend() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestPrependLable->setText(TestPrepend() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestInsertLable->setText(TestInsert() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestRemoveLable->setText(TestRemove() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestReplaceLable->setText(TestReplace() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestToStringLable->setText(TestToString() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestSubStringLable->setText(TestSubString() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
	test_window.ui.TestFindSubStringLable->setText(TestFindSubString() ? "<font color=\"green\">Success</font>" : "<font color=\"red\">Failure</font>");
}
