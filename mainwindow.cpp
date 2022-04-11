#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <random>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    operation = 1;
    ui->setupUi(this);
    deviceOn = false;
    batteryLvl = 70;
    blinkTimer = new QTimer(this);
    connectionTimer = new QTimer(this);
    connectionStatus = 1;
    connectionCount = 0;
    blinkCount = 0;
    blinkingNum = 0;
    leftEarConnected = false;
    rightEarConnected = false;
    sessionInProgress = false;
    ui->historyListWidget->setVisible(false);
    currentGroup = NULL;
    currentSession = NULL;
    session = new Session();
    connect(ui->tickButton, &QPushButton::released, this, &MainWindow::confirmSelection);
    connect(ui->upButton, &QPushButton::released, this, &MainWindow::selectUpButtonAction);
    connect(ui->downButton, &QPushButton::released, this, &MainWindow::selectDownButtonAction);
    connect(blinkTimer, &QTimer::timeout, this, &MainWindow::blinkNumber);
    connect(connectionTimer, &QTimer::timeout, this, &MainWindow::displayConnectionStatus);
    connect(ui->powerButton, &QPushButton::pressed, this, &MainWindow::startPowerTimer);
    connect(ui->powerButton, &QPushButton::released, this, &MainWindow::selectPowerAction);
    connect(ui->leftEarButton, &QPushButton::released, this, &MainWindow::toggleLeftEarConnection);
    connect(ui->rightEarButton, &QPushButton::released, this, &MainWindow::toggleRightEarConnection);
    connect(ui->historyButton, &QPushButton::released, this, &MainWindow::displayHistory);
}

MainWindow::~MainWindow()
{
    delete ui;

    for(int i = 0; i < savedSessions.size(); ++i){
        delete savedSessions[i];
    }
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
        if(!sessionInProgress){
            navigateSessionGroups();
        }

    }
}

//This function switches the device on and off
void MainWindow::togglePower(){
    if(!deviceOn){
        if(batteryLvl > 0){
            powerOn();
            qDebug() << batteryLvl;
        }
    }

    else{
        powerOff();
    }


}

void MainWindow::powerOff(){
    ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/PowerOff.svg)");
    ui->historyListWidget->setVisible(false);
    sessionInProgress = false;
    deviceOn = false;
    leftEarConnected = false;
    rightEarConnected = false;
    currentGroup = NULL;
    currentSession = NULL;
    session->setType(NON);
    blinkTimer->stop();
    hideBattery();
    hideLabels();
    hideSessionLabels();

//    if(session->duration == 0){
//        session->duration = powerTimer.elapsed();
//        drainBattery(session);
//    }
}

void MainWindow::powerOn(){
    deviceOn = true;
    operation = 1;
    ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/Power.svg)");
    displayBattery();
    displayLabels();
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

 void MainWindow:: hideSessionLabels(){

     ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSessionOff.svg)");
     ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSessionOff.svg)");
     ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/CustomSessionOff.svg)");

     ui->metLabel->setStyleSheet("border-image: url(:/images/icons/METOff.svg)");
     ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaOff.svg)");
     ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaSOff.svg)");

     ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/ThetaOff.svg)");


 }


// battery for 20 min session -> at least 1 battery bar -> 12.5 percent
// battery for 45 min session -> at least 2 battery bars -> 25 percent


void MainWindow::lightUpGroups(){
    if(!deviceOn){return;}

    if(currentSession == NULL){
        currentSession = ui->metLabel;
        sessionOff();
        ui->metLabel->setStyleSheet("border-image: url(:/images/icons/MET.svg)");
    }

    else if(currentSession == ui->metLabel){
        currentSession = ui->subDeltaLabel;
        sessionOff();
        ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaS.svg)");

    }

    else if(currentSession == ui->subDeltaLabel){
        currentSession = ui->deltaLabel;
        sessionOff();
        ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/Delta.svg)");
    }

    else if(currentSession == ui->deltaLabel){
        currentSession = ui->thetaLabel;
        sessionOff();
        ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/Theta.svg)");
    }
    else if(currentSession == ui->thetaLabel){
        currentSession = ui->metLabel;
        sessionOff();
        ui->metLabel->setStyleSheet("border-image: url(:/images/icons/MET.svg)");
    }

}
void MainWindow::sessionOff()
{
    ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/ThetaOff.svg)");
    ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaOff.svg)");
    ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaSOff.svg)");
    ui->metLabel->setStyleSheet("border-image: url(:/images/icons/METOff.svg)");

}

void MainWindow::navigateSessionGroups(){
    if(!deviceOn){return;}

    if(batteryLvl >= 12.5){

        if(currentGroup == NULL){
            currentGroup = ui->twentyMinsLabel;
            displaySessionLabel(currentGroup);
            return;
        }

        else if(currentGroup == ui->customSessionLabel){
            ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/CustomSessionOff.svg)");
            currentGroup = ui->twentyMinsLabel;
            displaySessionLabel(currentGroup);
            return;
        }
    }

    if (batteryLvl >= 25){
        if(currentGroup == ui->twentyMinsLabel){
            ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSessionOff.svg)");
            currentGroup = ui->fortyFiveMinsLabel;
            displaySessionLabel(currentGroup);
            return;
        }
    }

    if(batteryLvl > 0){
        if(currentGroup == ui->fortyFiveMinsLabel){
            ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSessionOff.svg)");
            currentGroup = ui->customSessionLabel;
            displaySessionLabel(currentGroup);
            return;
        }

        else if(currentGroup == ui->twentyMinsLabel){
             ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSessionOff.svg)");
             currentGroup = ui->customSessionLabel;
             displaySessionLabel(currentGroup);
             return;
        }

        else if(currentGroup == NULL){
            currentGroup = ui->customSessionLabel;
            displaySessionLabel(currentGroup);
            return;
        }
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
    ui->historyButton->setStyleSheet("color:rgb(0,255,0);"
                                     "border:none;"
                                     "font-size: 20px");
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
    ui->historyButton->setStyleSheet("color:rgb(200,200,200);"
                                     "border:none;"
                                     "font-size: 20px");
    ui->rightEarButton->setStyleSheet("border-image: url(:/images/icons/RightOff.svg)");
    ui->leftEarButton->setStyleSheet("border-image: url(:/images/icons/LeftOff.svg)");
    ui->leftConnectionLabel->setStyleSheet("border-image: url(:/images/icons/LeftConnectionOff.svg)");
    ui->rightConnectionLabel->setStyleSheet("border-image: url(:/images/icons/RightConnectionOff.svg)");
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
    if(blinkingNum == 0){
        return;
    }

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

        if(currentGroup != NULL && currentSession != NULL){
            hideBattery();
            testConnection();
        }
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

        //After the connection status is displayed, grey out all number
        hideBattery();

        //If there is no connection, the session will not start
        if(connectionStatus == 1){
            sessionInProgress = false;
        }

        else{
            startSession();
        }
//        displayBattery();
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

//This function displays the history of treatments and changes the text of the historyButton
//from "HISTORY" to "HOME" and vice versa when appropriate
void MainWindow::displayHistory(){
    if(!deviceOn){
        return;
    }

    if(sessionInProgress){
        operation = 2;
    }

    else if(!ui->historyListWidget->isVisible()){
        ui->historyButton->setText("HOME");
        ui->historyListWidget->setVisible(true);
        operation = 3;
    }

    else{
        ui->historyButton->setText("HISTORY");
        ui->historyListWidget->setVisible(false);
        operation=1;
    }

    for(int i = 0; i < savedSessions.size(); ++i){
        sessionNumType type = savedSessions.at(i)->getType();
        float dur = savedSessions.at(i)->getDuration();
        int inten = savedSessions.at(i)->getIntensity();
        QListWidgetItem* testWidgetItem = new QListWidgetItem();
        testWidgetItem->setText(QString("Date: 08/26/200%1\n Session Type: %2\n Duration: %3\n Intensity Level: %4").arg(i).arg(type).arg(dur).arg(inten));
        ui->historyListWidget->addItem(testWidgetItem);
    }

}

//This function determines what functionality downButton will have
void MainWindow::selectDownButtonAction(){

    if(!deviceOn){
        return;
    }

    if(operation ==3 ) //navigate history
    {


        int nextRow = ui->historyListWidget->currentRow()+1;

        //Wrap around to the first item in the list view
        if(nextRow >= ui->historyListWidget->count()){
            nextRow = 0;
        }
        ui->historyListWidget->setCurrentRow(nextRow);
     }

    else if (operation ==2) //navigate intensity
    {
        int temp = session->decreaseIntensity();
        showIntensity(temp);
    }

    else //navigate sessions
    {
        if(currentGroup != NULL){
            assignSession(session->previousSession());
            lightUpGroups();
        }

    }
}

//This function determines what functionality upButton will have
void MainWindow::selectUpButtonAction(){
    if(!deviceOn){
        return;
    }


    if(operation ==3 ) //for navigating history
    {


        int nextRow = ui->historyListWidget->currentRow()-1;

        //Wrap around to the last item in the list view
        if(nextRow < 0){
            nextRow = ui->historyListWidget->count()-1;
        }
        ui->historyListWidget->setCurrentRow(nextRow);
     }

    else if (operation ==2) //in case for intensity
    {
        int temp = session->increaseIntensity();
        showIntensity(temp);

    }

    else //to naviagte sessions
    {
        if(currentGroup != NULL){
            assignSession(session->nextSession());
            lightUpGroups();
        }

    }
}


void MainWindow::showIntensity(int inten)
{
    hideBattery();
    switch (inten) {
    case 1:
        ui->oneLabel->setStyleSheet("border-image: url(:/images/icons/One.svg)");
        break;
    case 2:
        ui->twoLabel->setStyleSheet("border-image: url(:/images/icons/Two.svg)");
        break;
    case 3:
        ui->threeLabel->setStyleSheet("border-image: url(:/images/icons/Three.svg)");
        break;
    case 4:
        ui->fourLabel->setStyleSheet("border-image: url(:/images/icons/Four.svg)");
        break;
    case 5:
        ui->fiveLabel->setStyleSheet("border-image: url(:/images/icons/Five.svg)");
        break;
    case 6:
        ui->sixLabel->setStyleSheet("border-image: url(:/images/icons/Six.svg)");
        break;
    case 7:
        ui->sevenLabel->setStyleSheet("border-image: url(:/images/icons/Seven.svg)");
        break;
    case 8:
        ui->eightLabel->setStyleSheet("border-image: url(:/images/icons/Eight.svg)");
        break;
    default:
        break;
    }

}

void MainWindow::assignSession(int num)
{
    switch(num){
    case 0:
        currentSession = ui->thetaLabel;
        break;
    case 1:
        currentSession = ui->metLabel;
        break;
    case 2:
        currentSession = ui->subDeltaLabel;
        break;
    case 3:
        currentSession = ui->deltaLabel;
        break;
    default:
        currentSession = ui->metLabel;
        break;
    }


}

void MainWindow::confirmSelection(){
    if(currentSession == NULL){
        return;
    }

    displayBattery();
    displayLabels();


    hideBattery();
    blinkingNum = session->getType()+1;
    blinkTimer->start(300);
}

void MainWindow::startSession(){
    sessionInProgress = true;
    operation = 2;

    if(currentGroup == ui->twentyMinsLabel){
        session->duration = 20;
    }

    else if(currentGroup == ui->fortyFiveMinsLabel){
        session->duration = 45;
    }

    QTimer* t = new QTimer(this);

    connect(t, &QTimer::timeout, [=]{
        ui->tickButton->blockSignals(false);
        sessionInProgress = false;
        savedSessions.push_back(session);
        drainBattery(session);
        t->stop();
        powerOff();
    });

    ui->tickButton->blockSignals(true);


    if(session->duration == 20 || session->duration == 45){
        t->start(session->duration*1000);
    }

    else{
        powerTimer.start();
    }
}

void MainWindow::drainBattery(Session* ses){
    batteryLvl -= (BATTERY_DRAIN * connectionStatus * ses->getIntensity() * ses->getDuration());
}
