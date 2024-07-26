#ifndef ACCOUNT_MANAGEMENT_H
#define ACCOUNT_MANAGEMENT_H

#include <QtSql>
#include <QDebug>

class account_management
{
public:
    account_management(); // Initializes the database connection and ensures the table exists.
    ~account_management(); // Closes the database connection.

    // Creates a new account with the given username, password, and role.
    bool createAccount(const QString& username, const QString& password, const QString& role);

    // Deletes the account with the given username.
    bool deleteAccount(const QString& username);

    // Promotes a user to an employee or administrator role.
    bool promoteAccount(const QString& username, const QString& newRole);

    // Demotes an employee or administrator to a regular user role.
    bool demoteAccount(const QString& username);

    // Retrieves all accounts from the database and returns them as a list of QVariantMap.
    QList<QVariantMap> getAllAccounts();

private:
    QSqlDatabase db; // Database connection object.
};

#endif // ACCOUNT_MANAGEMENT_H
