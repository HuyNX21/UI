#include "SquareBoard.h"

#include <QGridLayout>
#include <QPushButton>
#include <QResizeEvent>
#include <QtMath>

static constexpr int MinButtonSize = 40;

SquareBoard::SquareBoard(QWidget* parent)
    : QWidget(parent)
{
    m_grid = new QGridLayout(this);
    m_grid->setSpacing(0);
    m_grid->setContentsMargins(0, 0, 0, 0);

    setBoardSize(8);
}

void SquareBoard::setBoardSize(int size)
{
    if (size <= 0 || size == m_boardSize)
        return;

    m_boardSize = size;
    rebuildBoard();

    const int minSide = MinButtonSize * m_boardSize;
    setMinimumSize(minSide, minSide);

    updateGeometry();
}

void SquareBoard::rebuildBoard()
{
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

            btn->setSizePolicy(QSizePolicy::Ignored,
                               QSizePolicy::Ignored);

            m_grid->addWidget(btn, r, c);
        }
    }
}

// ===== Qt layout contract =====

bool SquareBoard::hasHeightForWidth() const
{
    return true;
}

int SquareBoard::heightForWidth(int w) const
{
    const int minSide = MinButtonSize * m_boardSize;
    return qMax(w, minSide);
}

QSize SquareBoard::sizeHint() const
{
    const int side = MinButtonSize * m_boardSize;
    return QSize(side, side);
}

QSize SquareBoard::minimumSizeHint() const
{
    const int side = MinButtonSize * m_boardSize;
    return QSize(side, side);
}

void SquareBoard::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
}
