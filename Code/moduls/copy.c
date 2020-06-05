#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../lib.h"

void copy_element(HEAD* head)
{
	if (head->first != NULL)
	{
		HEAD* new_head = NULL;
		new_head = malloc(sizeof(head));
		new_head->count = 0;
		new_head->first = NULL;
		new_head->last = NULL;
		NODE* new_ptr = NULL;
		new_ptr = malloc(sizeof(NODE));



		int n=1, count, i;
		int* num;
		char s1[10], n1[1000];
		printf("\033[0d\033[2J");
		output(head);
		printf("\nEntre the number of numbers to copy: ");
		fgets(s1, 100, stdin);
		count = atoi(s1);
		if (count <= head->count)
		{

			num = malloc(count * sizeof(int));
			printf("Entre number elements:\n");
			for (i = 0; i < count; i++)
			{
				scanf("%d", &num[i]);
				if (num[i] > head->count) n = 0;
			}
			if (n)
			{
				bubbleSort(num, count);
				for (i = 0; i < count; i++)
				{
					new_ptr = select_id(head, num[i]);
					add_last_node(new_head, new_ptr);
				}
			}


			if (n)
			{
				output(new_head);
				file_print(new_head);
			}
			else error();
		}
		else error();
	}
	else error();
}


