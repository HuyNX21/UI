#pragma once

#include <QWidget>

class QGridLayout;

class SquareBoard : public QWidget
{
    Q_OBJECT

public:
    explicit SquareBoard(QWidget* parent = nullptr);

    void setBoardSize(int size);

    bool hasHeightForWidth() const override;
    int  heightForWidth(int w) const override;

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void rebuildBoard();

private:
    QGridLayout* m_grid = nullptr;
    int m_boardSize = 0;
};
