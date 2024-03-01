#include "lib/mainwindow.h"

#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("PingFang SC",10);
    a.setFont(f);
    QFile  qss(":/resource/style.css");
    if(qss.open(QFile::ReadOnly)){
        a.setStyleSheet(qss.readAll());
    }
    qss.close();
    MainWindow w;
    w.setWindowFlags(w.windowFlags() &~ Qt::WindowMaximizeButtonHint);
    w.setFixedSize(400, 300);
    w.show();
    return a.exec();
}
