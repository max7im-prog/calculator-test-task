#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QQmlEngine>
#include <QtQml>

class Calculator : public QObject
{
    Q_OBJECT
    QML_ELEMENT
private:
    QString result;
    QString equation;
    int numBrackets;
public:
    explicit Calculator(QObject *parent = nullptr);
    Q_INVOKABLE void evaluate();
    Q_INVOKABLE void sum();
    Q_INVOKABLE void sub();
    Q_INVOKABLE void fraq();
    Q_INVOKABLE void mul();
    Q_INVOKABLE void percent();
    Q_INVOKABLE void signToggle();
    Q_INVOKABLE void brackets();
    Q_INVOKABLE void decimalPoint();
    Q_INVOKABLE void num(int n);
    Q_INVOKABLE void clear();


signals:
    void resultChanged(QString newResult);
    void expressionChanged(QString newEquation);
};

#endif // CALCULATOR_H
