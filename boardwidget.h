#pragma once

#include <QWidget>

class CentralWidget;

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BoardWidget(QWidget* parent = nullptr);

    void setBoardSize(int size);

private:
    CentralWidget* m_central = nullptr;

signals:
    void backRequested();
};
