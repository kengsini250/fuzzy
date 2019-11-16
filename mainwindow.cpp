#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fuzzy = new Fuzzy;
    painter = new Painter(this);
    painter->setSizeAndPos(POSX,POSY,WIDTH,HEIGHT);
    painter->show();
    connect(ui->pushButton,&QAbstractButton::clicked,this,[&]{
        float a,b;
        a = ui->lineEdit1->text().toFloat();
        b = ui->lineEdit2->text().toFloat();

        fuzzy->setValue(a,b);
        ui->label->setText(QString::number(fuzzy->getFuzzyValue()));

        painter->getData(a,b,fuzzy->getSmall(),fuzzy->getMid(),fuzzy->getLarge(),fuzzy->getAll());
        painter->update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

