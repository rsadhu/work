#include "imageprocessor.h"

ImageProcessor::ImageProcessor(QString &path)
{
    mSrc = new QImage(path);
}

ImageProcessor::~ImageProcessor()
{
    if(mSrc)
        delete mSrc;
}


void ImageProcessor::process()
{
    for(int i=0;i<mSrc->width();i+=2){
        for(int j=0;j<mSrc->height();j+=2)
        {
            QImage imgs = mSrc->copy(i,j,2,2);
            mImages.push_back(imgs);
        }
    }
}


void ImageProcessor::printRGB(CType t)
{
    QVector<QImage>::Iterator it;
    QImage tImage;
    for (it = mImage.begin(); it != mImage.end(); ++it)
    {
        tImage = *it;

    }


}

