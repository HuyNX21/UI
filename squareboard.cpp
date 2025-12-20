#include "SquareBoard.h"
#include <QResizeEvent>
#include <QtMath>

static constexpr int MinButtonSize = 40;

SquareBoard::SquareBoard(QWidget* parent)
    : QWidget(parent)
{
    m_grid = new QGridLayout(this);
    m_grid->setSpacing(0);
    m_grid->setContentsMargins(0, 0, 0, 0);

    setBoardSize(8); // mode mặc định
}

void SquareBoard::setBoardSize(int size)
{
    if (size <= 0 || size == m_boardSize)
        return;

    m_boardSize = size;
    rebuildBoard();

    const int minBoardSize = MinButtonSize * m_boardSize;
    setMinimumSize(minBoardSize, minBoardSize);

    updateGeometry();
}

void SquareBoard::rebuildBoard()
{
    // Clear old widgets
    while (QLayoutItem* item = m_grid->takeAt(0))
    {
        delete item->widget();
        delete item;
    }

    for (int r = 0; r < m_boardSize; ++r)
    {
        for (int c = 0; c < m_boardSize; ++c)
        {
            auto* btn = new QPushButton(this);
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            btn->setText(QString("%1,%2").arg(r).arg(c));
            m_grid->addWidget(btn, r, c);
        }
    }
}

void SquareBoard::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int side = qMin(width(), height());
    side = qMax(side, MinButtonSize * m_boardSize);

    resize(side, side);
}
