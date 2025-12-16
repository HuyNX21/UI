#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

class SquareBoard;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    SquareBoard* m_board;
    const int m_minButtonSize = 80;
};

#endif
