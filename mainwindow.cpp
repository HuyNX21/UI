#include "mainwindow.h"
#include "centralwidget.h"
#include "mainsellectmode.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    //m_centralWidget = new CentralWidget(this);
    //setCentralWidget(m_centralWidget);
    setCentralWidget(new MainSellectMode(this));
    resize(600, 400);
}
