#include "MainWindow.h"
#include "CentralWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new CentralWidget(this));
    resize(600, 400);
}
