#include "mainsellectmode.h"
#include "boardsellect.h"

#include <QResizeEvent>
#include <QDebug>

MainSellectMode::MainSellectMode(QWidget* parent)
    : QWidget(parent)
{
    m_board = new BoardSellect(this);

    const int minButtonSize = 160;
    const int minBoardSize  = minButtonSize * 2;

    setMinimumSize(minBoardSize, minBoardSize);

    // ⭐ FORWARD SIGNAL
    connect(m_board, &BoardSellect::modeSelected,
            this,    &MainSellectMode::modeSelected);
}

void MainSellectMode::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int side = qMin(width(), height());
    int minBoardSize = 160 * 2;
    side = qMax(side, minBoardSize);

    int x = (width()  - side) / 2;
    int y = (height() - side) / 2;

    m_board->setGeometry(x, y, side, side);
}
