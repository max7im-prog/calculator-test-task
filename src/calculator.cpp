#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{
    this->equation = "";
    this->result = "";
    this->numBrackets = 0;
}

Q_INVOKABLE void Calculator::evaluate()
{
    qDebug() << "eval";

    emit expressionChanged(this->equation);
    emit resultChanged(this->result);
}

Q_INVOKABLE void Calculator::sum()
{
    qDebug() << "sum";
    this->equation.push_back("+");

    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::sub()
{
    qDebug() << "sub";
    this->equation.push_back("-");
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::fraq()
{
    qDebug() << "fraq";
    this->equation.push_back("/");
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::mul()
{
    qDebug() << "mul";
    this->equation.push_back("*");
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::percent()
{
    qDebug() << "percent";
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::plusMinus()
{
    qDebug() << "+/-";
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::brackets()
{
    qDebug() << "brackets";
    QChar lastVal;
    if(this->equation.size() > 0){
        lastVal = this->equation.back();
    }else{
        lastVal = ' ';
    }
    if (this->numBrackets == 0)
    {
        this->equation.push_back("(");
        this->numBrackets++;
    }
    else
    {
        if (lastVal.isDigit())
        {
            this->equation.push_back(")");
            this->numBrackets--;
        }
        else
        {
            this->equation.push_back("(");
            this->numBrackets++;
        }
    }
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::num(int n)
{
    qDebug() << "num " << n;
    this->equation.push_back(QString::number(n));
    emit expressionChanged(this->equation);
}

Q_INVOKABLE void Calculator::clear()
{
    qDebug() << "clear";
    this->equation = "";
    this->result = "";
    this->numBrackets = 0;
    emit expressionChanged(this->equation);
    emit resultChanged(this->result);
}
