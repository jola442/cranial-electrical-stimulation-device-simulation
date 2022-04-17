#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <QtWidgets>

#include "session.h"
#include "record.h"
#define BATTERY_DRAIN 0.026
//1 bar of battery is required for a 20 min session
//battery depletion is dependent on connection to skin, intensity and duration of the session
//BATTERY_DRAIN must be 0.026 in order for a 20 min session with 8 intensity and excellent connection to skin (connectionStatus = 3) to deplete 12.5 battery
//see drainBattery(Session*) for how the battery is depleted

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    float batteryLvl;           //the battery level of the device
    bool deviceOn;              //whether the device is on or off
    QTimer* sessionTimer;       //measures and keeps track of how long a session is
    QElapsedTimer powerTimer;   //measures how long the powerButton is pressed
    QTimer* blinkTimer;         //regulates how long a number is blinked for
    QTimer* connectionTimer;    //regulates how long the connection status is displayed
    int connectionStatus;       //1.No Connection 2. Okay Connection. 3. Excellent Connection
    int blinkCount;             //how long a number has blinked for (blinkCount * blinkTimer->interval)
    int connectionCount;        //how long connection status has been displayed for (connectionCount * connectionTimer->interval)
    int blinkingNum;            //the number that is being blinked (1-8)
    int sessionTimerCount;      //how many seconds the current session has lasted
    bool leftEarConnected;      //whether the left ear is connected or not
    bool rightEarConnected;     //whether the right ear is connected or not
    bool sessionInProgress;     //whether the user is currently being treated or not
    QLabel* currentGroup;
    QLabel* currentSession;
    Session* session;           //the active session
    int operation; //1 is to select session, 2 is to select intensity, 3 is to go up and down in history
    sessionNumType type;        //the session type of the session the user wants to create
    Record r;
    void displayBattery();
    void hideBattery();
    void displayLabels();
    void hideLabels();
    void hideSessionLabels();
    void togglePower();
    void blinkNumber();
    void navigateSessionGroups();
    void displaySessionGroup(QLabel* label);
    void testConnection();
    void displayConnectionStatus();
    void selectUpButtonAction();
    void selectDownButtonAction();
    void displaySession();
    void startSession();
    void powerOff();
    void powerOn();
    void showIntensity(int);
    void assignSession(int);
    void hideGroupAndSessionLabels();
    void hideSessionTypeLabels();
    void drainBattery();
    void saveSession();
    int previousSession();
    int nextSession();

private slots:
    void startPowerTimer();
    void selectPowerAction();
    void toggleLeftEarConnection();
    void toggleRightEarConnection();
    void displayHistory();
    void confirmSelection();
    void updateSessionTimerCount();
};
#endif // MAINWINDOW_H
