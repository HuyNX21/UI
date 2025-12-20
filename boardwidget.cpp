#include "BoardWidget.h"
#include "CentralWidget.h"

#include <QVBoxLayout>

BoardWidget::BoardWidget(QWidget* parent)
    : QWidget(parent)
{
    m_board = new SelectModeWidget(this);
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    m_central = new CentralWidget(this);
    layout->addWidget(m_central);

    connect(m_central, &CentralWidget::backRequested,
            this,       &BoardWidget::backRequested);
}

void BoardWidget::setBoardSize(int size)
{
    m_central->setBoardSize(size);
}

void BoardWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int side = qMin(width(), height());
    int minBoardSize = 160 * 2;

    side = qMax(side, minBoardSize);

    int x = (width()  - side) / 2;
    int y = (height() - side) / 2;


    m_board->setGeometry(x, y, side, side);
}
