#ifndef MAINTAINCEWINDOW_H
#define MAINTAINCEWINDOW_H

#include <QDialog>

namespace Ui {
class MaintainceWindow;
}

class MaintainceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MaintainceWindow(QWidget *parent = nullptr);
    ~MaintainceWindow();

private:
    Ui::MaintainceWindow *ui;
};

#endif // MAINTAINCEWINDOW_H
