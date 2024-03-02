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
    QIcon *close_icon;
signals:

};

#endif // MODEL_H
