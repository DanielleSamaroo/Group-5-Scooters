#ifndef SCOOTERREQUESTS_H
#define SCOOTERREQUESTS_H

#include <QDialog>

namespace Ui {
class scooterRequests;
}

class scooterRequests : public QDialog
{
    Q_OBJECT

public:
    explicit scooterRequests(QWidget *parent = nullptr);
    ~scooterRequests();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_2_accepted();

    void on_buttonBox_rejected();

    void on_buttonBox_2_rejected();

    void on_toolButton_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

private:
    Ui::scooterRequests *ui;
};

#endif // SCOOTERREQUESTS_H
