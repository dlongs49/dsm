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
class Toast : public QLabel  {
Q_OBJECT;

public:
    Toast(QWidget  *parent = nullptr);
    ~Toast();
public slots:
    void showToast(QString msg = " ");
    void onMsgTimeOut();
private:
    QHBoxLayout *layout;
    QWidget *widget;
    QTimer *timer;
    QLabel *label;
};

#endif // MESSAGE_H
