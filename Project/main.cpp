#include <QApplication>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>

#include "mainform.h"

#include "opencv2/core.hpp"
#include "opencv/cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

static QImage Mat2QImage(Mat& image)
{
    QImage img;

    if (image.channels()==3) {
       // cvtColor(image, image, CV_BGR2RGB);
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                image.cols*image.channels(), QImage::Format_RGB888);
    } else if (image.channels()==1) {
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                image.cols*image.channels(), QImage::Format_ARGB32);
    } else {
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                image.cols*image.channels(), QImage::Format_RGB888);
    }

    return img;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainform *myform = new mainform();
    myform->setWindowTitle("Learn Opencv");
    myform->show();

    QWidget *wn = new QWidget;
    wn->setWindowTitle("disp image");

    QString filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.jpg *.png *.bmp", 0);
    if (filename.isNull()) {
        return -1;
    }

    Mat image = imread(filename.toStdString().data(), 1);
    QImage img = Mat2QImage(image);

    QLabel *label = new QLabel("", 0);
    label->setPixmap(QPixmap::fromImage(img));

    QPushButton *bnt = new QPushButton("Quit");
    QObject::connect(bnt, SIGNAL(clicked()), &app, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(bnt);
    wn->setLayout(layout);

    wn->show();

    return app.exec();
}

