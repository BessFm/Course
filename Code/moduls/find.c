#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"

void search_settings_1(HEAD* head, HEAD* new_head, int n)
{
	char s1[100];
	int m=0;
	printf("Entre name or part of the name to search:\n");
	scanf("%s", s1);

	NODE* q = head->first;
	NODE* new_ptr;
	while (q != NULL)
	{
		if (strstr(q->name, s1) != NULL)
		{
			m = 1;
			new_ptr = select_id(head, q->id);
			add_last_node(new_head, new_ptr);
		}
		q = q->next;
	}
	printf("Search result:\n");
	if (m) printNODE(new_head);
	else printf("nothing found");
	if (n) file_print(new_head);
	printf("Entre 1 to continue: ");
	scanf("%d", &m);
}

void search_settings_2(HEAD* head, HEAD* new_head, int n)
{
	char s1[100];
	int m = 0;
	printf("Entre data to search in format xx.xx.xxxx:\n");
	scanf("%s", s1);

	NODE* q = head->first;
	NODE* new_ptr;
	while (q != NULL)
	{
		if (strstr(q->data, s1) != NULL)
		{
			m = 1;
			new_ptr = select_id(head, q->id);
			add_last_node(new_head, new_ptr);
		}
		q = q->next;
	}
	printf("Search result:\n");
	if (m) printNODE(new_head);
	else printf("nothing found");
	if (n) file_print(new_head);
	printf("Entre 1 to continue: ");
	scanf("%d", &m);
}

void search_settings_3(HEAD* head, HEAD* new_head, int n)
{
	int k, m=0;
	printf("Entre age to search:\n");
	scanf("%d", &k);

	NODE* q = head->first;
	NODE* new_ptr;
	while (q != NULL)
	{
		if (q->age == k)
		{
			m = 1;
			new_ptr = select_id(head, q->id);
			add_last_node(new_head, new_ptr);
		}
		q = q->next;
	}
	printf("Search result:\n");
	if (m) printNODE(new_head);
	else printf("nothing found");
	if (n) file_print(new_head);
	printf("Entre 1 to continue: ");
	scanf("%d", &m);
}

void search_settings_4(HEAD* head, HEAD* new_head, int n)
{
	int m = 0;
	float k;
	printf("Entre error to search:\n");
	scanf("%f", &k);

	NODE* q = head->first;
	NODE* new_ptr;
	while (q != NULL)
	{
		if (q->error == k)
		{
			m = 1;
			new_ptr = select_id(head, q->id);
			add_last_node(new_head, new_ptr);
		}
		q = q->next;
	}
	printf("Search result:\n");
	if (m) printNODE(new_head);
	else printf("nothing found");
	if (n) file_print(new_head);
	printf("Entre 1 to continue: ");
	scanf("%d", &m);
}

void search_settings_5(HEAD* head, HEAD* new_head, int n)
{
	int m = 0;
	float k;
	printf("Entre result point to search:\n");
	scanf("%f", &k);

	NODE* q = head->first;
	NODE* new_ptr;
	while (q != NULL)
	{
		if (q->resultpoint == k)
		{
			m = 1;
			new_ptr = select_id(head, q->id);
			add_last_node(new_head, new_ptr);
		}
		q = q->next;
	}
	printf("Search result:\n");
	if (m) printNODE(new_head);
	else printf("nothing found");
	if (n) file_print(new_head);
	printf("Entre 1 to continue: ");
	scanf("%d", &m);
}