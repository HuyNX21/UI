#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <vector>

class SquareBoard : public QWidget
{
    Q_OBJECT

public:
    explicit SquareBoard(QWidget* parent = nullptr);

    void setBoardSize(int size); // 8, 16, 32

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void rebuildBoard();

private:
    QGridLayout* m_grid = nullptr;
    int m_boardSize = 2; // default 2x2 (hoặc bạn có thể set 8)
};
