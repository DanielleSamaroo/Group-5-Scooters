#include "scooter_management.h"
#include "ui_scooter_management.h"
#include "ui_rentscooter.h"
#include "mainwindow.h"
#include "rentscooter.h"
#include <QPixmap>

scooter_management::scooter_management(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::scooter_management),
      mainWindow(nullptr)
{
    ui->setupUi(this);

    ui->comboBox->hide();

    // Set Window Color
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

    ui->frame->setStyleSheet("QFrame {" "background-color: black;}");

     ui->comboBox->setCurrentIndex(0);

    // Initialize the SQLite database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("database_q.db"); // Set the database name
    //db.setDatabaseName("/Users/juanpostiglione/Desktop/Database/database_q.db");
    // db.setDatabaseName("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/database_q.db");
    db.setDatabaseName("C:/Users/danie/Downloads/Group-5-Scooters-main (2)/Group-5-Scooters-main/database_q.db");


    //QPixmap picture("/Users/juanpostiglione/Downloads/scooter.png");
    // QPixmap picture("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/scooter.png");
    QPixmap picture("C:/Users/danie/Downloads/Group-5-Scooters-main (3)/Group-5-Scooters-main/scooter.png");

    ui->label->setPixmap(picture);


    // Check if the database opens successfully
    if (!db.open()) {
        qDebug() << "Error: Could not open database."; // Output error message if the database fails to open
        return;
    }


    // Create a SQL query to create the scooterDetails table if it doesn't exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS scooterDetails ("
               "scooter_id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "available TEXT, "
               "location TEXT, "
               "rental_rate INTEGER, "
               "renter TEXT)");

}

scooter_management::~scooter_management()
{
    delete ui;
}

// Method to add a new scooter to the database
void scooter_management::addScooter(const QString& sAvailability, const QString& sLocation, double sPricing, const QString& sRenter) {
    // Prepare an SQL query to insert a new scooter record
    QSqlQuery query;
    query.prepare("INSERT INTO scooterDetails (available, location, rental_rate, renter) VALUES (:availability, :location, :pricing, :renter)");
    query.bindValue(":availability", sAvailability); // Bind the availability parameter
    query.bindValue(":location", sLocation); // Bind the location parameter
    query.bindValue(":pricing", sPricing); // Bind the pricing parameter
    query.bindValue(":renter", sRenter); // Bind the renter parameter

    if (!query.exec()) {
        qDebug() << "Error adding scooter: " << query.lastError().text();
    }
}

// Method to update an existing scooter's details in the database
void scooter_management::updateScooter(int sID, const QString& sAvailability, const QString& sLocation, double sPricing, const QString& sRenter ) {
    // Prepare an SQL query to update a scooter record based on its ID
    QSqlQuery query;
    query.prepare("UPDATE scooterDetails SET available = :availability, location = :location, rental_rate = :pricing, renter = :renter WHERE scooter_id = :id");
    query.bindValue(":availability", sAvailability); // Bind the availability parameter
    query.bindValue(":location", sLocation); // Bind the location parameter
    query.bindValue(":pricing", sPricing); // Bind the pricing parameter
    query.bindValue(":id", sID); // Bind the ID parameter
    query.bindValue(":renter", sRenter); // Bind the renter parameter

    if (!query.exec()) {
        qDebug() << "Error updating scooter: " << query.lastError().text();
    }
}

// Method to delete a scooter from the database
void scooter_management::deleteScooter(int sID) {
    // Prepare an SQL query to delete a scooter record based on its ID
    QSqlQuery query;
    query.prepare("DELETE FROM scooterDetails WHERE scooter_id = :id");
    query.bindValue(":id", sID); // Bind the ID parameter

    if (!query.exec()) {
        qDebug() << "Error deleting scooter: " << query.lastError().text();
    }
}

// Method to retrieve all scooters from the database
QList<QVariantMap> scooter_management::getAllScooters() {
    QList<QVariantMap> scooters; // Create a list to hold the scooter records
    QSqlQuery query("SELECT * FROM scooterDetails"); // Execute an SQL query to select all records from the scooterDetails table

    // Iterate over the result set
    while (query.next()) {
        QVariantMap scooter; // Create a map to hold the scooter details
        scooter["scooter_id"] = query.value("scooter_id"); // Retrieve and store the ID value
        scooter["available"] = query.value("available"); // Retrieve and store the availability value
        scooter["location"] = query.value("location"); // Retrieve and store the location value
        scooter["rental_rate"] = query.value("rental_rate"); // Retrieve and store the pricing value
        scooter["renter"] = query.value("renter"); // Retrieve and store the renter value
        scooters.append(scooter); // Add the map to the list
    }

    return scooters; // Return the list of scooters
}

// Method to approve a rental request
bool scooter_management::approveRental(int scooterID, const QString& renter) {
    QSqlQuery query;
    query.prepare("UPDATE scooterDetails SET available = 'No', renter = :renter WHERE scooter_id = :scooter_id");
    query.bindValue(":renter", renter);
    query.bindValue(":scooter_id", scooterID);

    return query.exec();
}

// Method to reject a rental request
bool scooter_management::rejectRental(int scooterID) {
    QSqlQuery query;
    query.prepare("UPDATE scooterDetails SET available = 'Yes', renter = NULL WHERE scooter_id = :scooter_id");
    query.bindValue(":scooter_id", scooterID);

    return query.exec();
}

// Method to set guestAcc
void scooter_management::setGuest(bool isGuest)
{
    guestAcc = isGuest;
}


// When Menu button is clicked
void scooter_management::on_toolButton_clicked()
{
    ui->comboBox->show();
}

// When an index of the Menu is clicked
void scooter_management::on_comboBox_activated(int index)
{
    ui->comboBox->hide();
    mainWindow = new MainWindow(nullptr);
    rentScooter window;
    window.setGuest(guestAcc);

    // Switch windows from Menu
    switch(index)
    {

    // Go to Rent a Scooter window
    case 1:
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

// When Log Out button is pressed
void scooter_management::on_pushButton_3_clicked()
{
    // Go to log in window and close current window
    mainWindow = new MainWindow(nullptr);
    mainWindow->show();
    this->close();
}

// When Rent a Scooter Button is pressed
void scooter_management::on_pushButton_2_clicked()
{
    // Go to rent a scooter window and close current window
    this->close();
    rentScooter rent;
    rent.setGuest(guestAcc);
    rent.setModal(true);
    rent.exec();

}
