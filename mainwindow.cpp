#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstdlib>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int randomNumber(){
    int number = rand() % 10;
    return number;
}

int* passwordGenerator(int length){
    int randomPassword[15];
    if(length < 15){
        for (int i; i < length; i++){
            int num = randomNumber();
            randomPassword[i] = num;
        }
    } else {
           throw std::invalid_argument("Length must be under 15 Characters");
    }

    return randomPassword;
}
