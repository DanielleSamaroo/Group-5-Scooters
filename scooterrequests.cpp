#include "scooterrequests.h"
#include "ui_scooterrequests.h"
#include "scooter_management.h"
#include "accountmanagement.h"
#include "employee_manager.h"

scooterRequests::scooterRequests(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::scooterRequests)
{
    ui->setupUi(this);

    // Set image and UI Style

    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();

    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();

    QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label->setPixmap(image);

    ui->comboBox_3->hide();

    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;" "}");

    ui->buttonBox->setStyleSheet("QPushButton{" "color: white;" "background-color: grey;"
                                 "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->buttonBox_2->setStyleSheet("QPushButton{" "color: white;" "background-color: grey;"
                                 "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->toolButton->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                    "}" "QToolButton:hover {" "background-color: orange;""}");

    ui->pushButton->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");


    ui->pushButton_2->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

}

scooterRequests::~scooterRequests()
{
    delete ui;
}

// When Approve button is pressed
void scooterRequests::on_pushButton_clicked()
{
    ui->lineEdit->show();
    ui->lineEdit_2->show();

    ui->label_6->show();
    ui->label_7->show();
}

// When Reject button is pressed
void scooterRequests::on_pushButton_2_clicked()
{
    ui->lineEdit_3->show();
    ui->label_8->show();
}

// When accept is pressed, approveRental function works with the UI
void scooterRequests::on_buttonBox_accepted()
{

    scooter_management scooter;
    QString username = ui->lineEdit->text();
    bool done;
    int scooterID = ui->lineEdit_2->text().toInt(&done);

    if(username.isEmpty() || !done)
    {
        ui->label_3->setText("Missing Fields.");
    }

    else
    {
        if(scooter.approveRental(scooterID, username))
        {
            ui->label_3->setText("Rental Aproved.");
        }

        else
        {
            ui->label_3->setText("Rental Aprove failed, username or ID were not found.");
        }
    }
}

// When accpet button is pressed, rejectRental function works with the UI
void scooterRequests::on_buttonBox_2_accepted()
{
    scooter_management scooter;
    bool done;
    int scooterID = ui->lineEdit_3->text().toInt(&done);

    if(!done)
    {
        ui->label_3->setText("Missing Fields.");
    }

    else
    {
        if(scooter.rejectRental(scooterID))
        {
            ui->label_3->setText("Rental Rejected successfully.");
        }

        else
        {
            ui->label_3->setText("Rental Reject failed.");
        }
    }
}

// When cancel button fro approval is pressed, line contents clear
void scooterRequests::on_buttonBox_rejected()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();

    ui->label_6->hide();
    ui->label_7->hide();
}

// When cancel button for reject is pressed, line contents clear
void scooterRequests::on_buttonBox_2_rejected()
{
    ui->lineEdit_3->clear();
    ui->lineEdit_3->hide();
    ui->label_8->hide();
}

// When menu button is pressed, menu bar shows up
void scooterRequests::on_toolButton_clicked()
{
    ui->comboBox_3->show();
}

// Change windows from menu bar
void scooterRequests::on_comboBox_3_currentIndexChanged(int index)
{
    accountmanagement acc;
    scooterRequests scooter;
    employee_manager em;

    switch(index)
    {
    case 1: // Employe manager window opens
        this->close();
        acc.close();
        em.setModal(true);
        em.exec();
        break;

    case 2: // Account management window opens
        this->close();
        em.close();
        acc.setModal(true);
        acc.exec();
        break;
    }
}

