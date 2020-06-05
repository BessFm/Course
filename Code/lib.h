#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct head
{
	int count;
	struct list* first;
	struct list* last;
}HEAD;
typedef struct list {
	int id;
	char* name;
	char* data;
	int age;
	char* time;
	int maxpoint;
	float error;
	float resultpoint;
	char* result;
	struct list* next;
}NODE;


NODE* puts_line();

NODE* split(char* s1, int n1);

NODE* struct_fill(char** str);

NODE* struct_copy(NODE* ptr);

NODE* select_id(HEAD* head, int k);

void printstructr(NODE* id1);

void printNODE(HEAD* ptr);

void print_menu();

void menu();

int input();

void output(HEAD* head);

int by_name(NODE* p, int way);

int by_age(NODE* p, int way);

int by_exam_time(NODE* p, int way);

int by_RB(NODE* p, int way);

void sort(HEAD* head, int n, int (*funcName)(NODE* p, int way));

int by_id(NODE* p, int way);

void edit_char(NODE* q, int n);

void bubbleSort(int* num, int size);

void search_settings_1(HEAD* head, HEAD* new_head, int n);

void search_settings_2(HEAD* head, HEAD* new_head, int n);

void search_settings_3(HEAD* head, HEAD* new_head, int n);

void search_settings_4(HEAD* head, HEAD* new_head, int n);

void search_settings_5(HEAD* head, HEAD* new_head, int n);

void error();

void delete (HEAD* head);

void add(HEAD* head);

// Доступные функции //
//-------------------------------------------------------------------------------//
void revers(HEAD* my_head, int n); // реверс списка

void edit_menu(HEAD* head); // редактирование ячеек

void copy_element(HEAD* head); // копирование и записывание в файл

void file_print(HEAD* head); // запись в файл

void sort_menu(HEAD* head); // сортировка списка

void add_from_file(HEAD* head);// считывание из файлов

void search(HEAD* head); // поиск по значению

void add_last_node(HEAD* head, NODE* ptr); // добавление последнего элемента

void add_first_node(HEAD* head, NODE* ptr); //добавление первого элемента

void delet_last_node(HEAD* head); //удаление последнего элемента

void delet_first_node(HEAD* head); //удаление первого элемента

void delete_by_id_node(HEAD* head); //удаление выбранного элемента

//-------------------------------------------------------------------------------//
