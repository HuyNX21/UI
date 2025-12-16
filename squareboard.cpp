#include "squareboard.h"

#include <QGridLayout>
#include <QPushButton>
#include <QResizeEvent>
#include <QtMath>

SquareBoard::SquareBoard(QWidget* parent)
    : QWidget(parent)
{
    auto* grid = new QGridLayout(this);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 4; ++i)
    {
        auto* btn = new QPushButton(QString::number(i + 1), this);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        grid->addWidget(btn, i / 2, i % 2);
    }

    const int minBoardSize = MinButtonSize * 2;
    setMinimumSize(minBoardSize, minBoardSize);
}

void SquareBoard::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int side = qMin(width(), height());
    side = qMax(side, MinButtonSize * 2);

    resize(side, side);
}
