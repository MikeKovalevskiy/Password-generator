#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int passwordLength = ui->spinBox->value();
    bool isLower = ui->checkBox->isChecked();
    bool isUpper = ui->checkBox_upper->isChecked();
    bool isNumbers = ui->checkBox_numbers->isChecked();
    bool isSymbols = ui->checkBox_symbols->isChecked();

    QString letters = "abcdefghijklmnopqrstuvwxyz";
    QString upperLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString numbers = "0123456789";
    QString symbols = "!@#$%^&*()~,./;:?[]{}-_+=|<>";
    QString password;

    for(int i = 0; i < passwordLength; i++)
    {
        if (password.length() < passwordLength)
        {
            if(isLower)
                password.push_back(letters[rand() % 26]);

            if(isUpper)
                password.push_back(upperLetters[rand() % 26]);

            if(isNumbers)
                password.push_back(numbers[rand() % 10]);

            if(isSymbols)
                password.push_back(symbols[rand() % 28]);
        }
    }

    ui->lineEdit->setText(password);
}
