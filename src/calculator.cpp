#include "calculator.h"
#include "exprtk.hpp"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{
    this->equation = "";
    this->result = "";
    this->numBrackets = 0;
}

Q_INVOKABLE void Calculator::evaluate()
{
    qDebug() << "Evaluating: " << this->equation;

    // Define the necessary ExprTk components
    typedef exprtk::symbol_table<double> SymbolTable;
    typedef exprtk::expression<double> Expression;
    typedef exprtk::parser<double> Parser;

    SymbolTable symbol_table;
    Expression expr;
    expr.register_symbol_table(symbol_table);

    Parser parser;
    std::string exprStr = this->equation.toStdString(); 

    if (!parser.compile(exprStr, expr))
    {
        qDebug() << "Error: Failed to parse expression!";
        this->result = "Error";
    }
    else
    {
        double evalResult = expr.value();
        this->result = QString::number(evalResult);
    }

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
    if(this->result != ""){
        this->equation = this->result;
        this->equation.push_back("/100");
        this->evaluate();
    }
}

Q_INVOKABLE void Calculator::signToggle()
{
    qDebug() << "+/-" << this->equation;

    if (this->equation.isEmpty()) return; // No operation on empty expression

    int i = this->equation.length() - 1;

    while (i >= 0 && this->equation[i].isSpace()) {
        i--;
    }

    int end = i;
    while (i >= 0 && (this->equation[i].isDigit() || this->equation[i] == '.')) {
        i--;
    }

    int start = i + 1;

    if (i >= 0 && (this->equation[i] == '-' || this->equation[i] == '+')) {
        // Toggle sign
        if (this->equation[i] == '-') {
            this->equation.remove(i, 1); // Remove existing '-'
        } else {
            this->equation[i] = '-'; // Change `+` to `-`
        }
    } else {
        // No sign present, insert `-`
        this->equation.insert(start, '-');
    }


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

Q_INVOKABLE void Calculator::decimalPoint()
{
    qDebug() << "decimal point";
    this->equation.push_back(".");
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
