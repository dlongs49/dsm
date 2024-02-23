#include "mainwindow.h"

#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("微软雅黑",10);
    a.setFont(f);
    QFile  qss(":/style.css");
    if(qss.open(QFile::ReadOnly)){
        a.setStyleSheet(qss.readAll());
    }
    qss.close();
    MainWindow w;
    w.show();
    return a.exec();
}
