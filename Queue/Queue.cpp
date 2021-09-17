#include "Queue.h"

/***************************************循环队列***************************************/
//初始化循环队列
bool Init_Squeue(Squeue& Q) {
	Q.front = Q.rear = 0;
	return true;
}

//判断循环队列是否为空
bool Empty_Squeue(Squeue Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}

//循环队列入队操作
bool En_Squeue(Squeue& Q, int Data) {
	//入队的第一步应该判满!
	if (Q.front == (Q.rear + 1) % Maxsize) {
		printf("队列已满!\n");
		return false;
	}

	//从队尾入队操作
	Q.data[Q.rear] = Data;
	Q.rear = (Q.rear + 1) % Maxsize;

	return true;
}

//循环队列出队操作
bool Del_Squeue(Squeue& Q, int& Data) {
	//出队的第一步应该判空!
	if (Q.rear == Q.front) {
		printf("队列为空!\n");
		return false;
	}

	//从队头出队操作
	Data = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;

	return true;
}

//获得循环队列队头数据
bool Gethead_Squeue(Squeue Q, int& Data) {

	if (Q.rear == Q.front) {
		printf("队列为空!\n");
		return false;
	}

	Data = Q.data[Q.front];

	return true;
}

//获得循环队列的元素个数
bool GetLenth_Squeue(Squeue Q, int& Lenth) {
	Lenth = (Q.rear - Q.front + Maxsize) % Maxsize;
	return true;
}
/***************************************循环队列****************************************/

/*------------------------------------------------------------------------------------*/

/***************************************链式队列***************************************/

//不带头节点的链式队列初始化
bool NoHead_Linkqueue_Init(LinkQueue& LQ) {
	LQ.front = LQ.rear = NULL;
	return true;
}
//带头节点的链式队列初始化
bool Linkqueue_Init(LinkQueue& LQ) {
	LQ.front = LQ.rear = (LinkNode*)malloc(sizeof(LinkNode));
	if (LQ.front == NULL) {
		printf("申请空间失败!\n");
		return false;
	}
	LQ.front->next = NULL;
	return true;
}

//不带头节点的链式队列判空
bool NoHead_Linkqueue_Empty(LinkQueue LQ) {
	if (LQ.front == NULL)
		return true;
	return false;
}
//带头节点的链式队列判空
bool Linkqueue_Empty(LinkQueue LQ) {
	if (LQ.front == LQ.rear)
		return true;
	return false;
}

//不带头街点链式队列入队
bool NoHead_EN_Linkqueue(LinkQueue& LQ, int Data) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == p) {
		printf("申请空间失败!\n");
		return false;
	}
	p->data = Data;
	p->next = NULL;

	//不带头节点时 对第一次的入队做特殊处理（front这个指针要特殊处理）
	if (NULL == LQ.front) {
		LQ.front = p;
		LQ.rear = p;
	}
	else {
		LQ.rear->next = p;
		LQ.rear = p;
	}
	return true;
}
//带头节点链式队列入队
bool EN_Linkqueue(LinkQueue& LQ, int Data) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == p) {
		printf("声请空间失败!\n");
		return false;
	}
	p->data = Data;
	p->next = NULL;

	LQ.rear->next = p;
	LQ.rear = p;

	return true;
}

//不带头节点链式队列出队
bool NoHead_Del_Linkqueue(LinkQueue& LQ, int& Data) {
	//出队的第一步时判空
	if (NoHead_Linkqueue_Empty(LQ)) {
		printf("队列为空!\n");
		return false;
	}
	LinkNode* p = LQ.front; //用于记录当前要出队的元素
	Data = p->data;
	LQ.front = p->next;
	//判断是否为最后一个元素（如果是则要对队头队尾指针做处理）
	if (LQ.rear == p) {
		LQ.front = NULL;
		LQ.rear = NULL;
	}
	free(p);
	return true;
}
//带头结点链式队列出队
bool Del_Linkqueue(LinkQueue& LQ, int& Data) {
	//第一步判空
	if (Linkqueue_Empty(LQ)) {
		printf("队列为空!\n");
		return false;
	}
	LinkNode* p = LQ.front->next;
	Data = p->data;
	LQ.front->next = p->next;

	//最后一个元素特殊处理
	if (LQ.rear == p) {
		LQ.rear = LQ.front;
	}

	free(p);
	return true;
}

/***************************************链式队列***************************************/
