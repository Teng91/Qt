# 臉部辨識 + 追蹤雲台系統

這個項目實現了基於 Raspberry Pi 和攝像頭的臉部辨識和追蹤雲台控制系統，使用 Python 編寫，並運用了 OpenCV 的 Haar Cascade 進行人臉辨識。系統控制步進馬達來實現雲台的精確運動，使雲台能夠自動追蹤人臉。

## 功能介紹

- 使用 Raspberry Pi 和攝像頭進行實時影像捕捉。
- 利用 Haar Cascade 演算法進行人臉辨識。
- 根據辨識到的人臉位置，控制步進馬達進行自動追蹤。

## 系統架構

- **硬體**：
  - Raspberry Pi 4
  - Raspberry Pi Camera Module 或 USB 攝像頭
  - 伺服馬達
  - 雲台

- **軟體**：
  - Python 3.x
  - OpenCV 4.x
  - Raspberry Pi GPIO（用於控制馬達）
  - ```RPi.GPIO``` 或 ```gpiozero``` 庫（用於操作 GPIO 引腳）
