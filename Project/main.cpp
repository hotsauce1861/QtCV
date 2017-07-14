#include <QApplication>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


#include "mainform.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainform *myform = new mainform();
    myform->setWindowTitle("Learn Opencv");
    myform->show();

    return app.exec();
}

