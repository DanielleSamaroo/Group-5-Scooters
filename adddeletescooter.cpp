#include "adddeletescooter.h"
#include "ui_adddeletescooter.h"
#include <QPixmap>

addDeleteScooter::addDeleteScooter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addDeleteScooter)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: rgb(1, 68, 3);");

    ui->frame->setStyleSheet("QFrame {" "background-color: black;" "}");

    ui->toolButton->setStyleSheet("QToolButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                  "}" "QToolButton:hover {" "background-color: orange;""}");

    ui->pushButton->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                  "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_3->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    ui->pushButton_4->setStyleSheet("QPushButton {" "color: white;" "background-color: grey;"  "padding: 3px;"
                                    "}" "QPushButton:hover {" "background-color: orange;""}");

    // Image of scooter to display in the window
    QPixmap image("/Users/juanpostiglione/Downloads/scooter.png");
    ui->label->setPixmap(image);

    ui->comboBox->hide();

}

addDeleteScooter::~addDeleteScooter()
{
    delete ui;
}
