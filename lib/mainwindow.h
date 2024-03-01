#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./message.h"
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressBar>
#include <QTimer>
#include <QFileInfo>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:

    void customClick();

    void inpChange();

    void onTimeOut();

    void onMsgTimeOut();

private:
    QLineEdit *lineEdit;
    QHBoxLayout *layout;
    QHBoxLayout *layouts;
    QHBoxLayout *layout_msg;
    QVBoxLayout *vlayout;
    QWidget *inp_widget;
    QWidget *bar_widget;
    QWidget *main_widget;
    QWidget *msg_widget;
    QPushButton *btn;
    QMessageBox *msg;
    QTimer *timer;
    QProgressBar *progressBar;
    QLabel *msg_label;
    Message *message;
};

#endif // MAINWINDOW_H
