#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <random>
#include <iostream>
#include <string>

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
    sessionTimer = new QTimer(this);
    connectionStatus = 1;
    connectionCount = 0;
    sessionTimerCount = 0;
    blinkCount = 0;
    blinkingNum = 0;
    type = NON;
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
    connect(sessionTimer, &QTimer::timeout, this, &MainWindow::updateSessionTimerCount);
    connect(ui->powerButton, &QPushButton::pressed, this, &MainWindow::startPowerTimer);
    connect(ui->powerButton, &QPushButton::released, this, &MainWindow::selectPowerAction);
    connect(ui->leftEarButton, &QPushButton::released, this, &MainWindow::toggleLeftEarConnection);
    connect(ui->rightEarButton, &QPushButton::released, this, &MainWindow::toggleRightEarConnection);
    connect(ui->historyButton, &QPushButton::released, this, &MainWindow::displayHistory);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete session;
}

//This function starts the timer for the power button
void MainWindow::startPowerTimer(){
    powerTimer.start();
}

//This function determines takes into account the time that the power button was pressed for and performs the appropriate step
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

//This function is responsible for turning the device on or off
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

//This function performs all the required steps to achieve the state when the device is turned off
//disabling buttons
//changing ui
//resetting variables and timers
void MainWindow::powerOff(){
    ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/PowerOff.svg)");
    ui->historyListWidget->setVisible(false);
    sessionInProgress = false;
    deviceOn = false;
    leftEarConnected = false;
    rightEarConnected = false;
    blinkTimer->stop();
    connectionTimer->stop();
    blinkCount = 0;
    connectionCount = 0;
    hideBattery();
    hideLabels();
    hideGroupAndSessionLabels();

    if(session->getDuration() != 0){
        if(session->getDuration() == 1){
            session->setDuration(sessionTimerCount);
        }

        //for 20 and 45 minute sessions, the battery is drained at once
        else{
            drainBattery();
        }

        saveSession();
        type = NON;
        sessionTimerCount = 0;
        session->setDuration(0);
        session->setIntensity(1);
        session->setType(type);
        currentGroup = NULL;
        currentSession = NULL;
    }

}


//This function performs all the required steps to achieve the state when the device is turned on
//enabling buttons
//changing ui
//setting variables and timers
void MainWindow::powerOn(){
    deviceOn = true;
    operation = 1;
    ui->powerLabel->setStyleSheet("border-image: url(:/images/icons/Power.svg)");
    ui->historyButton->setText("HISTORY");
    displayBattery();
    displayLabels();
}



//this function is responsible for highlighting the current selection of the group
//changes ui
//sets label
void MainWindow::displaySessionGroup(QLabel* label){

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



//this function is hides all the groups and sessions,
//sets an off image (meaning no group or session is selected)
 void MainWindow:: hideGroupAndSessionLabels(){

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

 //this function displays the currently selected session.
void MainWindow::displaySession(){
    if(!deviceOn){return;}

    if(currentSession == NULL){
        currentSession = ui->metLabel;
        hideSessionLabels();
        ui->metLabel->setStyleSheet("border-image: url(:/images/icons/MET.svg)");
    }

    else if(currentSession == ui->metLabel){
        hideSessionLabels();
        ui->metLabel->setStyleSheet("border-image: url(:/images/icons/MET.svg)");

    }

    else if(currentSession == ui->subDeltaLabel){
        hideSessionLabels();
        ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaS.svg)");
    }

    else if(currentSession == ui->deltaLabel){
        hideSessionLabels();
        ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/Delta.svg)");
    }
    else if(currentSession == ui->thetaLabel){
        hideSessionLabels();
        ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/Theta.svg)");
    }

}


//this functions hides all the session labels, meaning no session is currently selected.
void MainWindow::hideSessionLabels()
{
    ui->thetaLabel->setStyleSheet("border-image: url(:/images/icons/ThetaOff.svg)");
    ui->deltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaOff.svg)");
    ui->subDeltaLabel->setStyleSheet("border-image: url(:/images/icons/DeltaSOff.svg)");
    ui->metLabel->setStyleSheet("border-image: url(:/images/icons/METOff.svg)");

}


//this function keeps a track of the group selection from the device.
//also keeps battery level in check
void MainWindow::navigateSessionGroups(){
    if(!deviceOn){return;}

    if(batteryLvl >= 12.5){

        if(currentGroup == NULL){
            currentGroup = ui->twentyMinsLabel;
//            qDebug() << "current group = twenty mins";
            displaySessionGroup(currentGroup);
            return;
        }

        else if(currentGroup == ui->customSessionLabel){
            ui->customSessionLabel->setStyleSheet("border-image: url(:/images/icons/CustomSessionOff.svg)");
            currentGroup = ui->twentyMinsLabel;
//            qDebug() << "current group = twenty mins";
            displaySessionGroup(currentGroup);
            return;
        }
    }

    if (batteryLvl >= 25){
        if(currentGroup == ui->twentyMinsLabel){
            ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSessionOff.svg)");
//            qDebug() << "current group = forty five mins";
            currentGroup = ui->fortyFiveMinsLabel;
            displaySessionGroup(currentGroup);
            return;
        }
    }

    if(batteryLvl > 0){
        if(currentGroup == ui->fortyFiveMinsLabel){
            ui->fortyFiveMinsLabel->setStyleSheet("border-image: url(:/images/icons/45minSessionOff.svg)");
            currentGroup = ui->customSessionLabel;
//            qDebug() << "current group = custom";
            displaySessionGroup(currentGroup);
            return;
        }

        else if(currentGroup == ui->twentyMinsLabel){
             ui->twentyMinsLabel->setStyleSheet("border-image: url(:/images/icons/20minSessionOff.svg)");
             currentGroup = ui->customSessionLabel;
             qDebug() << "current group = custom";
             displaySessionGroup(currentGroup);
             return;
        }

        else if(currentGroup == NULL){
            currentGroup = ui->customSessionLabel;
            qDebug() << "current group = custom";
            displaySessionGroup(currentGroup);
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
//If the user has chosen a session group and number, this function calls testConnection()
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
//the connection of the device depends on these
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
        return;
    }

    else if(ui->historyListWidget->isVisible()){
        ui->historyButton->setText("HISTORY");
        ui->historyListWidget->setVisible(false);
        operation=1;

    }

    else{
        ui->historyButton->setText("HOME");
        ui->historyListWidget->setVisible(true);
        operation = 3;
    }


}

//This function determines what functionality downButton will have
//history navigation
//intensity
//sessions
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
            assignSession(previousSession());
            displaySession();
        }

    }
}

//This function determines what functionality upButton will have
//history navigation
//intensity
//sessions
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
            assignSession(nextSession());
            displaySession();
        }

    }
}

//this functions is used to show the intensity to the user in between a session
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

//this functions assigns the sessions when the user is navigating through them
void MainWindow::assignSession(int num)
{
    switch(num){
    case MET:
        currentSession = ui->metLabel;
//        qDebug() << "current session = met";
        break;
    case SUBDELTA:
        currentSession = ui->subDeltaLabel;
//        qDebug() << "current session = subdelta";
        break;
    case DELTA:
        currentSession = ui->deltaLabel;
//        qDebug() << "current session = delta";
        break;
    case THETA:
        currentSession = ui->thetaLabel;
//        qDebug() << "current session = theta";
        break;
    default:
        currentSession = ui->metLabel;
    }


}

//This function blinks the current session number
void MainWindow::confirmSelection(){
    if(currentSession == NULL){
        return;
    }

    displayBattery();
    displayLabels();


    hideBattery();
    blinkingNum = type;
    blinkTimer->start(300);
}

//This function initializes a session based on the user's choices and starts timers for the session
void MainWindow::startSession(){
    sessionInProgress = true;
    operation = 2;

    if(currentGroup == ui->twentyMinsLabel){
        session->setDuration(20);
    }

    else if(currentGroup == ui->fortyFiveMinsLabel){
        session->setDuration(45);
    }

    //Set the custom session's duration to 1 so it can be drained every second
    else{
        session->setDuration(1);
    }
    sessionTimer->start(1000);
}


//This function is called by the sessionTimer every second. It counts how long the session has lasted and it determines whether to turn off device or leave it on.
void MainWindow::updateSessionTimerCount(){
    if(batteryLvl <= 1){
        sessionTimer->stop();
        powerOff();
    }

    ++sessionTimerCount;
    if(session->getDuration() == 20 || session->getDuration() == 45){
        if(sessionTimerCount == session->getDuration()){
            sessionTimer->stop();
            powerOff();
        }
    }

    else{
        drainBattery();
    }


}

//This function depletes the device's battery according to the connection strength, duration and intensity of the active session
void MainWindow::drainBattery(){
    batteryLvl -= (BATTERY_DRAIN * connectionStatus * session->getIntensity() * session->getDuration());
}

//This function records a session
void MainWindow::saveSession(){
        QString sessionString;
        if(currentSession == ui->metLabel){
            session->setType(MET);
            sessionString = "MET";
        }

        else if(currentSession == ui->subDeltaLabel){
            session->setType(SUBDELTA);
            sessionString = "SUBDELTA";
        }

        else if(currentSession == ui->deltaLabel){
            session->setType(DELTA);
            sessionString = "DELTA";
        }

        else{
            session->setType(THETA);
            sessionString = "THETA";
        }

        r.saveRecords(session);
        r.createRecord(&session);
        int inten = session->getIntensity();
        QString date = QDateTime::currentDateTime().toString("ddd MMMM d yyyy");
        QListWidgetItem* sessionWidget = new QListWidgetItem();
        //Time recorded is in seconds, multiply by 60 to get a minutes representation
        QString dur = QDateTime::fromTime_t(session->getDuration()*60).toUTC().toString("hh:mm:ss");
        sessionWidget->setText(QString("Date: %1\n Session Type: %2\n Duration: %3\n Intensity Level: %4").arg(date).arg(sessionString).arg(dur).arg(inten));
        ui->historyListWidget->addItem(sessionWidget);
}

//this function changes to the next session when up button is used
int MainWindow::nextSession(){
    if(type == MET)
    {
        type = SUBDELTA;
    }

    else if(type == SUBDELTA)
    {
        type = DELTA;
    }

    else if(type == DELTA)
    {
        type = THETA;
    }
    else
    {
        type = MET;
    }
    //cout<<type<<endl;
    return type;
}

//this function changes to the previous session when down button is used
int MainWindow::previousSession(){
    if(type == MET)
    {
        type = THETA;
    }

    else if(type == THETA)
    {
        type = DELTA;
    }

    else if(type == DELTA)
    {
        type = SUBDELTA;
    }
    else
    {
        type = MET;
    }

    //cout<<type<<endl;
    return type;
}
