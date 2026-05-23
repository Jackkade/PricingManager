#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "costEntry.cpp"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QFileDialog>
#include <QTableWidget>
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

    QTextStream in(&file);
    
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("'")) {

            CostEntry* entry = new CostEntry(line.toStdString());

            ui->tableWidget->insertRow(i);
            QTableWidgetItem* itemPartName = new QTableWidgetItem("'Skibidi'", 0);
            ui->tableWidget->setItem(i, 0, itemPartName);
            ui->tableWidget->setItem(i, 1, itemPartName);
            ui->tableWidget->setItem(i, 2, itemPartName);
            ui->tableWidget->setItem(i, 3, itemPartName);
            ui->tableWidget->setItem(i, 4, itemPartName);
            ui->tableWidget->setItem(i, 5, itemPartName);
            ui->tableWidget->setItem(i, 6, itemPartName);
            ui->tableWidget->setItem(i, 7, itemPartName);
            ui->tableWidget->setItem(i, 8, itemPartName);


            i++;
        }
    }
    file.close();
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
    for (int i = 0; i < ui->tableWidget->count(); ++i) {
        out << ui->tableWidget->item(i)->text() << '\n';
    }*/
    
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
        //QListWidgetItem* item = new QListWidgetItem(ui->addEntryInput->text());
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(
            CostEntry(
                ui->addEntryFileName->text().toStdString(),
                ui->addEntrySupID->value(),
                partColorStr,
                ui->addEntryCostUnit->currentText().toStdString(),
                Money(100000),
                Money(0),
                ui->addEntryMinUnits->value(),
                ""
            ).getStandardForm()
        ));

//                    QTableWidgetItem* itemPartName = new QTableWidgetItem(ui->addEntryFileName->text(), 0);

        item->setFlags(item->flags() | Qt::ItemIsEditable);
        //ui->listWidget->addItem(item);
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
    ui->tableWidget->clearContents();
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
    if(ui->tableWidget->selectedItems().isEmpty()) {
        
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