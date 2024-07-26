#include "account_management.h"

// Initializes the database connection and ensures the userAccounts table exists.
account_management::account_management() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("database_q.db");
    db.setDatabaseName("C:/Users/danie/Downloads/Group-5-Scooters-main (3)/Group-5-Scooters-main/database_q.db");


    // Attempt to open the database
    if (!db.open()) {
        qDebug() << "Error: Could not open database.";
        return;
    }

    // Create the userAccounts table if it doesn't already exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS userAccounts ("
               "userID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password TEXT, "
               "role TEXT)");
}

// Closes the database connection.
account_management::~account_management() {
    db.close();
}

// Creates a new account with the given username, password, and role.
bool account_management::createAccount(const QString& username, const QString& password, const QString& role) {
    QSqlQuery query;
    query.prepare("INSERT INTO userAccounts (username, password, role) VALUES (:username, :password, :role)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":role", role);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Deletes the account with the given username.
bool account_management::deleteAccount(const QString& username) {
    QSqlQuery query;
    query.prepare("DELETE FROM userAccounts WHERE username = :username");
    query.bindValue(":username", username);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Promotes a user to an employee or administrator role.
bool account_management::promoteAccount(const QString& username, const QString& newRole) {
    QSqlQuery query;
    query.prepare("UPDATE userAccounts SET role = :role WHERE username = :username");
    query.bindValue(":role", newRole);
    query.bindValue(":username", username);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Demotes an employee or administrator to a regular user role.
bool account_management::demoteAccount(const QString& username) {
    QSqlQuery query;
    query.prepare("UPDATE userAccounts SET role = 'user' WHERE username = :username");
    query.bindValue(":username", username);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Retrieves all accounts from the database and returns them as a list of QVariantMap.
QList<QVariantMap> account_management::getAllAccounts() {
    QList<QVariantMap> accounts;
    QSqlQuery query("SELECT * FROM userAccounts");

    // Iterate through the results and add them to the list
    while (query.next()) {
        QVariantMap account;
        account["userID"] = query.value("userID");
        account["username"] = query.value("username");
        account["role"] = query.value("role");
        accounts.append(account);
    }

    return accounts;
}
