#include"pch.h"
#include"myQueue.h"

// 队列初始化函数 //
void initQueue(Queue* q)
{
	/* 初始化队列，最初，队列的头和尾指向同一个位置 */
	q->front = q->rear = (Node*)malloc(sizeof(Node));
}
// 队列判空函数 //
int isQueueEmpty(Queue* q)
{
	/* 队列为空时，头和尾指向同一个位置 */
	return q->front == q->rear;
}
// 队列元素压入函数 //
void enQueue(Queue* q, TreeNode* ch)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = ch;
	cur->next = NULL;

	q->rear->next = cur;
	q->rear = cur;
}
// 队列的链式存储方式的出队函数 //
TreeNode* deQueue(Queue* q)
{
	/* 定义一个变量ch将出队元素的数据暂存起来 */
	TreeNode* ch = q->front->next->data;
	/* 如果队列里面就两个点一个front、一个rear */
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