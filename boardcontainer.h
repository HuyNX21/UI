#ifndef BOARDCONTAINER_H
#define BOARDCONTAINER_H

#include <QWidget>

class BoardContainer : public QWidget
{
    Q_OBJECT
public:
    explicit BoardContainer(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QWidget* m_board;
    const int minCell = 75;
};


#endif // BOARDCONTAINER_H
