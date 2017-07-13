#include "mainform.h"

mainform::mainform(QWidget *parent) : QMainWindow(parent)
{
    InitUI();
    InitData();
    InitConnect();
}

void mainform::InitData(){


}

void mainform::InitUI(){

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainTabwidget = new QTabWidget();
    //mainTabwidget->addTab();
    mainLayout->addWidget(mainTabwidget);
}

void mainform::InitConnect(){

}
