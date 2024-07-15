#ifndef SCOOTER_MANAGEMENT_H
#define SCOOTER_MANAGEMENT_H

#include <QtSql>  // Include Qt SQL module for database functionality
#include <QDebug> // Include Qt Debug module for debugging output

class scooter_management
{
public:
    // Constructor to initialize database connection and setup table
    scooter_management();

    // Destructor to close the database connection
    ~scooter_management();

    // Method to add a new scooter to the database
    void addScooter(const QString& availability, const QString& location, double pricing, const QString& renter);

    // Method to update an existing scooter's details in the database
    void updateScooter(int id, const QString& availability, const QString& location, double pricing, const QString& renter);

    // Method to delete a scooter from the database
    void deleteScooter(int id);

    // Method to retrieve all scooters from the database
    QList<QVariantMap> getAllScooters();

private:
    // Database connection object
    QSqlDatabase db;
};

#endif // SCOOTER_MANAGEMENT_H
