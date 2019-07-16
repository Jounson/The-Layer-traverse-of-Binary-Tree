// TreeLayerTraverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include"Tree.h"
#include<stdlib.h>
#include"myQueue.h"

#if 0
//  实现一棵树
int main()
{
	/* 这棵树有下面7个节点 */
	TreeNode a, b, c, d, f, j, k;
	/* 树根a */
	TreeNode* root = &a;
	/* 树每个节点所携带的数据 */
	a._data = 'A';
	b._data = 'B';
	c._data = 'C';
	d._data = 'D';
	f._data = 'F';
	j._data = 'J';
	k._data = 'K';

	/* a */
	a._left = &b;
	a._right = &c;
	/* b */
	b._left = &d;
	b._right = NULL;
	/* c */
	c._left = c._right = NULL;
	/* d */
	d._left = d._right = NULL;
	/* f */
	f._left = &j;
	f._right = &k;
	/* j */
	j._left = j._right = NULL;
	/* k */
	k._left = k._right = NULL;

	return 0;
}
#endif


//  遍历一棵树
int main()
{
	/* 这棵树有下面7个节点 */
	TreeNode a, b, c, d, f, j, k;
	/* 树根a */
	TreeNode* root = &a;
	/* 树每个节点所携带的数据 */
	a._data = 'A';
	b._data = 'B';
	c._data = 'C';
	d._data = 'D';
	f._data = 'F';
	j._data = 'J';
	k._data = 'K';

	/* a */
	a._left = &b;
	a._right = &c;
	/* b */
	b._left = &d;
	b._right = NULL;
	/* c */
	c._left = &f;
	c._right = NULL;
	/* d */
	d._left = d._right = NULL;
	/* f */
	f._left = &j;
	f._right = &k;
	/* j */
	j._left = j._right = NULL;
	/* k */
	k._left = k._right = NULL;

	/* 定义一个队列 */
	Queue q;
	/* 初始化队列 */
	initQueue(&q);
	/* 树的根节点先压栈 */
	enQueue(&q, root);
	while (!isQueueEmpty(&q))
	{
		TreeNode* t = deQueue(&q);
		printf("%3c", t->_data);

		if (t->_left)
			enQueue(&q, t->_left);
		if (t->_right)
			enQueue(&q, t->_right);
	}
	
	return 0;
}
