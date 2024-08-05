#include "employee_manager.h"
#include "ui_employee_manager.h"
#include <QPixmap>
#include "accountmanagement.h"
#include "mainwindow.h"
#include "scooterrequests.h"
#include "adddeletescooter.h"
employee_manager::employee_manager(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::employee_manager)
{
    ui->setupUi(this);

    this->show();

    ui->comboBox->hide();

    // Set image

    QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label->setPixmap(image);

    // Set style button and window
    ui->comboBox->hide();

    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    ui->pushButton->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_2->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_3->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_4->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->toolButton->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QToolButton:hover {" "background-color: orange;""}");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;" "}");

}



employee_manager::~employee_manager()
{
    delete ui;
}

// When menu button is pressed, menubar shows up
void employee_manager::on_toolButton_clicked()
{
    ui->comboBox->show();
}


// When Account Management button is pressed
void employee_manager::on_pushButton_4_clicked()
{
    this->close();
    accountmanagement acc;
    acc.setModal(true);
    acc.exec();
}

// When Account Management button is pressed in Menu
void employee_manager::on_comboBox_currentIndexChanged(int index)
{
    accountmanagement acc;
    scooterRequests req;
    addDeleteScooter sc;
    switch(index)
    {
    case 1: // Open account management window
        this->close();
        req.close();
        acc.setModal(true);
        acc.exec();
        sc.close();
        break;

    case 2: // Open add, delete, update scooter window
        this->close();
        acc.close();
        req.close();
        sc.setModal(true);
        sc.exec();
        break;

    case 3: // Open scooter request window
        this->close();
        acc.close();
        sc.close();
        req.setModal(true);
        req.exec();
        break;

    case 4: // Log Out
        this->close();
        acc.close();
        req.close();
        sc.close();
        // Go to log in window and close current window
        mainWindow = new MainWindow(nullptr);
        mainWindow->show();
        break;


    }
}

// When approve reject scooter button is pressed
void employee_manager::on_pushButton_3_clicked()
{
    this->close();
    scooterRequests req;
    req.setModal(true);
    req.exec();
}

// When log out button is clicked
void employee_manager::on_pushButton_clicked()
{
    // Go to log in window and close current window
    mainWindow = new MainWindow(nullptr);
    mainWindow->show();
    this->close();
}

// When add, delete, update scooter button is pressed
void employee_manager::on_pushButton_2_clicked()
{
    this->close();
    addDeleteScooter sc;
    sc.setModal(true);
    sc.exec();
}

