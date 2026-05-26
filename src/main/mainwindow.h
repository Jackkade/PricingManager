#pragma once
#include <QMainWindow>
#include <costEntry.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString fileName;

    bool saveFile();    //Save Current File; Returns true if file saved correctly.
    
    void addTableItemFromCostEntry(CostEntry* entry,  int row);
    
private slots:

    void on_btnOpenFile_clicked();
    void on_btnSave_clicked();

    void on_btnAdd_clicked ();
    void on_btnRemove_clicked();
    void on_btnRemoveAll_clicked();
    void on_btnEditEntry_clicked();

    void on_addEntryFileName_textChanged(const QString &text);
    void on_listWidget_itemSelectionChanged();

};
