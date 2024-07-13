#include "scooter_management.h"

// Constructor implementation
scooter_management::scooter_management() {
    // Initialize the SQLite database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database_q.db"); // Set the database name

    // Check if the database opens successfully
    if (!db.open()) {
        qDebug() << "Error: Could not open database."; // Output error message if the database fails to open
        return;
    }

    // Create a SQL query to create the scooterDetails table if it doesn't exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS scooterDetails ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "Availability TEXT, "
               "Location TEXT, "
               "Pricing REAL)");
}

// Destructor implementation
scooter_management::~scooter_management() {
    db.close(); // Close the database connection when the object is destroyed
}

// Method to add a new scooter to the database
void scooter_management::addScooter(const QString& availability, const QString& location, double pricing) {
    // Prepare an SQL query to insert a new scooter record
    QSqlQuery query;
    query.prepare("INSERT INTO scooterDetails (Availability, Location, Pricing) VALUES (:availability, :location, :pricing)");
    query.bindValue(":availability", availability); // Bind the availability parameter
    query.bindValue(":location", location); // Bind the location parameter
    query.bindValue(":pricing", pricing); // Bind the pricing parameter

    if (!query.exec()) {
        qDebug() << "Error adding scooter: " << query.lastError().text();
    }
}

// Method to update an existing scooter's details in the database
void scooter_management::updateScooter(int id, const QString& availability, const QString& location, double pricing) {
    // Prepare an SQL query to update a scooter record based on its ID
    QSqlQuery query;
    query.prepare("UPDATE scooterDetails SET Availability = :availability, Location = :location, Pricing = :pricing WHERE ID = :id");
    query.bindValue(":availability", availability); // Bind the availability parameter
    query.bindValue(":location", location); // Bind the location parameter
    query.bindValue(":pricing", pricing); // Bind the pricing parameter
    query.bindValue(":id", id); // Bind the ID parameter

    if (!query.exec()) {
        qDebug() << "Error updating scooter: " << query.lastError().text();
    }
}

// Method to delete a scooter from the database
void scooter_management::deleteScooter(int id) {
    // Prepare an SQL query to delete a scooter record based on its ID
    QSqlQuery query;
    query.prepare("DELETE FROM scooterDetails WHERE ID = :id");
    query.bindValue(":id", id); // Bind the ID parameter

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
        scooter["ID"] = query.value("ID"); // Retrieve and store the ID value
        scooter["Availability"] = query.value("Availability"); // Retrieve and store the availability value
        scooter["Location"] = query.value("Location"); // Retrieve and store the location value
        scooter["Pricing"] = query.value("Pricing"); // Retrieve and store the pricing value
        scooters.append(scooter); // Add the map to the list
    }

    return scooters; // Return the list of scooters
}
