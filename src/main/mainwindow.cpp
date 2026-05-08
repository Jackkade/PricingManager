#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "costEntry.cpp"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//pricingfile.txt");

    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
    file.close();
}

MainWindow::~MainWindow() {
    delete ui;


    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\pricingfile.txt");

    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out << ui->listWidget->item(i)->text() << '\n';
    }

    file.close();
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
                ui->addEntryMinUnits->value()
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