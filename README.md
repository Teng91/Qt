# Qt 與 OpenCV 安裝使用教學
## 安裝 Qt 6.0.2
- 可以從 Qt 官網 https://www.qt.io/ 下載並安裝 Qt Creator(開發Qt應用程式的IDE)
## 安裝 OpenCV 4.10.0
- Windows: 可以使用 OpenCV 官方網站提供的安裝檔 https://opencv.org/blog/opencv-4-10-0/
- Linux: 在 Ubuntu 上通過包管理器安裝 ```sudo apt-get install libopencv-dev```
- macOS: 通過 Homebrew 安裝 ```brew install opencv```
## 在 Qt Creator 中配置 OpenCV
1. 打開 Qt Creator，創建一個新的 Qt Widgets Application
2. 配置 .pro 文件以包含 OpenCV 函式庫： 打開項目的 .pro 文件，並將以下內容添加到文件中
```pro
# OpenCV 配置
INCLUDEPATH += C:/path/to/opencv/include
LIBS += -LC:/path/to/opencv/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc
```
- ```C:/path/to/opencv/include``` 替換為安裝 OpenCV 時包含檔案的目錄
- ```C:/path/to/opencv/lib``` 替換為安裝 OpenCV 時函式庫文件的目錄
3. 將 OpenCV 目錄添加到 PATH 系統環境變量
4. 在 Qt 代碼中包含 OpenCV 標頭文件：
```cpp
#include <opencv2/opencv.hpp>
```
5. 使用OpenCV函數
- 以下例子展示如何用 OpenCV 打開一個影像並在 Qt 窗口中顯示
```cpp
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QLabel>
#include <QPixmap>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        // 加載圖像
        cv::Mat img = cv::imread("path_to_image.jpg");
        if (img.empty()) {
            qDebug() << "Image not found!";
            return;
        }

        // 將 Mat 轉換為 QImage
        QImage qImg = QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);

        // 顯示圖像
        QLabel *label = new QLabel(this);
        label->setPixmap(QPixmap::fromImage(qImg.rgbSwapped())); // OpenCV 默認是 BGR 格式，Qt 需要 RGB
        label->setFixedSize(qImg.size());
        setCentralWidget(label);
    }
};
```
