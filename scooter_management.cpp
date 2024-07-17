#include "scooter_management.h"
#include "ui_scooter_management.h"
#include <QPixmap>

scooter_management::scooter_management(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::scooter_management)
{
    ui->setupUi(this);

    ui->comboBox->hide();

    // Set Window Color
    this->setStyleSheet("background-color: rgb(35, 25, 158);");

    ui->pushButton_2->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_3->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_4->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->toolButton->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QToolButton:hover {" "background-color: orange;""}");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;}");

    // Initialize the SQLite database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("database_q.db"); // Set the database name
    db.setDatabaseName("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/database_q.db");

    QPixmap picture("/Users/juanpostiglione/Downloads/scooter.png");
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

void scooter_management::on_toolButton_clicked()
{
    ui->comboBox->show();
}


void scooter_management::on_comboBox_activated(int index)
{
    ui->comboBox->hide();
}

