#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>

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
    float batteryLvl;
    bool deviceOn;
    void displayBattery();
    void hideBattery();
    void displayEarConnections();
    void hideEarConnections();
    QElapsedTimer powerTimer;
    void togglePower();
    void navigateSessionGroups();

private slots:
    void startPowerTimer();
    void selectPowerAction();

};
#endif // MAINWINDOW_H
