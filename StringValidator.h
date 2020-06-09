#pragma once
#include <QValidator>

class StringValidator : public QValidator
{
	Q_OBJECT

public:
	StringValidator(int value);
	StringValidator(int value, QObject *parent);
	QValidator::State validate(QString& input, int& pos) const;
	~StringValidator();
private:
	int value;
};
