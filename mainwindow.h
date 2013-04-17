#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "uart.h"

#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_send_clicked();
    void refresh_console();

    void on_clear_clicked();

    void on_dc_clicked();

    void on_send_c_clicked();

    void on_test_clicked();

    void on_send_n_clicked();

private:
    Ui::MainWindow *ui;

    Uart* _uart;
    QTimer _timerConsole;
};

#endif // MAINWINDOW_H
