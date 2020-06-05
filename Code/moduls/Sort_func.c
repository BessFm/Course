#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"



void sort(HEAD* head, int n, int (*funcName)(NODE* p, int way))
{
	NODE* p1 = NULL, * q = NULL, * b = NULL, * c = NULL, * d = NULL;
	int flag = 1, i, k = 0;
	while (flag)
	{
		flag = 0;
		p1 = head->first;
		for (i = 0; i < head->count && p1 != head->last; i++)
		{
			if (funcName(p1, n))
			{

				q = head->first;
				if (p1 != head->first)
				{
					while (q->next != p1)
					{
						q = q->next;
					}
				}

				b = p1;
				c = p1->next;
				d = p1->next->next;

				if (b == head->first) head->first = c;
				if (c == head->last) head->last = b;

				q->next = c;
				b->next = d;
				c->next = b;


				flag = 1;
				k = 1;
			}
			if (k)
			{
				k = 0;
			}
			else
			{
				p1 = p1->next;
			}
		}
	}
}

int by_id(NODE* p, int way)
{
	if (way)
	{
		if (p->id > p->next->id)
			return 1;
		else
			return 0;
	}
	else
	{
		if (p->id < p->next->id)
			return 1;
		else
			return 0;
	}
}

int by_name(NODE* p, int way)
{
	if (way == 1)
	{
		if (strcmp(p->name, p->next->name) > 0)
			return 1;
		else
			return 0;
	}
	else
	{

		if (strcmp(p->name, p->next->name) < 0)
			return 1;
		else
			return 0;
	}
}

int by_age(NODE* p, int way)
{
	if (way)
	{
		if (p->age > p->next->age)
			return 1;
		else
			return 0;
	}
	else
	{
		if (p->age < p->next->age)
			return 1;
		else
			return 0;
	}
}

int by_exam_time(NODE* p, int way)
{
	if (way)
	{
		if (strcmp(p->time, p->next->time) > 0)
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(p->time, p->next->time) < 0)
			return 1;
		else
			return 0;
	}
}

int by_RB(NODE* p, int way)
{
	if (way)
	{
		if (p->resultpoint > p->next->resultpoint)
			return 1;
		else
			return 0;
	}
	else
	{
		if (p->resultpoint < p->next->resultpoint)
			return 1;
		else
			return 0;
	}
}