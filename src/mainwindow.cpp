#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "network.h"

#include <QMessageBox>
#include <QFile>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //connect(ui->action_About, ui->action_About->triggered(), this, this->showAboutDialog);
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
    connect(ui->action_Update, SIGNAL(triggered()), this, SLOT(updateData()));
    connect(ui->pushButton_Update, SIGNAL(clicked()), this, SLOT(updateData()));
    connect(ui->pushButton_SearchBankers, SIGNAL(clicked()), this, SLOT(searchBankers()));
}

MainWindow::~MainWindow()
{
    //delete this->net;
    delete ui;
}


void MainWindow::showAboutDialog()
{
    QMessageBox::about(this, "About - BankerFix-NG", "Bull-Labs - http://bull-labs.com\nCopyright 2015");

}

void MainWindow::showTextOnListView(QStringList *list)
{
    this->model = new QStringListModel(this);
    //QStringList list;
    //list << "test";
    //list << "test1";
    this->model->setStringList(*list);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

void MainWindow::updateData()
{
    QStringList list;
    qDebug("Updating data...\n");
    list << "Updating data...";
    list <<"Ok!";
    this->showTextOnListView(&list);
}

void MainWindow::searchBankers()
{
    QStringList list;
    list = this->readUpdateFile();
    list.prepend("Searching for infected files... ");
    this->showTextOnListView(&list);

}

QStringList MainWindow::readUpdateFile()
{
    QStringList list;
    QFile file("data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical("Unable reading data file..\n");
        list << "Unable reading data file..\n";
        return list;
    }

    QByteArray line;
    while(!file.atEnd()){
        line = file.readLine();
        if(line.length() > 1) {
            qDebug("processing: ");
            qDebug(line);
            list << line;
        }
    }

    return list;

}
