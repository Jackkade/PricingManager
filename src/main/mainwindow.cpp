#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "costEntry.cpp"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QFileDialog>
#include <QVariant>
#include "listEntry.h"
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

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("'")) {
            QListWidgetItem* item = new QListWidgetItem(line, ui->listWidget);

            ListEntry* widget = new ListEntry(this);
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item, widget);
            //item->setFlags(item->flags() | Qt::ItemIsEditable);

        }
    }
    file.close();
}

MainWindow::~MainWindow() {
    
    QFile file(fileName);
    
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    
    QTextStream out(&file);
    
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out << ui->listWidget->item(i)->text() << '\n';
    }
    
    file.close();
    delete ui;
}


void MainWindow::on_btnAdd_clicked() {
    std::cout << ui->addEntryFileName->text().toStdString() << "\n";
    if (!ui->addEntryFileName->text().isEmpty()) {
        string partColorStr = "--";
        if (!ui->addEntryColor->text().isEmpty()) {
            partColorStr = ui->addEntryColor->text().toStdString();
        }
        //QListWidgetItem* item = new QListWidgetItem(ui->addEntryInput->text());
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(
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
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->listWidget->addItem(item);
        ui->addEntryFileName->clear();
        ui->addEntryFileName->setFocus();
    }
}

void MainWindow::on_btnRemove_clicked() {
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    if(item) {
        delete item;
    }
}

void MainWindow::on_btnRemoveAll_clicked() {
    ui->listWidget->clear();
}


void MainWindow::on_btnEditEntry_clicked() {
    QListWidgetItem* item = ui->listWidget->item(ui->listWidget->currentRow());
    if (item) {
        QStringList strList = item->text().split(' ', Qt::SkipEmptyParts, Qt::CaseSensitive);
        QString str = strList.at(0);
        ui->addEntryFileName->setText(str.replace("'", ""));
    }
}