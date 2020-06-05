#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"

void add_first_node(HEAD* head, NODE* ptr)
{
	if (ptr)
	{
		int i = 1;
		NODE* q = head->first;
		head->first = ptr;
		head->first->next = q;
		head->count++;
		q = head->first;
		for (i = 1; i < head->count + 1; i++)
		{
			q->id = i;
			q = q->next;
		}
	}
	else 
	{
		printf("\n--------Line entered in wrong format---------\n");
		error();
	}
}

void add_from_file(HEAD* head)
{
	int n = 0, k = 0;
	NODE* ptr;
	char s[1000];
	char finame[15];
	printf("Enter the name of file: \n");
	scanf("%s", finame);
	FILE* file;
	file = fopen(finame, "r");
	if (file)
	{
		while (fgets(s, 1000, file) != NULL)
		{
			n++;
		}
		if (n != 0)
		{
			fseek(file, 0, SEEK_SET);

			for (int i = 0; i < n; i++)
			{
				fgets(s, 1000, file);
				k = strlen(s);
				ptr = split(s, k);
				add_last_node(head, ptr);
			}
		}
		n = 0;
		k = 0;
		fclose(file);
		fflush(stdin);
	}
	else error();
}

void add_last_node(HEAD* my_head, NODE* str)
{
	if (str)
	{
		NODE* str0 = my_head->last;
		NODE* q = my_head->first;

		int k = my_head->count;
		if (q)
		{
			my_head->count++;
			str0->next = str;
			my_head->last = str;
			my_head->last->id = my_head->count;
			str->next = NULL;

		}
		else
		{
			my_head->count++;
			my_head->first = str;
			my_head->last = str;
			my_head->first->id = my_head->count;
		}
	}
	else
	{
		printf("\n--------Line entered in wrong format---------\n");
		error();
	}

}

void delet_first_node(HEAD* head)
{
	NODE* ptr = NULL;
	int i = 0;
	NODE* q;
	if (head->count > 1)
	{
		ptr = head->first;
		head->first = head->first->next;
		head->count--;
		free(ptr);
		q = head->first;
		for (i = 1; i < head->count + 1; i++)
		{
			q->id = i;
			q = q->next;
		}
	}
	else
	{
		head->first = NULL;
		head->last = NULL;
		head->count = 0;
	}
}

void delet_last_node(HEAD* head)
{
	NODE* ptr = NULL;
	NODE* q = head->first;
	NODE* last = head->last;
	if (head->count > 1)
	{
		while (q->next != last)
		{
			q = q->next;
		}
		ptr = q->next;
		free(ptr);
		q->next = NULL;
		head->last = q;
		head->count--;
		head->last->id = head->count;
	}
	else
	{
		ptr = head->first;
		free(ptr);
		head->first = NULL;
		head->last = NULL;
		head->count = 0;
	}
}

void delete_by_id_node(HEAD* head)
{
	NODE* ptr = NULL;
	NODE* q = head->first;
	int k;
	printf("Entre list number to delete:\n");
	scanf("%d", &k);
	if (k <= head->count)
	{
		if (q->id != k)
		{
			while (q->next->id != k)
			{
				q = q->next;
			}
			q->next = q->next->next;
			ptr = q->next;
			free(ptr);
		}
		else head->first = head->first->next;
		head->count--;
		q = head->first;
		for (int i = 1; i < head->count + 1; i++)
		{
			q->id = i;
			q = q->next;
		}
	}
	else error();
}

void edit_char(NODE* q, int n)
{
	char s1[100];
	fgets(s1, 100, stdin);
	char** s;
	s = malloc(1 * sizeof(char*));
	s[0] = (char*)malloc(strlen(s1) * sizeof(char));
	for (int i = 0; i < strlen(s1) - 1; i++)
	{
		s[0][i] = s1[i];
	}
	s[0][strlen(s1) - 1] = '\0';
	switch (n)
	{
	case 1:
		q->name = s[0];
		break;
	case 2:
		q->data = s[0];
		break;
	case 4:
		q->time = s[0];
		break;
	case 8:
		q->result = s[0];
		break;
	}
}