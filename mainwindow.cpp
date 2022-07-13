#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_00, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_01, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_02, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_03, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_04, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_05, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_06, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_07, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_08, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_09, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pushButton_plussminus, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percentage, SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    connect(ui->pushButton_sum, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_subtraction, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_division, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(binary_operation_pressed()));

    ui->pushButton_sum->setCheckable(true);
    ui->pushButton_subtraction->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{

    QPushButton *pressButton = (QPushButton *)sender();
    QString newLabel;
    double labelNumber;

    if (ui->pushButton_sum->isChecked() || ui->pushButton_subtraction->isChecked() ||
        ui->pushButton_division->isChecked() || ui->pushButton_multiply->isChecked())
    {
        labelNumber = pressButton->text().toDouble();
    }else{
        labelNumber = (ui->label->text() + pressButton->text()).toDouble();
    }

    newLabel = QString::number(labelNumber, 'g', 15);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    if (!usingDecimal)
    {
        ui->label->setText(ui->label->text() + ".");
        usingDecimal = true;
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
    QPushButton *pressButton = (QPushButton *)sender();

    if (pressButton->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->label->setText(newLabel);
    }
    if (pressButton->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_C_released()
{
}

void MainWindow::on_pushButton_iquals_released()
{
    QString newLabel;
    double labelNumber, secondNumber;
    secondNumber = ui->label->text().toDouble();

    if (ui->pushButton_sum->isChecked())
    {
        labelNumber = firstNum + secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_sum->setChecked(false);
    }
    else if (ui->pushButton_subtraction->isChecked())
    {
        labelNumber = firstNum - secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_subtraction->setChecked(false);
    }
    else if (ui->pushButton_multiply->isChecked())
    {
        labelNumber = firstNum * secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if (ui->pushButton_division->isChecked())
    {
        labelNumber = firstNum / secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_division->setChecked(false);
    }
}

void MainWindow::binary_operation_pressed()
{

    QPushButton *pressButton = (QPushButton *)sender();
}
