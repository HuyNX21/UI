#include "CentralWidget.h"
#include "SquareBoard.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent)
{
    const int sizeButton = 75;

    auto* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(8, 8, 8, 8);
    mainLayout->setSpacing(8);

    // ===== Left: Board =====
    m_board = new SquareBoard(this);
    m_board->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // ===== Right: Side panel =====
    auto* sidePanel = new QWidget(this);
    sidePanel->setFixedWidth(200);

    auto* sideLayout = new QVBoxLayout(sidePanel);
    sideLayout->setContentsMargins(0, 0, 0, 0);
    sideLayout->setSpacing(8);

    sideLayout->addStretch();

    QPushButton* b1  = new QPushButton("x", sidePanel);
    QPushButton* back = new QPushButton("Back", sidePanel);
    QPushButton* b3 = new QPushButton("x", sidePanel);

    for (auto* b : {b1, back, b3})
    {
        b->setMinimumSize(sizeButton, sizeButton);
        b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sideLayout->addWidget(b);
    }

    connect(back, &QPushButton::clicked,
            this, &CentralWidget::backRequested);

    // ===== Assemble =====
    mainLayout->addWidget(m_board, 1);
    mainLayout->addWidget(sidePanel);
}

void CentralWidget::setBoardSize(int size)
{
    m_board->setBoardSize(size);
}
