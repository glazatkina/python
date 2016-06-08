/********************************************************************************
** Form generated from reading UI file 'BarchelorsThesis.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHELORSTHESIS_H
#define UI_BARCHELORSTHESIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *actionCheckUpdates;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionConnectDB;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabDB;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableViewServerDB1;
    QLabel *label;
    QPushButton *btnOpenFolderDB1;
    QPushButton *btnRefreshDB1;
    QLabel *label_2;
    QPushButton *btnDeleteAllDB1;
    QTableView *tableViewLocalDB1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QTableView *tableViewServerDB2;
    QLabel *label_4;
    QTableView *tableViewLocalDB2;
    QPushButton *btnOpenFolderDB2;
    QPushButton *btnRefrechDB2;
    QPushButton *btnDeleteAllDB2;
    QWidget *tabGIS;
    QGridLayout *gridLayout_3;
    QPushButton *btnRefreshDB1_2;
    QLabel *label_6;
    QTableView *tableViewServerDB1_2;
    QTableView *tableViewLocalDB1_2;
    QLabel *label_5;
    QPushButton *btnDeleteAllDB1_2;
    QPushButton *btnOpenFolderDB1_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(698, 540);
        actionCheckUpdates = new QAction(mainWindow);
        actionCheckUpdates->setObjectName(QStringLiteral("actionCheckUpdates"));
        actionExit = new QAction(mainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(mainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(mainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionConnectDB = new QAction(mainWindow);
        actionConnectDB->setObjectName(QStringLiteral("actionConnectDB"));
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabDB = new QWidget();
        tabDB->setObjectName(QStringLiteral("tabDB"));
        horizontalLayout = new QHBoxLayout(tabDB);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(tabDB);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableViewServerDB1 = new QTableView(groupBox);
        tableViewServerDB1->setObjectName(QStringLiteral("tableViewServerDB1"));
        tableViewServerDB1->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(tableViewServerDB1, 1, 0, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        btnOpenFolderDB1 = new QPushButton(groupBox);
        btnOpenFolderDB1->setObjectName(QStringLiteral("btnOpenFolderDB1"));

        gridLayout->addWidget(btnOpenFolderDB1, 4, 0, 1, 1);

        btnRefreshDB1 = new QPushButton(groupBox);
        btnRefreshDB1->setObjectName(QStringLiteral("btnRefreshDB1"));

        gridLayout->addWidget(btnRefreshDB1, 4, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 3);

        btnDeleteAllDB1 = new QPushButton(groupBox);
        btnDeleteAllDB1->setObjectName(QStringLiteral("btnDeleteAllDB1"));

        gridLayout->addWidget(btnDeleteAllDB1, 4, 2, 1, 1);

        tableViewLocalDB1 = new QTableView(groupBox);
        tableViewLocalDB1->setObjectName(QStringLiteral("tableViewLocalDB1"));
        tableViewLocalDB1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewLocalDB1->setSortingEnabled(true);
        tableViewLocalDB1->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        gridLayout->addWidget(tableViewLocalDB1, 3, 0, 1, 3);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tabDB);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 3);

        tableViewServerDB2 = new QTableView(groupBox_2);
        tableViewServerDB2->setObjectName(QStringLiteral("tableViewServerDB2"));
        tableViewServerDB2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(tableViewServerDB2, 1, 0, 1, 3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 3);

        tableViewLocalDB2 = new QTableView(groupBox_2);
        tableViewLocalDB2->setObjectName(QStringLiteral("tableViewLocalDB2"));
        tableViewLocalDB2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(tableViewLocalDB2, 3, 0, 1, 3);

        btnOpenFolderDB2 = new QPushButton(groupBox_2);
        btnOpenFolderDB2->setObjectName(QStringLiteral("btnOpenFolderDB2"));

        gridLayout_2->addWidget(btnOpenFolderDB2, 4, 0, 1, 1);

        btnRefrechDB2 = new QPushButton(groupBox_2);
        btnRefrechDB2->setObjectName(QStringLiteral("btnRefrechDB2"));

        gridLayout_2->addWidget(btnRefrechDB2, 4, 1, 1, 1);

        btnDeleteAllDB2 = new QPushButton(groupBox_2);
        btnDeleteAllDB2->setObjectName(QStringLiteral("btnDeleteAllDB2"));

        gridLayout_2->addWidget(btnDeleteAllDB2, 4, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        tabWidget->addTab(tabDB, QString());
        tabGIS = new QWidget();
        tabGIS->setObjectName(QStringLiteral("tabGIS"));
        gridLayout_3 = new QGridLayout(tabGIS);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnRefreshDB1_2 = new QPushButton(tabGIS);
        btnRefreshDB1_2->setObjectName(QStringLiteral("btnRefreshDB1_2"));

        gridLayout_3->addWidget(btnRefreshDB1_2, 5, 1, 1, 1);

        label_6 = new QLabel(tabGIS);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 3);

        tableViewServerDB1_2 = new QTableView(tabGIS);
        tableViewServerDB1_2->setObjectName(QStringLiteral("tableViewServerDB1_2"));
        tableViewServerDB1_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_3->addWidget(tableViewServerDB1_2, 1, 0, 1, 3);

        tableViewLocalDB1_2 = new QTableView(tabGIS);
        tableViewLocalDB1_2->setObjectName(QStringLiteral("tableViewLocalDB1_2"));
        tableViewLocalDB1_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_3->addWidget(tableViewLocalDB1_2, 3, 0, 1, 3);

        label_5 = new QLabel(tabGIS);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 3);

        btnDeleteAllDB1_2 = new QPushButton(tabGIS);
        btnDeleteAllDB1_2->setObjectName(QStringLiteral("btnDeleteAllDB1_2"));

        gridLayout_3->addWidget(btnDeleteAllDB1_2, 5, 2, 1, 1);

        btnOpenFolderDB1_2 = new QPushButton(tabGIS);
        btnOpenFolderDB1_2->setObjectName(QStringLiteral("btnOpenFolderDB1_2"));

        gridLayout_3->addWidget(btnOpenFolderDB1_2, 5, 0, 1, 1);

        tabWidget->addTab(tabGIS, QString());

        verticalLayout_2->addWidget(tabWidget);

        mainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 698, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        mainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(tableViewServerDB1);
        label_2->setBuddy(tableViewLocalDB1);
        label_3->setBuddy(tableViewServerDB2);
        label_4->setBuddy(tableViewLocalDB2);
        label_6->setBuddy(tableViewLocalDB1);
        label_5->setBuddy(tableViewServerDB1);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tableViewServerDB1, tableViewLocalDB1);
        QWidget::setTabOrder(tableViewLocalDB1, btnOpenFolderDB1);
        QWidget::setTabOrder(btnOpenFolderDB1, btnRefreshDB1);
        QWidget::setTabOrder(btnRefreshDB1, btnDeleteAllDB1);
        QWidget::setTabOrder(btnDeleteAllDB1, tableViewServerDB2);
        QWidget::setTabOrder(tableViewServerDB2, tableViewLocalDB2);
        QWidget::setTabOrder(tableViewLocalDB2, btnOpenFolderDB2);
        QWidget::setTabOrder(btnOpenFolderDB2, btnRefrechDB2);
        QWidget::setTabOrder(btnRefrechDB2, btnDeleteAllDB2);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionConnectDB);
        menuFile->addAction(actionCheckUpdates);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionAbout);

        retranslateUi(mainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "\320\236\320\261\320\274\320\265\320\275 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", 0));
        actionCheckUpdates->setText(QApplication::translate("mainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        actionExit->setText(QApplication::translate("mainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        actionHelp->setText(QApplication::translate("mainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
        actionAbout->setText(QApplication::translate("mainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        actionConnectDB->setText(QApplication::translate("mainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\272 \320\261\320\260\320\267\320\265", 0));
#ifndef QT_NO_ACCESSIBILITY
        tabDB->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        groupBox->setTitle(QApplication::translate("mainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260 \321\203\321\201\320\273\320\276\320\262\320\275\321\213\321\205 \320\267\320\275\320\260\320\272\320\276\320\262 \320\276\320\277\320\265\321\200\320\260\321\202\320\270\320\262\320\275\320\276\320\271 \320\276\320\261\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270", 0));
        label->setText(QApplication::translate("mainWindow", "<h2>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213 \320\264\320\273\321\217 \321\201\320\272\320\260\321\207\320\270\320\262\320\260\320\275\320\270\321\217", 0));
        btnOpenFolderDB1->setText(QApplication::translate("mainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", 0));
        btnRefreshDB1->setText(QApplication::translate("mainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        label_2->setText(QApplication::translate("mainWindow", "<h3>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\276:", 0));
        btnDeleteAllDB1->setText(QApplication::translate("mainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", 0));
        groupBox_2->setTitle(QApplication::translate("mainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\276\320\275\320\275\320\260\321\217 \320\261\320\260\320\267\320\260 \320\262\320\276\320\271\321\201\320\272", 0));
        label_3->setText(QApplication::translate("mainWindow", "<h2>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213 \320\264\320\273\321\217 \321\201\320\272\320\260\321\207\320\270\320\262\320\260\320\275\320\270\321\217", 0));
        label_4->setText(QApplication::translate("mainWindow", "<h3>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\276:", 0));
        btnOpenFolderDB2->setText(QApplication::translate("mainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", 0));
        btnRefrechDB2->setText(QApplication::translate("mainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        btnDeleteAllDB2->setText(QApplication::translate("mainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDB), QApplication::translate("mainWindow", "\320\221\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        btnRefreshDB1_2->setText(QApplication::translate("mainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        label_6->setText(QApplication::translate("mainWindow", "<h3>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\276:", 0));
        label_5->setText(QApplication::translate("mainWindow", "<h2>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213 \320\264\320\273\321\217 \321\201\320\272\320\260\321\207\320\270\320\262\320\260\320\275\320\270\321\217", 0));
        btnDeleteAllDB1_2->setText(QApplication::translate("mainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", 0));
        btnOpenFolderDB1_2->setText(QApplication::translate("mainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGIS), QApplication::translate("mainWindow", "\320\223\320\265\320\276\320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        menuFile->setTitle(QApplication::translate("mainWindow", "\320\234\320\265\320\275\321\216", 0));
        menuAbout->setTitle(QApplication::translate("mainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
#ifndef QT_NO_ACCESSIBILITY
        statusbar->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHELORSTHESIS_H
