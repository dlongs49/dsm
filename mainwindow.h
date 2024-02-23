#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void customClick();
    void inpChange();
private:
    QLineEdit *lineEdit;
    QHBoxLayout *layout;
    QWidget *widget;
    QPushButton *btn;
    QMessageBox *msg;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
