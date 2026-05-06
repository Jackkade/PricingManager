#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked() {
    std::cout << ui->addEntryInput->text().toStdString() << "\n";
    if (!ui->addEntryInput->text().isEmpty()) {
        QListWidgetItem* item = new QListWidgetItem(ui->addEntryInput->text());
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