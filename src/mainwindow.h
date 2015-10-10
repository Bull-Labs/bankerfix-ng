#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStringListModel *model;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStringList readUpdateFile();
    void showTextOnListView(QStringList*);


public slots:
    void showAboutDialog();
    void updateData();
    void searchBankers();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
