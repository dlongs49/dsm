#include "model.h"

Model::Model(QWidget *parent) : QWidget(parent) {
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    int width = 300;
    int height = 90;
    this->setFixedWidth(width);
    this->setFixedHeight(height);
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor("#ffffff"));
    shadow->setBlurRadius(12);
    this->setGraphicsEffect(shadow);
    this->setContentsMargins(1, 1, 1, 1);

    header_layout = new QHBoxLayout();
    header_widget = new QWidget(this);
    header_widget->setFixedWidth(width);
    header_widget->setFixedHeight(40);
    header_widget->setObjectName("header_widget");

    header_title = new QLabel();
    header_title->setText("提示");
    header_title->setStyleSheet("background:#ff0");
    header_layout->addWidget(header_title);
    header_widget->setLayout(header_layout);
//    header_layout->addWidget(header_widget);
}
void Model::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush("#ffffff"));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);

    QWidget::paintEvent(event);
    painter.fillRect(this->rect().adjusted(4, 4, -4, -4), "#ffffff");
}