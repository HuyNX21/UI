#include "CentralWidget.h"
#include "SquareBoard.h"
#include <QResizeEvent>
#include <QDebug>

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent)
{
    m_board = new SquareBoard(this);

    const int minButtonSize = 160;
    const int minBoardSize  = minButtonSize * 2;

    // CỰC KỲ QUAN TRỌNG
    setMinimumSize(minBoardSize, minBoardSize);
}


void CentralWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int side = qMin(width(), height());
    qDebug() << "side qmin : " << side;
    int minBoardSize = 160 * 2;

    side = qMax(side, minBoardSize);
    qDebug() << "side qMax : " << side;

    int x = (width()  - side) / 2;
    int y = (height() - side) / 2;

    qDebug() << "x : " << x << "-" << "y : " << y;

    m_board->setGeometry(x, y, side, side);
}
