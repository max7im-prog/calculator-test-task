#ifndef SECRETMENU_H
#define SECRETMENU_H

#include <QObject>
#include <QQmlEngine>
#include <QtQml>
#include <QDateTime>

class SecretMenu : public QObject
{
    Q_OBJECT
    QML_ELEMENT
private:
    QDateTime timePressed;
    QDateTime timeReleased;
    QString sequence;
    QTimer *resetTimer;
    bool listening;
public:
    explicit SecretMenu(QObject *parent = nullptr);
    Q_INVOKABLE void processNumber(int num);
    Q_INVOKABLE void processEvalPress();
    Q_INVOKABLE void processEvalRelease();



signals:
    void secretUnlocked();


};

#endif // SECRETMENU_H
