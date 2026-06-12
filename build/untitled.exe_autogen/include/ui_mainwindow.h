/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *addEntryPartName;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpinBox *addEntrySupID;
    QLineEdit *addEntryColor;
    QComboBox *addEntryCostUnit;
    QDoubleSpinBox *addEntryMaterialCost;
    QDoubleSpinBox *addEntryLaborCost;
    QSpinBox *addEntryMinUnits;
    QPushButton *btnOpenFile;
    QPushButton *btnSave;
    QTableWidget *itemsTableWidget;
    QListWidget *categoriesListWidget;
    QPushButton *btnAddCategory;
    QLineEdit *addCategoryName;
    QLineEdit *addEntryFileName;
    QFrame *line;
    QLabel *labelEntryName;
    QLabel *labelEntryColor;
    QLabel *labelEntryDesc;
    QTextBrowser *entryPartDescription;
    QLabel *labelEntryNameOut;
    QLabel *labelEntryColorOut;
    QPushButton *btnSaveAs;
    QPushButton *btnEditSelection;
    QLineEdit *changeEntryDataText;
    QPushButton *btnMoveItemsCategory;
    QPushButton *btnOpenCategory;
    QLabel *labelSelectedCategory;
    QLabel *labelSelectedCategoryData;
    QLabel *labelSelectedCategoryDataHeader;
    QPushButton *btnRenameCategory;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1750, 1200);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        addEntryPartName = new QLineEdit(centralwidget);
        addEntryPartName->setObjectName("addEntryPartName");
        addEntryPartName->setGeometry(QRect(960, 80, 100, 32));
        addEntryPartName->setMaxLength(8);
        addEntryPartName->setClearButtonEnabled(true);
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setEnabled(false);
        btnAdd->setGeometry(QRect(1650, 80, 90, 32));
        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setEnabled(false);
        btnRemove->setGeometry(QRect(1650, 1130, 90, 30));
        addEntrySupID = new QSpinBox(centralwidget);
        addEntrySupID->setObjectName("addEntrySupID");
        addEntrySupID->setGeometry(QRect(1060, 80, 60, 32));
        addEntryColor = new QLineEdit(centralwidget);
        addEntryColor->setObjectName("addEntryColor");
        addEntryColor->setGeometry(QRect(1120, 80, 60, 32));
        addEntryColor->setMaxLength(2);
        addEntryColor->setClearButtonEnabled(true);
        addEntryCostUnit = new QComboBox(centralwidget);
        addEntryCostUnit->addItem(QString());
        addEntryCostUnit->addItem(QString());
        addEntryCostUnit->addItem(QString());
        addEntryCostUnit->addItem(QString());
        addEntryCostUnit->setObjectName("addEntryCostUnit");
        addEntryCostUnit->setGeometry(QRect(1180, 80, 50, 32));
        addEntryCostUnit->setEditable(false);
        addEntryCostUnit->setMaxVisibleItems(4);
        addEntryCostUnit->setMaxCount(4);
        addEntryMaterialCost = new QDoubleSpinBox(centralwidget);
        addEntryMaterialCost->setObjectName("addEntryMaterialCost");
        addEntryMaterialCost->setGeometry(QRect(1230, 80, 120, 32));
        addEntryMaterialCost->setDecimals(4);
        addEntryMaterialCost->setMaximum(9999.999900000000707);
        addEntryLaborCost = new QDoubleSpinBox(centralwidget);
        addEntryLaborCost->setObjectName("addEntryLaborCost");
        addEntryLaborCost->setGeometry(QRect(1350, 80, 120, 32));
        addEntryLaborCost->setDecimals(4);
        addEntryLaborCost->setMaximum(9999.999900000000707);
        addEntryMinUnits = new QSpinBox(centralwidget);
        addEntryMinUnits->setObjectName("addEntryMinUnits");
        addEntryMinUnits->setGeometry(QRect(1470, 80, 70, 32));
        addEntryMinUnits->setMaximum(9999);
        btnOpenFile = new QPushButton(centralwidget);
        btnOpenFile->setObjectName("btnOpenFile");
        btnOpenFile->setGeometry(QRect(0, 0, 70, 30));
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setEnabled(false);
        btnSave->setGeometry(QRect(70, 0, 70, 30));
        itemsTableWidget = new QTableWidget(centralwidget);
        if (itemsTableWidget->columnCount() < 8)
            itemsTableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        itemsTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        itemsTableWidget->setObjectName("itemsTableWidget");
        itemsTableWidget->setGeometry(QRect(350, 120, 1390, 1000));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(itemsTableWidget->sizePolicy().hasHeightForWidth());
        itemsTableWidget->setSizePolicy(sizePolicy);
        itemsTableWidget->setMinimumSize(QSize(750, 500));
        itemsTableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
        itemsTableWidget->setSortingEnabled(true);
        itemsTableWidget->horizontalHeader()->setVisible(true);
        itemsTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        itemsTableWidget->horizontalHeader()->setMinimumSectionSize(80);
        itemsTableWidget->horizontalHeader()->setDefaultSectionSize(170);
        itemsTableWidget->horizontalHeader()->setStretchLastSection(true);
        itemsTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        categoriesListWidget = new QListWidget(centralwidget);
        categoriesListWidget->setObjectName("categoriesListWidget");
        categoriesListWidget->setGeometry(QRect(10, 120, 320, 450));
        btnAddCategory = new QPushButton(centralwidget);
        btnAddCategory->setObjectName("btnAddCategory");
        btnAddCategory->setEnabled(false);
        btnAddCategory->setGeometry(QRect(260, 60, 70, 30));
        addCategoryName = new QLineEdit(centralwidget);
        addCategoryName->setObjectName("addCategoryName");
        addCategoryName->setGeometry(QRect(10, 60, 250, 30));
        addCategoryName->setMaxLength(99);
        addCategoryName->setClearButtonEnabled(true);
        addEntryFileName = new QLineEdit(centralwidget);
        addEntryFileName->setObjectName("addEntryFileName");
        addEntryFileName->setGeometry(QRect(1540, 80, 100, 32));
        addEntryFileName->setMaxLength(64);
        addEntryFileName->setClearButtonEnabled(true);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 710, 320, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        labelEntryName = new QLabel(centralwidget);
        labelEntryName->setObjectName("labelEntryName");
        labelEntryName->setGeometry(QRect(10, 730, 58, 18));
        labelEntryColor = new QLabel(centralwidget);
        labelEntryColor->setObjectName("labelEntryColor");
        labelEntryColor->setGeometry(QRect(10, 760, 58, 18));
        labelEntryDesc = new QLabel(centralwidget);
        labelEntryDesc->setObjectName("labelEntryDesc");
        labelEntryDesc->setGeometry(QRect(10, 790, 81, 18));
        entryPartDescription = new QTextBrowser(centralwidget);
        entryPartDescription->setObjectName("entryPartDescription");
        entryPartDescription->setGeometry(QRect(10, 820, 320, 190));
        labelEntryNameOut = new QLabel(centralwidget);
        labelEntryNameOut->setObjectName("labelEntryNameOut");
        labelEntryNameOut->setGeometry(QRect(70, 730, 261, 18));
        labelEntryNameOut->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        labelEntryColorOut = new QLabel(centralwidget);
        labelEntryColorOut->setObjectName("labelEntryColorOut");
        labelEntryColorOut->setGeometry(QRect(70, 760, 261, 18));
        labelEntryColorOut->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        btnSaveAs = new QPushButton(centralwidget);
        btnSaveAs->setObjectName("btnSaveAs");
        btnSaveAs->setEnabled(false);
        btnSaveAs->setGeometry(QRect(140, 0, 70, 30));
        btnEditSelection = new QPushButton(centralwidget);
        btnEditSelection->setObjectName("btnEditSelection");
        btnEditSelection->setEnabled(false);
        btnEditSelection->setGeometry(QRect(610, 1130, 165, 30));
        changeEntryDataText = new QLineEdit(centralwidget);
        changeEntryDataText->setObjectName("changeEntryDataText");
        changeEntryDataText->setGeometry(QRect(350, 1130, 250, 30));
        changeEntryDataText->setMaxLength(99);
        changeEntryDataText->setClearButtonEnabled(true);
        btnMoveItemsCategory = new QPushButton(centralwidget);
        btnMoveItemsCategory->setObjectName("btnMoveItemsCategory");
        btnMoveItemsCategory->setEnabled(false);
        btnMoveItemsCategory->setGeometry(QRect(10, 610, 320, 30));
        btnOpenCategory = new QPushButton(centralwidget);
        btnOpenCategory->setObjectName("btnOpenCategory");
        btnOpenCategory->setEnabled(false);
        btnOpenCategory->setGeometry(QRect(10, 580, 320, 30));
        labelSelectedCategory = new QLabel(centralwidget);
        labelSelectedCategory->setObjectName("labelSelectedCategory");
        labelSelectedCategory->setGeometry(QRect(10, 640, 121, 18));
        labelSelectedCategoryData = new QLabel(centralwidget);
        labelSelectedCategoryData->setObjectName("labelSelectedCategoryData");
        labelSelectedCategoryData->setGeometry(QRect(150, 640, 181, 20));
        labelSelectedCategoryData->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        labelSelectedCategoryDataHeader = new QLabel(centralwidget);
        labelSelectedCategoryDataHeader->setObjectName("labelSelectedCategoryDataHeader");
        labelSelectedCategoryDataHeader->setGeometry(QRect(350, 70, 341, 41));
        QFont font;
        font.setPointSize(20);
        labelSelectedCategoryDataHeader->setFont(font);
        labelSelectedCategoryDataHeader->setTextFormat(Qt::TextFormat::PlainText);
        labelSelectedCategoryDataHeader->setScaledContents(false);
        labelSelectedCategoryDataHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelSelectedCategoryDataHeader->setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByMouse);
        btnRenameCategory = new QPushButton(centralwidget);
        btnRenameCategory->setObjectName("btnRenameCategory");
        btnRenameCategory->setEnabled(false);
        btnRenameCategory->setGeometry(QRect(260, 90, 70, 30));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addEntryPartName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Part Name", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        btnRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        addEntryColor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        addEntryCostUnit->setItemText(0, QCoreApplication::translate("MainWindow", "FT", nullptr));
        addEntryCostUnit->setItemText(1, QCoreApplication::translate("MainWindow", "EA", nullptr));
        addEntryCostUnit->setItemText(2, QCoreApplication::translate("MainWindow", "LB", nullptr));
        addEntryCostUnit->setItemText(3, QCoreApplication::translate("MainWindow", "WF", nullptr));

        btnOpenFile->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        QTableWidgetItem *___qtablewidgetitem = itemsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Part Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = itemsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "SupID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = itemsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = itemsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "CostUnit", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = itemsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Material Cost", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = itemsTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Labor Cost", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = itemsTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Minimum Units", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = itemsTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        btnAddCategory->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        addCategoryName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Category Name", nullptr));
        addEntryFileName->setPlaceholderText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        labelEntryName->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        labelEntryColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        labelEntryDesc->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        entryPartDescription->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Temp</p></body></html>", nullptr));
        labelEntryNameOut->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        labelEntryColorOut->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        btnSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        btnEditSelection->setText(QCoreApplication::translate("MainWindow", "Modify Selection", nullptr));
        changeEntryDataText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Category Name", nullptr));
        btnMoveItemsCategory->setText(QCoreApplication::translate("MainWindow", "Move Items to Category", nullptr));
        btnOpenCategory->setText(QCoreApplication::translate("MainWindow", "Open Category", nullptr));
        labelSelectedCategory->setText(QCoreApplication::translate("MainWindow", "Selected Category", nullptr));
        labelSelectedCategoryData->setText(QCoreApplication::translate("MainWindow", "All Entries", nullptr));
        labelSelectedCategoryDataHeader->setText(QCoreApplication::translate("MainWindow", "All Entries", nullptr));
        btnRenameCategory->setText(QCoreApplication::translate("MainWindow", "Rename", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
