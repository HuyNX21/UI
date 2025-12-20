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

    QPushButton* b8  = new QPushButton("8 x 8", sidePanel);
    QPushButton* b16 = new QPushButton("16 x 16", sidePanel);
    QPushButton* b32 = new QPushButton("32 x 32", sidePanel);

    for (auto* b : {b8, b16, b32})
    {
        b->setMinimumSize(sizeButton, sizeButton);
        b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sideLayout->addWidget(b);
    }

    connect(b8,  &QPushButton::clicked, this, [this]() {
        m_board->setBoardSize(8);
    });
    connect(b16, &QPushButton::clicked, this, [this]() {
        m_board->setBoardSize(16);
    });
    connect(b32, &QPushButton::clicked, this, [this]() {
        m_board->setBoardSize(32);
    });

    // ===== Assemble =====
    mainLayout->addWidget(m_board, 1);
    mainLayout->addWidget(sidePanel);
}
