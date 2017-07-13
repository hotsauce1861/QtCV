#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QObject>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

class mainform : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainform(QWidget *parent = 0);

public:
    QTabWidget *mainTabwidget;
private:
    void InitUI();
    void InitData();
    void InitConnect();
signals:

public slots:
};

#endif // MAINFORM_H
