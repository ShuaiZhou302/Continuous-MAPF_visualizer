#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Settings *settings;
    settings = new Settings(&w);
    QMainWindow::connect(settings, SIGNAL(sendData(QString, int)), &w, SLOT(setLogFile(QString, int)));
    QMainWindow::connect(&w, SIGNAL(openSettings()), settings, SLOT(openSettings()));
//    w.show();
    settings->show();
    return a.exec();
}
