#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scooter_management.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    this->resize(400,500);

    QPixmap pix("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label_4->setPixmap(pix);

    // Set Window Color
    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    // Initially hide Labels and Line Text
    ui->label->hide();
    ui->lineEdit->hide();

    ui->label_2->hide();
    ui->lineEdit_2->hide();

    ui->label_6->hide();
    ui->lineEdit_5->hide();

    ui->label_7->hide();
    ui->lineEdit_6->hide();

    ui->label_8->hide();
    ui->label_5->hide();

    // Hide "Next", "Back" and "Create Account" Button
    ui->pushButton_4->hide();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();

    // Set Button and Label Colors
    ui->label_3->setStyleSheet("QLabel { color : rgb(255, 165, 0); }");
    ui->pushButton->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_2->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_3->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_4->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_5->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;" "border-radius: 3px;" "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    // Initially set Button Position
    buttonPosition();

    // Edit Font
    setFontAttributes(30, true, true);

    // Initially set Label Position
    labelPosition();
}


void MainWindow::setFontAttributes(int size, bool bold, bool italic)
{
    QFont font = ui->label_3->font();
    font.setPointSize(size);
    font.setBold(bold);
    font.setItalic(italic);

    ui->label_3->setFont(font);
}

// Set the Buttons Position
void MainWindow::buttonPosition()
{
    // Get Width and Height for Buttons
    int pushButtonWidth = ui->pushButton->width();
    int pushButtonHeight = ui->pushButton->height();

    // Get the Center of the Window
    int centerX = (windowWidth - pushButtonWidth) / 2;
    int centerY = (windowHeight - pushButtonHeight) / 2;

    // Buttons Position
    ui->pushButton->move(centerX -200,centerY + 100);
    ui->pushButton_2->move(centerX -35, centerY + 100);
    ui->pushButton_4->move(centerX -35,centerY+100);
    ui->pushButton_5->move(centerX -200,centerY+100);
    ui->pushButton_3->move(centerX -40,centerY+100);

}

// Set the Labels Position
void MainWindow::labelPosition()
{
    // Get Width and Height for Labels
    int labelWidth = ui->label->width();
    int labelHeight = ui->label->height();

    // Get the Center of the Window
    int centerX = (windowWidth - labelWidth) / 2;
    int centerY = (windowHeight - labelHeight) / 2;

    // Labels Position
    ui->label->move(centerX-180, centerY-98.5);
    ui->label_2->move(centerX-180,centerY-48.5);
    ui->label_3->move(centerX-195,centerY-150);
    ui->label_4->move(centerX -125, centerY - 50);
    ui->label_5->move(centerX-180, centerY +20);
    ui->label_6->move(centerX-190,centerY - 98.5);
    ui->label_7->move(centerX-190,centerY - 48.5);
    ui->label_8->move(centerX-180, centerY + 2.5);
}

// Set the Line Text Position
void MainWindow::lineTextPosition()
{
    // Get Width and Height for Line Text
    int lineTextWidth = ui->lineEdit->width();
    int lineTextHeight = ui->lineEdit->height();

    // Get the Center of the Window
    int centerX = (windowHeight - lineTextHeight) /2;
    int centerY = (windowWidth - lineTextWidth) /2;

    // Line Text Position
    ui->lineEdit->move(centerX -50 ,centerY - 130);
    ui->lineEdit_2->move(centerX -50,centerY - 80);
    ui->lineEdit_5->move(centerX-20,centerY-130);
    ui->lineEdit_6->move(centerX-20,centerY - 80);
}


MainWindow::~MainWindow()
{
    delete ui;
}

// When Login button is clicked
void MainWindow::on_pushButton_clicked()
{
    // When button is clicked, hide login, sign up button and title
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();

    // Label Names
    ui->label->setText("Username:");
    ui->label_2->setText("Password:");


    // When Login Button is clicked show Labels
    ui->label->show();
    ui->label_2->show();

    // When Login Button is clicked show Line Text
    ui->lineEdit->show();
    ui->lineEdit_2->show();

    // When Login Button is clicked show "Next" and "Back" button
    ui->pushButton_4->show();
    ui->pushButton_5->show();

    // Set Label Position
    labelPosition();

    // Set Line Text Position
    lineTextPosition();

    // Set Button Position
    buttonPosition();
}

// When "Back" button is clicked
void MainWindow::on_pushButton_5_clicked()
{
    // Show title, login and sign op button
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->label_3->show();
    ui->label_4->show();

    // Hide other labels and edit lines
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_6->hide();
    ui->lineEdit_5->hide();
    ui->label_7->hide();
    ui->lineEdit_6->hide();
    ui->label_8->hide();
    ui->label_5->hide();

    // Hide buttons
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();

}


// When Sign Up button is clicked
void MainWindow::on_pushButton_2_clicked()
{
    // When Sign Up Button is clicked show "Next", "Back" and Create Account button
    ui->pushButton_3->show();
    ui->pushButton_5->show();

    // Show labels and line edits
    ui->label_6->show();
    ui->lineEdit_5->show();
    ui->label_7->show();
    ui->lineEdit_6->show();

    // Hide and line edits
    ui->label_3->hide();
    ui->label_4->hide();

    // Hide buttons
    ui->pushButton->hide();
    ui->pushButton_2->hide();

    // Set Label Position
    labelPosition();

    // Set Line Text Position
    lineTextPosition();

    // Set Button Position
    buttonPosition();
}

// When "Create Account" button is clicked
void MainWindow::on_pushButton_3_clicked()
{
    // Set Database
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/Users/juanpostiglione/Desktop/Database/database_q.db");
    //mydb.setDatabaseName("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/database_q.db");
    mydb.open();

    if (mydb.open())
    {
        qDebug() << "DB opened";
    }
    else
    {
        qDebug() << "Db not opened";
    }

    // Strings for sign up credentials
    QString createUsername = ui->lineEdit_5->text();
    QString createPassword = ui->lineEdit_6->text();
    QString addStatus = "customer"; //"customer", "employee", or "administrator". Default status is "customer".

    //Check if username/password fields are empty
    if(createUsername == "" || createPassword == "")
    {
        ui->label_8->setText("Missing fields");
        ui->label_8->show();
    }
    else
    {
        // Create a query
        QSqlQuery query(mydb);

        // Insert data written to the database filters
        query.prepare("INSERT INTO loginDetails (username, password, status) VALUES (:username, :password, :status)");
        query.bindValue(":username", createUsername);
        query.bindValue(":password", createPassword);
        query.bindValue(":status", addStatus);

        if(query.exec())
        {
            // Print message when account is created
            ui->label_8->setText("Account created.");
            ui->label_8->show();
            ui->label_5->setText("Enter Username and Password");
            ui->label_5->show();

            // Go to Login window, only if account is successfully registered
            on_pushButton_clicked();

            // Hide labels and line edits, only if account is successfully registered
            ui->label_6->hide();
            ui->lineEdit_5->hide();
            ui->label_7->hide();
            ui->lineEdit_6->hide();

            // Hide "Create Account" button
            ui->pushButton_3->hide();
        }
        else //Query execution will fail if username already exists
        {
            ui->label_8->setText("This username already exists");
            ui->label_8->show();
        }

        query.finish();
    }

    mydb.close();
}

// When "Next" button is pressed
void MainWindow::on_pushButton_4_clicked()
{

    // Set Database
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/Users/juanpostiglione/Desktop/Database/database_q.db");
    //mydb.setDatabaseName("C:/Users/david/Documents/Homework/Summer_2024/Group-5-Scooters-main/database_q.db");
    mydb.open();


    // When the databse is opened
    if(mydb.open())
    {
        qDebug() << "DB opened";
    }
    else
    {
        qDebug() << "DB not opened";
    }

    // Strings for username and password
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString status = "customer"; //"customer", "employee", or "administrator". Default status is "customer".

    //Check if username/password fields are empty
    bool fieldFilled = true;
    if(username == "" || password == "")
    {
        fieldFilled = false;
    }

    if(fieldFilled)
    {
        // Create a query
        QSqlQuery query(mydb);

        // Assign strings to database filters
        query.prepare("SELECT * FROM loginDetails WHERE username = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if(query.exec())
        {
            if(query.next())
            {
                //ui->label_8->hide();

                ui->label_8->setText("Valid username/password");
                ui->label_8->show();
                scooter_management s;
                s.setModal(true);
                this->close();
                s.exec();

            }
            else
            {
                // Show message for invalid credentials
                ui->label_8->setText("Invalid username or password");
                ui->label_8->show();
            }
        }
        query.finish();
    }
    else
    {
        //If username/password fields are empty
        ui->label_8->setText("Missing fields");
        ui->label_8->show();
    }
}



