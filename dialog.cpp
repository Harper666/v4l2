#include "dialog.h"
#include "ui_dialog.h"
#include <QImage>
//#include <iostream>
//#include <QTimer>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(cameraWillReadFrame()));
//    timer->start(50);
      ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::showImage(QImage image)
{
    image = image.scaled(ui->label->size());
    ui->label->setPixmap(QPixmap::fromImage(image));
}

