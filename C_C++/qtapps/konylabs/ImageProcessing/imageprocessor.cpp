#include "imageprocessor.h"

MyImageList & MyImageList::operator <<(MyImage *img)
{
    if(!mHead)
    {
       mHead = img;
    }else{

    MyImage *tra;
    for(tra= mHead;tra->next!=NULL;tra=tra->next);
    tra->next = img;
    }
    return *this;
}

void MyImageList::ascending(CType t)
{

}

void MyImageList::descending(CType t)
{

}

ImageProcessor::ImageProcessor(QString &path)
{
    mSrc = new QImage(path);
    if(mSrc->isNull()==true)
    {
        qDebug()<<" file cudnt be opened\n";
    }
}

ImageProcessor::~ImageProcessor()
{
    if(mSrc)
        delete mSrc;
}


void ImageProcessor::process()
{
    for(int i=0;i<mSrc->width();i+=2)
    {
        for(int j=0;j<mSrc->height();j+=2)
        {
            QImage img = mSrc->copy(i,j,2,2);

            if ( false == img.isNull() )
            {
                int rv=0,gv=0,bv=0;
                QVector<QRgb> v = img.colorTable(); // returns a list of colors contained in the image's color table.

                 for ( QVector<QRgb>::const_iterator it = v.begin(), itE = v.end(); it != itE; ++it )
                {
                    QColor clrCurrent( *it );
                    qDebug()<< "Red: " << clrCurrent.red()<< " Green: " << clrCurrent.green()<< " Blue: " << clrCurrent.blue()<< " Alpha: " << clrCurrent.alpha()<<"\n";
                    bv+=clrCurrent.blue();
                    gv+=clrCurrent.green();
                    rv+=clrCurrent.red();
                }
                 QImage *tmp =  new QImage(img);
                 MyImage *Img= new MyImage(tmp,rv,gv,bv);
                 mImageList<<Img;
            }
        }
    }
}


void ImageProcessor::showImage(CType t,int ad)
{



}

