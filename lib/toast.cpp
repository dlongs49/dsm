#include "toast.h"
#include <QDebug>

Toast::Toast(QWidget *parent) : QLabel(parent) {
    int width = 200;
    int height = 40;
    widget = new QWidget(this);
    this->move(100, 100);
    this->setMinimumWidth(width);
    this->setMinimumHeight(height);
    this->hide();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onMsgTimeOut()));
    widget->setObjectName("msg_widget");
    widget->setMinimumWidth(width);
    widget->setMinimumHeight(height);
    layout = new QHBoxLayout;
    layout->setAlignment(Qt::AlignHCenter);
    label = new QLabel;
    label->setObjectName("msg_label");
    label->setWordWrap(true);
    layout->addWidget(label);
    widget->setLayout(layout);
}

void Toast::showToast(QString msg) {
    if(this->timer->isActive()){
        // 关闭上次的定时器
        this->timer->stop();
    }
    this->label->setText(msg);
    this->timer->start(1500);
    this->show();
}

void Toast::onMsgTimeOut() {
    this->timer->stop();
    this->hide();
}

Toast::~Toast() {
}