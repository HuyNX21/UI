#pragma once

#include <QWidget>

class SquareBoard;

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget* parent = nullptr);
    void setBoardSize(int size);

private:
    SquareBoard* m_board = nullptr;

signals:
    void backRequested();
};
