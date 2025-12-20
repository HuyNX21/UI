#include "SelectModeWidget.h"

#include <QVBoxLayout>
#include <QPushButton>

SelectModeWidget::SelectModeWidget(QWidget* parent)
    : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout(this);
    grid->setSpacing(5);
    grid->setContentsMargins(0, 0, 0, 0);

    QPushButton* btn1 = new QPushButton(tr("8x8"), this);
    QPushButton* btn2 = new QPushButton(tr("16x16"), this);
    QPushButton* btn3 = new QPushButton(tr("30x16"), this);
    QPushButton* btn4 = new QPushButton(tr("?"), this);

    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    grid->addWidget(btn1, 0, 0);
    grid->addWidget(btn2, 0, 1);
    grid->addWidget(btn3, 1, 0);
    grid->addWidget(btn4, 1, 1);

    grid->setRowStretch(0, 1);
    grid->setRowStretch(1, 1);
    grid->setColumnStretch(0, 1);
    grid->setColumnStretch(1, 1);

    connect(btn1,  &QPushButton::clicked, this, [this]() { emit modeSelected(8);  });
    connect(btn2,  &QPushButton::clicked, this, [this]() { emit modeSelected(16); });
    connect(btn3,  &QPushButton::clicked, this, [this]() { emit modeSelected(32); });
}
