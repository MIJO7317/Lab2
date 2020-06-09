#pragma once
#include"qobject.h"
#include "qvalidator.h"

class MyValidator : public QValidator
{

	Q_OBJECT

public:
	explicit MyValidator(int par, QObject* parent = 0) : par(par) {}
	virtual State validate(QString& input, int& pos) const
	{
		if (input.isEmpty())
			return Acceptable;
		bool b;
		int val = input.toInt(&b);
		if ((b == true) && (val >= 0) && (val < par))
		{
			return Acceptable;
		}
		return Invalid;
	}
	~MyValidator(){}
private:
	int par;
};