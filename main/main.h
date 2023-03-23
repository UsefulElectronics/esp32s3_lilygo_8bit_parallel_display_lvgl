
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  main.h
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Aug 20, 2022
 * @brief   		:
 *
 ******************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_


/* INCLUDES ------------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// Please update the following configuration according to your LCD spec //////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define EXAMPLE_LCD_PIXEL_CLOCK_HZ     (6528000) // 170 (h) * 320 (w) * 2 (sizeof(lv_color_t)) * 60 (max fps)
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL  1
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL

#define EXAMPLE_PIN_NUM_DATA0          39
#define EXAMPLE_PIN_NUM_DATA1          40
#define EXAMPLE_PIN_NUM_DATA2          41
#define EXAMPLE_PIN_NUM_DATA3          42
#define EXAMPLE_PIN_NUM_DATA4          45
#define EXAMPLE_PIN_NUM_DATA5          46
#define EXAMPLE_PIN_NUM_DATA6          47
#define EXAMPLE_PIN_NUM_DATA7          48

#define EXAMPLE_PIN_RD          	   GPIO_NUM_9
#define EXAMPLE_PIN_PWR          	   15
#define EXAMPLE_PIN_NUM_PCLK           GPIO_NUM_8		//LCD_WR
#define EXAMPLE_PIN_NUM_CS             6
#define EXAMPLE_PIN_NUM_DC             7
#define EXAMPLE_PIN_NUM_RST            5
#define EXAMPLE_PIN_NUM_BK_LIGHT       38

// The pixel number in horizontal and vertical
#define EXAMPLE_LCD_H_RES              320
#define EXAMPLE_LCD_V_RES              170
#define LVGL_LCD_BUF_SIZE            (EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES)
// Bit number used to represent command and parameter
#define EXAMPLE_LCD_CMD_BITS           8
#define EXAMPLE_LCD_PARAM_BITS         8

#define EXAMPLE_LVGL_TICK_PERIOD_MS    2
/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/



#endif /* MAIN_MAIN_H_ */

/**************************  Useful Electronics  ****************END OF FILE***/
