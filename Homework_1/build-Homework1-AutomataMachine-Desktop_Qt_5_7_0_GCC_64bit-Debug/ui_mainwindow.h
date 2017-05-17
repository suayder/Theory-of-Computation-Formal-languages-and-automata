/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *InputAlphabet;
    QLabel *label;
    QPushButton *insertButton;
    QPushButton *merge;
    QLabel *label_2;
    QLineEdit *wordTest;
    QPushButton *check;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prefixe;
    QPushButton *suffixe;
    QPushButton *subword;
    QListWidget *listWidget;
    QPushButton *leave;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(338, 380);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        InputAlphabet = new QLineEdit(centralWidget);
        InputAlphabet->setObjectName(QStringLiteral("InputAlphabet"));
        InputAlphabet->setGeometry(QRect(10, 40, 211, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 111, 21));
        insertButton = new QPushButton(centralWidget);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(240, 40, 81, 22));
        merge = new QPushButton(centralWidget);
        merge->setObjectName(QStringLiteral("merge"));
        merge->setGeometry(QRect(90, 200, 131, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 220, 81, 16));
        wordTest = new QLineEdit(centralWidget);
        wordTest->setObjectName(QStringLiteral("wordTest"));
        wordTest->setGeometry(QRect(10, 240, 221, 22));
        check = new QPushButton(centralWidget);
        check->setObjectName(QStringLiteral("check"));
        check->setGeometry(QRect(240, 240, 80, 22));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 270, 311, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prefixe = new QPushButton(layoutWidget);
        prefixe->setObjectName(QStringLiteral("prefixe"));

        horizontalLayout->addWidget(prefixe);

        suffixe = new QPushButton(layoutWidget);
        suffixe->setObjectName(QStringLiteral("suffixe"));

        horizontalLayout->addWidget(suffixe);

        subword = new QPushButton(layoutWidget);
        subword->setObjectName(QStringLiteral("subword"));

        horizontalLayout->addWidget(subword);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 70, 311, 121));
        leave = new QPushButton(centralWidget);
        leave->setObjectName(QStringLiteral("leave"));
        leave->setGeometry(QRect(10, 300, 311, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 338, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(leave, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Homework 1", 0));
        label->setText(QApplication::translate("MainWindow", "Alphabet Input:", 0));
        insertButton->setText(QApplication::translate("MainWindow", "Insert", 0));
        merge->setText(QApplication::translate("MainWindow", "Merge Alphabets", 0));
        label_2->setText(QApplication::translate("MainWindow", "Word Test:", 0));
        check->setText(QApplication::translate("MainWindow", "Check", 0));
        prefixe->setText(QApplication::translate("MainWindow", "Prefixes", 0));
        suffixe->setText(QApplication::translate("MainWindow", "Suffixes", 0));
        subword->setText(QApplication::translate("MainWindow", "Subwords", 0));
        leave->setText(QApplication::translate("MainWindow", "Leave", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
