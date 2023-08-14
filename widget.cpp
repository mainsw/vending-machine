#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0); // Set the initial state of the drink buttons
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);

    // Enable or disable drink buttons based on the money amount
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}



void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    if(money >= 100) {
        changeMoney(-100);
    }
}


void Widget::on_pbTea_clicked()
{
    if(money >= 150) {
        changeMoney(-150);
    }
}


void Widget::on_pbMilk_clicked()
{
    if(money >= 200) {
        changeMoney(-200);
    }
}

void Widget::on_pbReset_clicked()
{
    int num_500 = money / 500;
    money %= 500;
    int num_100 = money / 100;
    money %= 100;
    int num_50 = money / 50;
    money %= 50;
    int num_10 = money / 10;
    money %= 10;

    QString change_info = QString("Money Reset: \n500 won: %1 coins\n100 won: %2 coins\n50 won: %3 coins\n10 won: %4 coins")
                              .arg(num_500).arg(num_100).arg(num_50).arg(num_10);
    QMessageBox::information(this, "Reset", change_info);

    // Reset the money
    changeMoney(-money);
}


