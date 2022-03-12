/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QWidget *gridLayoutWidget;
    QGridLayout *fieldGridLayout;
    QLabel *Field1_1;
    QLabel *Field1_3;
    QLabel *Field3_4;
    QLabel *Field2_3;
    QLabel *Field3_0;
    QLabel *Field4_0;
    QLabel *Field4_2;
    QLabel *Field1_4;
    QLabel *Field1_2;
    QLabel *Field4_1;
    QLabel *Field4_3;
    QLabel *Field2_1;
    QLabel *Field0_1;
    QLabel *Field0_2;
    QLabel *Field3_1;
    QLabel *Field2_2;
    QLabel *Field2_4;
    QLabel *Field2_0;
    QLabel *Field0_4;
    QLabel *Field0_3;
    QLabel *Field1_0;
    QLabel *Field4_4;
    QLabel *Field3_3;
    QLabel *Field0_0;
    QLabel *Field3_2;
    QPushButton *playButton;
    QLabel *pointsLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(150, 50, 491, 441));
        fieldGridLayout = new QGridLayout(gridLayoutWidget);
        fieldGridLayout->setObjectName(QString::fromUtf8("fieldGridLayout"));
        fieldGridLayout->setContentsMargins(0, 0, 0, 0);
        Field1_1 = new QLabel(gridLayoutWidget);
        Field1_1->setObjectName(QString::fromUtf8("Field1_1"));
        Field1_1->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field1_1->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field1_1->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field1_1, 1, 1, 1, 1);

        Field1_3 = new QLabel(gridLayoutWidget);
        Field1_3->setObjectName(QString::fromUtf8("Field1_3"));
        Field1_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field1_3->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field1_3->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field1_3, 1, 3, 1, 1);

        Field3_4 = new QLabel(gridLayoutWidget);
        Field3_4->setObjectName(QString::fromUtf8("Field3_4"));
        Field3_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field3_4->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field3_4->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field3_4, 3, 4, 1, 1);

        Field2_3 = new QLabel(gridLayoutWidget);
        Field2_3->setObjectName(QString::fromUtf8("Field2_3"));
        Field2_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field2_3->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field2_3->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field2_3, 2, 3, 1, 1);

        Field3_0 = new QLabel(gridLayoutWidget);
        Field3_0->setObjectName(QString::fromUtf8("Field3_0"));
        Field3_0->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field3_0->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field3_0->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field3_0, 3, 0, 1, 1);

        Field4_0 = new QLabel(gridLayoutWidget);
        Field4_0->setObjectName(QString::fromUtf8("Field4_0"));
        Field4_0->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field4_0->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field4_0->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field4_0, 4, 0, 1, 1);

        Field4_2 = new QLabel(gridLayoutWidget);
        Field4_2->setObjectName(QString::fromUtf8("Field4_2"));
        Field4_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field4_2->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field4_2->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field4_2, 4, 2, 1, 1);

        Field1_4 = new QLabel(gridLayoutWidget);
        Field1_4->setObjectName(QString::fromUtf8("Field1_4"));
        Field1_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field1_4->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field1_4->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field1_4, 1, 4, 1, 1);

        Field1_2 = new QLabel(gridLayoutWidget);
        Field1_2->setObjectName(QString::fromUtf8("Field1_2"));
        Field1_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field1_2->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field1_2->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field1_2, 1, 2, 1, 1);

        Field4_1 = new QLabel(gridLayoutWidget);
        Field4_1->setObjectName(QString::fromUtf8("Field4_1"));
        Field4_1->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field4_1->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field4_1->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field4_1, 4, 1, 1, 1);

        Field4_3 = new QLabel(gridLayoutWidget);
        Field4_3->setObjectName(QString::fromUtf8("Field4_3"));
        Field4_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field4_3->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field4_3->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field4_3, 4, 3, 1, 1);

        Field2_1 = new QLabel(gridLayoutWidget);
        Field2_1->setObjectName(QString::fromUtf8("Field2_1"));
        Field2_1->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field2_1->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field2_1->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field2_1, 2, 1, 1, 1);

        Field0_1 = new QLabel(gridLayoutWidget);
        Field0_1->setObjectName(QString::fromUtf8("Field0_1"));
        Field0_1->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field0_1->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field0_1->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field0_1, 0, 1, 1, 1);

        Field0_2 = new QLabel(gridLayoutWidget);
        Field0_2->setObjectName(QString::fromUtf8("Field0_2"));
        Field0_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field0_2->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field0_2->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field0_2, 0, 2, 1, 1);

        Field3_1 = new QLabel(gridLayoutWidget);
        Field3_1->setObjectName(QString::fromUtf8("Field3_1"));
        Field3_1->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field3_1->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field3_1->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field3_1, 3, 1, 1, 1);

        Field2_2 = new QLabel(gridLayoutWidget);
        Field2_2->setObjectName(QString::fromUtf8("Field2_2"));
        Field2_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field2_2->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field2_2->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field2_2, 2, 2, 1, 1);

        Field2_4 = new QLabel(gridLayoutWidget);
        Field2_4->setObjectName(QString::fromUtf8("Field2_4"));
        Field2_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field2_4->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field2_4->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field2_4, 2, 4, 1, 1);

        Field2_0 = new QLabel(gridLayoutWidget);
        Field2_0->setObjectName(QString::fromUtf8("Field2_0"));
        Field2_0->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field2_0->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field2_0->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field2_0, 2, 0, 1, 1);

        Field0_4 = new QLabel(gridLayoutWidget);
        Field0_4->setObjectName(QString::fromUtf8("Field0_4"));
        Field0_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field0_4->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field0_4->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field0_4, 0, 4, 1, 1);

        Field0_3 = new QLabel(gridLayoutWidget);
        Field0_3->setObjectName(QString::fromUtf8("Field0_3"));
        Field0_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field0_3->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field0_3->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field0_3, 0, 3, 1, 1);

        Field1_0 = new QLabel(gridLayoutWidget);
        Field1_0->setObjectName(QString::fromUtf8("Field1_0"));
        Field1_0->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field1_0->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field1_0->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field1_0, 1, 0, 1, 1);

        Field4_4 = new QLabel(gridLayoutWidget);
        Field4_4->setObjectName(QString::fromUtf8("Field4_4"));
        Field4_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field4_4->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field4_4->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field4_4, 4, 4, 1, 1);

        Field3_3 = new QLabel(gridLayoutWidget);
        Field3_3->setObjectName(QString::fromUtf8("Field3_3"));
        Field3_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field3_3->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field3_3->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field3_3, 3, 3, 1, 1);

        Field0_0 = new QLabel(gridLayoutWidget);
        Field0_0->setObjectName(QString::fromUtf8("Field0_0"));
        Field0_0->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field0_0->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field0_0->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field0_0, 0, 0, 1, 1);

        Field3_2 = new QLabel(gridLayoutWidget);
        Field3_2->setObjectName(QString::fromUtf8("Field3_2"));
        Field3_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid black\n"
"}"));
        Field3_2->setPixmap(QPixmap(QString::fromUtf8("ressources/FieldIcon.png")));
        Field3_2->setAlignment(Qt::AlignCenter);

        fieldGridLayout->addWidget(Field3_2, 3, 2, 1, 1);

        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(300, 500, 211, 51));
        pointsLabel = new QLabel(centralwidget);
        pointsLabel->setObjectName(QString::fromUtf8("pointsLabel"));
        pointsLabel->setGeometry(QRect(340, 0, 111, 41));
        pointsLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:white\n"
"}"));
        pointsLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Field1_1->setText(QString());
        Field1_3->setText(QString());
        Field3_4->setText(QString());
        Field2_3->setText(QString());
        Field3_0->setText(QString());
        Field4_0->setText(QString());
        Field4_2->setText(QString());
        Field1_4->setText(QString());
        Field1_2->setText(QString());
        Field4_1->setText(QString());
        Field4_3->setText(QString());
        Field2_1->setText(QString());
        Field0_1->setText(QString());
        Field0_2->setText(QString());
        Field3_1->setText(QString());
        Field2_2->setText(QString());
        Field2_4->setText(QString());
        Field2_0->setText(QString());
        Field0_4->setText(QString());
        Field0_3->setText(QString());
        Field1_0->setText(QString());
        Field4_4->setText(QString());
        Field3_3->setText(QString());
        Field0_0->setText(QString());
        Field3_2->setText(QString());
        playButton->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
        pointsLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
