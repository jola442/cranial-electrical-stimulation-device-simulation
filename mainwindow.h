#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>

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
    float batteryLvl;   //the battery level of the device
    bool deviceOn;      //whether the device is on or off
    void displayBattery();
    void hideBattery();
    void displayLabels();
    void hideLabels();
    QElapsedTimer powerTimer;   //tracks how long the powerButton is pressed
    QTimer* blinkTimer;         //used to call blinkNumber() at regular intervals
    int blinkCount;             //tracks how many times a number on the number graph has blinked
    int blinkingNum;            //the number that is being blinked (1-8)
    void togglePower();
    void navigateSessionGroups();
    void blinkNumber();
    void navigateSessionGroups();
    void displaySessionLabel(QLabel* label);


    // Therapy* therapies[MAX_THERAPY_COUNT];

private slots:
    void startPowerTimer();
    void selectPowerAction();

};
#endif // MAINWINDOW_H
