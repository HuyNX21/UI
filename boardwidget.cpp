#include "BoardWidget.h"
#include "CentralWidget.h"

#include <QVBoxLayout>

BoardWidget::BoardWidget(QWidget* parent)
    : QWidget(parent)
{
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
