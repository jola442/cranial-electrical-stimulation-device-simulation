#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <random>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deviceOn = false;
    batteryLvl = 1;
    blinkTimer = new QTimer(this);
    connectionTimer = new QTimer(this);
    connectionStatus = 1;
    connectionCount = 0;
    blinkCount = 0;
    blinkingNum = 0;
    leftEarConnected = false;
    rightEarConnected = false;
    currentLabel = NULL;
    connect(blinkTimer, &QTimer::timeout, this, &MainWindow::blinkNumber);
    connect(connectionTimer, &QTimer::timeout, this, &MainWindow::displayConnectionStatus);
    connect(ui->powerButton, &QPushButton::pressed, this, &MainWindow::startPowerTimer);
    connect(ui->powerButton, &QPushButton::released, this, &MainWindow::selectPowerAction);
    connect(ui->leftEarButton, &QPushButton::released, this, &MainWindow::toggleLeftEarConnection);
    connect(ui->rightEarButton, &QPushButton::released, this, &MainWindow::toggleRightEarConnection);
    connect(ui->connectionTestButton, &QPushButton::released, this, &MainWindow::testConnection);
    // populate therapies
    // therapies[0] = new Therapy("MET", 0.5, 3.0);
    // therapies[1] = new Therapy("DELTA", 2.5, 5.0);
    // therapies[2] = new Therapy("THETA", 6.0, 8.0);
    // therapies[3] = new Therapy("ALPHA", 9.0, 11.0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//This function starts the timer that measures how long the powerButton is clicked for
void MainWindow::startPowerTimer(){
    powerTimer.start();
}

//This function determines the action of the power button depending on how long it is clicked for
void MainWindow::selectPowerAction(){
    if(powerTimer.elapsed() > 500){
        togglePower();
    }

    else{
        navigateSessionGroups();
    }
}

//This function switches the device on and off
void MainWindow::togglePower(){
    if(!deviceOn){
        if(batteryLvl > 0){
            ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/powerOn.svg)");
            deviceOn = true;
            displayBattery();
            displayLabels();
        }
    }

    else{
        ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/powerOff.svg)");
        deviceOn = false;
        leftEarConnected = false;
        rightEarConnected = false;
        hideBattery();
        hideLabels();
    }


}

void MainWindow::displaySessionLabel(QLabel* label){

    if(label == ui->twentyMinsLabel){
        ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSession.svg)");
    }

    else if(label == ui->fortyFiveMinsLabel){
        ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSession.svg)");
    }

    else if(label == ui->customSessionLabel){
        ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/CustomSession.svg)");
    }
}

// void mainwindow::displaySessionLabels(){

//     ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSession.svg)");
//     ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSession.svg)");
//     ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/CustomSession.svg)");

//     ui->metLabel->setStyleSheet("border-image: url(:/images/icons/MET.svg)");
//     ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaOn.svg)");
//     ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaS.svg)");

//     ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/Theta.svg)");
// }

// void mainwindow:: hideSessionLabels(){

//     ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSession.svg)");
//     ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSession.svg)");
//     ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/customSession.svg)");

//     ui->metLabel->setStyleSheet("border-image: url(:/images/icons/MET.svg)");
//     ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaOn.svg)");
//     ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaS.svg)");

//     // change this to theta later
//     ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/Theta.svg)");


// }




void MainWindow::navigateSessionGroups(){
    if(currentLabel == NULL){
        currentLabel = ui->twentyMinsLabel;
        displaySessionLabel(currentLabel);
    }



    if(currentLabel == ui->twentyMinsLabel){
        ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSessionOff.svg)");
        currentLabel = ui->fortyFiveMinsLabel;
        displaySessionLabel(currentLabel);
    }


    else if(currentLabel == ui->fortyFiveMinsLabel){
        ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSessionOff.svg)");
        currentLabel = ui->customSessionLabel;
        displaySessionLabel(currentLabel);
    }

    else if(currentLabel == ui->customSessionLabel){
        ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/CustomSessionOff.svg)");
        currentLabel = ui->twentyMinsLabel;
        displaySessionLabel(currentLabel);
    }

}

//This function highlights parts of the number graph depending on the battery level of the device
void MainWindow::displayBattery(){
    if(batteryLvl > 0 && batteryLvl < 12.5){
        blinkingNum = 1;
        //calls blinkNumber() every 300 milliseconds
        blinkTimer->start(300);
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

//This function changes the colour of all icons their respective colours to grey
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

//This function changes the colour of all icons from grey to their respective colours
void MainWindow::displayLabels(){
//    ui->rightEarButton->setStyleSheet("border-image: url(:/images/icons/Right.svg)");
//    ui->leftEarButton->setStyleSheet("border-image: url(:/images/icons/Left.svg)");
//    ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnection.svg)");
//    ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/RightConnection.svg)");
    ui->tDCSLabel->setStyleSheet("color: rgba(255, 0, 0)");
    ui->zeroTwoFiveLabel->setStyleSheet("color: rgba(0, 255, 0)");
    ui->zeroFiveLabel->setStyleSheet("color: rgba(0, 255, 0)");
    ui->zeroSevenFiveLabel->setStyleSheet("color: rgba(0, 255, 0)");
    ui->oneZeroZeroLabel->setStyleSheet("color:yellow");
    ui->oneFiveZeroLabel->setStyleSheet("color:yellow");
    ui->twoZeroZeroLabel->setStyleSheet("color:yellow");
    ui->plusOneLabel->setStyleSheet("border-image: url(:/images/icons/PlusOne.svg)");
    ui->plusTwoLabel->setStyleSheet("border-image: url(:/images/icons/PlusTwo.svg)");
}

//This function changes the colour of all icons from their respective colours to grey
void MainWindow::hideLabels(){
    ui->rightEarButton->setStyleSheet("border-image: url(:/images/icons/RightOff.svg)");
    ui->leftEarButton->setStyleSheet("border-image: url(:/images/icons/LeftOff.svg)");
    ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnectionOff.svg)");
    ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnectionOff.svg)");
    ui->tDCSLabel->setStyleSheet("color: rgba(200, 200, 200)");
    ui->zeroTwoFiveLabel->setStyleSheet("color: rgba(200, 200, 200)");
    ui->zeroFiveLabel->setStyleSheet("color: rgba(200, 200, 200)");;
    ui->zeroSevenFiveLabel->setStyleSheet("color: rgba(200, 200, 200)");
    ui->oneZeroZeroLabel->setStyleSheet("color: rgba(200, 200, 200)");
    ui->oneFiveZeroLabel->setStyleSheet("color: rgba(200, 200, 200)");
    ui->twoZeroZeroLabel->setStyleSheet("color: rgba(200, 200, 200)");
    ui->plusOneLabel->setStyleSheet("border-image: url(:/images/icons/PlusOneOff.svg)");
    ui->plusTwoLabel->setStyleSheet("border-image: url(:/images/icons/PlusTwoOff.svg)");
}

//This function causes the label corresponding to blinkingNum to blink
void MainWindow::blinkNumber(){
    QString blinkingStyleSheet = "";
    QString normalStyleSheet = "";
    QLabel* label = NULL;

    switch (blinkingNum){
        case 1:
            label = ui->oneLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/OneFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/One.svg)";
            break;
        case 2:
            label = ui->twoLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/TwoFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Two.svg)";
            break;
        case 3:
            label = ui->threeLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/ThreeFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Three.svg)";
            break;
        case 4:
            label = ui->fourLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/FourFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Four.svg)";
            break;
        case 5:
            label = ui->fiveLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/FiveFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Five.svg)";
            break;
        case 6:
            label = ui->sixLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/SixFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Six.svg)";
            break;
        case 7:
            label = ui->sevenLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/SevenFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Seven.svg)";
            break;
        case 8:
            label = ui->eightLabel;
            blinkingStyleSheet =  "border-image: url(:/images/icons/EightFlashing.svg)";
            normalStyleSheet = "border-image: url(:/images/icons/Eight.svg)";
            break;
    }

    if(blinkCount < 10){
        if(blinkCount % 2 == 0){
           label->setStyleSheet(blinkingStyleSheet);
        }
        else{
            label->setStyleSheet(normalStyleSheet);
        }
        blinkCount++;
    }

    else{
        blinkTimer->stop();
        blinkCount = 0;
    }
}

//This function switches the left ear icons on and off
void MainWindow::toggleLeftEarConnection(){
    if(!deviceOn){
        return;
    }

    if(leftEarConnected){
        ui->leftEarButton->setStyleSheet("border-image:url(:/images/icons/LeftOff.svg)");
        ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnectionOff.svg)");
        leftEarConnected = false;
        connectionStatus = 1;
    }

    else{
        ui->leftEarButton->setStyleSheet("border-image:url(:/images/icons/Left.svg)");
        ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnection.svg)");
        leftEarConnected = true;
    }
}

//This function switches the right ear icons on and off
void MainWindow::toggleRightEarConnection(){
    if(!deviceOn){
        return;
    }

    if(rightEarConnected){
        ui->rightEarButton->setStyleSheet("border-image:url(:/images/icons/RightOff.svg)");
        ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/RightConnectionOff.svg)");
        rightEarConnected = false;
        connectionStatus = 1;
    }

    else{
        ui->rightEarButton->setStyleSheet("border-image:url(:/images/icons/Right.svg)");
        ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/RightConnection.svg)");
        rightEarConnected = true;
    }
}

//This function displays the connection status of the ear clips
void MainWindow::displayConnectionStatus(){
    if(connectionCount >= 10){
        connectionTimer->stop();
        connectionCount = 0;
        //After the connection status is displayed, grey out all numbers and display the battery again
        hideBattery();
        displayBattery();
    }

    else{
        connectionCount++;
        if(connectionStatus == 1){
            if(connectionCount % 2 == 0){
               ui->sevenLabel->setStyleSheet("border-image: url(:/images/icons/SevenFlashing.svg)");
               ui->eightLabel->setStyleSheet("border-image: url(:/images/icons/EightFlashing.svg)");
            }
            else{
                ui->sevenLabel->setStyleSheet("border-image: url(:/images/icons/Seven.svg)");
                ui->eightLabel->setStyleSheet("border-image: url(:/images/icons/Eight.svg)");
            }
        }

        else if(connectionStatus == 2){
            ui->sixLabel->setStyleSheet("border-image: url(:/images/icons/Six.svg)");
            ui->fiveLabel->setStyleSheet("border-image: url(:/images/icons/Five.svg)");
            ui->fourLabel->setStyleSheet("border-image: url(:/images/icons/Four.svg)");
        }

        else if(connectionStatus == 3){
            ui->oneLabel->setStyleSheet("border-image: url(:/images/icons/One.svg)");
            ui->twoLabel->setStyleSheet("border-image: url(:/images/icons/Two.svg)");
            ui->threeLabel->setStyleSheet("border-image: url(:/images/icons/Three.svg)");
        }
    }


}

//This function determines the connection status of the ear clips and displays it by starting the connectionTimer
void MainWindow::testConnection(){
    //Grey out all numbers because only a maximum of 3 numbers will be lit during the connection test
    hideBattery();

    //If only one ear is connected, the connection status is 1 (No Connection)
    if(!leftEarConnected || !rightEarConnected){
        connectionStatus = 1;

    }

    else{
        //Connection status is assigned the value 2 (Okay Connection) or 3 (Excellent Connection) randomly
        srand(time(NULL));
        connectionStatus = (rand() % 2)+2;
    }

    //calls displayConnectionStatus() every 300ms
    connectionTimer->start(300);
}
