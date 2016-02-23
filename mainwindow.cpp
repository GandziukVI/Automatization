#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "VisaDevice/includes/iexperimentaldevice.h"
#include "VisaDevice/includes/visadevice.h"

#include "VisaDevice/includes/tests.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SuperClass* sClass = new SuperClass();

    QObject::connect(ui->cmdPushMe, SIGNAL(clicked(bool)), sClass, SLOT(RequestSubmitted(bool)));
    QObject::connect(sClass, SIGNAL(PrintRequest(QString)), ui->textEdit, SLOT(setPlainText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
