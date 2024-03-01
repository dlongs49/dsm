#include "message.h"

Message::Message(QWidget *parent) : QWidget(parent) {
    msg_widget = new QWidget(this);
    const int w = 40;
    const int h = 30;
    this->resize(w, h);
    msg_widget->setFixedHeight(100);
    msg_widget->setFixedWidth(50);
    msg_widget->setStyleSheet("background:#ff0");

//    msg_widget->hide();
    //msg_widget->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
//    timer->setInterval(1500);
//    connect(timer, SIGNAL(timeout()), this, SLOT(onMsgTimeOut()));
//    msg_widget->setProperty("class", "msg_widget");
//    layout_msg = new QHBoxLayout(this);
//    layout_msg->setAlignment(Qt::AlignHCenter);
//    msg_label = new QLabel;
//    msg_label->setProperty("class", "msg_label");
//    layout_msg->addWidget(msg_label);
//    msg_widget->setLayout(layout_msg);
//    msg_widget->setGeometry(100, 100, 200, 40);
//    msg_label->setText("文件路径或文件不存在");
}

Message::~Message() {
}