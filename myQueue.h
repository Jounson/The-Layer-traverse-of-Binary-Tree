#pragma once
#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include<stdlib.h>
#include<stdio.h>
#include"Tree.h"

typedef struct _Node
{
	TreeNode* data;
	struct _Node* next;
}Node;
typedef struct _Queue
{
	Node* front;
	Node* rear;
}Queue;

void initQueue(Queue* q);
int isQueueEmpty(Queue* q);
void enQueue(Queue* q, TreeNode* ch);
TreeNode* deQueue(Queue* q);
void resetQueue(Queue* q);
void clearQueue(Queue* q);




#endif