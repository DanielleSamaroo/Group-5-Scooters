#include "changedata.h"
#include "ui_changedata.h"
#include "accountmanagement.h"
#include "promoteaccount.h"
#include "deleteuser.h"
#include "employee_manager.h"

changeData::changeData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changeData)
{
    ui->setupUi(this);

    // Set image for window
    QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label_6->setPixmap(image);

    // Set style of window and buttons
    ui->comboBox->hide();

    ui->comboBox->hide();
    ui->buttonBox->hide();


    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;" "}");

    ui->buttonBox->setStyleSheet("QPushButton{" "color: white;" "background-color: grey;"
                                 "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->toolButton_2->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                    "}" "QToolButton:hover {" "background-color: orange;""}");
}

changeData::~changeData()
{
    delete ui;
}

// Function to set the UI with the changeUserPass function
void changeData::on_buttonBox_accepted()
{
    ui->buttonBox->hide();
    accountmanagement acc;
    QString currentUsername = ui->lineEdit->text();
    QString newUsername = ui->lineEdit_2->text();
    QString newPass = ui->lineEdit_3->text();

    if(currentUsername.isEmpty() || newUsername.isEmpty() || newPass.isEmpty())
    {
        ui->label_4->setText("Missing Fields.");
    }

    else
    {
        if(acc.changeUserPass(currentUsername, newUsername, newPass))
        {
            ui->label_4->setText("Username changed.");
        }

        else
        {
            ui->label_4->setText("Username change failed, username does not exist.");
        }
    }

}

// When menu button is clicked
void changeData::on_toolButton_2_clicked()
{
    ui->comboBox->show();
}

// When changin windows from menu bar
void changeData::on_comboBox_currentIndexChanged(int index)
{
    accountmanagement acc;
    promoteaccount prom;
    employee_manager em;
    deleteUser user;
    switch(index)
    {
    case 1: // Open account management window
        this->close();
        prom.close();
        user.close();
        em.close();
        acc.setModal(true);
        acc.exec();

        break;

    case 3: // Open promote/demote account
        this->close();
        acc.close();
        em.close();
        user.close();
        prom.setModal(true);
        prom.exec();
        break;

    case 2: // Open delete account window
        this->close();
        prom.close();
        acc.close();
        em.close();
        user.setModal(true);
        user.exec();
        break;
    }

}

// When finish writing in line edit, button box shows up
void changeData::on_lineEdit_editingFinished()
{
    ui->buttonBox->show();
}

// When cancel button is pressed, button box hide
void changeData::on_buttonBox_rejected()
{
    ui->buttonBox->hide();
}
