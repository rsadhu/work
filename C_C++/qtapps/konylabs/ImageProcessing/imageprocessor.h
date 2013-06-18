#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include<QImage>
#include<QVector>

typedef enum
{
    RED,
    GREEN,
    BLUE
}CType;

class ImageProcessor
{
public:
    explicit ImageProcessor(QString &path);
    void process();
    void printRGB(CType t);
    ~ImageProcessor();
private:
    QImage *mSrc;
    QVector<QImage> mImages;
};

#endif // IMAGEPROCESSOR_H
