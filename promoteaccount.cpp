#include "promoteaccount.h"
#include "ui_promoteaccount.h"
#include "accountmanagement.h"
#include "employee_manager.h"
#include "changedata.h"
#include "deleteuser.h"


promoteaccount::promoteaccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::promoteaccount)
{
    ui->setupUi(this);

    ui->buttonBox->hide();

    // Set image and window style and buttons

    QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label_5->setPixmap(image);
    ui->comboBox->hide();

    ui->toolButton_2->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                  "}" "QToolButton:hover {" "background-color: orange;""}");

    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;" "}");

    ui->buttonBox->setStyleSheet("QPushButton{" "color: white;" "background-color: grey;"
                                 "}" "QPushButton:hover {" "background-color: orange;""}");
}


promoteaccount::~promoteaccount()
{
    delete ui;
}

// When click Accept, promoteAccount function works with the UI
void promoteaccount::on_buttonBox_accepted()
{
    ui->buttonBox->hide();

    accountmanagement acc;
    QString username = ui->lineEdit->text();
    QString newStatus = ui->lineEdit_2->text();

    if(username.isEmpty() || newStatus.isEmpty() )
    {
        ui->label_3->setText("Please fill in all fields.");
    }

    else
    {
        if(acc.promoteAccount(username, newStatus))
        {
            ui->label_3->setText("Account Updated.");
        }

        else
        {
            ui->label_3->setText("Failed Promotion, username does not exist.");
        }
    }

}

// When Cancel button is pressed
void promoteaccount::on_buttonBox_rejected()
{
    ui->buttonBox->hide();
}

// When write in line edit, accept and cancel button shows up
void promoteaccount::on_lineEdit_editingFinished()
{
    ui->buttonBox->show();
}


// When Menu button is pressed
void promoteaccount::on_toolButton_2_clicked()
{
    ui->comboBox->show();
}

// Change windows from menu bar
void promoteaccount::on_comboBox_currentIndexChanged(int index)
{
    accountmanagement acc;
    employee_manager em;
    changeData data;
    promoteaccount prom;
    deleteUser user;


    switch(index)
    {
    case 1: // Account management window opens
        this->close();
        em.close();
        prom.close();
        data.close();
        acc.setModal(true);
        acc.exec();
        break;

    case 2: // Delete account window opens
        this->close();
        acc.close();
        em.close();
        data.close();
        user.setModal(true);
        user.exec();
        break;

    case 3: // Change account data window opens
        this->close();
        prom.close();
        acc.close();
        em.close();
        data.setModal(true);
        data.exec();
        break;
    }
}
