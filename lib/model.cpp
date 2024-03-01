#include "model.h"

Model::Model(QWidget *parent) : QWidget(parent) {
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setFixedWidth(250);
    this->setFixedHeight(80);
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor("#ffffff"));
    shadow->setBlurRadius(12);
    this->setGraphicsEffect(shadow);
    this->setContentsMargins(1, 1, 1, 1);
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