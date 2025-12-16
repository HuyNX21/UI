#include "mainwindow.h"
#include "centralwidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_centralWidget = new CentralWidget(this);
    setCentralWidget(m_centralWidget);
}
