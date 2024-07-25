#ifndef RENTSCOOTER_H
#define RENTSCOOTER_H

#include <QDialog>
#include <mainwindow.h>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class rentScooter;
}

class rentScooter : public QDialog
{
    Q_OBJECT

public:
    explicit rentScooter(QWidget *parent = nullptr);
    ~rentScooter();

private slots:

    void on_toolButton_clicked();

    void on_comboBox_activated(int index);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void updateUnits(int numRows);

private:
    Ui::rentScooter *ui;
    MainWindow *mainWindow;
    QList<QVariantMap> scooters; // Create a list to hold the scooter records
};

#endif // RENTSCOOTER_H
