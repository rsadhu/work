#include "ModelBasedClasses.h"
#include<QSplitter>
#include<qlistview.h>
#include<QFileSystemModel>

ModelBasedClasses::ModelBasedClasses(QWidget *parent)
	//: //QWidget(parent)
{
	//ui.setupUi(this);

	QSplitter *splitter = new QSplitter;

	QFileSystemModel *model = new QFileSystemModel;
	model->setRootPath(QDir::currentPath());
	QTreeView *tree = new QTreeView(splitter);
	tree->setModel(model);
	tree->setRootIndex(model->index(QDir::currentPath()));

	QListView *list = new QListView(splitter);
	list->setModel(model);
	list->setRootIndex(model->index(QDir::currentPath()));
	splitter->setWindowTitle("Two views onto the same file system model");

	QWidget * w = new QWidget(splitter);
	w->setStyleSheet("background-color:red");
	splitter->show();
}
