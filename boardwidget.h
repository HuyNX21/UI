#pragma once

#include <QWidget>
#include "selectmodewidget.h"

class CentralWidget;

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BoardWidget(QWidget* parent = nullptr);

    void setBoardSize(int size);
protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    CentralWidget* m_central = nullptr;
    const int m_minButtonSize = 80;
    SelectModeWidget* m_board;

signals:
    void backRequested();
};
