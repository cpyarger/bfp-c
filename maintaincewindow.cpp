#include "maintaincewindow.h"
#include "ui_maintaincewindow.h"

MaintainceWindow::MaintainceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaintainceWindow)
{
    ui->setupUi(this);
}

MaintainceWindow::~MaintainceWindow()
{
    delete ui;
}
