#include "deleteuser.h"
#include "ui_deleteuser.h"
#include "accountmanagement.h"
#include "promoteaccount.h"
#include "changedata.h"


deleteUser::deleteUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteUser)
{
    ui->setupUi(this);

    // Set image
    QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label_6->setPixmap(image);

    // Set window style and buttons
    ui->comboBox->hide();

    ui->comboBox->hide();

    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;" "}");

    ui->buttonBox->setStyleSheet("QPushButton{" "color: white;" "background-color: grey;"
                                 "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->toolButton_2->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                    "}" "QToolButton:hover {" "background-color: orange;""}");
}

deleteUser::~deleteUser()
{
    delete ui;
}

// When Accept button is pressed, function delete account occurs, connected with the UI
void deleteUser::on_buttonBox_accepted()
{
    accountmanagement acc;
    QString username = ui->lineEdit->text();

    if(username.isEmpty())
    {
        ui->label_2->setText("Missing Fields.");
    }

    else
    {
        if(acc.deleteAccount(username))
        {
            ui->label_2->setText("Account deleted successfully.");
        }

        else
        {
            ui->label_2->setText("Account delete failed, username does not exist.");
        }
    }
}

// Change windows from the menu bar
void deleteUser::on_comboBox_currentIndexChanged(int index)
{
    accountmanagement acc;
    promoteaccount prom;
    changeData data;

    switch(index)
    {
    case 1: // Open account management window
        this->close();
        prom.close();
        data.close();
        acc.setModal(true);
        acc.exec();
        break;

    case 2: // Open promote/demote window
        this->close();
        acc.close();
        data.close();
        prom.setModal(true);
        prom.exec();
        break;

    case 3: // Open change data account window
        this->close();
        prom.close();
        acc.close();
        data.setModal(true);
        data.exec();
        break;

    }
}

// When menu button is pressed, menu bar shows up
void deleteUser::on_toolButton_2_clicked()
{
    ui->comboBox->show();
}

// When cancel button is pressed, it clears the content in lines
void deleteUser::on_buttonBox_rejected()
{
    ui->lineEdit->clear();
}

