#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPlainTextEdit>
#include<QMenu>
#include<QAction>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap p;
    p.load("/home/rsadhu/Desktop/chick.jpg");
    ui->widget->render(&p);
}

void MainWindow::setUpForms()
{


    m_Form1 = new Form1();
    m_Form2 = new Form2();
   // ui->gridLayout->addWidget(m_Form1);
   // ui->gridLayout2->addWidget(m_Form2);
}

void MainWindow::testMixStuff()
{

    menu = this->menuBar()->addMenu("Test");
    sayHello = new QAction("sayHEllo", this);
    openBrowser = new QAction("surf", this);
    connect(sayHello, SIGNAL(triggered(bool)), this, SLOT(slotSayHello(bool)));
    connect(openBrowser, SIGNAL(triggered(bool)), this, SLOT(slotTestWebView(bool)));
    menu->addAction(sayHello);
    menu->addAction(openBrowser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotSayHello(bool val)
{
 tmpDialog.show();
}


void MainWindow::slotTestWebView(bool val)
{
   mWebView = new QWebView;
   mWebView->load(QUrl("http://google.com"));
   mWebView->show();
}

