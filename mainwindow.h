#pragma once

#include <QMainWindow>

class QStackedWidget;
class SelectModeWidget;
class BoardWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    QStackedWidget*   m_stack = nullptr;
    SelectModeWidget* m_selectScreen = nullptr;
    BoardWidget*      m_boardScreen  = nullptr;
};
