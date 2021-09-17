#pragma once
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 20

//循环队列
typedef struct {
	int data[Maxsize];
	int front, rear;
}Squeue;

//链式队列
typedef struct linknode {
	int data;
	struct linknode* next;
}LinkNode;

typedef struct linkqueue {
	LinkNode *front, *rear;
}LinkQueue;

/***************************************循环队列***************************************/
//初始化循环队列
bool Init_Squeue(Squeue&);
//判断循环队列是否为空
bool Empty_Squeue(Squeue );
//循环队列入队操作
bool En_Squeue(Squeue&, int);
//循环队列出队操作
bool Del_Squeue(Squeue& , int& );
//获得循环队列队头数据
bool Gethead_Squeue(Squeue , int& );
//获得循环队列的元素个数
bool GetLenth_Squeue(Squeue, int&);
/***************************************循环队列****************************************/

/*------------------------------------------------------------------------------------*/

/***************************************链式队列***************************************/

//不带头节点的链式队列初始化
bool NoHead_Linkqueue_Init(LinkQueue&);
//带头节点的链式队列初始化
bool Linkqueue_Init(LinkQueue&);
//不带头节点的链式队列判空
bool NoHead_Linkqueue_Empty(LinkQueue);
//带头节点的链式队列判空
bool Linkqueue_Empty(LinkQueue);
//不带头街点链式队列入队
bool NoHead_EN_Linkqueue(LinkQueue& , int);
//带头节点链式队列入队
bool EN_Linkqueue(LinkQueue& , int );
//不带头节点链式队列出队
bool NoHead_Del_Linkqueue(LinkQueue& , int& );
//带头结点链式队列出队
bool Del_Linkqueue(LinkQueue& , int& );
/***************************************链式队列***************************************/
