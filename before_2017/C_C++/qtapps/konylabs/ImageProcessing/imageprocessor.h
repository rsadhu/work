#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include<QImage>
#include<QVector>
#include<QDebug>
#include<QColor>




typedef enum
{
    RED,
    GREEN,
    BLUE
}CType;

class MyImage
{
public:
    MyImage(QImage *img,int rv,int gv,int bv):mImage(img),rValue(rv),gValue(gv),bValue(bv),next(0)
    {
        qDebug()<<"MyImage::MyImage\n";
    }
    
    QImage *mImage;
    int rValue;
    int gValue;
    int bValue;
    MyImage *next;
};

class MyImageList
{
public:
    MyImageList():mHead(0){}
    MyImageList & operator <<(MyImage *);
    void ascending(CType t);
    void descending(CType t);
private:
    MyImage *mHead;
};


class ImageProcessor
{
public:
    explicit ImageProcessor(QString &path);
    void process();
    void showImage(CType t,int ad=0);
    ~ImageProcessor();
private:
   MyImageList mImageList;
   QImage *mSrc;
};

#endif // IMAGEPROCESSOR_H
