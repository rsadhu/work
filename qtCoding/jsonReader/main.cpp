#include <QApplication>
#include<QDebug>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QVector>

class Listings
{
public:
    QString title;
    QString manufacturer;
    QString currency;
    QString price;
};

class Products
{
public:
    QString productName;
    QString manufacturer;
    QString model;
    QString dateOfRelease;
    QString family;
};

class Result
{
public:
 QString  productName;
 QList<Listings> listing;
};

void getMeListings(char *fileName,QVector<Listings> &listingsArray)
{
    //QFile file("/home/syilmaz/rsadhu/coding/work/qtCoding/jsonReader/listings.txt");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString val;
        val = in.readLine();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(val.toUtf8());
        qDebug()<<jsonResponse.isNull();
        QJsonObject jsObj = jsonResponse.object();

        Listings l;
        l.title =  jsObj.value(QString("title")).toString();
        l.manufacturer =  jsObj.value(QString("manufacturer")).toString();
        l.currency =  jsObj.value(QString("currency")).toString();
        l.price =  jsObj.value(QString("price")).toString();
        listingsArray.push_back(l);
    }

    for(int i=0;i<listingsArray.size();i++)
        qDebug()<<listingsArray.at(i).title<< "\n"<<listingsArray.at(i).manufacturer<<"\n"<<listingsArray.at(i).currency<<"\n"<<listingsArray.at(i).price<<"\n";

    file.close();
}
void getMeProducts(char *fileName, QVector<Products>& productsArray)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString val;
        val = in.readLine();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(val.toUtf8());
        qDebug()<<jsonResponse.isNull();
        QJsonObject jsObj = jsonResponse.object();

        Products p;
        p.productName =  jsObj.value(QString("product_name")).toString();
        p.manufacturer =  jsObj.value(QString("manufacturer")).toString();
        p.model =  jsObj.value(QString("model")).toString();
        p.dateOfRelease =  jsObj.value(QString("announced-date")).toString();
        p.family =  jsObj.value(QString("family")).toString();
        productsArray.push_back(p);
    }

    for(int i=0;i<productsArray.size();i++)
        qDebug()<<productsArray.at(i).productName<< "\n"<<productsArray.at(i).manufacturer<<"\n"<<
                  productsArray.at(i).model<<"\n"<<productsArray.at(i).dateOfRelease<<"\n"
               <<productsArray.at(i).family<<"\n";

    file.close();

}

int main(int argc, char *argv[])
{
    QVector<Listings>  listingsArray;
    QVector<Products>  productsArray;
#ifndef WIN32
    getMeListings("/home/syilmaz/rsadhu/coding/work/qtCoding/jsonReader/listings.txt",listingsArray);
    getMeProducts("/home/syilmaz/rsadhu/coding/work/qtCoding/jsonReader/products.txt",productsArray);
#elif WIN32
    getMeListings("C:\\Users\\KEREM\\Desktop\\work\\qtCoding\\jsonReader\\listings.txt",listingsArray);
    getMeProducts("C:\\Users\\KEREM\\Desktop\\work\\qtCoding\\jsonReader\\products.txt",productsArray);
#endif

    QVector<Result> results;
    for(int i=0;i<productsArray.size();i++)
    {
        Result r;
        r.productName= productsArray.at(i).productName;
        for(int j=0;j<listingsArray.size();j++)
        {
            if(
              productsArray.at(i).manufacturer.compare(listingsArray.at(j).manufacturer,Qt::CaseInsensitive)
           && listingsArray.at(j).title.contains(productsArray.at(i).family,Qt::CaseInsensitive)
           && listingsArray.at(j).title.contains(productsArray.at(i).model,Qt::CaseInsensitive))
            {
                r.listing.append(listingsArray.at(j));
            }
        }
        results.push_back(r);
    }




    return 0;
}