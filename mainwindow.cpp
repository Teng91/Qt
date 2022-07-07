#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QGraphicsScene>
#include <iostream>
#include <QDateTime>

Mat inputimage;
Mat outputimage;
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_next = time.toString("hh : mm : ss");
    ui->label_date_time->setText(time_next);
}
void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open file"), "",tr("Images (*.png *.jpg *.jpeg *.gif)"));

        inputimage = imread(filename.toLatin1().data());
        cvtColor(inputimage,inputimage,COLOR_BGR2RGB);
        QImage image = QImage((const uchar*)(inputimage.data),inputimage.cols,inputimage.rows,QImage::Format_RGB888);
        int w = ui->graphicsView->width();
        int h = ui->graphicsView->height();
        image = image.scaled(w, h, Qt::KeepAspectRatio);
        QGraphicsScene* scene = new QGraphicsScene;
        scene->addPixmap(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        ui->graphicsView->show();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actiongray_triggered()
{
    cvtColor(inputimage,outputimage,COLOR_BGR2GRAY);
    QImage image = QImage((const uchar*)(outputimage.data),outputimage.cols,outputimage.rows,QImage::Format_Grayscale8);
    int w = ui->graphicsView_2->width();
    int h = ui->graphicsView_2->height();
    image = image.scaled(w, h, Qt::KeepAspectRatio);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();
}

void MainWindow::on_actionMono_triggered()
{
    cvtColor(inputimage,outputimage,COLOR_BGR2GRAY);
    QImage image = QImage((const uchar*)(outputimage.data),outputimage.cols,outputimage.rows,QImage::Format_MonoLSB);
    int w = ui->graphicsView_2->width();
    int h = ui->graphicsView_2->height();
    image = image.scaled(w, h, Qt::KeepAspectRatio);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();
}

void MainWindow::on_actionSave_triggered()
{
    QString format = "Images (*.png);;Images (*.jpg);;Images (*.jpeg);;Images (*.gif)";
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Image File"), QString(), format);
    cv::imwrite(filename.toStdString(),outputimage);
}

void MainWindow::on_actionRed_triggered()
{
    Mat RGBimage;
    vector<Mat> RGBchannels;
    cvtColor(inputimage, RGBimage, COLOR_RGB2BGR);
    split(RGBimage, RGBchannels);
    RGBchannels[0] = RGBchannels[0]*0;
    RGBchannels[1] = RGBchannels[1]*0;
    merge(RGBchannels, RGBimage);
    cvtColor(RGBimage, RGBimage, COLOR_BGR2RGB);
    QImage image = QImage((const uchar*)(RGBimage.data),RGBimage.cols,RGBimage.rows,QImage::Format_RGB888);
    int w = ui->graphicsView_2->width();
    int h = ui->graphicsView_2->height();
    image = image.scaled(w, h, Qt::KeepAspectRatio);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();
}


void MainWindow::on_actionGreen_triggered()
{
    Mat RGBimage;
    vector<Mat> RGBchannels;
    cvtColor(inputimage, RGBimage, COLOR_RGB2BGR);
    split(RGBimage, RGBchannels);
    RGBchannels[0] = RGBchannels[0]*0;
    RGBchannels[2] = RGBchannels[2]*0;
    merge(RGBchannels, RGBimage);
    cvtColor(RGBimage, RGBimage, COLOR_BGR2RGB);
    QImage image = QImage((const uchar*)(RGBimage.data),RGBimage.cols,RGBimage.rows,QImage::Format_RGB888);
    int w = ui->graphicsView_2->width();
    int h = ui->graphicsView_2->height();
    image = image.scaled(w, h, Qt::KeepAspectRatio);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();
}


void MainWindow::on_actionBlue_triggered()
{
    Mat RGBimage;
    vector<Mat> RGBchannels;
    cvtColor(inputimage, RGBimage, COLOR_RGB2BGR);
    split(RGBimage, RGBchannels);
    RGBchannels[1] = RGBchannels[1]*0;
    RGBchannels[2] = RGBchannels[2]*0;
    merge(RGBchannels, RGBimage);
    cvtColor(RGBimage, RGBimage, COLOR_BGR2RGB);
    QImage image = QImage((const uchar*)(RGBimage.data),RGBimage.cols,RGBimage.rows,QImage::Format_RGB888);
    int w = ui->graphicsView_2->width();
    int h = ui->graphicsView_2->height();
    image = image.scaled(w, h, Qt::KeepAspectRatio);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();
}

