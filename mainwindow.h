#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>
using namespace cv;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void myfunction();
private slots:
    void on_actionOpen_triggered();

    void on_actionQuit_triggered();

    void on_actiongray_triggered();

    void on_actionMono_triggered();

    void on_actionSave_triggered();

    void on_actionEdge_triggered();

    void on_actionRed_triggered();

    void on_actionGreen_triggered();

    void on_actionBlue_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H
