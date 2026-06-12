/********************************************************************************
** Form generated from reading UI file 'listEntry.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTENTRY_H
#define UI_LISTENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListEntry
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelFileName;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelSupID;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelColor;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelCostUnit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelMaterialCost;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelLaborCost;
    QSpacerItem *horizontalSpacer;
    QLabel *labelMinUnits;

    void setupUi(QWidget *ListEntry)
    {
        if (ListEntry->objectName().isEmpty())
            ListEntry->setObjectName("ListEntry");
        ListEntry->resize(680, 50);
        horizontalLayoutWidget = new QWidget(ListEntry);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, -10, 671, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelFileName = new QLabel(horizontalLayoutWidget);
        labelFileName->setObjectName("labelFileName");

        horizontalLayout->addWidget(labelFileName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelSupID = new QLabel(horizontalLayoutWidget);
        labelSupID->setObjectName("labelSupID");

        horizontalLayout->addWidget(labelSupID);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelColor = new QLabel(horizontalLayoutWidget);
        labelColor->setObjectName("labelColor");

        horizontalLayout->addWidget(labelColor);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        labelCostUnit = new QLabel(horizontalLayoutWidget);
        labelCostUnit->setObjectName("labelCostUnit");

        horizontalLayout->addWidget(labelCostUnit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        labelMaterialCost = new QLabel(horizontalLayoutWidget);
        labelMaterialCost->setObjectName("labelMaterialCost");

        horizontalLayout->addWidget(labelMaterialCost);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        labelLaborCost = new QLabel(horizontalLayoutWidget);
        labelLaborCost->setObjectName("labelLaborCost");

        horizontalLayout->addWidget(labelLaborCost);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelMinUnits = new QLabel(horizontalLayoutWidget);
        labelMinUnits->setObjectName("labelMinUnits");

        horizontalLayout->addWidget(labelMinUnits);


        retranslateUi(ListEntry);

        QMetaObject::connectSlotsByName(ListEntry);
    } // setupUi

    void retranslateUi(QWidget *ListEntry)
    {
        ListEntry->setWindowTitle(QCoreApplication::translate("ListEntry", "Form", nullptr));
        labelFileName->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
        labelSupID->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
        labelColor->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
        labelCostUnit->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
        labelMaterialCost->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
        labelLaborCost->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
        labelMinUnits->setText(QCoreApplication::translate("ListEntry", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListEntry: public Ui_ListEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTENTRY_H
