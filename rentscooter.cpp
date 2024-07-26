#include "rentscooter.h"
#include "ui_rentscooter.h"
#include "scooter_management.h"
#include<QSqlQuery>
#include <QPixmap>
#include <QtSql>

rentScooter::rentScooter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rentScooter),
     mainWindow(nullptr)
{
    ui->setupUi(this);

    // Hide index Menu
    ui->comboBox->hide();

    // Hide button box
    ui->buttonBox->hide();

    // Hide message after rent
    ui->label_6->hide();

    // Set Scooter Image
    //QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    QPixmap image("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/scooter.png");
    ui->label->setPixmap(image);

    // Use images as emojis for check boxes
    ui->label_4->setPixmap(image);
    ui->label_10->setPixmap(image);
    ui->label_11->setPixmap(image);
    ui->label_12->setPixmap(image);
    ui->label_13->setPixmap(image);


    // Top label color
    ui->frame->setStyleSheet("QFrame {" "background-color: black;}");

    ui->toolButton->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                  "}" "QToolButton:hover {" "background-color: orange;""}");

    ui->buttonBox->setStyleSheet("QPushButton{" "color: white;" "background-color: grey;"
                                 "}" "QPushButton:hover {" "background-color: orange;""}");

    // Set Window Color
    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    // Check the Index Menu
    ui->comboBox->setCurrentIndex(1);

    // Set Database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("/Users/juanpostiglione/Desktop/Database/database_q.db");
    db.setDatabaseName("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/database_q.db");

    if (!db.open()) {
        qDebug() << "Error: Could not open database." << db.lastError();
        return; // Exit the function if the database cannot be opened
    }

    QSqlQuery query("SELECT * FROM scooterDetails"); // Execute an SQL query to select all records from the scooterDetails table

    // Iterate over the result set
    while (query.next()) {
        QVariantMap scooter; // Create a map to hold the scooter details
        scooter["lot_id"] = query.value("lot_id"); // Retrieve and store the ID value
        scooter["status"] = query.value("status"); // Retrieve and store the availability value
        scooter["location"] = query.value("location"); // Retrieve and store the location value
        scooter["units"] = query.value("units"); // Retrieve and store the pricing value
        scooters.append(scooter); // Add the map to the list

        // If the list is not empty
        if(!scooters.empty())
        {
            // Access to the first row of scooterDetails
            QVariantMap firstRow = scooters.at(0);
            QString ID = firstRow.value("lot_id").toString();
            QString Status = firstRow.value("status").toString();
            QString Location = firstRow.value("location").toString();
            QString Units = firstRow.value("units").toString();

            QString text = "LOT ID: " + ID + " | Status: " + Status + " | Location: " + Location + " | Units: " + Units;

            // Show data in check box
            ui->checkBox->setText(text);
        }

        if(scooters.size() > 1)
        {
            // Access to the second row of scooterDetails
            QVariantMap secondRow = scooters.at(1);
            QString ID = secondRow.value("lot_id").toString();
            QString Status = secondRow.value("status").toString();
            QString Location = secondRow.value("location").toString();
            QString Units = secondRow.value("units").toString();

            QString text = "LOT ID: " + ID + " | Status: " + Status + " | Location: " + Location + " | Units: " + Units;

            // Show data in check box
            ui->checkBox_2->setText(text);
        }

        if(scooters.size() > 2)
        {
            // Access to the third row of scooterDetails
            QVariantMap thirdRow = scooters.at(2);
            QString ID = thirdRow.value("lot_id").toString();
            QString Status = thirdRow.value("status").toString();
            QString Location = thirdRow.value("location").toString();
            QString Units = thirdRow.value("units").toString();

            QString text = "LOT ID: " + ID + " | Status: " + Status + " | Location: " + Location + " | Units: " + Units;

            // Show data in check box
            ui->checkBox_3->setText(text);
        }

        if(scooters.size() > 3)
        {
            // Access to the fourth row of scooterDetails
            QVariantMap fourthRow = scooters.at(3);
            QString ID = fourthRow.value("lot_id").toString();
            QString Status = fourthRow.value("status").toString();
            QString Location = fourthRow.value("location").toString();
            QString Units = fourthRow.value("units").toString();

            QString text = " LOT ID: " + ID + " | Status: " + Status + " | Location: " + Location + " | Units: " + Units;

            // Show data in check box
            ui->checkBox_4->setText(text);
        }

        if(scooters.size() > 4)
        {
            // Access to the fifth row of scooterDetails
            QVariantMap fifthRow = scooters.at(4);
            QString ID = fifthRow.value("lot_id").toString();
            QString Status = fifthRow.value("status").toString();
            QString Location = fifthRow.value("location").toString();
            QString Units = fifthRow.value("units").toString();

            QString text = "LOT ID: " + ID + " | Status: " + Status + " | Location: " + Location + " | Units: " + Units;

            // Show data in check box
            ui->checkBox_5->setText(text);
        }
    }
    query.finish();
}

rentScooter::~rentScooter()
{
    delete ui;
}


// Method to set guestAcc
void rentScooter::setGuest(bool isGuest)
{
    guestAcc = isGuest;
}


// Show Menu when tool button is clicked
void rentScooter::on_toolButton_clicked()
{
    ui->comboBox->show();
}

// Switch windows from the Menu
void rentScooter::on_comboBox_activated(int index)
{
    ui->comboBox->hide();
    scooter_management window;
    mainWindow = new MainWindow(nullptr);

    switch(index)
    {
    // Go to Home window
    case 0:
        this->close();
        window.setModal(true);
        window.exec();
        break;

    // Go to log in Window
    case 5:
        this->close();
        window.close();
        mainWindow->show();
        mainWindow->resize(400,500);
        break;

    }
}

// Update scooterDetails table after an user rents a scooter
void rentScooter::updateUnits(int numRows)
{
    if(!guestAcc)
    {
        if (numRows < scooters.size()) {
            QVariantMap selectedRow = scooters.at(numRows);
            QString lotID = selectedRow.value("lot_id").toString();
            int currentUnits = selectedRow.value("units").toInt();

            if (currentUnits > 0) {
                // Decrement units by 1
                currentUnits--;

                // Update the database
                QSqlQuery query;
                query.prepare("UPDATE scooterDetails SET units = :units WHERE lot_id = :lot_id");
                query.bindValue(":units", currentUnits);
                query.bindValue(":lot_id", lotID);

                if (query.exec()) {
                    qDebug() << "Units updated successfully for lot_id:" << lotID;
                    ui->label_6->setText("Scooter rented, go to My Scooters to see your details");
                } else {
                    qDebug() << "Error updating units:" << query.lastError().text();
                    ui->label_6->setText("There was an error with your rental request");
                }
            } else {
                qDebug() << "No units available for lot_id:" << lotID;
                ui->label_6->setText("No units available for this lot");
            }
        }
    }
    else
    {
        ui->label_6->setText("You must be signed in to place a rental request");
    }
}

// When first check box is clicked
void rentScooter::on_checkBox_clicked()
{
    // Hide or show button box depending if the check bx is checked or not
    ui->buttonBox->show();

    if(!ui->checkBox->isChecked())
    {
        ui->buttonBox->hide();
    }
}

// When second check box is clicked
void rentScooter::on_checkBox_2_clicked()
{
    // Hide or show button box depending if the check bx is checked or not
    ui->buttonBox->show();

    if(!ui->checkBox_2->isChecked())
    {
        ui->buttonBox->hide();
    }
}

// When third check box is clicked
void rentScooter::on_checkBox_3_clicked()
{
    // Hide or show button box depending if the check bx is checked or not
    ui->buttonBox->show();

    if(!ui->checkBox_3->isChecked())
    {
        ui->buttonBox->hide();
    }
}

// When fourth check box is clicked
void rentScooter::on_checkBox_4_clicked()
{
    // Hide or show button box depending if the check bx is checked or not
    ui->buttonBox->show();

    if(!ui->checkBox_4->isChecked())
    {
        ui->buttonBox->hide();
    }
}

// When fifth check box is clicked
void rentScooter::on_checkBox_5_clicked()
{
    // Hide or show button box depending if the check bx is checked or not
    ui->buttonBox->show();

    if(!ui->checkBox_5->isChecked())
    {
        ui->buttonBox->hide();
    }
}

// When Cancel button is clicked
void rentScooter::on_buttonBox_rejected()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->buttonBox->hide();
}

// When OK button is clicked
void rentScooter::on_buttonBox_accepted()
{

    // If first row is checked and click OK update scooterDetails
    if(ui->checkBox->isChecked())
    {
        updateUnits(0);
    }

    // If second row is checked and click OK update scooterDetails
    if(ui->checkBox_2->isChecked())
    {
        updateUnits(1);
    }

    // If third row is checked and click OK update scooterDetails
    if(ui->checkBox_3->isChecked())
    {
        updateUnits(2);
    }

    // If fourth row is checked and click OK update scooterDetails
    if(ui->checkBox_4->isChecked())
    {
        updateUnits(3);
    }

    // If fifth row is checked and click OK update scooterDetails
    if(ui->checkBox_5->isChecked())
    {
        updateUnits(4);
    }

    // Uncheck all checkboxes after updating the units
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);

    // Hide the button box after the action
    ui->buttonBox->hide();

    // Show message after rent
    ui->label_6->show();
}

