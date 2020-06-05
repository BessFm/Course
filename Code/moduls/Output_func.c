#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"



void file_print(HEAD* head)
{
	int i, count = head->count;
	char finame[100];
	printf("Enter the name of file: \n");
	scanf("%s", finame);
	FILE* file;
	file = fopen(finame, "w");
	NODE* id1 = NULL;
	id1 = malloc(sizeof(NODE));
	id1 = head->first;
	for (i = 0; i < count; i++)
	{
		fprintf(file, "%15s;%s;%3d;%2s;%3d;%4.2f;%4.2f;%5s;\n", id1->name, id1->data, id1->age, id1->time, id1->maxpoint, id1->error, id1->resultpoint, id1->result);
		id1 = id1->next;
	}
	fclose(file);
}

void output(HEAD* head)
{
	system("cls");
	printf("YOUR NODE:\n");
	printf("--------------------------------------------------------------\n");
	printNODE(head);
	printf("--------------------------------------------------------------\n\n\n");
}

void print_menu()
{
	system("cls");
	printf("Enter information about another people in the next form:\n");
	printf("+-------------------------------------------------------------------------------------+\n");
	printf("| name -> data exam -> age -> time exam -> maxpoint -> error -> total point -> result |\n");
	printf("+-------------------------------------------------------------------------------------+\n");
	printf("Example:\n\tIvan Ivanov;20.05.2020;31;12:04;100;32;68;PASSED\n");

}

void printNODE(HEAD* ptr)
{
	NODE* ptr1;
	ptr1 = ptr->first;
	if (ptr->count > 0)
	{
		for (int i = 0; i < ptr->count; i++)
		{
			printstructr(ptr1);
			ptr1 = ptr1->next;
		}
	}
	else printf("!!!list is free!!!\n");
}


void printstructr(NODE* id1)
{
	if (id1 != NULL)
	{
		printf("|%3d |%15s |%s |%3d |%2s |%3d |%4.2f |%4.2f |%5s|\n", id1->id, id1->name, id1->data, id1->age, id1->time, id1->maxpoint, id1->error, id1->resultpoint, id1->result);
	}
}



