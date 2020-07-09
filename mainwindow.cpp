#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QPushButton>
#include <QObject>
#include <string>
#include <QCoreApplication>
//#include "stdafx.h"
#include <QGridLayout>
#include <QLayout>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //QComboBox *ship_box = new QComboBox();

    ui->setupUi(this);
    ui->ship_box->addItem("Empty");
    ui->ship_box->addItem("1 deck");
    ui->ship_box->addItem("2 deck");
    ui->ship_box->addItem("3 deck");
    ui->ship_box->addItem("4 deck");

   connect(ui->a6, SIGNAL (released()),this, SLOT (handleButton()));
    connect(ui->a5_2, SIGNAL (released()),this, SLOT (handleButton_a5_2()));
    connect(ui->c1, SIGNAL (released()),this, SLOT (handleButton_c1()));
    connect(ui->b2_2, SIGNAL (released()),this, SLOT (handleButton_b2_2()));
    connect(ui->j5, SIGNAL (released()),this, SLOT (handleButton_j5()));
    connect(ui->h10_2, SIGNAL (released()),this, SLOT (handleButton_h10_2()));
    connect(ui->h1_2, SIGNAL (released()),this, SLOT (handleButton_h1_2()));
    connect(ui->d3, SIGNAL (released()),this, SLOT (handleButton_d3()));

    //bool matrix[10][10];

    //int x, y;
    //x=rand() % 9;
    //y=rand() % 9;

 // matrix[x][y]=true;
  //matrix[x][y]=true;
  //matrix[x][y]=true;

  //ui->gridLayout_2->ItemAtPosition(x,y);

  //for (int i=0; i<10; i++)
    //{
      //for (int j=0; j<10; j++)
      //{
          //if (i==0) { std::string text = "a";
             //text += std::to_string(i);
              //QPushButton* button = this->findChild<QPushButton*>();
              //connect(button, SIGNAL (released()), this, SLOT (handleButton()));


              //button.setStyleSheet("QPushButton {hover{"background-color: red; }}");
          //}
     // }
  // }
    cl = new Client(this);
    cl->readUserName();
    this->setWindowTitle(cl->userName);


    cl->readAddress();

    connect(cl, &Client::cannotConnect, this, &MainWindow::connectUnsuccess);
    cl->connectToServer();


    connect(cl->socketClient, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MainWindow::handleError);



}
void MainWindow::handleButton()
{
 ui->a6->setText("X");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/cow.mp3"));
 player->play();
}

void MainWindow::handleButton_a5_2()
{
 ui->a5_2->setText("X");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/cow.mp3"));
 player->play();
}

void MainWindow::handleButton_c1()
{
 ui->c1->setText("X");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/cow.mp3"));
 player->play();
}

void MainWindow::handleButton_b2_2()
{
 ui->b2_2->setText("X");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/cow.mp3"));
 player->play();
}

void MainWindow::handleButton_j5()
{
 ui->j5->setText("X");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/cow.mp3"));
 player->play();
}

void MainWindow::handleButton_h10_2()
{
 ui->h10_2->setText("X");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/cow.mp3"));
 player->play();
}

void MainWindow::handleButton_h1_2()
{
 ui->h1_2->setText("0");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/aaa.mp3"));
 player->play();
}

void MainWindow::handleButton_d3()
{
 ui->d3->setText("0");
 QMediaPlayer* player = new QMediaPlayer();
 player->setMedia(QUrl::fromLocalFile("C:/morskoy_boi_udali/voina/aaa.mp3"));
 player->play();
}

MainWindow::~MainWindow()
{
    cl->socketClient->close();
    delete ui;
}

void MainWindow::sendButtonClick()
{


}

void MainWindow::connectUnsuccess()
{

}

void MainWindow::handleError(QAbstractSocket::SocketError socketError)
{
    qDebug() << socketError;
    connectUnsuccess();
}



