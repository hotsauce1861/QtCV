#include "inputpicture.hpp"
#include <QFileDialog>
#include <QRadioButton>
//imread
//imwrite
//imshow
//nameWindow

InputPicture::InputPicture(QWidget *parent):
    QWidget(parent)
{
    InitData();
    InitUI();
    InitConnect();

}

void InputPicture::InitData()
{
    Btnloadfile = new QPushButton();
    m_label_target = new QLabel();
    m_label_processed = new QLabel();

}

void InputPicture::InitConnect()
{
    connect(Btnloadfile,SIGNAL(clicked()),this,SLOT(loadpicture()));
}

void InputPicture::InitUI()
{
    mainLayout = new QVBoxLayout();

    QHBoxLayout *leftLayout = new QHBoxLayout();
    QHBoxLayout *middleLayout = new QHBoxLayout();

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(middleLayout);


    m_label_target->setText(tr(""));
    m_label_target->setFixedWidth(490);
    m_label_target->setScaledContents(true);
    m_label_target->setFrameStyle(QFrame::Panel);

    m_label_processed->setText(tr(""));
    m_label_processed->setFixedWidth(490);
    m_label_processed->setScaledContents(true);
    m_label_processed->setFrameStyle(QFrame::Panel);

    Btnloadfile->setText(tr("Browser"));
    middleLayout->addWidget(m_label_target);
    middleLayout->addWidget(m_label_processed);
    mainLayout->addWidget(Btnloadfile);

    QRadioButton *ROI = new QRadioButton();
    ROI->setText(tr("ROI"));

    QRadioButton *COLOR = new QRadioButton();
    COLOR->setText(tr("Color channels"));
    leftLayout->addWidget(ROI);
    leftLayout->addWidget(COLOR);
    this->setLayout(mainLayout);

}

void InputPicture::readfile(QString path){
      //  Mat myMat = imread();

    Mat image = imread(path.toStdString().data(), 1);
    QImage img = Mat2QImage(image);

    m_label_target->setPixmap(QPixmap::fromImage(img));
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

void InputPicture::loadpicture()
{
    QString filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.jpg *.png *.bmp", 0);
    if (filename.isNull()) {
        return ;
    }
    Mat image = imread(filename.toStdString().data(), 1);
    QImage img = Mat2QImage(image);

    m_label_target->setPixmap(QPixmap::fromImage(img));
}
