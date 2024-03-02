#ifndef MODEL_H
#define MODEL_H
#include <qpainter.h>
#include <QWidget>
#include <QtSvg/QSvgRenderer>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
class Model : public QWidget {
Q_OBJECT
public:
    Model(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QGraphicsDropShadowEffect *shadow;
    QHBoxLayout *header_layout;
    QWidget *header_widget;
    QLabel *header_title;
    QSvgRenderer *render;
signals:

};

#endif // MODEL_H
