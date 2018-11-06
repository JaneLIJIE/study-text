		USART_Config();
		void DMA_Config(void)
		{
			DMA_InitTypeDef DMA_InitStructure;
	 
			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA,ENABLE);//开启时钟
	 
			NVIC_Config();     //配置DMA中断
	 
			/*设置DMA源：内存地址&串口数据寄存器地址*/
			DMA_InitStructure.DMA_PeripheralBaseAddr = USART_DR_Base;
	 
	 
			/*内存地址（要传输的变量的指针）  */
			DMA_InitStructure.DMA_MemoryBaseAddr = (u32)SendBuff;
	 
	 
			 /*方向：从内存到外设*/
			 DMA_InitStructure.DMA_DIR_PeripheralDST;
			 
			 
			 /*传输大小DMA_BufferSize=SENDBUFF_SIZE*/
			 DMA_InitStructure.DMA_BufferSize=SENDBUFF_SIZE;
			 
			 
			 /*外设地址不增*/
			 DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
			 
			 
			 /*内存地址自增*/
			 DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;


			 /*外设数据单位*/
			 DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDa taSize_Byte; 
			 
			 
			 /*内存数据单位  8bit*/
			 DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_B yte;
			 
			 
			 /*DMA模式：一次传输，循环*/
			 DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ; 
			 
			 
			 /*优先级：中*/
			 DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 
			 
			 
			 /*禁止内存到内存的传输*/
			 DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 
	 
	 
			 /*配置DMA1的4通道*/
			 DMA_Init(DMA1_Channel4, &DMA_InitStructure);       
			 
			 DMA_Cmd (DMA1_Channel4,ENABLE); //使能DMA
			 
			 DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE); //配置DMA发送完成后产生中断
		}