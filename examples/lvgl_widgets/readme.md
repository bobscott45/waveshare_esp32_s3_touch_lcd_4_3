    # Waveshare ESP32-S3 Touch LCD 4.3 - LVGL Widgets Example
  
    This example demonstrates how to compile and run the official LVGL Widgets demo on the Waveshare ESP32-S3 Touch LCD 4.3 board.

    ## Requirements
  
    * **Target Hardware:** Waveshare ESP32-S3-Touch-LCD-4.3 (A) board.
    * **ESP-IDF Version:** v5.3 or higher.
  
    ## Building and Flashing
  
    Because this project uses board-specific RGB display timings and Octal PSRAM configurations, the build target is locked to the `esp32s3`.

    1. **Set the build target:**
       ```bash
       idf.py set-target esp32s3

    2. Build the project:
        idf.py build

    3. Flash the executable and open the serial monitor:
        idf.py flash monitor
  


