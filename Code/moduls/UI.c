#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"


int input() {
	int k = 7, z = 0, s;
	char s1[100];
	HEAD* head = NULL;
	head = malloc(sizeof(head));
	head->count = 0;
	head->first = NULL;
	head->last = NULL;
	NODE* ptr = NULL;

	while (k != 5)
	{
		output(head);
		printf("What you want to do:\n----------------------------------------------\n");
		printf("\t1 - read list from file\n");
		printf("\t2 - add line\n");
		printf("\t3 - edit content\n");
		printf("\t4 - copy and save elements in file\n");
		printf("\t5 - search in list\n");
		printf("\t6 - delete line\n");
		printf("\t7 - sort list\n");
		printf("\t8 - revers list\n");
		printf("\t9 - save list at file\n");
		printf("----------------------------------------------\nEnter stop to finish work\n ");
		fgets(s1, 126, stdin);
		if (strlen(s1) < 4)
		{
			s = atoi(s1);
			if (s == 8)
			{
				if (z) { revers(head, 1); z = 0; }
				else { revers(head, 0); z = 1; }

			};
			if (s == 1) add_from_file(head);
			if (s == 2) add(head);
			if (s == 6) delete(head);
			if (s == 7) sort_menu(head);
			if (s == 3) edit_menu(head);
			if (s == 4) copy_element(head);
			if (s == 9) file_print(head);
			if (s == 5) search(head);
			
		}
		else system("cls");
		if (strlen(s1) == 5 && s1[0] == 's' && s1[2] == 'o') k = 5;
		
		
	}
	ptr = head->first;
	for (int i = 1; i <= head->count; i++)
	{
		ptr = head->first;
		head->first = head->first->next;
		free(ptr);
	}
	free(head);
	return(-1);
}

void search(HEAD* head)
{
	if (head->first != NULL)
	{
		int k = 0, s = 0;

		HEAD* new_head = NULL;
		new_head = malloc(sizeof(head));
		new_head->count = 0;
		new_head->first = NULL;
		new_head->last = NULL;
		NODE* new_ptr = NULL;
		new_ptr = malloc(sizeof(NODE));


		output(head);
		printf("Select the column in which you want to search:\n");
		printf("\t1\tname\n");
		printf("\t2\tdata\n");
		printf("\t3\tage\n");
		printf("\t4\terror\n");
		printf("\t5\tresult point\n");
		scanf("%d", &k);

		printf("\nDo you want save found result to file?\n\t1\tYes\n\t0\tNo\n");
		scanf("%d", &s);


		switch (k)
		{
		case 1:
			search_settings_1(head, new_head, s);
			break;
		case 2:
			search_settings_2(head, new_head, s);
			break;
		case 3:
			search_settings_3(head, new_head, s);
			break;
		case 4:
			search_settings_4(head, new_head, s);
			break;
		case 5:
			search_settings_5(head, new_head, s);
			break;
		}
	}
	else error();
}

void sort_menu(HEAD* head)
{
	int obj, way, i;
	char s1[100];
	system("cls");
	printf("\tChose sorn settings:\n\t\tPuts '1' to sort by name\n\t\tPuts '2' to sort by age\n\t\tPuts '3' to sort by exam time\n\t\tPuts '4' to sort by result ball\n");
	scanf("%d", &obj);
	printf("\t\Puts 1 to sort ascending\n\tPuts 0 to sort descending\n");
	scanf("%d", &way);

	switch (obj)
	{
	case 1:
		sort(head, way, by_name);
		break;
	case 2:
		sort(head, way, by_age);
		break;
	case 3:
		sort(head, way, by_exam_time);
		break;
	case 4:
		sort(head, way, by_RB);
		break;
	}

	NODE* q = head->first;
	for (i = 1; i < head->count + 1; i++)
	{
		q->id = i;
		q = q->next;
	}
}


void edit_menu(HEAD* head)
{
	if (head->first != NULL) {
		NODE* q = head->first;
		char num1[10], area1[10], n1[100];
		int num, area, n;
		float f;
		system("cls");
		output(head);
		printf("\nEntre user number to be edited:\n");
		fgets(num1, 100, stdin);
		num = atoi(num1);
		printf("\nSelect which area you want to edit:\n");
		printf("+------------------------------------------------------------------------------+\n");
		printf("| name | data exam | age | time exam | maxpoint | error | total point | result |\n");
		printf("+------|-----------|-----|-----------|----------|-------|-------------|--------|\n");
		printf("|   1  |     2     |  3  |     4     |     5    |   6   |      7      |    8   |\n");
		printf("+------------------------------------------------------------------------------+\n");
		fgets(area1, 100, stdin);
		area = atoi(area1);

		if (num <= head->count)
		{
			while (q->id != num)
			{
				q = q->next;
			}
		}
		printf("Entre new value:\n");
		switch (area)
		{
		case (1):
			edit_char(q, 1);
			break;
		case (2):
			edit_char(q, 2);
			break;
		case (3):
			fgets(n1, 100, stdin);
			n = atoi(n1);
			q->age = n;
			break;
		case (4):
			edit_char(q, 4);
			break;
		case (5):
			fgets(n1, 100, stdin);
			n = atoi(n1);
			q->maxpoint = n;
			break;
		case (6):
			fgets(n1, 100, stdin);
			f = atof(n1);
			q->error = f;
			break;
		case (7):
			fgets(n1, 100, stdin);
			f = atof(n1);
			q->resultpoint = f;
			break;
		case (8):
			edit_char(q, 8);
		}
	}
	else error();
}

void delete (HEAD* head)
{
	printf("You want:\n");
	printf("\t1 - delete last line\n");
	printf("\t2 - delete first line\n");
	printf("\t3 - delete line by id\n");
	printf("\t4 - back to menu\n");
	int k;
	scanf("%d", &k);
	if (k > 0 && k < 5)
	{
		switch (k)
		{
		case(1):
			delet_last_node(head);
			break;
		case(2):
			delet_first_node(head);
			break;
		case(3):
			delete_by_id_node(head);
			break;
		case(4):
			break;
		}
	}
	else error();
}

void add (HEAD* head)
{
	printf("You want:\n");
	printf("\t1 - add line in end of list\n");
	printf("\t2 - add line in head list\n");
	printf("\t3 - back to menu\n");
	int k;
	char s1[10];
	fgets(s1, 100, stdin);
	k = atoi(s1);
	if (k > 0 && k < 4)
	{
		switch (k)
		{
		case(1):
			add_last_node(head, puts_line());
			break;
		case(2):
			add_first_node(head, puts_line());
			break;
		case(3):
			break;
		}
	}
	else error();
}
