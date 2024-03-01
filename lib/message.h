#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressBar>
#include <QTimer>
#include <QFileInfo>
#include <QLabel>
class Message : public QWidget {
Q_OBJECT;

public:
    Message(QWidget *parent = nullptr);
    ~Message();
private:
    QHBoxLayout *layout_msg;
    QWidget *msg_widget;
    QTimer *timer;
    QLabel *msg_label;
};

#endif // MESSAGE_H
