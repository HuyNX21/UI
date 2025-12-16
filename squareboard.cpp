#include "SquareBoard.h"
#include <QGridLayout>
#include <QPushButton>

SquareBoard::SquareBoard(QWidget* parent)
    : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout(this);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 4; ++i)
    {
        QPushButton* btn = new QPushButton(QString::number(i + 1), this);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        grid->addWidget(btn, i / 2, i % 2);
    }

    grid->setRowStretch(0, 1);
    grid->setRowStretch(1, 1);
    grid->setColumnStretch(0, 1);
    grid->setColumnStretch(1, 1);
}
