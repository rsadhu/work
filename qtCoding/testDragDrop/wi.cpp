#include "wi.h"
#include "ui_wi.h"

wi::wi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wi)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

wi::~wi()
{
    delete ui;
}


void wi::dropEvent( QDropEvent *event )
{
    if (event->mimeData()->hasFormat("red")){
        setStyleSheet("background-color: rgb(255, 0, 0);");
        event->accept();
    }
    else
        event->ignore();
    event->acceptProposedAction();
}

void wi::dragEnterEvent( QDragEnterEvent *event )
{
    event->acceptProposedAction();
}

void wi::mousePressEvent( QMouseEvent* event )
{
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    QByteArray itemData;



    mimeData->setData("red", itemData );

    drag->setMimeData(mimeData);

    setStyleSheet("background-color: rgb(0, 255, 0);");

    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    event->accept();
}
