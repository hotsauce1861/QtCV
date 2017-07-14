#include "inputpicture.hpp"
#include <QFileDialog>



//imread
//imwrite
//imshow
//nameWindow

InputPicture::InputPicture()
{
    QString filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.jpg *.png *.bmp", 0);
    if (filename.isNull()) {
        return ;
    }

    Mat image = imread(filename.toStdString().data(), 1);
    QImage img = Mat2QImage(image);

    QLabel *label = new QLabel("", 0);
    label->setPixmap(QPixmap::fromImage(img));
}

void InputPicture::readfile(QString path){
      //  Mat myMat = imread();
}


QImage InputPicture::Mat2QImage(Mat& image)
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
