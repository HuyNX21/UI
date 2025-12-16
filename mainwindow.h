#pragma once

#include <QMainWindow>

class CentralWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    CentralWidget* m_centralWidget;
};
