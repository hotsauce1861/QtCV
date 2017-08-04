#include "mainform.h"
#include <QPushButton>

mainform::mainform(QWidget *parent) : QMainWindow(parent)
{
    InitData();
    InitUI();
    InitConnect();
}

void mainform::InitData(){
    picOpt = new InputPicture();
    picDis = new InputPicture();
    picFilter = new InputPicture();
}

void mainform::InitUI(){

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainTabwidget = new QTabWidget();

    QHBoxLayout *topLayout = new QHBoxLayout();
    QHBoxLayout *middleLayout = new QHBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QWidget *newWidget = new QWidget(this);
    newWidget->setLayout(mainLayout);
    this->setCentralWidget(newWidget);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(middleLayout);
    mainLayout->addLayout(buttonLayout);

    QPushButton *temp = new QPushButton();

    temp->setText(tr("Connect"));
    //mainTabwidget->addTab();

    mainTabwidget = new QTabWidget();
    mainTabwidget->addTab(picDis,tr("Display"));
    //mainTabwidget->addTab(picOpt,tr("Operation"));
    mainTabwidget->addTab(picFilter,tr("Filter"));

    buttonLayout->addWidget(temp);
    topLayout->addWidget(mainTabwidget);
    //this->setLayout(mainLayout);

}

void mainform::InitConnect()
{

}

void mainform::paintEvent(QPaintEvent *e){
    picOpt->m_label_target->resize(this->size());
    picOpt->m_label_processed->resize(this->size());
}
