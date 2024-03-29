#include "model.h"

Model::Model(QWidget *parent) : QWidget(parent) {
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    int width = 300;
    int height = 150;
    this->resize(width+10, height+10);




    // 头部标题+关闭
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
    header_title->setStyleSheet("margin-left:20px;font-size:16px");

    close_btn = new QPushButton();
    close_btn = new QPushButton();
    close_btn->setIcon(QIcon(":/resource/close.png"));
    close_btn->setIconSize(QSize(12, 12));
    close_btn->setFixedSize(40, 20);
    close_btn->setObjectName("close_btn");
    close_btn->setCursor(Qt::PointingHandCursor);
    close_btn->installEventFilter(this);
    connect(close_btn, SIGNAL(clicked()), this, SLOT(handleClose()));

    header_layout->addWidget(header_title, Qt::AlignLeft);
    header_layout->addStretch(5);
    header_layout->addWidget(close_btn, Qt::AlignRight);
    header_widget->setLayout(header_layout);

    // 提示文字区域
    con_layout = new QHBoxLayout();
    tip = new QLabel();
    tip->setFixedSize(50, 30);
    tip->setStyleSheet("margin-left:20px;");
    tip->setScaledContents(true);
    pixmap = new QPixmap(":/resource/tip.png");
    tip->setPixmap(*pixmap);

    text = new QLabel();
    text->setText("此操作不可逆,确定此操作吗?");
    text->setStyleSheet("font-size:14px;margin-left:5px;");

    con_layout->setMargin(0);
    con_layout->setSpacing(0);
    con_layout->addWidget(tip);
    con_layout->addWidget(text);
    con_widget = new QWidget(this);
    con_widget->setFixedWidth(width);
    con_widget->setFixedHeight(50);
    con_widget->setLayout(con_layout);

    // 按钮区域
    opear_layout = new QHBoxLayout();
    opear_layout->setMargin(0);
    opear_layout->setSpacing(0);
    opear_layout->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    on_btn = new QPushButton();
    on_btn->setText("确定");
    on_btn->setObjectName("on_btn");
    on_btn->setCursor(Qt::PointingHandCursor);
    on_btn->setFixedSize(80, 30);
    connect(on_btn, SIGNAL(clicked()), this, SLOT(handleOn()));
    cancle_btn = new QPushButton();
    cancle_btn->setText("取消");
    cancle_btn->setCursor(Qt::PointingHandCursor);
    cancle_btn->setFixedSize(80, 30);
    cancle_btn->setObjectName("cancle_btn");
    connect(cancle_btn, SIGNAL(clicked()), this, SLOT(handleClose()));
    opear_layout->addWidget(on_btn);
    opear_layout->addSpacing(10);
    opear_layout->addWidget(cancle_btn);
    opear_layout->addSpacing(15);
    opear_widget = new QWidget(this);
    opear_widget->setContentsMargins(0, 0, 0, 10);
    opear_widget->setLayout(opear_layout);
    opear_widget->setFixedWidth(width);
    opear_widget->setFixedHeight(50);

    model_layout = new QVBoxLayout();
    model_layout->setMargin(0);
    model_layout->setSpacing(0);
    model_layout->addWidget(header_widget);
    model_layout->addWidget(con_widget);
    model_layout->addWidget(opear_widget);

    frame = new QFrame(this);
    frame->setFixedSize(width, height);
    frame->setStyleSheet("QFrame{background:#fff;border-radius:10px;}");
    frame->setGeometry(5, 5, this->width() - 5, this->height() - 5);
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(1, 0);
    shadow->setColor(QColor("#ccc"));
    shadow->setBlurRadius(10);
    frame->setGraphicsEffect(shadow);
    frame->setLayout(model_layout);
}
/*
 * QWidget 设置圆角作废 使用 QFrame 替代
void Model::paintEvent(QPaintEvent *event) {
    painter = new QPainter(this);
    painter->setRenderHint(painter->Antialiasing);
    painter->setBrush(QBrush("#ffffff"));
    painter->setPen(Qt::transparent);

    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter->drawRoundedRect(rect, 10, 10);
    QWidget::paintEvent(event);
    painter->fillRect(this->rect().adjusted(10, 10, -4, -4), "#ffffff");
    painter->end();
}
*/
// 事件过滤器 监听鼠标移出移出  【鼠标移入关闭按钮切换图标】
bool Model::eventFilter(QObject *obj, QEvent *event) {
    QEvent::Type type = event->type();
    if (type == QEvent::Enter) {
        this->close_btn->setIcon(QIcon(":/resource/close_hover.png"));
        return true;
    }
    if (type == QEvent::Leave) {
        this->close_btn->setIcon(QIcon(":/resource/close.png"));
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

// 向父窗口传递信息，使父窗口监听到 Model 确认事件
void Model::handleOn() {
    emit emitOn();
}

void Model::handleClose() {
    this->hide();
}

// 窗口拖拽移动 鼠标按下事件
void Model::mousePressEvent(QMouseEvent *event) {
    // 判断按下是鼠标左键
    if (event->button() == Qt::LeftButton) {
        // 相对 Model 坐标
        start_point = event->globalPos();
        // 起始坐标 相对屏幕
        init_point = this->frameGeometry().topLeft();
    }
}

// 窗口拖拽移动 鼠标移动事件
void Model::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        QPoint move_point = event->globalPos() - start_point;
        this->move(init_point + move_point);
    }
}

// 窗口拖拽移动 鼠标松开事件
void Model::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "松开" << event;
}