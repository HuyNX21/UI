#include "MainWindow.h"
#include "SelectModeWidget.h"
#include "BoardWidget.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_stack = new QStackedWidget(this);
    setCentralWidget(m_stack);

    m_selectScreen = new SelectModeWidget(this);
    m_boardScreen  = new BoardWidget(this);

    m_stack->addWidget(m_selectScreen); // index 0
    m_stack->addWidget(m_boardScreen);  // index 1

    m_stack->setCurrentIndex(0);

    connect(m_selectScreen, &SelectModeWidget::modeSelected,
            this, [this](int size)
            {
                m_boardScreen->setBoardSize(size);
                m_stack->setCurrentIndex(1);
            });

    connect(m_boardScreen, &BoardWidget::backRequested,
            this, [this]()
            {
                m_stack->setCurrentIndex(0);
            });
}
