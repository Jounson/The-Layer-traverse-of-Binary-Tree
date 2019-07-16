#include"pch.h"
#include"myQueue.h"

// ���г�ʼ������ //
void initQueue(Queue* q)
{
	/* ��ʼ�����У���������е�ͷ��βָ��ͬһ��λ�� */
	q->front = q->rear = (Node*)malloc(sizeof(Node));
}
// �����пպ��� //
int isQueueEmpty(Queue* q)
{
	/* ����Ϊ��ʱ��ͷ��βָ��ͬһ��λ�� */
	return q->front == q->rear;
}
// ����Ԫ��ѹ�뺯�� //
void enQueue(Queue* q, TreeNode* ch)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = ch;
	cur->next = NULL;

	q->rear->next = cur;
	q->rear = cur;
}
// ���е���ʽ�洢��ʽ�ĳ��Ӻ��� //
TreeNode* deQueue(Queue* q)
{
	/* ����һ������ch������Ԫ�ص������ݴ����� */
	TreeNode* ch = q->front->next->data;
	/* ������������������һ��front��һ��rear */
	if (q->front->next == q->rear)
	{
		q->rear = q->front;
		free(q->front->next);
		q->front->next = NULL;
	}
	else
	{
		Node* t = q->front->next;
		q->front->next = t->next;
		free(t);
	}
	return ch;
}
void resetQueue(Queue* q)
{
	Node* head = q->front->next;
	q->front->next = NULL;
	q->rear = q->front;
	Node* t;
	while (head)
	{
		t = head->next;
		free(head);
		head = t;
	}
}
void clearQueue(Queue* q)
{
	resetQueue(q);
	free(q->front);
}