#include <QCoreApplication>
#include <QDebug>
#include "scooter_management.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    scooter_management manager;

    // Add a new scooter
    manager.addScooter("Available", "Location A", 10.0, "");

    // Update an existing scooter
    manager.updateScooter(1, "Unavailable", "Location B", 15.0, "");

    // Retrieve and print all scooters
    QList<QVariantMap> scooters = manager.getAllScooters();
    for (const auto& scooter : scooters) {
        qDebug() << "ID: " << scooter["scooter_id"].toInt()
                 << "Availability: " << scooter["available"].toString()
                 << "Location: " << scooter["location"].toString()
                 << "Pricing: " << scooter["rental_rate"].toDouble()
                 << "Renter: " << scooter["renter"].toString();
    }

    // Delete a scooter
    manager.deleteScooter(1);
    manager.deleteScooter(2);

    return a.exec();
}
