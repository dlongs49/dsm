#include "mainwindow.h"
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
    lineEdit->setMinimumHeight(40);
    lineEdit->setProperty("class", "lineEdit");
    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(inpChange()));
    btn = new QPushButton;
    btn->setText("确定");
    btn->setProperty("class","btn");
    btn->setFixedWidth(90);
    btn->setMinimumHeight (40);
    btn->setCursor(Qt::PointingHandCursor);
    connect(btn, SIGNAL(clicked()), this, SLOT(customClick()));

    this->setContentsMargins(0,0,0,0);
    widget = new QWidget(this);
    widget->setMinimumWidth(w);
    widget->setMinimumHeight(60);
    layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    layout->setAlignment(Qt::AlignHCenter);
    widget->setLayout(layout);

    vlayout = new QVBoxLayout(this);
    widget1 = new QWidget(this);
    widget1->setFixedWidth(w);
    widget1->setFixedHeight(80);
    progressBar = new QProgressBar;
    progressBar->setRange(0,100);
    timer = new QTimer();
    timer->setInterval(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->start();
    progressBar->setFixedSize(280,30);
    progressBar->setVisible(true);
    progressBar->setProperty("class","processBar");
    layouts = new QHBoxLayout();
    layouts->addWidget(progressBar);
    widget1->setLayout(layouts);

    vlayout->addWidget(widget);
    vlayout->addWidget(widget1);
    widget2 = new QWidget(this);
    widget2->setFixedWidth(w);
    widget2->setFixedHeight(300);

    vlayout->setSpacing(0);
    vlayout->setMargin(0);
    vlayout->setAlignment(Qt::AlignTop);
    widget2->setLayout(vlayout);
    this->setCentralWidget(widget2);
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
void MainWindow::onTimeOut(){
    static int time = 0;
    time++;
    this->progressBar->setValue(time);
    qDebug()<< "进度:"<<time;
    if(time >= 100){
        timer->stop();
//        this->progressBar->setVisible(false);
    }
}
MainWindow::~MainWindow() {
}
