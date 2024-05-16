#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QRegExp>
#include <QMessageBox>
#include <algorithm>

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

    int amountOfLowerLetters = ui->spinBox_lower->value();
    int amountOfUpperLetters = ui->spinBox_upper->value();
    int amountOfNumberLetters = ui->spinBox_numbers->value();
    int amountOfSymbolLetters = ui->spinBox_symbols->value();

    QString letters = "abcdefghijklmnopqrstuvwxyz";
    QString upperLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString numbers = "0123456789";
    QString symbols = "!@#$%^&*()~,./;:?[]{}-_+=|<>";
    QString password;

    if(!(ui->spinBox->value() >= amountOfLowerLetters + amountOfUpperLetters +
            amountOfNumberLetters + amountOfSymbolLetters))
    {
        QMessageBox msgBox;
        msgBox.setText("Число конкретних символів не може перевищувати загальну довжину паролю!");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
    }
    else {
        for(int i = 0; i < passwordLength; i++)
        {
            if (password.length() < passwordLength)
            {
                if(isLower && amountOfLowerLetters > 0)
                {
                    password.push_back(letters[rand() % 26]);
                    amountOfLowerLetters--;
                }

                if(isUpper && amountOfUpperLetters > 0)
                {
                    password.push_back(upperLetters[rand() % 26]);
                    amountOfUpperLetters--;
                }

                if(isNumbers && amountOfNumberLetters > 0)
                {
                    password.push_back(numbers[rand() % 10]);
                    amountOfNumberLetters--;
                }

                if(isSymbols && amountOfSymbolLetters > 0)
                {
                    password.push_back(symbols[rand() % 28]);
                    amountOfSymbolLetters--;
                }
            }
        }

        if (password.length() < passwordLength)
        {
            for(int i = 0; i <= passwordLength - password.length(); i++)
            {
                if(isLower && password.length() < passwordLength)
                {
                    password.push_back(letters[rand() % 26]);
                }

                if(isUpper && password.length() < passwordLength)
                {
                    password.push_back(upperLetters[rand() % 26]);
                }

                if(isNumbers && password.length() < passwordLength)
                {
                    password.push_back(numbers[rand() % 10]);
                }

                if(isSymbols && password.length() < passwordLength)
                {
                    password.push_back(symbols[rand() % 28]);
                }
            }
        }

        std::random_shuffle(std::begin(password), std::end(password));
    }

    ui->lineEdit->setText(password);
}
