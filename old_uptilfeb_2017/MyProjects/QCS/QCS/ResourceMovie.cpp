#include "ResourceMovie.h"


ResourceMovie::ResourceMovie(const QString &file, QWidget*parent) :QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
}


ResourceMovie::~ResourceMovie()
{
}


void ResourceMovie::showResource()
{

}