#pragma once

#include <QWidget>

class SelectModeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectModeWidget(QWidget* parent = nullptr);

signals:
    void modeSelected(int size);
};
