#pragma once
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 20

//ѭ������
typedef struct {
	int data[Maxsize];
	int front, rear;
}Squeue;

//��ʽ����
typedef struct linknode {
	int data;
	struct linknode* next;
}LinkNode;

typedef struct linkqueue {
	LinkNode *front, *rear;
}LinkQueue;

/***************************************ѭ������***************************************/
//��ʼ��ѭ������
bool Init_Squeue(Squeue&);
//�ж�ѭ�������Ƿ�Ϊ��
bool Empty_Squeue(Squeue );
//ѭ��������Ӳ���
bool En_Squeue(Squeue&, int);
//ѭ�����г��Ӳ���
bool Del_Squeue(Squeue& , int& );
//���ѭ�����ж�ͷ����
bool Gethead_Squeue(Squeue , int& );
//���ѭ�����е�Ԫ�ظ���
bool GetLenth_Squeue(Squeue, int&);
/***************************************ѭ������****************************************/

/*------------------------------------------------------------------------------------*/

/***************************************��ʽ����***************************************/

//����ͷ�ڵ����ʽ���г�ʼ��
bool NoHead_Linkqueue_Init(LinkQueue&);
//��ͷ�ڵ����ʽ���г�ʼ��
bool Linkqueue_Init(LinkQueue&);
//����ͷ�ڵ����ʽ�����п�
bool NoHead_Linkqueue_Empty(LinkQueue);
//��ͷ�ڵ����ʽ�����п�
bool Linkqueue_Empty(LinkQueue);
//����ͷ�ֵ���ʽ�������
bool NoHead_EN_Linkqueue(LinkQueue& , int);
//��ͷ�ڵ���ʽ�������
bool EN_Linkqueue(LinkQueue& , int );
//����ͷ�ڵ���ʽ���г���
bool NoHead_Del_Linkqueue(LinkQueue& , int& );
//��ͷ�����ʽ���г���
bool Del_Linkqueue(LinkQueue& , int& );
/***************************************��ʽ����***************************************/
