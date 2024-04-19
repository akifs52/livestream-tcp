#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    player = new QMediaPlayer(ui->widget);
    videoWidget =new QVideoWidget(ui->widget);
    videoWidget->setMaximumSize(ui->widget->size());    //widgeta multimediayı genişletiyor
    videoWidget->setMinimumSize(ui->widget->size());

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  /*  player = new QMediaPlayer(ui->widget);
    videoWidget =new QVideoWidget(ui->widget); //burda daha gerek yok
*/
    if(!ui->lineEdit->text().isEmpty())
    {
        if(player->isPlaying())
        {
            player->stop();
            videoWidget->close();   //fazla video açılmasını engllemek için kullanıldı hem videoyu kapatıyor hem penceresini kapatıyor.
        }

        ip = ui->lineEdit->text();
        player->setVideoOutput(videoWidget);
        player->setSource(QUrl("tcp://"+ip)); //tcp://
        player->play();
        videoWidget->show();
    }
}
