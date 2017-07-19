#ifndef INPUTPICTURE_HPP
#define INPUTPICTURE_HPP

#include <QObject>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class InputPicture:public QWidget
{
    Q_OBJECT
public:
    explicit InputPicture(QWidget* parent = 0);
    QPushButton *Btnloadfile;

    QImage Mat2QImage(Mat& image);
private:

    QVBoxLayout* mainLayout;
    QLabel *label;
    void InitUI();
    void InitData();
    void InitConnect();

public:
    void readfile(QString path);

private slots:

    void loadpicture();

};

#endif // INPUTPICTURE_HPP

