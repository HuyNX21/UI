#ifndef MAINSELLECTMODE_H
#define MAINSELLECTMODE_H

#include <QWidget>

class BoardSellect;

class MainSellectMode : public QWidget
{
    Q_OBJECT
public:
    explicit MainSellectMode(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    BoardSellect* m_board;
    const int m_minButtonSize = 80;
};

#endif // MAINSELLECTMODE_H
