#pragma once

#include <QWidget>

class SquareBoard : public QWidget
{
    Q_OBJECT
public:
    explicit SquareBoard(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    static constexpr int MinButtonSize = 160;
};
