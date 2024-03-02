#ifndef MODEL_H
#define MODEL_H

#include <qpainter.h>
#include <QWidget>
#include <QtSvg/QSvgRenderer>
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
class Model : public QWidget {
Q_OBJECT
public:
    Model(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void handleCloseBtn();
private:
    QGraphicsDropShadowEffect *shadow;
    QHBoxLayout *header_layout;
    QWidget *header_widget;
    QLabel *header_title;
    QSvgRenderer *renderer;
    QPushButton *close_btn;
    QPushButton *on_btn;
    QPushButton *cancle_btn;
    QPixmap *pixmap;
    QPainter *painter;
    QIcon *close_icon;
signals:

};

#endif // MODEL_H
