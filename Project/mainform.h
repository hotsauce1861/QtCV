#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QObject>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPaintEvent>

#include "inputpicture.hpp"

class mainform : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainform(QWidget *parent = 0);

public:
    QTabWidget *mainTabwidget;

private:
    InputPicture *picOpt;
    InputPicture *picDis;
    InputPicture *picFilter;

private:
    void InitUI();
    void InitData();
    void InitConnect();
protected:
    virtual void paintEvent(QPaintEvent *e);
signals:

public slots:
};

#endif // MAINFORM_H
