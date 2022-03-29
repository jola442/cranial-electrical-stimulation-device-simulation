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
    QLabel *sDeltaLabel;
    QLabel *deltaLabel;
    QLabel *alphaLabel;
    QLabel *betaOneLabel;
    QLabel *betaTwoLabel;
    QLabel *hundredHertzLabel;
    QLabel *onwLabel;
    QLabel *twoLabel;
    QLabel *threeLabel;
    QLabel *fourLabel;
    QLabel *fiveLabel;
    QLabel *sixLabel;
    QLabel *eightLabel_2;
    QLabel *eightLabel;
    QLabel *zeroTwoFiveLabel;
    QLabel *zerooFiveLabel;
    QLabel *zeroSevenFiveLabel;
    QLabel *onwZeroZeroLabel;
    QLabel *pluaTwoLabel;
    QLabel *twoZeroZeroLabe;
    QLabel *oneFiveZeroLabel;
    QLabel *pluaOneLabel;
    QLabel *tDCSLabel;
    QLabel *leftConnectionLabel_2;
    QLabel *deltaLabel_2;
    QLabel *deltaLabel_3;
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
        sDeltaLabel = new QLabel(centralwidget);
        sDeltaLabel->setObjectName(QString::fromUtf8("sDeltaLabel"));
        sDeltaLabel->setGeometry(QRect(190, 200, 21, 21));
        sDeltaLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/DeltaSOff.svg)\n"
""));
        deltaLabel = new QLabel(centralwidget);
        deltaLabel->setObjectName(QString::fromUtf8("deltaLabel"));
        deltaLabel->setGeometry(QRect(230, 200, 21, 21));
        deltaLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/DeltaOff.svg)\n"
""));
        alphaLabel = new QLabel(centralwidget);
        alphaLabel->setObjectName(QString::fromUtf8("alphaLabel"));
        alphaLabel->setGeometry(QRect(310, 200, 21, 21));
        alphaLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/AlphaOff.svg)\n"
""));
        betaOneLabel = new QLabel(centralwidget);
        betaOneLabel->setObjectName(QString::fromUtf8("betaOneLabel"));
        betaOneLabel->setGeometry(QRect(350, 200, 16, 21));
        betaOneLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/BetaOneOff.svg)\n"
""));
        betaTwoLabel = new QLabel(centralwidget);
        betaTwoLabel->setObjectName(QString::fromUtf8("betaTwoLabel"));
        betaTwoLabel->setGeometry(QRect(380, 200, 16, 21));
        betaTwoLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/BetaTwoOff.svg)\n"
""));
        hundredHertzLabel = new QLabel(centralwidget);
        hundredHertzLabel->setObjectName(QString::fromUtf8("hundredHertzLabel"));
        hundredHertzLabel->setGeometry(QRect(410, 200, 31, 21));
        hundredHertzLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/100HzOff.svg)\n"
""));
        onwLabel = new QLabel(centralwidget);
        onwLabel->setObjectName(QString::fromUtf8("onwLabel"));
        onwLabel->setGeometry(QRect(260, 420, 41, 16));
        onwLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/OneOff.svg)\n"
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
        eightLabel_2 = new QLabel(centralwidget);
        eightLabel_2->setObjectName(QString::fromUtf8("eightLabel_2"));
        eightLabel_2->setGeometry(QRect(260, 280, 41, 16));
        eightLabel_2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/EightOff.svg)\n"
""));
        eightLabel = new QLabel(centralwidget);
        eightLabel->setObjectName(QString::fromUtf8("eightLabel"));
        eightLabel->setGeometry(QRect(260, 300, 41, 16));
        eightLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/SevenOff.svg)\n"
""));
        zeroTwoFiveLabel = new QLabel(centralwidget);
        zeroTwoFiveLabel->setObjectName(QString::fromUtf8("zeroTwoFiveLabel"));
        zeroTwoFiveLabel->setGeometry(QRect(330, 420, 41, 16));
        QFont font1;
        font1.setPointSize(15);
        zeroTwoFiveLabel->setFont(font1);
        zeroTwoFiveLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        zerooFiveLabel = new QLabel(centralwidget);
        zerooFiveLabel->setObjectName(QString::fromUtf8("zerooFiveLabel"));
        zerooFiveLabel->setGeometry(QRect(330, 400, 41, 16));
        zerooFiveLabel->setFont(font1);
        zerooFiveLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        zeroSevenFiveLabel = new QLabel(centralwidget);
        zeroSevenFiveLabel->setObjectName(QString::fromUtf8("zeroSevenFiveLabel"));
        zeroSevenFiveLabel->setGeometry(QRect(330, 380, 41, 16));
        zeroSevenFiveLabel->setFont(font1);
        zeroSevenFiveLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        onwZeroZeroLabel = new QLabel(centralwidget);
        onwZeroZeroLabel->setObjectName(QString::fromUtf8("onwZeroZeroLabel"));
        onwZeroZeroLabel->setGeometry(QRect(330, 360, 41, 16));
        onwZeroZeroLabel->setFont(font1);
        onwZeroZeroLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        pluaTwoLabel = new QLabel(centralwidget);
        pluaTwoLabel->setObjectName(QString::fromUtf8("pluaTwoLabel"));
        pluaTwoLabel->setGeometry(QRect(340, 280, 21, 16));
        pluaTwoLabel->setFont(font1);
        pluaTwoLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/PlusTwoOff.svg)"));
        twoZeroZeroLabe = new QLabel(centralwidget);
        twoZeroZeroLabe->setObjectName(QString::fromUtf8("twoZeroZeroLabe"));
        twoZeroZeroLabe->setGeometry(QRect(330, 320, 41, 16));
        twoZeroZeroLabe->setFont(font1);
        twoZeroZeroLabe->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        oneFiveZeroLabel = new QLabel(centralwidget);
        oneFiveZeroLabel->setObjectName(QString::fromUtf8("oneFiveZeroLabel"));
        oneFiveZeroLabel->setGeometry(QRect(330, 340, 41, 16));
        oneFiveZeroLabel->setFont(font1);
        oneFiveZeroLabel->setStyleSheet(QString::fromUtf8("color: rgba(200,200, 200)"));
        pluaOneLabel = new QLabel(centralwidget);
        pluaOneLabel->setObjectName(QString::fromUtf8("pluaOneLabel"));
        pluaOneLabel->setGeometry(QRect(340, 300, 21, 16));
        pluaOneLabel->setFont(font1);
        pluaOneLabel->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/PlusOneOff.svg)"));
        tDCSLabel = new QLabel(centralwidget);
        tDCSLabel->setObjectName(QString::fromUtf8("tDCSLabel"));
        tDCSLabel->setGeometry(QRect(330, 250, 54, 17));
        tDCSLabel->setFont(font1);
        tDCSLabel->setStyleSheet(QString::fromUtf8("color:red"));
        leftConnectionLabel_2 = new QLabel(centralwidget);
        leftConnectionLabel_2->setObjectName(QString::fromUtf8("leftConnectionLabel_2"));
        leftConnectionLabel_2->setGeometry(QRect(510, 110, 31, 16));
        leftConnectionLabel_2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/RightConnectionOff.svg)\n"
""));
        deltaLabel_2 = new QLabel(centralwidget);
        deltaLabel_2->setObjectName(QString::fromUtf8("deltaLabel_2"));
        deltaLabel_2->setGeometry(QRect(150, 200, 21, 21));
        deltaLabel_2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/METOff.svg)\n"
""));
        deltaLabel_3 = new QLabel(centralwidget);
        deltaLabel_3->setObjectName(QString::fromUtf8("deltaLabel_3"));
        deltaLabel_3->setGeometry(QRect(270, 200, 21, 21));
        deltaLabel_3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/ThetaOff.svg)\n"
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
        sDeltaLabel->setText(QString());
        deltaLabel->setText(QString());
        alphaLabel->setText(QString());
        betaOneLabel->setText(QString());
        betaTwoLabel->setText(QString());
        hundredHertzLabel->setText(QString());
        onwLabel->setText(QString());
        twoLabel->setText(QString());
        threeLabel->setText(QString());
        fourLabel->setText(QString());
        fiveLabel->setText(QString());
        sixLabel->setText(QString());
        eightLabel_2->setText(QString());
        eightLabel->setText(QString());
        zeroTwoFiveLabel->setText(QApplication::translate("MainWindow", "0.25", nullptr));
        zerooFiveLabel->setText(QApplication::translate("MainWindow", "0.50", nullptr));
        zeroSevenFiveLabel->setText(QApplication::translate("MainWindow", "0.75", nullptr));
        onwZeroZeroLabel->setText(QApplication::translate("MainWindow", "1.00", nullptr));
        pluaTwoLabel->setText(QString());
        twoZeroZeroLabe->setText(QApplication::translate("MainWindow", "2.00", nullptr));
        oneFiveZeroLabel->setText(QApplication::translate("MainWindow", "1.50", nullptr));
        pluaOneLabel->setText(QString());
        tDCSLabel->setText(QApplication::translate("MainWindow", "tDCS", nullptr));
        leftConnectionLabel_2->setText(QString());
        deltaLabel_2->setText(QString());
        deltaLabel_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
