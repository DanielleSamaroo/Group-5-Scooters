#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Group5ScootersProject.h"

class Group5ScootersProject : public QMainWindow
{
    Q_OBJECT

public:
    Group5ScootersProject(QWidget *parent = nullptr);
    ~Group5ScootersProject();

private:
    Ui::Group5ScootersProjectClass ui;
};
