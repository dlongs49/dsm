#include "mainwindow.h"
#include <iostream>

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
    lineEdit->setFont(QFont("PingFang SC", 10));
    lineEdit->setFixedWidth(240);
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
    inp_widget->setFixedSize(w, 60);
    layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    layout->setContentsMargins(0, 20, 0, 0);
    layout->setAlignment(Qt::AlignHCenter);
    inp_widget->setLayout(layout);


    bar_widget = new QWidget(this);
    bar_widget->setFixedWidth(w);
    bar_widget->setFixedHeight(50);
    progressBar = new QProgressBar;
    progressBar->setRange(0, 100);
    progressBar->setFixedSize(330, 30);
    progressBar->setProperty("class", "processBar");
    progressBar->setVisible(false);
    layouts = new QHBoxLayout();
    layouts->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
    layouts->setMargin(0);
    layouts->setSpacing(0);
    layouts->addWidget(progressBar);
    bar_widget->setLayout(layouts);
    timer = new QTimer();
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));


    list_widget = new QWidget(this);
    list_widget->setFixedSize(w, 180);
    list_layout = new QHBoxLayout();
    list = new QListWidget(this);
    list->setFixedSize(330, 170);
    list->setObjectName("list");
    list_layout->addWidget(list);
    list_layout->setContentsMargins(0, 10, 0, 0);
    list_layout->setAlignment(Qt::AlignHCenter);
    list_widget->setLayout(list_layout);
    list_widget->setVisible(false);

    vlayout = new QVBoxLayout();
    vlayout->setSpacing(0);
    vlayout->setMargin(0);
    vlayout->addWidget(inp_widget);
    vlayout->addWidget(list_widget);
    vlayout->addWidget(bar_widget);
    vlayout->setAlignment(Qt::AlignTop);
    main_widget = new QWidget(this);
    main_widget->setFixedWidth(w);
    main_widget->setFixedHeight(300);

    toast = new Toast(this); // 轻提示
    model = new Model(); // 弹框
    model->setWindowModality(Qt::ApplicationModal);
    model->setAttribute(Qt::WA_DeleteOnClose);
    connect(model, SIGNAL(emitOn()), this, SLOT(handleOn()));


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
    if (str == "") {
        this->toast->showToast("请输入文件路径或目录路径");
        return;
    }
    if (!qdir.exists(str)) {
        this->toast->showToast("文件路径或文件不存在");
        return;
    }
    this->list_widget->show();
    this->list->clear();
    QDir dir(str);
    dir.setFilter (QDir::Dirs|QDir::Files);
    QStringList filters;
//    filters << "*.." << "*.";
//    QStringList files = dir.entryList();
    QList<QFileInfo>files = dir.entryInfoList(filters);
    for (int i = 0; i < files.count(); i++) {
        item = new QListWidgetItem();
        item->setText(files.at(i).fileName());
        this->list->addItem(item);
    }
    this->model->show();

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
        this->list->clear();
        this->progressBar->setVisible(false);
    }
}

void MainWindow::handleOn() {
    QDir qdir;
    QFileInfo fileInfo(str);
    this->progressBar->setVisible(true);
    this->timer->start();
    if (fileInfo.isFile()) {
        QFile::remove(str);
        this->model->hide();
    } else if (fileInfo.isDir()) {
        QDir qDir(str);
        qDir.removeRecursively();
        this->model->hide();
    }

}

MainWindow::~MainWindow() {
}
