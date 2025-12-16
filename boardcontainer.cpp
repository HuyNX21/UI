#include "boardcontainer.h"
#include "squareboard.h"

BoardContainer::BoardContainer(QWidget* parent)
    : QWidget(parent)
{
    m_board = new SquareBoard(this);

    const int minBoardSize = minCell * 2;
    setMinimumSize(minBoardSize, minBoardSize);
}

void BoardContainer::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int side = qMin(width(), height());
    side = qMax(side, minCell * 2);

    int x = (width()  - side) / 2;
    int y = (height() - side) / 2;

    m_board->setGeometry(x, y, side, side);
}

