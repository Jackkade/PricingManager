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

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\pricingfile.txt");

    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_btnAdd_clicked() {
    std::cout << ui->addEntryInput->text().toStdString() << "\n";
    if (!ui->addEntryInput->text().isEmpty()) {

        //QListWidgetItem* item = new QListWidgetItem(ui->addEntryInput->text());
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(CostEntry(ui->addEntryInput->text().toStdString(), 15, "--", "TP", Money(100000), Money(0), 5).getStandardForm()));
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->listWidget->addItem(item);
        ui->addEntryInput->clear();
        ui->addEntryInput->setFocus();
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