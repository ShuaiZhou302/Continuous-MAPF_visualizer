/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QListWidget *listWidget;
    QPushButton *paths_button;
    QPushButton *open_button;
    QPushButton *pause_button;
    QPushButton *restart_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *left_button;
    QPushButton *right_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(466, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_2->addWidget(graphicsView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(listWidget);

        paths_button = new QPushButton(centralWidget);
        paths_button->setObjectName("paths_button");

        verticalLayout->addWidget(paths_button);

        open_button = new QPushButton(centralWidget);
        open_button->setObjectName("open_button");

        verticalLayout->addWidget(open_button);

        pause_button = new QPushButton(centralWidget);
        pause_button->setObjectName("pause_button");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pause_button->sizePolicy().hasHeightForWidth());
        pause_button->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pause_button);

        restart_button = new QPushButton(centralWidget);
        restart_button->setObjectName("restart_button");
        sizePolicy1.setHeightForWidth(restart_button->sizePolicy().hasHeightForWidth());
        restart_button->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(restart_button);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        left_button = new QPushButton(centralWidget);
        left_button->setObjectName("left_button");

        horizontalLayout->addWidget(left_button);

        right_button = new QPushButton(centralWidget);
        right_button->setObjectName("right_button");

        horizontalLayout->addWidget(right_button);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 466, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        paths_button->setText(QCoreApplication::translate("MainWindow", "Show paths", nullptr));
        open_button->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pause_button->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        restart_button->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        left_button->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        right_button->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
