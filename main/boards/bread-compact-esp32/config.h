#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

// Microphone Pins
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_18  // Replace 18 with your WS pin
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_19  // Replace 19 with your SCK pin
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_23  // Replace 23 with your DIN/SD pin

// Speaker Output Disabled (Set to GPIO_NUM_NC if unused or assign your I2S DAC pins)
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_NC
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_NC
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_NC

#endif

// Button & LED Pins
#define BOOT_BUTTON_GPIO        GPIO_NUM_0   // Replace 0 with your Boot button pin
#define TOUCH_BUTTON_GPIO       GPIO_NUM_5   // Replace 5 with your Touch button pin
#define ASR_BUTTON_GPIO         GPIO_NUM_13  // Replace 13 with your ASR button pin
#define BUILTIN_LED_GPIO        GPIO_NUM_2   // Replace 2 with your Status LED pin

// Display Pins
#define DISPLAY_SDA_PIN         GPIO_NUM_21  // Replace 21 with your Display SDA pin

#endif // BOARD_CONFIG_H
