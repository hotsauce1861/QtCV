#ifndef INPUTPICTURE_HPP
#define INPUTPICTURE_HPP

#include "opencv2/opencv.hpp"
#include <QString>
#include <QPushButton>
#include <QLabel>
class InputPicture{
public:
    InputPicture();
    QPushButton *Btnloadfile;
private:
    void InitUI();
    void InitData();
    void InitConnect();

public:
    void readfile(QString path);
};

#endif // INPUTPICTURE_HPP

