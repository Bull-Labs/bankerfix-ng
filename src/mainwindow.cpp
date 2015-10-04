#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->action_About, ui->action_About->triggered(), this, this->showAboutDialog);
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showAboutDialog()
{
    QMessageBox::about(this, "About - BankerFix-NG", "Bull-Labs - http://bull-labs.com\nCopyright 2015");

}
