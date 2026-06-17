#pragma once
#include <QMainWindow>
#include <costEntry.h>
#include <QListWidget>
#include <vector>
#include "costEntryCategory.h"


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

    bool hasOpenFile = false;

private:
    Ui::MainWindow *ui;
    QString fileName;
    unsigned int selectedCategory = -1;
    unsigned int viewingCategory = -1;
    std::vector<CostEntryCategory*> categories;

    bool saveFile(QString saveLocation);    //Save Current File; Returns true if file saved correctly.
    bool openFile(QString f_name);
    bool closeFile();
    
    void addTableItemFromCostEntry(CostEntry* entry,  int row);

    bool loadCostEntryCategory(int row);
    void addCategory(CostEntryCategory* category);
    bool execSelectionChangeConfirmationDialog();
    bool execRemoveItemsConfirmationDialog();
    bool execMoveItemsToCategory();
    bool execConfirmDeleteCategory();

    void readPartData();

private slots:

    void on_btnOpenFile_clicked();
    void on_btnCloseFile_clicked();
    void on_btnSave_clicked();
    void on_btnSaveAs_clicked();

    void on_btnAdd_clicked ();
    void on_btnRemove_clicked();
    void on_btnEditSelection_clicked();
    void on_btnMoveItemsCategory_clicked();
    void on_btnOpenCategory_clicked();
    void on_btnRenameCategory_clicked();
    void on_btnDeleteCategory_clicked();

    void on_addEntryPartName_textChanged(const QString &text);

    void on_btnAddCategory_clicked();
    void on_categoriesListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_categoriesListWidget_currentRowChanged(int currentRow);
    
    void on_itemsTableWidget_cellChanged(int row, int column);
    void on_itemsTableWidget_itemSelectionChanged();

};
