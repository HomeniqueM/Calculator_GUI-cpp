#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_00,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_01,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_02,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_03,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_04,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_05,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_06,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_07,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_08,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_09,SIGNAL(released()),this,SLOT(digit_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){

    QPushButton *pressButton = (QPushButton*)sender();
    QString newLabel;
    double labelNumber;


    labelNumber= (ui->label->text() + pressButton->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
}

