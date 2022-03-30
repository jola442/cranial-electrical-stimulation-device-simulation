#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deviceOn = false;
    batteryLvl = 100;
    connect(ui->powerButton, &QPushButton::pressed, this, &MainWindow::startPowerTimer);
    connect(ui->powerButton, &QPushButton::released, this, &MainWindow::selectPowerAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startPowerTimer(){
    powerTimer.start();
}

void MainWindow::selectPowerAction(){
    if(powerTimer.elapsed() > 500){
        togglePower();
    }

    else{
        navigateSessionGroups();
    }
}

void MainWindow::togglePower(){
    if(!deviceOn){
        if(batteryLvl > 0){
            ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/powerOn.svg)");
            deviceOn = true;
            displayBattery();
            displayEarConnections();
        }
    }

    else{
        ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/powerOff.svg)");
        deviceOn = false;
        hideBattery();
        hideEarConnections();
    }


}

void MainWindow::navigateSessionGroups(){

}

void MainWindow::displayBattery(){
    if(batteryLvl > 0 && batteryLvl < 12.5){
        ui->oneLabel->setStyleSheet("border-image: url(:/images/icons/One.svg)");
    }

    if(batteryLvl >= 12.5){
        ui->oneLabel->setStyleSheet("border-image: url(:/images/icons/One.svg)");
        ui->twoLabel->setStyleSheet("border-image: url(:/images/icons/Two.svg)");
    }

    if(batteryLvl >= 25){
        ui->threeLabel->setStyleSheet("border-image: url(:/images/icons/Three.svg)");
    }

    if(batteryLvl >= 37.5){
        ui->fourLabel->setStyleSheet("border-image: url(:/images/icons/Four.svg)");
    }

    if(batteryLvl >= 50){
        ui->fiveLabel->setStyleSheet("border-image: url(:/images/icons/Five.svg)");
    }

    if(batteryLvl >= 62.5){
        ui->sixLabel->setStyleSheet("border-image: url(:/images/icons/Six.svg)");
    }

    if(batteryLvl >= 75){
        ui->sevenLabel->setStyleSheet("border-image: url(:/images/icons/Seven.svg)");
    }

    if(batteryLvl >= 87.5){
        ui->eightLabel->setStyleSheet("border-image: url(:/images/icons/Eight.svg)");
    }

}

void MainWindow::hideBattery(){
    ui->oneLabel->setStyleSheet("border-image: url(:/images/icons/OneOff.svg)");
    ui->twoLabel->setStyleSheet("border-image: url(:/images/icons/TwoOff.svg)");
    ui->threeLabel->setStyleSheet("border-image: url(:/images/icons/ThreeOff.svg)");
    ui->fourLabel->setStyleSheet("border-image: url(:/images/icons/FourOff.svg)");
    ui->fiveLabel->setStyleSheet("border-image: url(:/images/icons/FiveOff.svg)");
    ui->sixLabel->setStyleSheet("border-image: url(:/images/icons/SixOff.svg)");
    ui->sevenLabel->setStyleSheet("border-image: url(:/images/icons/SevenOff.svg)");
    ui->eightLabel->setStyleSheet("border-image: url(:/images/icons/EightOff.svg)");

}

void MainWindow::displayEarConnections(){
    ui->rightEarLabel->setStyleSheet("border-image: url(:/images/icons/Right.svg)");
    ui->leftEarLabel->setStyleSheet("border-image: url(:/images/icons/Left.svg)");
    ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnection.svg)");
    ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/RightConnection.svg)");
}

void MainWindow::hideEarConnections(){
    ui->rightEarLabel->setStyleSheet("border-image: url(:/images/icons/RightOff.svg)");
    ui->leftEarLabel->setStyleSheet("border-image: url(:/images/icons/LeftOff.svg)");
    ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnectionOff.svg)");
    ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnectionOff.svg)");
}

