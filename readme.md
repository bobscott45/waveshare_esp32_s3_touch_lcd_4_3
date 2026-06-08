    # Waveshare ESP32-S3 Touch LCD 4.3 Dev Board Driver                                                           
                                                                                                                             
    This repository contains the ESP-IDF component driver for the **Waveshare ESP32-S3 Touch LCD 4.3 (A)** development board. It provides complete initialization for the 4.3-inch 800x480 RGB display, the GT911 capacitive touch screen (interfaced viaa CH422G I/O expander), and a thread-safe LVGL porting layer.

    ## Features                                                                                                              
                                                                                                                             
    * **RGB LCD Panel:** Support for the high-resolution 800x480 screen via ESP-IDF's `esp_lcd` driver.
    * **Touch Controller:** Integrated GT911 capacitive touchscreen.
    * **Backlight Control:** Managed via the onboard CH422G I2C I/O expander.
    * **LVGL Integration:** Pre-configured LVGL porting layer running in a dedicated thread with recursive mutex locking.    
    * **Optimized Configs:** Full support for Octal PSRAM at 80 MHz to prevent LCD DMA underflow.
  
    ---
  
    ## Hardware Pinout Configuration
  
    | Signal | GPIO / Interface | Description |
    |---|---|---|
    | **I2C SDA** | GPIO 8 | Shared I2C data bus (Touch controller / CH422G) |
    | **I2C SCL** | GPIO 9 | Shared I2C clock bus |
    | **RGB HSYNC** | GPIO 46 | Horizontal Synchronization |
    | **RGB VSYNC** | GPIO 3 | Vertical Synchronization |
    | **RGB DE** | GPIO 5 | Data Enable |
    | **RGB PCLK** | GPIO 7 | Pixel Clock |
    | **RGB Data (D0-D15)** | GPIO 14, 38, 18, 17, 10, 39, 0, 45, 48, 47, 21, 1, 2, 42, 41, 40 | 16-bit parallel RGB bus (565color format) |

    ---
  
    ## How to Include in Your Project
  
    Add this repository as a git dependency in your project's `main/idf_component.yml` file:
  
~~~~
dependencies:
  waveshare_esp32_s3_touch_lcd_4_3:
    git: https://github.com/bobscott45/waveshare_esp32_s3_touch_lcd_4_3.git
~~~~
## Running the Example

An example demonstrating the official LVGL widgets benchmark is included in this repository.

    1. Navigate to the example folder:
        cd examples/lvgl_widgets

    2. Set the S3 build target:
        idf.py set-target esp32s3

    3. Build, flash, and monitor:
        idf.py build flash monitor
  


