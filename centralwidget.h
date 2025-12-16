#pragma once

#include <QWidget>

class BoardContainer;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget* parent = nullptr);
};
