#include "includes.h"

//PA7      ʵ�ֺ�����

void TIM3_CH2_PWM_Init(u16 psc,u16 arr)
{
       /********ͨ���ܽŸ��ù�������*****/
	//��PA������ʱ��
	RCC->AHB1ENR |=(1<<0);
	//ģʽ�Ĵ���
	GPIOA->MODER &=~(0x3<<14); //����
	GPIOA->MODER |=(0x2<<14);  //���ù���
	//���ù���ѡ��
	GPIOA->AFR[0] &=~((unsigned int)0xf<<28); //����
	GPIOA->AFR[0] |=((unsigned int )0x2<<28);   //���ó�TIM3
	
	/******TIM3��������������********/
	//�򿪶�ʱ������ʱ��
	 RCC->APB1ENR |=(1<<1);
	//ѡ���ڲ�ʱ����Ϊ������ʱ��Դ
	TIM3->SMCR &=~(0x7<<0);
	//д���Ƶֵ
	TIM3->PSC =psc-1;
	//д����װ��ֵ
	TIM3->ARR =arr;
	//ѡ�������ʽ ���ϼ���
	TIM3->CR1 &=~(1<<4);
	
	/******���ͨ����������*****/
	//д�벶��/�ȽϼĴ����е���ֵ
	TIM3->CCR2= arr/4; 
	
	//��ͨ������Ϊ���
	TIM3->CCMR1 &=~(0x3<<8);
	
	//ѡ���Ƿ��Ӱ�ӹ���
	TIM3->CCMR1 &=~(0x1<<11);
	
	//ѡ��pwm�������ģʽ
	TIM3->CCMR1 &=~(0x7<<12);
	TIM3->CCMR1 |=(0x6<<12);
	
	//ѡ��ͨ������Ч��ƽ
	TIM3->CCER &=~(0x1<<5);
	
	//ͨ��2���ʹ��
	TIM3->CCER |=(0x1<<4);
	
	//������ʹ��
	TIM3->CR1  |=(0x1<<0);

}