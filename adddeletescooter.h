#ifndef ADDDELETESCOOTER_H
#define ADDDELETESCOOTER_H

#include <QDialog>

namespace Ui {
class addDeleteScooter;
}

class addDeleteScooter : public QDialog
{
    Q_OBJECT

public:
    explicit addDeleteScooter(QWidget *parent = nullptr);
    ~addDeleteScooter();

private:
    Ui::addDeleteScooter *ui;
};

#endif // ADDDELETESCOOTER_H

