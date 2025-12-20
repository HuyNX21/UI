#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStackedWidget;
class MainSellectMode;
class CentralWidget;   // hoặc CentralWidget nếu bạn dùng trực tiếp

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    QStackedWidget*   m_stack        = nullptr;
    MainSellectMode* m_selectScreen = nullptr;
    CentralWidget*     m_boardScreen  = nullptr;
};

#endif // MAINWINDOW_H
