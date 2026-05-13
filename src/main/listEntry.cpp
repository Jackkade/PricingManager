#include "listEntry.h"
#include "ui_listEntry.h"

#include <QPushButton>
#include <QListWidget>

ListEntry::ListEntry(QListWidget* parent)
    : QListWidgetItem(parent)
    , ui(new Ui::ListEntry)
{
    ui->setupUi(this);

}

ListEntry::~ListEntry() { }

void ListEntry::setText(const QString& text)
{
    ui->labelFileName->setText(text);
}

QString ListEntry::getText()
{
    return ui->labelFileName->text();
}

void ListEntry::closeButtonClicked()
{
    emit sendRemoveItem(ui->labelFileName->text());
}