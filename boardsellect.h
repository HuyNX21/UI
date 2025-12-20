#ifndef BOARDSELLECT_H
#define BOARDSELLECT_H

#include <QWidget>

class BoardSellect : public QWidget
{
    Q_OBJECT
public:
    explicit BoardSellect(QWidget* parent = nullptr);

signals:
    void modeSelected(int size);   // ⭐ NEW
};

#endif // BOARDSELLECT_H
