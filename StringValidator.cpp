#include "StringValidator.h"

StringValidator::StringValidator(int value)
	: value(value), QValidator(NULL)
{
}

StringValidator::StringValidator(int value, QObject *parent)
	: value(value), QValidator(parent)
{
}

QValidator::State StringValidator::validate(QString& input, int& pos) const
{
	if (input.isEmpty())
		return Acceptable;
	bool b;
	int val = input.toInt(&b);
	if ((b == true) && (val >= 0) && (val < value))
	{
		return Acceptable;
	}
	return Invalid;
}

StringValidator::~StringValidator()
{
}
