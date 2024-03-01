#include "mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QDir>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    this->setWindowIcon(QIcon(":/resource/logo.ico"));
    setWindowTitle("删小师");
    const int w = 400;
    const int h = 300;
    this->resize(w, h);
    lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText("输入要删除的文件夹");
    lineEdit->setFixedWidth(200);
    lineEdit->setMinimumHeight(40);
    lineEdit->setProperty("class", "lineEdit");
    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(inpChange()));

    btn = new QPushButton;
    btn->setText("删 除");
    btn->setProperty("class", "btn");
    btn->setFixedWidth(90);
    btn->setMinimumHeight(40);
    btn->setCursor(Qt::PointingHandCursor);
    connect(btn, SIGNAL(clicked()), this, SLOT(customClick()));

    inp_widget = new QWidget(this);
    inp_widget->setMinimumWidth(w);
    inp_widget->setMinimumHeight(60);
    layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    layout->setAlignment(Qt::AlignHCenter);
    inp_widget->setLayout(layout);

    vlayout = new QVBoxLayout();
    bar_widget = new QWidget(this);
    bar_widget->setFixedWidth(w);
    bar_widget->setFixedHeight(80);
    progressBar = new QProgressBar;
    progressBar->setRange(0, 100);
    progressBar->setFixedSize(280, 30);
    progressBar->setProperty("class", "processBar");
    progressBar->setVisible(false);
    layouts = new QHBoxLayout();
    layouts->addWidget(progressBar);
    bar_widget->setLayout(layouts);
    timer = new QTimer();
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    vlayout->addWidget(inp_widget);
    vlayout->addWidget(bar_widget);
    main_widget = new QWidget(this);
    main_widget->setFixedWidth(w);
    main_widget->setFixedHeight(300);

    toast = new Toast(this);

    vlayout->setSpacing(0);
    vlayout->setMargin(0);
    vlayout->setAlignment(Qt::AlignTop);
    main_widget->setLayout(vlayout);
    this->setCentralWidget(main_widget);
}

QString str = "";

void MainWindow::inpChange() {
    str = this->lineEdit->text();
};

void MainWindow::customClick() {

    QDir qdir;
    QFileInfo fileInfo(str);

    if(str == ""){
        this->toast->showToast("请输入文件路径或目录路径");
        return;
    }
    if (!qdir.exists(str)) {
        this->toast->showToast("文件路径或文件不存在");
        return;
    }
    this->progressBar->setVisible(true);
    this->timer->start();
    if (fileInfo.isFile()) {
        QFile::remove(str);
    } else if (fileInfo.isDir()) {
        QDir qDir(str);
        qDir.removeRecursively();
    }
};


void MainWindow::onTimeOut() {
    static int time = 0;
    time++;
    this->progressBar->setValue(time);
    if (time >= 100) {
        timer->stop();
        time = 0;
        this->lineEdit->setText("");
        str = "";
        this->progressBar->setVisible(false);
    }
}

MainWindow::~MainWindow() {
}
