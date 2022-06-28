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
    connect(ui->pushButton_plussminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
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


void MainWindow::on_pushButton_decimal_released()
{
    if(!usingDecimal){
    ui->label->setText(ui->label->text()+".");
    usingDecimal =true;
    }
}
/**
 * @brief MainWindow::unary_operation_pressed
 * Operaçoes unarias
 */
void MainWindow::unary_operation_pressed()
{
    QString newLabel;
    double labelNumber;

    QPushButton *pressButton = (QPushButton*)sender();
    if(pressButton->text() == "+/-"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber*-1;
        newLabel = QString::number(labelNumber,'g',15);

        ui->label->setText(newLabel);
    }
}
