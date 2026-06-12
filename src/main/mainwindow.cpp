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


}

void MainWindow::addTableItemFromCostEntry(CostEntry* entry, int row) {

    ui->itemsTableWidget->insertRow(row);
    QTableWidgetItem* itemPartName  = new QTableWidgetItem( QString::fromStdString(entry->get_PartID()) , 0);
    QTableWidgetItem* itemSupID     = new QTableWidgetItem( QString::number(entry->get_SupID()) , 0);
    QTableWidgetItem* itemColor     = new QTableWidgetItem( QString::fromStdString(entry->get_PartColor()) , 0);
    QTableWidgetItem* itemCostUnit  = new QTableWidgetItem( QString::fromStdString(entry->get_CostUnit()) , 0);
    QTableWidgetItem* itemMatCost   = new QTableWidgetItem( QString::fromStdString(entry->get_MaterialCost().getAmountStr()) , 0);
    QTableWidgetItem* itemLaborCost = new QTableWidgetItem( QString::fromStdString(entry->get_LaborCost().getAmountStr()) , 0);
    QTableWidgetItem* itemMinUnits  = new QTableWidgetItem( QString::number((entry->get_MinUnits()) , 0));
    QTableWidgetItem* itemFile      = new QTableWidgetItem(QString::fromStdString(entry->get_file()));
    ui->itemsTableWidget->setItem(row, 0, itemPartName);
    ui->itemsTableWidget->setItem(row, 1, itemSupID);
    ui->itemsTableWidget->setItem(row, 2, itemColor);
    ui->itemsTableWidget->setItem(row, 3, itemCostUnit);
    ui->itemsTableWidget->setItem(row, 4, itemMatCost);
    ui->itemsTableWidget->setItem(row, 5, itemLaborCost);
    ui->itemsTableWidget->setItem(row, 6, itemMinUnits);
    ui->itemsTableWidget->setItem(row, 7, itemFile);
}

MainWindow::~MainWindow() {

    saveFile(fileName);     
    
    delete ui;
}

bool MainWindow::saveFile(QString saveLocation) {


    bool saved = true;



    QFile file(saveLocation);

    if(QFile::exists(fileName + ".backup") ){
        file.copy(fileName + ".backup.backup");        
    }
    else {
        file.copy(fileName + ".backup");
        
    }

    file.remove();

    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
        saved = false;
    }

    
    QTextStream out(&file);
    
    for (int i = 1; i < categories.size(); ++i) {
        out << QString::fromStdString(categories.at(i)->getName()) << "\n";
        for (int j = 0; j < categories.at(i)->getAmount(); j++) {
            out << QString::fromStdString(categories.at(i)->getEntry(j)->getStandardForm()) << '\n';

        }
        out << '\n';
    }
    
    
    file.close();

    return saved;
}

bool MainWindow::openFile(QString f_name) {


    //TODO: read data from : AppDataLocation
    QFile file(f_name);

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
    bool hasCreatedCategory = false;
    while (!in.atEnd()) {
        QString line = in.readLine();
        /*
        if (line.startsWith("'")) {
            if (shouldCreateCategoryMutex) {
                //categories.push_back(new CostEntryCategory(std::to_string(categoryIndex)));
                addCategory(new CostEntryCategory(std::to_string(categoryIndex)));
                shouldCreateCategoryMutex = false;
            }
            CostEntry* entry = new CostEntry(line.toStdString());
            categories.at(0)->addEntry(entry);
            categories.at(categoryIndex)->addEntry(entry);
            addTableItemFromCostEntry(entry, i);
            
            
            i++;
        }
        else if (!line.startsWith("'")) {
            categoryIndex++;
            shouldCreateCategoryMutex = true;
        }
        */
        if(line.startsWith("*#")) {
            if (hasCreatedCategory) {
                categoryIndex++;
            }
            addCategory(new CostEntryCategory(line.toStdString()));
            hasCreatedCategory = true;
        }
        else if(line.startsWith("'")) {
            //Add Entry to current category
            if (!hasCreatedCategory) {
                addCategory(new CostEntryCategory(std::to_string(categoryIndex)));
                categoryIndex++;
                hasCreatedCategory = true;
            }
            CostEntry* entry = new CostEntry(line.toStdString());
            categories.at(0)->addEntry(entry);
            categories.at(categoryIndex)->addEntry(entry);
            addTableItemFromCostEntry(entry, i);
        }
        else if (line.startsWith(" ")) {
            //end current category if open
        }
        else if(line.startsWith("#")) {
            //ignore
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

    ui->categoriesListWidget->setCurrentItem(ui->categoriesListWidget->item(0));

    hasOpenFile = true;
    ui->btnSave->setEnabled(true);
    ui->btnAddCategory->setEnabled(true);
    ui->btnSaveAs->setEnabled(true);
    ui->btnRemove->setEnabled(true);
    ui->btnEditSelection->setEnabled(true);
    return i > 0;
}

bool MainWindow::execSelectionChangeConfirmationDialog() {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Please Review the changes and ensure they are correct:\n");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    
    QString infoText = "";
    
    QList<QTableWidgetItem *> items = ui->itemsTableWidget->selectedItems();
    for (int i = 0; i < items.size(); i++ ){
        infoText += items.at(i)->text() + " ---> " + ui->changeEntryDataText->text() + "\n";
    }
    
    msgBox.setInformativeText(infoText);

    int ret = msgBox.exec();

    return ret == QMessageBox::Ok;
}

bool MainWindow::execRemoveItemsConfirmationDialog() {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("The Following Items will be deleted. Please ensure you intend to delete them:\n");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    
    QString infoText = "";
    
    QList<QTableWidgetItem *> items = ui->itemsTableWidget->selectedItems();
    for (int i = 0; i < items.size(); i++ ){
        infoText += categories.at(viewingCategory)->getEntry(items.at(i)->row())->getStandardForm() + "\n";
    }
    
    msgBox.setInformativeText(infoText);

    int ret = msgBox.exec();

    return ret == QMessageBox::Ok;

}


bool MainWindow::execMoveItemsToCategory() {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("The following items will be moved to category" + ui->categoriesListWidget->item(viewingCategory)->text() + ". Is this correct?\n");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    
    QString infoText = "";
    
    QList<QTableWidgetItem *> items = ui->itemsTableWidget->selectedItems();
    for (int i = 0; i < items.size(); i++ ){
        infoText += categories.at(viewingCategory)->getEntry(items.at(i)->row())->getStandardForm() + "\n";
    }
    
    msgBox.setInformativeText(infoText);

    int ret = msgBox.exec();

    return ret == QMessageBox::Ok;

}

void MainWindow::on_btnAdd_clicked() {

    //std::cout << ui->addEntryPartName->text().toStdString() << "\n";
    if (!ui->addEntryPartName->text().isEmpty()) {
        string partColorStr = "--";
        if (!ui->addEntryColor->text().isEmpty()) {
            partColorStr = ui->addEntryColor->text().toStdString();
        }
            
        CostEntry* entry = new CostEntry(
            ui->addEntryPartName->text().toStdString(),
            ui->addEntrySupID->value(),
            partColorStr,
            ui->addEntryCostUnit->currentText().toStdString(),
            Money(ui->addEntryMaterialCost->cleanText().toFloat() * 10000),
            Money(ui->addEntryLaborCost->cleanText().toFloat() * 10000),
            ui->addEntryMinUnits->value(),
            ui->addEntryFileName->text().toStdString()
        );

        
        categories.at(ui->categoriesListWidget->row(ui->categoriesListWidget->currentItem()))->addEntry(entry);
        
        addTableItemFromCostEntry(entry, ui->itemsTableWidget->currentRow() + 1);

        ui->addEntryPartName->clear();
        ui->addEntryPartName->setFocus();
    }
}

void MainWindow::on_btnRemove_clicked() { 


    if(execRemoveItemsConfirmationDialog()) {

    
        QList<QTableWidgetItem*> items =ui->itemsTableWidget->selectedItems(); 

        for (int i = 0; i< items.size(); i++) {

            int row = items.at(i)->row();
            
            CostEntry *operand = categories.at(viewingCategory)->getEntry(row);
            categories.at(0)->removeEntry(operand);
            categories.at(viewingCategory)->removeEntry(operand);
            ui->itemsTableWidget->removeRow(row);
        }
        

    }
}


void MainWindow::on_addEntryFileName_textChanged(const QString &text) {
    if(text.isEmpty()) {
        ui->btnAdd->setDisabled(true);

    }
    else {
        ui->btnAdd->setDisabled(false);
    }
}


void MainWindow::on_btnOpenFile_clicked() {


    QFileDialog d;
    d.setFileMode(QFileDialog::AnyFile);
    fileName = d.getOpenFileName(this, tr("Select File"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("Text files (*.txt *.SIZ)"));

    std::cout << fileName.toStdString() << "\n";

    openFile(fileName);
}

void MainWindow::on_btnSave_clicked() {

    saveFile(fileName);
}

void MainWindow::on_btnSaveAs_clicked() {

    saveFile(QFileDialog::getSaveFileName(this, 
        tr("Save File As"), 
        "", 
        tr("Text Files (*.txt *.SIZ);;All Files (*)")));
}

void MainWindow::on_btnAddCategory_clicked() {

    if (selectedCategory == viewingCategory) {
        ui->btnMoveItemsCategory->setEnabled(false);
    }

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
        //std::cout << ui->categoriesListWidget->count() << " :count\n";
        foundCategory = true;
        ui->itemsTableWidget->clearContents();
        ui->itemsTableWidget->setRowCount(0);
        
        for (int j = 0; j < categories.at(row)->getAmount(); j++) {
            addTableItemFromCostEntry(categories.at(row)->getEntry(j), j); 
        }

    }



    return foundCategory;
}

void MainWindow::on_categoriesListWidget_currentRowChanged(int currentRow) {
    if(currentRow != -1) {
        selectedCategory = currentRow;
        ui->btnOpenCategory->setEnabled(true);
    }
}

void MainWindow::on_btnEditSelection_clicked() {

    if (execSelectionChangeConfirmationDialog()) {
        QList<QTableWidgetItem *> items = ui->itemsTableWidget->selectedItems();
        for (int i = 0; i < items.size(); i++ ){
            items.at(i)->setText(ui->changeEntryDataText->text());
        }
    }

}

void MainWindow::on_itemsTableWidget_cellChanged(int row, int column) {
    //std::cout << row << " " << column << '\n';
    if(viewingCategory >= 0 && viewingCategory < categories.size()) {
        CostEntry *operand = categories.at(viewingCategory)->getEntry(row);
        if(column == 0) {

            if (ui->itemsTableWidget->item(row, column)->text().length() > 8) {
                ui->itemsTableWidget->item(row, column)->setText(ui->itemsTableWidget->item(row, column)->text().first(8));
            }

            operand->set_PartID(ui->itemsTableWidget->item(row, column)->text().toStdString());
            string str = ui->itemsTableWidget->item(row, column)->text().toStdString();
            str.erase(std::remove(str.begin(), str.end(), ' '), str.end());


        }
        else if(column == 1) {
            operand->set_SupID(ui->itemsTableWidget->item(row, column)->text().toInt());

        }
        else if(column == 2) {

            if (ui->itemsTableWidget->item(row, column)->text().length() > 2) {
                ui->itemsTableWidget->item(row, column)->setText(ui->itemsTableWidget->item(row, column)->text().first(2));
            }
            operand->set_PartColor(ui->itemsTableWidget->item(row, column)->text().toStdString());

        }
        else if(column == 3) {


            if (ui->itemsTableWidget->item(row, column)->text().length() > 2) {
                ui->itemsTableWidget->item(row, column)->setText(ui->itemsTableWidget->item(row, column)->text().first(2));
            }

            operand->set_CostUnit(ui->itemsTableWidget->item(row, column)->text().toStdString());

        }
        else if(column == 4) {
            operand->set_MaterialCost(static_cast<unsigned long long>(ui->itemsTableWidget->item(row, column)->text().toFloat() * 10000));

        }
        else if(column == 5) {
            operand->set_LaborCost(static_cast<unsigned long long>(ui->itemsTableWidget->item(row, column)->text().toFloat() * 10000));

        }
        else if(column == 6) {
            operand->set_MinUnits(ui->itemsTableWidget->item(row, column)->text().toUInt());

        }
        else if(column == 7) {
            operand->set_file(ui->itemsTableWidget->item(row, column)->text().toStdString());

        }

        /*||||*/

        ui->labelEntryColorOut->setText(QString::fromStdString(operand->get_ColorDesc()));
        ui->labelEntryNameOut->setText(QString::fromStdString(operand->get_PartName()));
        ui->entryPartDescription->setText(QString::fromStdString(operand->get_Description()));
    }
}

void MainWindow::on_itemsTableWidget_itemSelectionChanged() {
    if (ui->itemsTableWidget->selectedItems().size() >= 1) {
        ui->btnRemove->setEnabled(true);
        if (viewingCategory != -1 && viewingCategory != selectedCategory && selectedCategory > 0) {
            ui->btnMoveItemsCategory->setEnabled(true);
        }
    }
    else {
        ui->btnRemove->setEnabled(false);
        ui->btnMoveItemsCategory->setEnabled(false);
    }
}


void MainWindow::on_btnMoveItemsCategory_clicked() {

    if(execMoveItemsToCategory()) {

        if (selectedCategory != viewingCategory) {

            QList<QTableWidgetItem*> items = ui->itemsTableWidget->selectedItems(); 
    
            for (int i = 0; i< items.size(); i++) {
    
                int row = items.at(i)->row();
                
                CostEntry *operand = categories.at(viewingCategory)->getEntry(row);
                if(viewingCategory != 0) {
                    categories.at(viewingCategory)->removeEntry(operand);
                }
                categories.at(selectedCategory)->addEntry(operand);
                ui->itemsTableWidget->removeRow(row);
        
            }
        
        }
        
    }
}

void MainWindow::on_btnOpenCategory_clicked() {
    viewingCategory = selectedCategory;
    if (selectedCategory == viewingCategory) {
        ui->btnMoveItemsCategory->setEnabled(false);
    }
    if ( loadCostEntryCategory(ui->categoriesListWidget->row(ui->categoriesListWidget->currentItem()))) {
    //    std::cout << "Category Changed!\n";
    }

}

void MainWindow::on_categoriesListWidget_itemDoubleClicked(QListWidgetItem *item) {
   
    viewingCategory = selectedCategory;
    if (selectedCategory == viewingCategory) {
        ui->btnMoveItemsCategory->setEnabled(false);
    }
    if ( loadCostEntryCategory(ui->categoriesListWidget->row(ui->categoriesListWidget->currentItem()))) {
        //    std::cout << "Category Changed!\n";
    }
}