#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstdlib>
#include <stdexcept>
#include <QString>
#include <QMessageBox>
#include <vector>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    length(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int randomNumber(){
    int number = QRandomGenerator::global()->bounded(0,9);
    return number;
}

std::vector<int> passwordGenerator(int length){
    std::vector<int> randomPassword;
    if(length < 15){
        for (int i = 0; i < length; i++){
            int num = randomNumber();
            randomPassword.push_back(num);
        }
    } else {
           throw std::invalid_argument("Length must be under 15 Characters");
    }

    return randomPassword;
}

void MainWindow::on_pushButton_clicked()
{
    try {
        if (length > 15) {
            QMessageBox::warning(this, "Warning", "Length is too high. Max is 15");
        } else {
            std::vector<int> password = passwordGenerator(length);

            QString passwordString;

            for (int i = 0; i < length; i++) {
                if (i < password.size()) {
                    passwordString += QString::number(password[i]) + " ";
                } else {
                    // Handle the case where the index is out of range
                }
            }

            // Change password to string
            ui->textEdit->setText(passwordString);

            // Display password, in QT through text.
        }
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Warning", e.what());
    }
}

void MainWindow::on_passwordNumberPick_editingFinished()
{
    length = ui->passwordNumberPick->value();
}


QString MainWindow::passwordAlgorithm(QString word1){

    if (word1.isEmpty() || word1.isNull()){
         QMessageBox::warning(this, "Warning", "One or more word boxes are empty");
    }
    char characters[11] = {'!', '@', '#', '$', '%' , '^' , '&' , '&' , '*' , '/' , '.'};

    for(int i =2; i < word1.length(); i+= 3){
        int random = QRandomGenerator::global()->bounded(0,11);
        QChar characterToReplace = QChar(characters[random]);
        word1.replace(i, 1, QString(characterToReplace));

    }

    return word1;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString password;
    QString word1 = on_word1_text_textChanged();
    QString word2 = on_word2_text_textChanged();
    QString word3 = on_word3_text_textChanged();
    if (word1.isEmpty() || word2.isEmpty() || word3.isEmpty()) {
        return;
    }

    QString newWord1 = passwordAlgorithm(word1);
    QString newWord2 = passwordAlgorithm(word2);
    QString newWord3 = passwordAlgorithm(word3);

    password += newWord1;
    password += newWord2;
    password += newWord3;
    int number = rand() % 200;
    password += QString::number(number);
    ui->textEdit_2->setText(password);
}


QString MainWindow::on_word1_text_textChanged()
{
    QString text = ui->word1_text->toPlainText();

    return text;

}




QString MainWindow::on_word2_text_textChanged()
{
    QString text = ui->word2_text->toPlainText();

    return text;

}


QString MainWindow::on_word3_text_textChanged()
{
    QString text = ui->word3_text->toPlainText();

    return text;
}



void MainWindow::on_actionHelp_2_triggered()
{
    QMessageBox::warning(this, "Help", "<FONT COLOR='#9EC8B9'>For number passcode generation, select amount of numbers you would like (Max is 15). And click generate password. For phrasepass, add three words into the boxes above generate button. Click generate and it will return you a password using them 3 words.</FONT>");
}

