#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QDir>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    xmlName = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(),tr("XML (*.xml)"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionwebcam_triggered()
{
    VideoCapture cap(0);
       if (!cap.isOpened()) {
           cout << "Cannot open camera";
       }

       Mat frame;
       Mat gray;
       while (true) {

           bool ret = cap.read(frame);
           if (!ret) {
               cout << "Can't receive frame";
               break;
           }
           //辨識人臉
           CascadeClassifier faceCascade;
           //faceCascade = cv::CascadeClassifier("file:///C:/Users/admin/Downloads/opencv-master/opencv-master/data/haarcascades/haarcascade_frontalface_alt.xml");
           faceCascade.load(xmlName.toStdString());
           if(faceCascade.empty()){
               cout << "XML file not loaded" << endl;
               break;
           }
           //框出長方形
           vector<Rect> faces;
           faceCascade.detectMultiScale(frame, faces, 1.1, 3);
           for (int i = 0; i < faces.size(); i++) {
               rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
           }


           imshow("live", frame);

           // 按'q'離開迴圈
           if (waitKey(1) == 'q') {
               destroyWindow("live");
               break;
           }
       }
       waitKey(0);
}


void MainWindow::on_actionexit_triggered()
{
    QApplication::quit();
}

