/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int16_t X = 32;
int16_t st1;
int16_t stflag1 = 0;
int16_t st2;
int16_t stflag2 = 0;
int16_t st3;
int16_t cnt11 = 0;
int16_t cnt12 = 0;
int16_t cnt13 = 0;
int16_t cnt14 = 0;
int16_t cnt21 = 0;
int16_t cnt22 = 0;
int16_t cnt23 = 0;
int16_t cnt24 = 0;
int16_t stflag3 = 0;
int myArray[];
int x =6;
int y =4;
int oldx =0;
int oldy =0;
uint16_t Period = 70;
uint16_t TickNum = 1; //150
extern volatile uint16_t fps=0;

extern uint8_t data1[16], data2[16], data3[16], data4[16];


void you()
{
	//Y
			  disp1color_DrawLine(24,8,24,9);
			  disp1color_DrawPixel(23,10,1);
			  disp1color_DrawPixel(25,10,1);
			  disp1color_DrawLine(26,11,26,13);
			  disp1color_DrawLine(22,11,22,13);
	//O
			  disp1color_DrawLine(15,8,15,13);
			  disp1color_DrawLine(19,8,19,13);
			  disp1color_DrawLine(19,8,15,8);
			  disp1color_DrawLine(19,13,15,13);
	//U
			  disp1color_DrawLine(8,8,8,13);
			  disp1color_DrawLine(12,8,12,13);
			  disp1color_DrawLine(12,8,8,8);
	//L
			  disp1color_DrawLine(26,1,26,6);
			  disp1color_DrawLine(26,1,22,1);
}

void lose()
{
	//L
			  disp1color_DrawLine(26,1,26,6);
			  disp1color_DrawLine(26,1,22,1);

	//O
			  disp1color_DrawLine(15,1,15,6);
			  disp1color_DrawLine(19,1,19,6);
			  disp1color_DrawLine(19,1,15,1);
			  disp1color_DrawLine(19,6,15,6);

	//S
			  disp1color_DrawLine(9,1,11,1);
			  disp1color_DrawLine(9,6,11,6);
			  disp1color_DrawLine(9,3,10,3);
			  disp1color_DrawPixel(8,2,1);
			  disp1color_DrawPixel(12,5,1);
			  disp1color_DrawPixel(11,4,1);

	//E
			  disp1color_DrawLine(1,1,5,1);
			  disp1color_DrawLine(2,4,5,4);

			  disp1color_DrawLine(1,6,5,6);
			  disp1color_DrawLine(5,1,5,6);
}

void win(){
	//w
			  disp1color_DrawPixel(25,1,1);
			  disp1color_DrawPixel(23,1,1);
			  disp1color_DrawLine(26,2,26,6);
			  disp1color_DrawLine(22,6,22,2);
			  disp1color_DrawLine(24,2,24,4);

			  //I
			  disp1color_DrawLine(18,1,18,6);
			  disp1color_DrawLine(19,1,17,1);
			  disp1color_DrawLine(19,6,17,6);

			  //N
			  disp1color_DrawLine(8,1,8,6);
			  disp1color_DrawLine(12,1,12,6);
			  disp1color_DrawPixel(9,3,1);
			  disp1color_DrawPixel(10,4,1);
			  disp1color_DrawPixel(11,5,1);
}

void oneone()
{
	disp1color_DrawLine(24,8,26,8);
	disp1color_DrawLine(25,8,25,13);
	disp1color_DrawPixel(26,12,1);
}

void onetwo()
{
	disp1color_DrawLine(15,8,20,13);
	disp1color_DrawLine(20,8,15,13);
}

void onethree()
{
	disp1color_DrawLine(8,8,13,13);
	disp1color_DrawLine(13,8,8,13);
}

void onefour()
{
	  disp1color_DrawLine(1,8,5,8);
	  disp1color_DrawPixel(5,9,1);
	  disp1color_DrawPixel(5,12,1);
	  disp1color_DrawPixel(1,12,1);
	  disp1color_DrawPixel(4,10,1);
	  disp1color_DrawLine(2,11,3,11);
	  disp1color_DrawLine(2,13,4,13);
}

void twoone()
{
	  disp1color_DrawLine(24,1,26,1);
	  disp1color_DrawLine(25,1,25,6);
	  disp1color_DrawPixel(26,5,1);
}

void twotwo()
{
	  disp1color_DrawPixel(15,2,1);
	  disp1color_DrawPixel(19,2,1);
	  disp1color_DrawPixel(15,5,1);
	  disp1color_DrawPixel(19,5,1);
	  disp1color_DrawLine(16,1,18,1);
	  disp1color_DrawLine(16,3,17,3);
	  disp1color_DrawLine(16,4,17,4);
	  disp1color_DrawLine(18,6,16,6);
}

void twothree()
{
	  disp1color_DrawLine(8,1,13,6);
	  disp1color_DrawLine(13,1,8,6);
}

void twofour()
{
	  disp1color_DrawLine(1,1,5,1);
	  disp1color_DrawPixel(5,2,1);
	  disp1color_DrawPixel(5,5,1);
	  disp1color_DrawPixel(1,5,1);
	  disp1color_DrawPixel(4,3,1);
	  disp1color_DrawLine(2,4,3,4);
	  disp1color_DrawLine(2,6,4,6);
}

void blacktwofour()
{
	 disp1color_DrawPixel(1,1,0);
	 disp1color_DrawPixel(2,1,0);
	 disp1color_DrawPixel(3,1,0);
	 disp1color_DrawPixel(4,1,0);
	 disp1color_DrawPixel(5,1,0);
	 disp1color_DrawPixel(5,2,0);
	 disp1color_DrawPixel(4,3,0);
	 disp1color_DrawPixel(3,4,0);
	 disp1color_DrawPixel(2,4,0);
	 disp1color_DrawPixel(1,5,0);
	 disp1color_DrawPixel(5,5,0);
	 disp1color_DrawPixel(2,6,0);
	 disp1color_DrawPixel(3,6,0);
	 disp1color_DrawPixel(4,6,0);

}

void blackarea (int16_t x1, int16_t y1, int16_t x2, int16_t y2)
{

	for(uint8_t i = x1; i >= x2; i--)
		{
		  disp1color_DrawPixel(i,y1,0);
		}

	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y1-1,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y1-2,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y1-3,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y1-4,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y1-5,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-5,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-6,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-7,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-8,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-9,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-10,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-11,0);
				}
	for(uint8_t i = x1; i >= x2; i--)
				{
				  disp1color_DrawPixel(i,y1-12,0);
				}


}

void blackrec (int16_t x1, int16_t y1, int16_t x2, int16_t y2)
{
	disp1color_DrawPixel(x1,y1,0);
	disp1color_DrawPixel(x1-1,y1,0);
	disp1color_DrawPixel(x2,y2,0);
	disp1color_DrawPixel(x2+1,y2,0);
	/*
	for(uint8_t i = x1; i >= x2; i--)
		{
		  disp1color_DrawPixel(i,y,0);
		}

	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y-1,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y-2,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y-3,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y-4,0);
			}
	for(uint8_t i = x1; i >= x2; i--)
			{
			  disp1color_DrawPixel(i,y-5,0);
			}
			*/
}

void drrec(int16_t x1, int16_t y1, int16_t x2, int16_t y2)
{
	for(uint8_t i = y2; i <= y1; i++)
	{
		 disp1color_DrawLine(x1,i,x2,i);
	}

}

void disp_row(int row){


	  if (row == 0){

		  for(uint8_t i=0; i<6; i++){
		  		HAL_SPI_Transmit(&hspi1, &data1, 16, 10);
		  }

		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
	  }
	  if (row == 1){

		  for(uint8_t i=0; i<6; i++){
		  		HAL_SPI_Transmit(&hspi1, &data2, 16, 10);
		  }

		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
	  }

	  if (row == 2){

		  for(uint8_t i=0; i<6; i++){
		  		HAL_SPI_Transmit(&hspi1, &data3, 16, 10);
		  }

		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  }

	  if (row == 3){

		  for(uint8_t i=0; i<6; i++){
		  		HAL_SPI_Transmit(&hspi1, &data4, 16, 10);
		  }

		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  }


	  HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_SET);
		  for(uint32_t x=0; x<=500; x++) {};
	 HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
  }

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
 HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
 HAL_TIM_Base_Start_IT(&htim1);
 char *pMyStr = "";  //РЎС‚СЂРѕРєР° РЅР° РІС‹РІРѕРґ
 uint16_t strSize = strlen(pMyStr);
 uint8_t symbolDelay = 2;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //disp1color_FillScreenbuff(0);



		  disp1color_DrawLine(0,0,28,0);
		  disp1color_DrawLine(0,14,28,14);
		  disp1color_DrawLine(0,7,28,7);
		  disp1color_DrawLine(0,0,0,14);
		  disp1color_DrawLine(7,0,7,14);
		  disp1color_DrawLine(14,0,14,14);
		  disp1color_DrawLine(21,0,21,14);
		  disp1color_DrawLine(28,0,28,14);






		  st1 = !(HAL_GPIO_ReadPin(button_GPIO_Port,button_Pin));
		  st2 = !(HAL_GPIO_ReadPin(button2_GPIO_Port,button2_Pin));
		  st3 = !(HAL_GPIO_ReadPin(button3_GPIO_Port,button3_Pin));


		  if(st1 == 1 && stflag1==0 )
		  {
			  stflag1=1;
			  if (x==6 && y==4)
			  {
				  twofour();
				  cnt24 =1;
			  }
			  if (x==13 && y==4)
			  {
				  twothree();
				  cnt23 =1;
			  }
			  if (x==20 && y==4)
			  {
			  	 twotwo();
			  	cnt22 =1;
			  }
			  if (x==27 && y==4)
			  {
			  	 twoone();
			  	cnt21 =1;
			  }

			  if (x==6 && y==11)
			  {
			  	onefour();
			  	cnt14 =1;
			  }
			  if (x==13 && y==11)
			  {
			  	onethree();
			  	cnt13 =1;
			  }
			  if (x==20 && y==11)
			  {
			  	onetwo();
			  	cnt12 =1;
			  }
			  if (x==27 && y==11)
			  {
			    oneone();
			    cnt11 =1;
			  }


		  }

		  if (cnt12==1 || cnt13==1 || cnt23==1)
		  {
			  blackarea(27,13,1,1);
			  you();
			  lose();

		  }

		  if (cnt11==1 && cnt21==1 && cnt22==1 && cnt14==1 && cnt24==1)
		  {
			  blackarea(27,13,1,1);
			  you();
			  win();
		  }

		  if (st1 ==0 && stflag1==1)
		  {
			  stflag1=0;
		  }


		  if(st2 == 1 && stflag2==0 )
		  {
	        stflag2=1;
	        oldx=x;
	        oldy=y;

	        if (x == 27)
	        {
	         x=6;
	        }
	        else{
	         x = x+7;
	        }
	        drrec(x,y,x-1,y-1);
	        blackrec(oldx,oldy,oldx-1,oldy-1);
		  }
		   if (st2 ==0 && stflag2==1)
		   {
		  	 stflag2=0;
		  }



		  if(st3 == 1 && stflag3==0 )
		  {
		    stflag3=1;
		    oldx=x;
		    oldy=y;
			   if (y == 11)
			   {
				  y=4;
			   }
			   else
			   {
				 y = y+7;
			   }
		   drrec(x,y,x-1,y-1);
		   blackrec(oldx,oldy,oldx-1,oldy-1);

		  }
		  if (st3 ==0 && stflag3==1)
		  {
		  	stflag3=0;
          }


		  disp1color_UpdateFromBuff(); //РџРµСЂРµРІРѕРґ СЂР°СЃСЃС‡РёС‚Р°РЅРЅС‹С… РґР°РЅРЅС‹С… РІ Р�?Р°СЃСЃРёРІ
		 		  prepare_data(); //Р Р°Р·Р±РёРµРЅРёРµ Р�?Р°СЃСЃРёРІР° РЅР° Р�?Р°СЃСЃРёРІС‹ РїРѕРґ РєР°Р¶РґСѓСЋ СЃС‚СЂРѕРєСѓ
		  //Р’РєР»СЋС‡РµРЅРёРµ Р�?Р°С‚СЂРёС†С‹ (РїРѕСЃС‚СЂРѕС‡РЅРѕ)
		  for(uint8_t i=0; i<20; i++){
			  disp_row(0);
			  disp_row(1);
			  disp_row(2);
			  disp_row(3);
		  }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
