#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QFileDialog>
#include <QTableWidget>

#include <costEntry.cpp>
#include <costEntryCategory.cpp>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    QFileDialog d;
    d.setFileMode(QFileDialog::AnyFile);
    fileName = d.getOpenFileName(this, tr("Select File"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("Text files (*.txt)"));

    QFile file(fileName);

    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    // Open File
    QTextStream in(&file);
    
    categories.push_back( new CostEntryCategory("All Entries"));
    ui->categoriesListWidget->addItem(QString::fromStdString(categories.at(0)->getName()));

    
    int i = 0;
    int categoryIndex = 1;
    bool shouldCreateCategoryMutex = true;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("'")) {
            if (shouldCreateCategoryMutex) {
                categories.push_back(new CostEntryCategory(std::to_string(categoryIndex)));
                addCategory(new CostEntryCategory(std::to_string(categoryIndex)));
                shouldCreateCategoryMutex = false;
            }
            CostEntry* entry = new CostEntry(line.toStdString());
            categories.at(0)->addEntry(entry);
            categories.at(categoryIndex)->addEntry(entry);
            addTableItemFromCostEntry(entry, i);
            
            
            i++;
        }
        else if (!line.startsWith('*')) {
            categoryIndex++;
            shouldCreateCategoryMutex = true;
        }
    }
    //DEBUG
    /*
    for(int i = 0; i < allEntries->getAmount(); i++) {
        std::cout << allEntries->getEntry(i)->getStandardForm() << '\n';
    }
    */
    //
    file.close();
}

void MainWindow::addTableItemFromCostEntry(CostEntry* entry, int row) {

    ui->itemsTableWidget->insertRow(row);
    QTableWidgetItem* itemPartName = new QTableWidgetItem( QString::fromStdString(entry->get_PartID()) , 0);
    QTableWidgetItem* itemSupID     = new QTableWidgetItem( QString::number(entry->get_SupID()) , 0);
    QTableWidgetItem* itemColor     = new QTableWidgetItem( QString::fromStdString(entry->get_PartColor()) , 0);
    QTableWidgetItem* itemCostUnit  = new QTableWidgetItem( QString::fromStdString(entry->get_CostUnit()) , 0);
    QTableWidgetItem* itemMatCost   = new QTableWidgetItem( QString::fromStdString(entry->get_MaterialCost().getAmountStr()) , 0);
    QTableWidgetItem* itemLaborCost = new QTableWidgetItem( QString::fromStdString(entry->get_LaborCost().getAmountStr()) , 0);
    QTableWidgetItem* itemMinUnits  = new QTableWidgetItem( QString::number((entry->get_MinUnits()) , 0));
    ui->itemsTableWidget->setItem(row, 0, itemPartName);
    ui->itemsTableWidget->setItem(row, 1, itemSupID);
    ui->itemsTableWidget->setItem(row, 2, itemColor);
    ui->itemsTableWidget->setItem(row, 3, itemCostUnit);
    ui->itemsTableWidget->setItem(row, 4, itemMatCost);
    ui->itemsTableWidget->setItem(row, 5, itemLaborCost);
    ui->itemsTableWidget->setItem(row, 6, itemMinUnits);
}

MainWindow::~MainWindow() {
    
    saveFile();     //TODO: Bring this out to confirmation dialouge
    
    delete ui;
}

bool MainWindow::saveFile() {

    //TODO: Add File Save location dialouge

    bool saved = true;
    QFile file(fileName);
    
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
        saved = false;
    }

    
    QTextStream out(&file);
    /*
    for (int i = 0; i < ui->itemsTableWidget->count(); ++i) {
        out << ui->itemsTableWidget->row(i)->text() << '\n';
    }
    */
    
    file.close();

    return saved;
}


void MainWindow::on_btnAdd_clicked() { //TODO

    std::cout << ui->addEntryFileName->text().toStdString() << "\n";
    if (!ui->addEntryFileName->text().isEmpty()) {
        string partColorStr = "--";
        if (!ui->addEntryColor->text().isEmpty()) {
            partColorStr = ui->addEntryColor->text().toStdString();
        }
            
        CostEntry* entry = new CostEntry(
            ui->addEntryFileName->text().toStdString(),
            ui->addEntrySupID->value(),
            partColorStr,
            ui->addEntryCostUnit->currentText().toStdString(),
            Money(100000),
            Money(0),
            ui->addEntryMinUnits->value(),
            ""
        );

        
        //allEntries->addEntry(entry);
        categories.at(ui->categoriesListWidget->row(ui->categoriesListWidget->currentItem()))->addEntry(entry);
        categories.at(0)->addEntry(entry);
        addTableItemFromCostEntry(entry, ui->itemsTableWidget->currentRow() + 1);

        ui->addEntryFileName->clear();
        ui->addEntryFileName->setFocus();
    }
}

void MainWindow::on_btnRemove_clicked() { //TODO
    /*
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    if(item) {
        delete item;
    }
    */
}

void MainWindow::on_btnRemoveAll_clicked() {
    ui->itemsTableWidget->clearContents();
}


void MainWindow::on_btnEditEntry_clicked() { //TODO
    /*
    QListWidgetItem* item = ui->listWidget->item(ui->listWidget->currentRow());
    if (item) {
        QStringList strList = item->text().split(' ', Qt::SkipEmptyParts, Qt::CaseSensitive);
        QString str = strList.at(0);
        ui->addEntryFileName->setText(str.replace("'", ""));
    }
    */
}

void MainWindow::on_addEntryFileName_textChanged(const QString &text) {
    if(text.isEmpty()) {
        ui->btnAdd->setDisabled(true);

    }   
    else {
        ui->btnAdd->setDisabled(false);
    }
}

void MainWindow::on_listWidget_itemSelectionChanged() {
    if(ui->itemsTableWidget->selectedItems().isEmpty()) {
        
        ui->btnRemove->setDisabled(true);
    }
    else {
        ui->btnRemove->setDisabled(false);
    
    }
}


void MainWindow::on_btnOpenFile_clicked() {


}

void MainWindow::on_btnSave_clicked() {

    saveFile();
}

void MainWindow::on_btnAddCategory_clicked() {

    //    std::cout << ui->addCategoryName->text().toStdString() << '\n';
    //    std::cout << temp->getName() << '\n';
    
    CostEntryCategory *temp = new CostEntryCategory(ui->addCategoryName->text().toStdString());
    ui->addCategoryName->clear();
    addCategory(temp);
}

void MainWindow::addCategory(CostEntryCategory* category) {
    
    ui->categoriesListWidget->addItem(QString::fromStdString(category->getName()));

    categories.push_back(category);
}

bool MainWindow::loadCostEntryCategory(int row) {
    bool foundCategory = false;
    
    if(row >= 0 && row <= ui->categoriesListWidget->count()) {
        std::cout << ui->categoriesListWidget->count() << " :count\n";
        foundCategory = true;
        ui->itemsTableWidget->clearContents();
        ui->itemsTableWidget->setRowCount(0);
        
        for (int j = 0; j < categories.at(row)->getAmount(); j++) {
            addTableItemFromCostEntry(categories.at(row)->getEntry(j), j); //TODO: Fix Switching ooff of category deleting entries
        }
        
    }
    
    

    return foundCategory;
}

void MainWindow::on_categoriesListWidget_currentRowChanged(int currentRow) {
    if(currentRow != -1) {
        
        if ( loadCostEntryCategory(ui->categoriesListWidget->row(ui->categoriesListWidget->currentItem()))) {
            std::cout << "Category Changed!\n";
        }
    }
}
