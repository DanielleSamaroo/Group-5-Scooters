#ifndef ACCOUNT_MANAGEMENT_H
#define ACCOUNT_MANAGEMENT_H

#include <QtSql>
#include <QDebug>

class account_management
{
public:
    account_management(); // Initializes the database connection and ensures the table exists.
    ~account_management(); // Closes the database connection.

    // Creates a new account with the given username, password, and status.
    bool createAccount(const QString& username, const QString& password, const QString& status);

    // Deletes the account with the given username.
    bool deleteAccount(const QString& username);

    // Promotes a user to an employee or administrator role.
    bool promoteAccount(const QString& username, const QString& newStatus);

    // Demotes an employee or administrator to a regular user role.
    bool demoteAccount(const QString& username);

    // Retrieves all accounts from the database and returns them as a list of QVariantMap.
    QList<QVariantMap> getAllAccounts();

private:
    QSqlDatabase db; // Database connection object.

    QString pwdKey = "HI0qnP4YuI1WttiUie0e"; // Key used for password encryption and decryption

    // Function to encrypt and decrypt each user's password before storing in database.
    QString encryptPassword(QString pwdStr);

    // Function to decrypt each user's password after reading from database.
    QString decryptPassword(QString pwdStr);
};

#endif // ACCOUNT_MANAGEMENT_H
