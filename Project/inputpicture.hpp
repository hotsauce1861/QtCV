#ifndef INPUTPICTURE_HPP
#define INPUTPICTURE_HPP


#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QImage>

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv/cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class InputPicture{
public:
    InputPicture();
    QPushButton *Btnloadfile;

    QImage Mat2QImage(Mat& image);
private:
    void InitUI();
    void InitData();
    void InitConnect();

public:
    void readfile(QString path);
};

#endif // INPUTPICTURE_HPP

