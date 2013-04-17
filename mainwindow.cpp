#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    _uart = new Uart("/dev/ttyUSB0");
    if ( _uart->openDevice() < 0 )
    {
        ui->console->setText("Error when opening");
    }
    else
    {
        ui->console->setText("ok.");
        _uart->setInterfaceAttrib(Uart::BR115200, 0);
        _uart->setBlocking(0);
        _timerConsole.start(1000);
        connect( &_timerConsole, SIGNAL(timeout()),this,SLOT(refresh_console()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_send_clicked()
{
    _uart->send( ui->addr->currentText().at(0).toAscii());
    _uart->send( ui->action->currentText().at(0).toAscii());



    _uart->send(ui->c0->value());
    _uart->send(ui->c1->value());
    _uart->send(ui->c2->value());
    _uart->send(ui->c3->value());
    _uart->send(ui->c4->value());
    _uart->send(ui->c5->value());
    _uart->send(ui->c6->value());



}

void MainWindow::refresh_console()
{
    QString value = _uart->readData().c_str();
    if( value.compare("")!=0 )
        ui->console->setText( value  );
}

void MainWindow::on_clear_clicked()
{
    ui->console->setText("");
}

void MainWindow::on_dc_clicked()
{
    if ( _uart->isDeviceOpen() )
    {
        _uart->closeDevice();
        ui->dc->setText("Close");
    }
    else
    {
        _uart->openDevice();
        if ( _uart->isDeviceOpen() )
            ui->dc->setText("Ok.");
    }
}

void MainWindow::on_send_c_clicked()
{
    _uart->send( ui->c->text().toStdString() );
}

void MainWindow::on_test_clicked()
{
    _uart->send(".");
}

void MainWindow::on_send_n_clicked()
{
    _uart->send( ui->n->text().toInt());
}
