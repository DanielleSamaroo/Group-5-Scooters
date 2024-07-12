#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    // Function for button position
    void buttonPosition();

    // Function for Label position
    void labelPosition();

    // Function for Line Text position
    void lineTextPosition();
    
    // Function for Font
    void setFontAttributes(int size, bool bold, bool italic);
    
    // Function to check if data is in database
    void loginDataBase();
    
    // Function to get the width of the window
    int windowWidth = this->width();
    
    // Function to get the heigth of the window
    int windowHeight = this->height();

private slots:
    
    // Function for Push Button 1 ( Login Button )
    void on_pushButton_clicked();
    
    // Function for Push Button 5 ( Back Button )
    void on_pushButton_5_clicked();
    
    // Function for Push Button 2 ( Sign up )
    void on_pushButton_2_clicked();
    
    // Function for Push Button 3 ( Create Account )
    void on_pushButton_3_clicked();
    
    // Function for Push Button 4 ( Next )
    void on_pushButton_4_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
