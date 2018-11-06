		USART_Config();
		void DMA_Config(void)
		{
			DMA_InitTypeDef DMA_InitStructure;
	 
			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA,ENABLE);//����ʱ��
	 
			NVIC_Config();     //����DMA�ж�
	 
			/*����DMAԴ���ڴ��ַ&�������ݼĴ�����ַ*/
			DMA_InitStructure.DMA_PeripheralBaseAddr = USART_DR_Base;
	 
	 
			/*�ڴ��ַ��Ҫ����ı�����ָ�룩  */
			DMA_InitStructure.DMA_MemoryBaseAddr = (u32)SendBuff;
	 
	 
			 /*���򣺴��ڴ浽����*/
			 DMA_InitStructure.DMA_DIR_PeripheralDST;
			 
			 
			 /*�����СDMA_BufferSize=SENDBUFF_SIZE*/
			 DMA_InitStructure.DMA_BufferSize=SENDBUFF_SIZE;
			 
			 
			 /*�����ַ����*/
			 DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
			 
			 
			 /*�ڴ��ַ����*/
			 DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;


			 /*�������ݵ�λ*/
			 DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDa taSize_Byte; 
			 
			 
			 /*�ڴ����ݵ�λ  8bit*/
			 DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_B yte;
			 
			 
			 /*DMAģʽ��һ�δ��䣬ѭ��*/
			 DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ; 
			 
			 
			 /*���ȼ�����*/
			 DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 
			 
			 
			 /*��ֹ�ڴ浽�ڴ�Ĵ���*/
			 DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 
	 
	 
			 /*����DMA1��4ͨ��*/
			 DMA_Init(DMA1_Channel4, &DMA_InitStructure);       
			 
			 DMA_Cmd (DMA1_Channel4,ENABLE); //ʹ��DMA
			 
			 DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE); //����DMA������ɺ�����ж�
		}