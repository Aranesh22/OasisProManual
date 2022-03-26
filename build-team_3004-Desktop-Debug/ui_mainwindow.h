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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *session_25min;
    QLabel *session_45min;
    QLabel *session_3hr;
    QLabel *session_custom;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *shortPulse_CESsession;
    QLabel *dutyCycle_CESsession;
    QLabel *left_CESchannel;
    QLabel *right_CESchannel;
    QLabel *label_18;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *col_num_8;
    QLabel *col_num_7;
    QLabel *col_num_6;
    QLabel *col_num_5;
    QLabel *col_num_4;
    QLabel *col_num_3;
    QLabel *col_num_2;
    QLabel *col_num_1;
    QPushButton *pushButton_8;
    QLabel *label_24;
    QPushButton *pushButton_9;
    QTableWidget *tableWidget;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1208, 536);
        MainWindow->setStyleSheet(QString::fromUtf8("background: black"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1211, 491));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background: black;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 370, 80, 71));
        pushButton_5->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/buttons/checkMark_Btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon);
        pushButton_5->setIconSize(QSize(75, 75));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(360, 289, 160, 170));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QString::fromUtf8("border: none"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/buttons/upArrow_Btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon1);
        pushButton_7->setIconSize(QSize(75, 75));

        verticalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/buttons/downArrow_Btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(75, 75));

        verticalLayout->addWidget(pushButton_6);

        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 20, 206, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        session_25min = new QLabel(horizontalLayoutWidget);
        session_25min->setObjectName(QString::fromUtf8("session_25min"));
        session_25min->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/session_times/icon_25Min.png")));

        horizontalLayout_2->addWidget(session_25min);

        session_45min = new QLabel(horizontalLayoutWidget);
        session_45min->setObjectName(QString::fromUtf8("session_45min"));
        session_45min->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/session_times/icon_45Min.png")));

        horizontalLayout_2->addWidget(session_45min);

        session_3hr = new QLabel(horizontalLayoutWidget);
        session_3hr->setObjectName(QString::fromUtf8("session_3hr"));
        session_3hr->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/session_times/icon_3Hour.png")));

        horizontalLayout_2->addWidget(session_3hr);

        session_custom = new QLabel(horizontalLayoutWidget);
        session_custom->setObjectName(QString::fromUtf8("session_custom"));
        session_custom->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/session_times/icon_customTime.png")));

        horizontalLayout_2->addWidget(session_custom);

        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(140, 110, 206, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        label_9 = new QLabel(horizontalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 10, 54, 61));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/icon_audioInput.png")));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 230, 54, 51));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/graph-icon.png")));
        formLayoutWidget_2 = new QWidget(frame);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(440, 20, 160, 80));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        shortPulse_CESsession = new QLabel(formLayoutWidget_2);
        shortPulse_CESsession->setObjectName(QString::fromUtf8("shortPulse_CESsession"));
        shortPulse_CESsession->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/icon_shortPulse_CESsession.png")));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, shortPulse_CESsession);

        dutyCycle_CESsession = new QLabel(formLayoutWidget_2);
        dutyCycle_CESsession->setObjectName(QString::fromUtf8("dutyCycle_CESsession"));
        dutyCycle_CESsession->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/icon_dutyCycle_CESsession.png")));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, dutyCycle_CESsession);

        left_CESchannel = new QLabel(formLayoutWidget_2);
        left_CESchannel->setObjectName(QString::fromUtf8("left_CESchannel"));
        left_CESchannel->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/icon_LeftCESchannel.png")));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, left_CESchannel);

        right_CESchannel = new QLabel(formLayoutWidget_2);
        right_CESchannel->setObjectName(QString::fromUtf8("right_CESchannel"));
        right_CESchannel->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/icon_RightCESchannel.png")));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, right_CESchannel);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(580, 130, 241, 181));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/res/logos/Logo_oasisPro.png")));
        verticalLayoutWidget_3 = new QWidget(frame);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(170, 230, 141, 231));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        col_num_8 = new QLabel(verticalLayoutWidget_3);
        col_num_8->setObjectName(QString::fromUtf8("col_num_8"));
        col_num_8->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_8.png")));

        verticalLayout_3->addWidget(col_num_8);

        col_num_7 = new QLabel(verticalLayoutWidget_3);
        col_num_7->setObjectName(QString::fromUtf8("col_num_7"));
        col_num_7->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_7.png")));

        verticalLayout_3->addWidget(col_num_7);

        col_num_6 = new QLabel(verticalLayoutWidget_3);
        col_num_6->setObjectName(QString::fromUtf8("col_num_6"));
        col_num_6->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_6.png")));

        verticalLayout_3->addWidget(col_num_6);

        col_num_5 = new QLabel(verticalLayoutWidget_3);
        col_num_5->setObjectName(QString::fromUtf8("col_num_5"));
        col_num_5->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_5.png")));

        verticalLayout_3->addWidget(col_num_5);

        col_num_4 = new QLabel(verticalLayoutWidget_3);
        col_num_4->setObjectName(QString::fromUtf8("col_num_4"));
        col_num_4->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_4.png")));

        verticalLayout_3->addWidget(col_num_4);

        col_num_3 = new QLabel(verticalLayoutWidget_3);
        col_num_3->setObjectName(QString::fromUtf8("col_num_3"));
        col_num_3->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_3.png")));

        verticalLayout_3->addWidget(col_num_3);

        col_num_2 = new QLabel(verticalLayoutWidget_3);
        col_num_2->setObjectName(QString::fromUtf8("col_num_2"));
        col_num_2->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_2.png")));

        verticalLayout_3->addWidget(col_num_2);

        col_num_1 = new QLabel(verticalLayoutWidget_3);
        col_num_1->setObjectName(QString::fromUtf8("col_num_1"));
        col_num_1->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_1.png")));

        verticalLayout_3->addWidget(col_num_1);

        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(520, 370, 158, 81));
        pushButton_8->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/buttons/power_Btn_unLit.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/res/buttons/powerBtn_lit.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_8->setIcon(icon3);
        pushButton_8->setIconSize(QSize(75, 75));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(420, 250, 81, 31));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/INT logo.png")));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(30, 290, 80, 71));
        pushButton_9->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/buttons/save_Btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon4);
        pushButton_9->setIconSize(QSize(75, 75));
        tableWidget = new QTableWidget(frame);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QBrush brush(QColor(238, 238, 236, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        __qtablewidgetitem1->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        __qtablewidgetitem2->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem3);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icons/Lit/sessionTimes/icon_25Min.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font1;
        font1.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font1);
        __qtablewidgetitem4->setIcon(icon5);
        tableWidget->setItem(0, 1, __qtablewidgetitem4);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/icons/Lit/colNumber/icon_5.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        __qtablewidgetitem5->setIcon(icon6);
        tableWidget->setItem(0, 2, __qtablewidgetitem5);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icons/unLit/session_times/icon_45Min.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem6->setIcon(icon7);
        tableWidget->setItem(1, 1, __qtablewidgetitem6);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icons/unLit/colNumbers/icon_7.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setIcon(icon8);
        tableWidget->setItem(1, 2, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(810, 70, 351, 281));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setStyleSheet(QString::fromUtf8("border: red solid"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setLineWidth(50);
        tableWidget->setMidLineWidth(50);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setIconSize(QSize(40, 40));
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setRowCount(4);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setMinimumSectionSize(45);
        tableWidget->horizontalHeader()->setDefaultSectionSize(115);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(45);
        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 10, 54, 51));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/res/icons/icon_audioInput.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1208, 22));
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
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        pushButton_6->setText(QString());
        session_25min->setText(QString());
        session_45min->setText(QString());
        session_3hr->setText(QString());
        session_custom->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "IMG", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "IMG", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "IMG", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "IMG", nullptr));
        label_11->setText(QString());
        label_12->setText(QString());
        shortPulse_CESsession->setText(QString());
        dutyCycle_CESsession->setText(QString());
        left_CESchannel->setText(QString());
        right_CESchannel->setText(QString());
        label_18->setText(QString());
        col_num_8->setText(QString());
        col_num_7->setText(QString());
        col_num_6->setText(QString());
        col_num_5->setText(QString());
        col_num_4->setText(QString());
        col_num_3->setText(QString());
        col_num_2->setText(QString());
        col_num_1->setText(QString());
        pushButton_8->setText(QString());
        label_24->setText(QString());
        pushButton_9->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Duration", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Intensity", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "img", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_13->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
