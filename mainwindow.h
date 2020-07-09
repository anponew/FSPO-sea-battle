#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "client.h"
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    Client* cl;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

    void sendButtonClick();

    void connectUnsuccess();

    void handleError(QAbstractSocket::SocketError socketError);
private:

    Ui::MainWindow *ui;
private slots:
 void handleButton();
void handleButton_a5_2();
void handleButton_c1();
void handleButton_b2_2();
void handleButton_j5();
void handleButton_h10_2();
void handleButton_h1_2();
void handleButton_d3();


private:
 QPushButton *button;

};
#endif // MAINWINDOW_H
