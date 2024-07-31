#include "account_management.h"

// Initializes the database connection and ensures the userAccounts table exists.
account_management::account_management() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("database_q.db");
    //db.setDatabaseName("C:/Users/danie/Downloads/Group-5-Scooters-main (3)/Group-5-Scooters-main/database_q.db");
    db.setDatabaseName("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/database_q.db");

    // Attempt to open the database
    if (!db.open()) {
        qDebug() << "Error: Could not open database.";
        return;
    }

    // Create the loginDetails table if it doesn't already exist
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS loginDetails ("
               "account_id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password TEXT, "
               "status TEXT)");

    if(query.exec())
    {
        //If there are no accounts, add a new administrator account.
        createAccount("admin0", "admin0", "administrator");
    }

}
// Closes the database connection.
account_management::~account_management() {
    db.close();
}

// Creates a new account with the given username, password, and role.
bool account_management::createAccount(const QString& username, const QString& password, const QString& status) {
    QString pwdEncrypted = encryptPassword(password);

    QSqlQuery query;
    query.prepare("INSERT INTO loginDetails (username, password, status) VALUES (:username, :password, :status)");
    query.bindValue(":username", username);
    query.bindValue(":password", pwdEncrypted);
    query.bindValue(":status", status); //"customer", "employee", or "administrator". Default status is "customer".

    // Execute the query and return whether it was successful
    return query.exec();
}

// Deletes the account with the given username.
bool account_management::deleteAccount(const QString& username) {
    QSqlQuery query;
    query.prepare("DELETE FROM loginDetails WHERE username = :username");
    query.bindValue(":username", username);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Promotes a user to an employee or administrator role.
bool account_management::promoteAccount(const QString& username, const QString& newStatus) {
    QSqlQuery query;
    query.prepare("UPDATE loginDetails SET status = :status WHERE username = :username");
    query.bindValue(":status", newStatus);
    query.bindValue(":username", username);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Demotes an employee or administrator to a regular user role.
bool account_management::demoteAccount(const QString& username) {
    QSqlQuery query;
    query.prepare("UPDATE loginDetails SET role = 'user' WHERE username = :username");
    query.bindValue(":username", username);

    // Execute the query and return whether it was successful
    return query.exec();
}

// Retrieves all accounts from the database and returns them as a list of QVariantMap.
QList<QVariantMap> account_management::getAllAccounts() {
    QList<QVariantMap> accounts;
    QSqlQuery query("SELECT * FROM loginDetails");

    // Iterate through the results and add them to the list
    while (query.next()) {
        QVariantMap account;
        account["account_id"] = query.value("account_id");
        account["username"] = query.value("username");
        account["status"] = query.value("status");
        accounts.append(account);
    }

    return accounts;
}


// Function to encrypt each user's password before storing in database.
QString account_management::encryptPassword(QString pwdStr)
{
    QString encodedPwd;
    char16_t newChar;

    char16_t strChar;
    char16_t keyChar;

    //char16_t QChar::unicode() const

    for(int i = 0; i < pwdStr.size(); i++)
    {
        strChar = pwdStr[i].unicode();
        keyChar = pwdKey[i].unicode();

        // XOR password with the key to encrypt.
        newChar = strChar ^ keyChar;

        // Store encrypted password as only printable values
        if(newChar > 79)
        {
            newChar -= 47;
        }
        if(newChar < 79)
        {
            newChar += 47;
        }

        QChar tempChar(newChar);
        encodedPwd.append(tempChar);
    }
    return encodedPwd;
}


// Function to decrypt each user's password after reading from database.
QString account_management::decryptPassword(QString pwdStr)
{
    QString decodedPwd;
    char16_t newChar;

    char16_t strChar;
    char16_t keyChar;

    for(int i = 0; i < pwdStr.size(); i++)
    {
        strChar = pwdStr[i].unicode();
        keyChar = pwdKey[i].unicode();

        // Revert characters back to their potentially unprintable forms.
        if(strChar > 79)
        {
            strChar -= 47;
        }
        if(strChar < 79)
        {
            strChar += 47;
        }

        // XOR encrypted password with the key to decrypt.
        newChar = strChar ^ keyChar;

        QChar tempChar(newChar);
        decodedPwd.append(tempChar);
    }
    return decodedPwd;
}
