# Waveshare ESP32-S3 Touch LCD 4.3 Board Support Package (BSP)

    This repository contains the ESP-IDF component driver for the **Waveshare ESP32-S3 Touch LCD 4.3 (A)** development board.
It provides complete initialization for the 4.3-inch 800x480 RGB display and the GT911 capacitive touch screen (interfaced
via a CH422G I/O expander).

    The hardware driver is fully decoupled from the UI framework, allowing you to use the screen independently or with the   
built-in, thread-safe LVGL porting layer.

    ## Features                                                                                                              
                                                                                                                             
    * **RGB LCD Panel:** Support for the high-resolution 800x480 screen via ESP-IDF's `esp_lcd` driver.                      
    * **Touch Controller:** Integrated GT911 capacitive touchscreen.                                                         
    * **Backlight Control:** Managed via the onboard CH422G I2C I/O expander.                                                
    * **Optional LVGL Integration:** Pre-configured LVGL porting layer running in a dedicated thread with recursive mutex    
locking.                                                                                                                   
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
    | **RGB Data (D0-D15)** | GPIO 14, 38, 18, 17, 10, 39, 0, 45, 48, 47, 21, 1, 2, 42, 41, 40 | 16-bit parallel RGB bus (565
color format) |

    ---                                                                                                                      

## How to Include in Your Project

### Option 1: Via the Espressif Component Registry (Recommended)
You can add this component to your project automatically by running this command inside your project directory:          
```bash
    idf.py add-dependency waveshare_esp32_s3_touch_lcd_4_3
````

### Option 2: Via Git Dependency

Alternatively, you can include it directly by adding the repository as a dependency in your project's  
main/idf_component.yml  file:
```yaml
    dependencies:
      waveshare_esp32_s3_touch_lcd_4_3:
        git: https://github.com/bobscott45/waveshare_esp32_s3_touch_lcd_4_3.git
```

## Quick Start (LVGL Usage)

In your application's  main.c , initialize the board and start the LVGL engine using the following sequence:

```C
    #include "bsp/board.h"                                                                                                   
    #include "lvgl_port.h"                                                                                                   
                                                                                                                             
    void app_main(void)                                                                                                      
    {                                                                                                                        
        esp_lcd_panel_handle_t panel = NULL;                                                                                 
        esp_lcd_touch_handle_t touch = NULL;                                                                                 
                                                                                                                             
        // 1. Initialize hardware drivers independently                                                                      
        ESP_ERROR_CHECK(waveshare_esp32_s3_rgb_lcd_init(&panel, &touch));                                                    
                                                                                                                             
        // 2. Initialize the LVGL port task loop with retrieved handles                                                      
        ESP_ERROR_CHECK(lvgl_port_init(panel, touch));                                                                       
                                                                                                                             
        // 3. Turn on the screen backlight                                                                                   
        ESP_ERROR_CHECK(waveshare_rgb_lcd_bl_on());                                                                          
                                                                                                                             
        // Now you can lock the port and build your UI...                                                                    
        if (lvgl_port_lock(-1)) {                                                                                            
            // Create widgets/screens                                                                                        
            lvgl_port_unlock();                                                                                              
        }                                                                                                                    
    }                                                                                                                        
```

## Running the Example

An example demonstrating the official LVGL widgets benchmark is included in this repository.

1. Navigate to the example folder:                                                                                         
   cd examples/lvgl_widgets

2. Set the S3 build target:
   idf.py set-target esp32s3

3. Build, flash, and monitor:
   idf.py build flash monitor

