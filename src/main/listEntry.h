#ifndef LISTENTRY_H
#define LISTENTRY_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class ListEntry;
}


class ListEntry : public QListWidgetItem {
    Q_OBJECT

public:
    explicit ListEntry(QListWidget* parent = nullptr);
    ~ListEntry();

    void setText(const QString& text);
    QString getText();

signals:
    void sendRemoveItem(const QString& text);

private slots:
    void closeButtonClicked();

private:
    std::unique_ptr<Ui::ListEntry> ui;
};

#endif