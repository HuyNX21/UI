#include "SelectModeWidget.h"

#include <QVBoxLayout>
#include <QPushButton>

SelectModeWidget::SelectModeWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);

    QPushButton* b8  = new QPushButton("8 x 8",  this);
    QPushButton* b16 = new QPushButton("16 x 16", this);
    QPushButton* b32 = new QPushButton("32 x 32", this);
    QPushButton* bQ  = new QPushButton("?",       this);

    for (auto* b : {b8, b16, b32, bQ})
    {
        b->setMinimumHeight(50);
        b->setMinimumWidth(20);
        layout->addWidget(b);
    }

    layout->addStretch();

    connect(b8,  &QPushButton::clicked, this, [this]() { emit modeSelected(8);  });
    connect(b16, &QPushButton::clicked, this, [this]() { emit modeSelected(16); });
    connect(b32, &QPushButton::clicked, this, [this]() { emit modeSelected(32); });

    // button "?" chưa implement → không connect
}
