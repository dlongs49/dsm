#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "toast.h"
#include "model.h"
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

private:
    QLineEdit *lineEdit;
    QHBoxLayout *layout;
    QHBoxLayout *layouts;
    QVBoxLayout *vlayout;
    QWidget *inp_widget;
    QWidget *bar_widget;
    QWidget *main_widget;
    QPushButton *btn;
    QTimer *timer;
    QProgressBar *progressBar;
    Toast *toast;
    Model *model;
};

#endif // MAINWINDOW_H
