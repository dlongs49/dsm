#ifndef MODEL_H
#define MODEL_H
#include <qpainter.h>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QVBoxLayout>
class Model : public QWidget {
Q_OBJECT
public:
    Model(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QGraphicsDropShadowEffect *shadow;
signals:

};

#endif // MODEL_H
