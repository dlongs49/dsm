#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QDir>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    this->setWindowIcon(QIcon(":/logo.ico"));
    setWindowTitle("删小师");
    const int w = 400;
    const int h = 300;
    this->resize(w, h);
    lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText("请输入要删除的路径");
    lineEdit->setFixedWidth(200);
    lineEdit->setProperty("class", "lineEdit");
    lineEdit->setMinimumHeight(40);
    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(inpChange()));
    btn = new QPushButton;
    btn->setText("确定");
    btn->setProperty("class","btn");
    btn->setFixedWidth(100);
    btn->setFixedHeight (40);
    btn->setCursor(Qt::PointingHandCursor);
    connect(btn, SIGNAL(clicked()), this, SLOT(customClick()));

    this->setContentsMargins(0,0,0,0);
    QWidget *widget = new QWidget(this);
    widget->setMinimumSize(w, h);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    widget->setLayout(layout);
}
QString str = "";
void MainWindow::inpChange(){
    str = this->lineEdit->text();
};
void MainWindow::customClick(){
    QDir qdir;
    msg = new QMessageBox;
    if(!qdir.exists(str)){
        msg->information(this,"提示","文件路径不合法");
        return;
    }
    qDebug() << str;
    QDir qDir(str);
    qDir.removeRecursively();
};

MainWindow::~MainWindow() {
}
