/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *oasisSkeleton;
    QPushButton *powerButton;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *tickButton;
    QLabel *intensityLabel;
    QLabel *leftEarLabel;
    QLabel *rightEarLabel;
    QLabel *leftConnectionLabel;
    QLabel *twentyMinsLabel;
    QLabel *customSessionOff;
    QLabel *fortyFiveMinsLabel;
    QLabel *deltaLabel;
    QLabel *metLabel;
    QLabel *subDeltaLabel;
    QLabel *oneLabel;
    QLabel *twoLabel;
    QLabel *threeLabel;
    QLabel *fourLabel;
    QLabel *fiveLabel;
    QLabel *sixLabel;
    QLabel *eightLabel;
    QLabel *sevenLabel;
    QLabel *zeroTwoFiveLabel;
    QLabel *zeroFiveLabel;
    QLabel *zeroSevenFiveLabel;
    QLabel *oneZeroZeroLabel;
    QLabel *plusTwoLabel;
    QLabel *twoZeroZeroLabel;
    QLabel *oneFiveZeroLabel;
    QLabel *plusOneLabel;
    QLabel *tDCSLabel;
    QLabel *rightConnectionLabel;
    QLabel *deltaLabel_3;
    QLabel *powerLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        oasisSkeleton = new QGraphicsView(centralwidget);
        oasisSkeleton->setObjectName(QString::fromUtf8("oasisSkeleton"));
        oasisSkeleton->setGeometry(QRect(20, 40, 761, 491));
        oasisSkeleton->setStyleSheet(QString::fromUtf8("border-image:url(:/images/overlay/OasisProSkeleton.svg)\n"
"\n"
""));
        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(510, 400, 61, 51));
        powerButton->setStyleSheet(QString::fromUtf8("border-image:url(:/images/buttons/powerButton.svg)"));
        upButton = new QPushButton(centralwidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(410, 330, 61, 51));
        upButton->setStyleSheet(QString::fromUtf8("border-image:url(:/images/buttons/upButton.svg)\n"
""));
        downButton = new QPushButton(centralwidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(410, 400, 61, 51));
        downButton->setStyleSheet(QString::fromUtf8("border-image:url(:/images/buttons/downButton.svg)\n"
""));
        tickButton = new QPushButton(centralwidget);
        tickButton->setObjectName(QString::fromUtf8("tickButton"));
        tickButton->setGeometry(QRect(150, 400, 61, 51));
        tickButton->setStyleSheet(QString::fromUtf8("border-image:url(:/images/buttons/tickButton.svg)\n"
""));
        intensityLabel = new QLabel(centralwidget);
        intensityLabel->setObjectName(QString::fromUtf8("intensityLabel"));
        intensityLabel->setGeometry(QRect(410, 280, 61, 41));
        QFont font;
        font.setPointSize(25);
        intensityLabel->setFont(font);
        intensityLabel->setStyleSheet(QString::fromUtf8("color:yellow"));
        leftEarLabel = new QLabel(centralwidget);
        leftEarLabel->setObjectName(QString::fromUtf8("leftEarLabel"));
        leftEarLabel->setGeometry(QRect(440, 130, 41, 21));
        leftEarLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/LeftOff.svg)"));
        rightEarLabel = new QLabel(centralwidget);
        rightEarLabel->setObjectName(QString::fromUtf8("rightEarLabel"));
        rightEarLabel->setGeometry(QRect(500, 130, 41, 21));
        rightEarLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/RightOff.svg)"));
        leftConnectionLabel = new QLabel(centralwidget);
        leftConnectionLabel->setObjectName(QString::fromUtf8("leftConnectionLabel"));
        leftConnectionLabel->setGeometry(QRect(450, 110, 31, 16));
        leftConnectionLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/leftConnectionOff.svg)\n"
""));
        twentyMinsLabel = new QLabel(centralwidget);
        twentyMinsLabel->setObjectName(QString::fromUtf8("twentyMinsLabel"));
        twentyMinsLabel->setGeometry(QRect(180, 150, 41, 31));
        twentyMinsLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/20minSessionOff.svg)\n"
""));
        customSessionOff = new QLabel(centralwidget);
        customSessionOff->setObjectName(QString::fromUtf8("customSessionOff"));
        customSessionOff->setGeometry(QRect(300, 150, 41, 31));
        customSessionOff->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/CustomSessionOff.svg)\n"
""));
        fortyFiveMinsLabel = new QLabel(centralwidget);
        fortyFiveMinsLabel->setObjectName(QString::fromUtf8("fortyFiveMinsLabel"));
        fortyFiveMinsLabel->setGeometry(QRect(240, 150, 41, 31));
        fortyFiveMinsLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/45minSessionOff.svg)\n"
""));
        deltaLabel = new QLabel(centralwidget);
        deltaLabel->setObjectName(QString::fromUtf8("deltaLabel"));
        deltaLabel->setGeometry(QRect(260, 200, 21, 21));
        deltaLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/DeltaOff.svg)\n"
""));
        metLabel = new QLabel(centralwidget);
        metLabel->setObjectName(QString::fromUtf8("metLabel"));
        metLabel->setGeometry(QRect(160, 200, 41, 21));
        metLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/METOff.svg)\n"
""));
        subDeltaLabel = new QLabel(centralwidget);
        subDeltaLabel->setObjectName(QString::fromUtf8("subDeltaLabel"));
        subDeltaLabel->setGeometry(QRect(220, 200, 21, 21));
        subDeltaLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/DeltaSOff.svg)\n"
""));
        oneLabel = new QLabel(centralwidget);
        oneLabel->setObjectName(QString::fromUtf8("oneLabel"));
        oneLabel->setGeometry(QRect(260, 420, 41, 16));
        oneLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/OneOff.svg)\n"
""));
        twoLabel = new QLabel(centralwidget);
        twoLabel->setObjectName(QString::fromUtf8("twoLabel"));
        twoLabel->setGeometry(QRect(260, 400, 41, 16));
        twoLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/TwoOff.svg)\n"
""));
        threeLabel = new QLabel(centralwidget);
        threeLabel->setObjectName(QString::fromUtf8("threeLabel"));
        threeLabel->setGeometry(QRect(260, 380, 41, 16));
        threeLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/ThreeOff.svg)\n"
""));
        fourLabel = new QLabel(centralwidget);
        fourLabel->setObjectName(QString::fromUtf8("fourLabel"));
        fourLabel->setGeometry(QRect(260, 360, 41, 16));
        fourLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/FourOff.svg)\n"
""));
        fiveLabel = new QLabel(centralwidget);
        fiveLabel->setObjectName(QString::fromUtf8("fiveLabel"));
        fiveLabel->setGeometry(QRect(260, 340, 41, 16));
        fiveLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/FiveOff.svg)\n"
""));
        sixLabel = new QLabel(centralwidget);
        sixLabel->setObjectName(QString::fromUtf8("sixLabel"));
        sixLabel->setGeometry(QRect(260, 320, 41, 16));
        sixLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/SixOff.svg)\n"
""));
        eightLabel = new QLabel(centralwidget);
        eightLabel->setObjectName(QString::fromUtf8("eightLabel"));
        eightLabel->setGeometry(QRect(260, 280, 41, 16));
        eightLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/EightOff.svg)\n"
""));
        sevenLabel = new QLabel(centralwidget);
        sevenLabel->setObjectName(QString::fromUtf8("sevenLabel"));
        sevenLabel->setGeometry(QRect(260, 300, 41, 16));
        sevenLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/SevenOff.svg)\n"
""));
        zeroTwoFiveLabel = new QLabel(centralwidget);
        zeroTwoFiveLabel->setObjectName(QString::fromUtf8("zeroTwoFiveLabel"));
        zeroTwoFiveLabel->setGeometry(QRect(330, 420, 41, 16));
        QFont font1;
        font1.setPointSize(15);
        zeroTwoFiveLabel->setFont(font1);
        zeroTwoFiveLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        zeroFiveLabel = new QLabel(centralwidget);
        zeroFiveLabel->setObjectName(QString::fromUtf8("zeroFiveLabel"));
        zeroFiveLabel->setGeometry(QRect(330, 400, 41, 16));
        zeroFiveLabel->setFont(font1);
        zeroFiveLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        zeroSevenFiveLabel = new QLabel(centralwidget);
        zeroSevenFiveLabel->setObjectName(QString::fromUtf8("zeroSevenFiveLabel"));
        zeroSevenFiveLabel->setGeometry(QRect(330, 380, 41, 16));
        zeroSevenFiveLabel->setFont(font1);
        zeroSevenFiveLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        oneZeroZeroLabel = new QLabel(centralwidget);
        oneZeroZeroLabel->setObjectName(QString::fromUtf8("oneZeroZeroLabel"));
        oneZeroZeroLabel->setGeometry(QRect(330, 360, 41, 16));
        oneZeroZeroLabel->setFont(font1);
        oneZeroZeroLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        plusTwoLabel = new QLabel(centralwidget);
        plusTwoLabel->setObjectName(QString::fromUtf8("plusTwoLabel"));
        plusTwoLabel->setGeometry(QRect(340, 280, 21, 16));
        plusTwoLabel->setFont(font1);
        plusTwoLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/PlusTwoOff.svg)"));
        twoZeroZeroLabel = new QLabel(centralwidget);
        twoZeroZeroLabel->setObjectName(QString::fromUtf8("twoZeroZeroLabel"));
        twoZeroZeroLabel->setGeometry(QRect(330, 320, 41, 16));
        twoZeroZeroLabel->setFont(font1);
        twoZeroZeroLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        oneFiveZeroLabel = new QLabel(centralwidget);
        oneFiveZeroLabel->setObjectName(QString::fromUtf8("oneFiveZeroLabel"));
        oneFiveZeroLabel->setGeometry(QRect(330, 340, 41, 16));
        oneFiveZeroLabel->setFont(font1);
        oneFiveZeroLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        plusOneLabel = new QLabel(centralwidget);
        plusOneLabel->setObjectName(QString::fromUtf8("plusOneLabel"));
        plusOneLabel->setGeometry(QRect(340, 300, 21, 16));
        plusOneLabel->setFont(font1);
        plusOneLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/PlusOneOff.svg)"));
        tDCSLabel = new QLabel(centralwidget);
        tDCSLabel->setObjectName(QString::fromUtf8("tDCSLabel"));
        tDCSLabel->setGeometry(QRect(330, 250, 54, 17));
        tDCSLabel->setFont(font1);
        tDCSLabel->setStyleSheet(QString::fromUtf8("color:red"));
        rightConnectionLabel = new QLabel(centralwidget);
        rightConnectionLabel->setObjectName(QString::fromUtf8("rightConnectionLabel"));
        rightConnectionLabel->setGeometry(QRect(510, 110, 31, 16));
        rightConnectionLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/RightConnectionOff.svg)\n"
""));
        deltaLabel_3 = new QLabel(centralwidget);
        deltaLabel_3->setObjectName(QString::fromUtf8("deltaLabel_3"));
        deltaLabel_3->setGeometry(QRect(310, 200, 21, 21));
        deltaLabel_3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/ThetaOff.svg)\n"
""));
        powerLabel = new QLabel(centralwidget);
        powerLabel->setObjectName(QString::fromUtf8("powerLabel"));
        powerLabel->setGeometry(QRect(520, 380, 41, 16));
        powerLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/powerOff.svg)\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        powerButton->setText(QString());
        upButton->setText(QString());
        downButton->setText(QString());
        tickButton->setText(QString());
        intensityLabel->setText(QApplication::translate("MainWindow", "INT", nullptr));
        leftEarLabel->setText(QString());
        rightEarLabel->setText(QString());
        leftConnectionLabel->setText(QString());
        twentyMinsLabel->setText(QString());
        customSessionOff->setText(QString());
        fortyFiveMinsLabel->setText(QString());
        deltaLabel->setText(QString());
        metLabel->setText(QString());
        subDeltaLabel->setText(QString());
        oneLabel->setText(QString());
        twoLabel->setText(QString());
        threeLabel->setText(QString());
        fourLabel->setText(QString());
        fiveLabel->setText(QString());
        sixLabel->setText(QString());
        eightLabel->setText(QString());
        sevenLabel->setText(QString());
        zeroTwoFiveLabel->setText(QApplication::translate("MainWindow", "0.25", nullptr));
        zeroFiveLabel->setText(QApplication::translate("MainWindow", "0.50", nullptr));
        zeroSevenFiveLabel->setText(QApplication::translate("MainWindow", "0.75", nullptr));
        oneZeroZeroLabel->setText(QApplication::translate("MainWindow", "1.00", nullptr));
        plusTwoLabel->setText(QString());
        twoZeroZeroLabel->setText(QApplication::translate("MainWindow", "2.00", nullptr));
        oneFiveZeroLabel->setText(QApplication::translate("MainWindow", "1.50", nullptr));
        plusOneLabel->setText(QString());
        tDCSLabel->setText(QApplication::translate("MainWindow", "tDCS", nullptr));
        rightConnectionLabel->setText(QString());
        deltaLabel_3->setText(QString());
        powerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
