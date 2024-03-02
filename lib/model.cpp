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
    header_layout->setMargin(0);
    header_layout->setSpacing(0);
    header_layout->setDirection(QHBoxLayout::LeftToRight);
    header_widget = new QWidget(this);
    header_widget->setFixedWidth(width);
    header_widget->setFixedHeight(40);
    header_widget->setObjectName("header_widget");

    header_title = new QLabel();
    header_title->setText("提示");
    header_title->setStyleSheet("margin-left:20px;font-size:14px");

    close_btn = new QPushButton();
    close_btn = new QPushButton();
    close_btn->setIcon(QIcon(":/resource/close.png"));
    close_btn->setIconSize(QSize(12, 12));
    close_btn->setFixedSize(40, 20);
    close_btn->setObjectName("close_btn");
    close_btn->setCursor(Qt::PointingHandCursor);
    connect(close_btn, SIGNAL(clicked()), this, SLOT(handleCloseBtn()));
    close_btn->installEventFilter(this);

    header_layout->addWidget(header_title, Qt::AlignLeft);
    header_layout->addStretch(5);
    header_layout->addWidget(close_btn, Qt::AlignRight);
    header_widget->setLayout(header_layout);
//    header_layout->addWidget(header_widget);
}

void Model::paintEvent(QPaintEvent *event) {
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

bool Model::eventFilter(QObject *obj, QEvent *event) {
    QEvent::Type type = event->type();
    if(type == QEvent::Enter){
        this->close_btn->setIcon(QIcon(":/resource/close_hover.png"));
        return true;
    }
    if(type == QEvent::Leave){
        this->close_btn->setIcon(QIcon(":/resource/close.png"));
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void Model::handleCloseBtn() {
    this->hide();
}