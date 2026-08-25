#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Using Simplex I2S Mode
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

// Custom INMP441 Microphone Pins
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_18
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_19
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_23

// Speaker Disabled (No Connection)
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_NC
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_NC
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_NC

#else

#define AUDIO_I2S_GPIO_WS   GPIO_NUM_NC
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_NC
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_NC
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_NC

#endif

#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_5
#define ASR_BUTTON_GPIO         GPIO_NUM_13  // Shifted from GPIO_NUM_19 to avoid I2S SCK conflict
#define BUILTIN_LED_GPIO        GPIO_NUM_2

#define ML307_RX_PIN            GPIO_NUM_16
#define ML307_TX_PIN            GPIO_NUM_17

// Standard I2C OLED Display Pins (SSD1306)
#define DISPLAY_SDA_PIN         GPIO_NUM_21
#define DISPLAY_SCL_PIN         GPIO_NUM_22
#define DISPLAY_WIDTH           128

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64 || CONFIG_OLED_SH1106_128X64
#define DISPLAY_HEIGHT  64
#else
#define DISPLAY_HEIGHT  64  // Default fallback if menuconfig setting is not set
#endif

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

// Control pin
#define LAMP_GPIO GPIO_NUM_4

#endif // _BOARD_CONFIG_H_
