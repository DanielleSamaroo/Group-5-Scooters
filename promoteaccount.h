#ifndef PROMOTEACCOUNT_H
#define PROMOTEACCOUNT_H

#include <QDialog>
#include <QtSql>
#include <QDebug>

namespace Ui {
class promoteaccount;
}

class promoteaccount : public QDialog
{
    Q_OBJECT

public:
    explicit promoteaccount(QWidget *parent = nullptr);
    ~promoteaccount();


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_lineEdit_editingFinished();

    void on_toolButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::promoteaccount *ui;
};

#endif // PROMOTEACCOUNT_H
