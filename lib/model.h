#ifndef MODEL_H
#define MODEL_H

#include <qpainter.h>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QIcon>
#include <QDebug>
#include <QEvent>
#include <QRect>
#include <QPoint>
#include <QMouseEvent>
#include <QFrame>
class Model : public QWidget {
Q_OBJECT
public:
    Model(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    bool eventFilter(QObject *obj, QEvent *event);
public slots:
    void handleClose();
    void handleOn();
private:
    QGraphicsDropShadowEffect *shadow;
    QHBoxLayout *header_layout;
    QHBoxLayout *con_layout;
    QHBoxLayout *opear_layout;
    QVBoxLayout *model_layout;
    QWidget *header_widget;
    QWidget *opear_widget;
    QWidget *con_widget;
    QLabel *header_title;
    QLabel *tip;
    QLabel *text;
    QPushButton *close_btn;
    QPushButton *on_btn;
    QPushButton *cancle_btn;
    QPixmap *pixmap;
    QPainter *painter;
    QFrame *frame;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    QPoint start_point;
    QPoint init_point;
signals:
    void emitOn();
};

#endif // MODEL_H
