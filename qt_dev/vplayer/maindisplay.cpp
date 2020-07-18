#include "maindisplay.h"
#include "./ui_maindisplay.h"

MainDisplay::MainDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainDisplay)
{
    ui->setupUi(this);
    ui->label_1->setText("play");
    ui->label_2->setText("record");
    ui->label_3->setText("stop");
}

MainDisplay::~MainDisplay()
{
    delete ui;
}

