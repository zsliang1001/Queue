#include "Queue.h"

/***************************************ѭ������***************************************/
//��ʼ��ѭ������
bool Init_Squeue(Squeue& Q) {
	Q.front = Q.rear = 0;
	return true;
}

//�ж�ѭ�������Ƿ�Ϊ��
bool Empty_Squeue(Squeue Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}

//ѭ��������Ӳ���
bool En_Squeue(Squeue& Q, int Data) {
	//��ӵĵ�һ��Ӧ������!
	if (Q.front == (Q.rear + 1) % Maxsize) {
		printf("��������!\n");
		return false;
	}

	//�Ӷ�β��Ӳ���
	Q.data[Q.rear] = Data;
	Q.rear = (Q.rear + 1) % Maxsize;

	return true;
}

//ѭ�����г��Ӳ���
bool Del_Squeue(Squeue& Q, int& Data) {
	//���ӵĵ�һ��Ӧ���п�!
	if (Q.rear == Q.front) {
		printf("����Ϊ��!\n");
		return false;
	}

	//�Ӷ�ͷ���Ӳ���
	Data = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;

	return true;
}

//���ѭ�����ж�ͷ����
bool Gethead_Squeue(Squeue Q, int& Data) {

	if (Q.rear == Q.front) {
		printf("����Ϊ��!\n");
		return false;
	}

	Data = Q.data[Q.front];

	return true;
}

//���ѭ�����е�Ԫ�ظ���
bool GetLenth_Squeue(Squeue Q, int& Lenth) {
	Lenth = (Q.rear - Q.front + Maxsize) % Maxsize;
	return true;
}
/***************************************ѭ������****************************************/

/*------------------------------------------------------------------------------------*/

/***************************************��ʽ����***************************************/

//����ͷ�ڵ����ʽ���г�ʼ��
bool NoHead_Linkqueue_Init(LinkQueue& LQ) {
	LQ.front = LQ.rear = NULL;
	return true;
}
//��ͷ�ڵ����ʽ���г�ʼ��
bool Linkqueue_Init(LinkQueue& LQ) {
	LQ.front = LQ.rear = (LinkNode*)malloc(sizeof(LinkNode));
	if (LQ.front == NULL) {
		printf("����ռ�ʧ��!\n");
		return false;
	}
	LQ.front->next = NULL;
	return true;
}

//����ͷ�ڵ����ʽ�����п�
bool NoHead_Linkqueue_Empty(LinkQueue LQ) {
	if (LQ.front == NULL)
		return true;
	return false;
}
//��ͷ�ڵ����ʽ�����п�
bool Linkqueue_Empty(LinkQueue LQ) {
	if (LQ.front == LQ.rear)
		return true;
	return false;
}

//����ͷ�ֵ���ʽ�������
bool NoHead_EN_Linkqueue(LinkQueue& LQ, int Data) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == p) {
		printf("����ռ�ʧ��!\n");
		return false;
	}
	p->data = Data;
	p->next = NULL;

	//����ͷ�ڵ�ʱ �Ե�һ�ε���������⴦��front���ָ��Ҫ���⴦��
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
//��ͷ�ڵ���ʽ�������
bool EN_Linkqueue(LinkQueue& LQ, int Data) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == p) {
		printf("����ռ�ʧ��!\n");
		return false;
	}
	p->data = Data;
	p->next = NULL;

	LQ.rear->next = p;
	LQ.rear = p;

	return true;
}

//����ͷ�ڵ���ʽ���г���
bool NoHead_Del_Linkqueue(LinkQueue& LQ, int& Data) {
	//���ӵĵ�һ��ʱ�п�
	if (NoHead_Linkqueue_Empty(LQ)) {
		printf("����Ϊ��!\n");
		return false;
	}
	LinkNode* p = LQ.front; //���ڼ�¼��ǰҪ���ӵ�Ԫ��
	Data = p->data;
	LQ.front = p->next;
	//�ж��Ƿ�Ϊ���һ��Ԫ�أ��������Ҫ�Զ�ͷ��βָ��������
	if (LQ.rear == p) {
		LQ.front = NULL;
		LQ.rear = NULL;
	}
	free(p);
	return true;
}
//��ͷ�����ʽ���г���
bool Del_Linkqueue(LinkQueue& LQ, int& Data) {
	//��һ���п�
	if (Linkqueue_Empty(LQ)) {
		printf("����Ϊ��!\n");
		return false;
	}
	LinkNode* p = LQ.front->next;
	Data = p->data;
	LQ.front->next = p->next;

	//���һ��Ԫ�����⴦��
	if (LQ.rear == p) {
		LQ.rear = LQ.front;
	}

	free(p);
	return true;
}

/***************************************��ʽ����***************************************/
