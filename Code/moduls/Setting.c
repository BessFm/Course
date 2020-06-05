#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"


NODE* split(char* s1, int n1)
{
	char** s2;
	NODE* str = NULL;;
	s2 = (char**)malloc(8 * sizeof(char*));
	char sep = ';';
	int i, j, f, count = 0;
	for (i = 0; i < 8; i++)
	{
		s2[i] = (char*)malloc(n1 * sizeof(char));
	}
	int len = n1;
	int p = 0, k = 0, m = 0;
	for (j = 0; j < len; j++)
	{
		if (s1[j] == sep) count++;
	}
	if (count == 7)
	{
		for (j = 0; j < len; j++)
		{
			if (s1[j] == sep)
			{
				for (f = m; f < j; f++)
				{
					s2[k][p] = s1[f];
					p++;
				}
				s2[k][p] = '\0';
				k++;
				j++;
				p = 0;
				m = j;
			}
			if (k == 7)
			{

				for (f = j; f < len; f++)
				{
					s2[k][p] = s1[f];
					p++;
				}
				s2[k][p - 1] = '\0';
				j = len;
			}
			p = 0;

		}
		str = struct_fill(s2);
	}
	return(str);
}

NODE* struct_fill(char** str)
{
	NODE* str0 = NULL;

	str0 = (NODE*)malloc(sizeof(NODE));
	if (str0 != NULL)
	{
		str0->name = str[0];
		str0->data = str[1];
		str0->age = atoi(str[2]);
		str0->time = str[3];
		str0->maxpoint = atoi(str[4]);
		str0->error = atof(str[5]);
		str0->resultpoint = atof(str[6]);
		str0->result = str[7];
	}
	return str0;
}

void bubbleSort(int* num, int size)
{
	int flag = 1;
	// Для всех элементов
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (num[i] > num[i + 1]) // если текущий элемент меньше предыдущего
			{
				int temp = num[i]; // меняем их местами
				num[i] = num[i + 1];
				num[i + 1] = temp;
				flag = 1;
			}

		}
	}
}

NODE* struct_copy(NODE* ptr)
{
	NODE* ptr1 = NULL;
	ptr1 = malloc(sizeof(NODE));
	if (ptr && ptr1)
	{
		ptr1->id = ptr->id;
		ptr1->name = ptr->name;
		ptr1->data = ptr->data;
		ptr1->age = ptr->age;
		ptr1->time = ptr->time;
		ptr1->maxpoint = ptr->maxpoint;
		ptr1->error = ptr->error;
		ptr1->resultpoint = ptr->resultpoint;
		ptr1->result = ptr->result;
		ptr1->next = NULL;
	}
	return (ptr1);
}


NODE* select_id(HEAD* head, int k)
{
	NODE* ptr = head->first;
	NODE* ptr1 = NULL;
	ptr1 = malloc(sizeof(NODE));
	int count = head->count;
	int p = ptr->id;
	if (p != k)
	{
		for (int i = 0; i < count; i++)
		{
			ptr = ptr->next;
			p = ptr->id;
			if (p == k) i = count;
		}
	}

	ptr1 = struct_copy(ptr);
	return (ptr1);
}

void revers(HEAD* head, int n)
{
	sort(head, n, by_id);
	int i = 1;
	NODE* q = head->first;
	for (i = 1; i < head->count + 1; i++)
	{
		q->id = i;
		q = q->next;
	}
}


NODE* puts_line()
{
	NODE* ptr = malloc(sizeof(NODE*));
	char k1[100];
	int k;
	float f;
	printf("Entre name:\t");
	edit_char(ptr, 1);
	printf("Entre data:\t");
	edit_char(ptr, 2);
	printf("Entre age:\t");
	fgets(k1, 1000, stdin);
	k = atoi(k1);
	ptr->age = k;
	printf("Entre time:\t");
	edit_char(ptr, 4);
	printf("Entre maxpoint:\t");
	fgets(k1, 1000, stdin);
	k = atoi(k1);
	ptr->maxpoint = k;
	printf("Entre error:\t");
	fgets(k1, 1000, stdin);
	f = atof(k1);
	ptr->error = f;
	printf("Entre resultpoint:\t");
	fgets(k1, 1000, stdin);
	f = atof(k1);
	ptr->resultpoint = f;
	printf("Entre result:\t");
	edit_char(ptr, 8);
	return ptr;

}

void menu()
{
	int STOP = 1;
	while (STOP > 0) {
		STOP = input();
	}
}

void error()
{
	printf("--------------------ERROR--------------------\n");
	system("pause");
	system("cls");

}

