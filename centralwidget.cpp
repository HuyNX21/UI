#include "centralwidget.h"
#include "squareboard.h"

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
    auto* board = new SquareBoard(this);
    board->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // ===== Right: Side panel =====
    auto* sidePanel = new QWidget(this);
    sidePanel->setFixedWidth(200);

    auto* sideLayout = new QVBoxLayout(sidePanel);
    sideLayout->setContentsMargins(0, 0, 0, 0);
    sideLayout->setSpacing(8);

    // 🔴 QUAN TRỌNG: đẩy khoảng trống lên TRÊN
    sideLayout->addStretch();

    QPushButton* b1 = new QPushButton("Button 1", sidePanel);
    QPushButton* b2 = new QPushButton("Button 2", sidePanel);
    QPushButton* b3 = new QPushButton("Button 3", sidePanel);

    for (auto* b : {b1, b2, b3})
    {
        b->setMinimumSize(sizeButton, sizeButton);
        b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sideLayout->addWidget(b);
    }

    // ===== Assemble =====
    mainLayout->addWidget(board, 1);
    mainLayout->addWidget(sidePanel);
}
