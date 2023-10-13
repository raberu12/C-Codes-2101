#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

//versions 1-4 of array lists

typedef struct {
	int elem[SIZE];
	int count;
} version1;

typedef struct node2 {
	int elem[SIZE];
	int count;
} *version2;

typedef struct node3 {
	int *elem;
	int count;
} version3;

typedef struct node4 {
	int *elem;
	int count;
} *version4;

void initver1(version1 *list);
void initver2(version2 *list);
void initver3(version3 *list);
void initver4(version4 *list);

void insertFirst1(version1 *list, int elem);
void insertFirst2(version2 *list, int elem);
void insertFirst3(version3 *list, int elem);
void insertFirst4(version4 *list, int elem);

void deleteFirst1(version1 *list);
void deleteFirst2(version2 *list);
void deleteFirst3(version3 *list);
void deleteFirst4(version4 *list);

int main() {
	
	version1 list1;
	version2 list2;
	version3 list3;
	version4 list4;

	initver1(&list1);
	initver2(&list2);
	initver3(&list3);
	initver4(&list4);
	
	insertFirst1(&list1, 2);
	insertFirst2(&list2, 2);
	insertFirst3(&list3, 2);
	insertFirst4(&list4, 2);
	insertFirst1(&list1, 1);
	insertFirst2(&list2, 1);
	insertFirst3(&list3, 1);
	insertFirst4(&list4, 1);
	
	deleteFirst1(&list1);
	deleteFirst2(&list2);
	deleteFirst3(&list3);
	deleteFirst4(&list4);

}

void initver1(version1 *list) {
	list->count = 0;
}
void initver2(version2 *list) {
	*list = (version2)malloc(sizeof(struct node2));
	(*list)->count = 0;
}
void initver3(version3 *list) {
	list->elem = (int*)malloc(sizeof(int)*SIZE);
	list->count = 0;
}
void initver4(version4 *list) {
	*list = (version4)malloc(sizeof(struct node4));
	(*list)->elem = (int*)malloc(sizeof(int)*SIZE);
	(*list)->count = 0;
}

void insertFirst1(version1 *list, int elem) {
	int i;
	for(i = list->count; i >= 0; i--) {
		list->elem[i+1] = list->elem[i];
	}
	list->elem[0] = elem;
	list->count++;
}

void insertFirst2(version2 *list, int elem){
	int i;
	for(i = (*list)->count; i >= 0; i--){
		(*list)->elem[i+1] = (*list)->elem[i];
	}
	(*list)->elem[0] = elem;
	(*list)->count++;
}
void insertFirst3(version3 *list, int elem) {
	int i;
	for(i = list->count; i >= 0; i--) {
		list->elem[i+1] = list->elem[i];
	}
	list->elem[0] = elem;
	list->count++;
}
void insertFirst4(version4 *list, int elem){
	int i;
	for(i = (*list)->count; i >= 0; i--){
		(*list)->elem[i+1] = (*list)->elem[i];
	}
	(*list)->elem[0] = elem;
	(*list)->count++;
}
void deleteFirst1(version1 *list){
	int i = 0;
	for(i = 0; i < list->count; i++){
		list->elem[i] = list->elem[i+1];
	}
	list->count--;
}
void deleteFirst2(version2 *list){
	int i = 0;
	for(i = 0; i < (*list)->count; i++){
		(*list)->elem[i] = (*list)->elem[i+1];
	}
	(*list)->count--;
}
void deleteFirst3(version3 *list){
	int i = 0;
	for(i = 0; i < list->count; i++){
		list->elem[i] = list->elem[i+1];
	}
	list->count--;
}
void deleteFirst4(version4 *list){
	int i = 0;
	for(i = 0; i < (*list)->count; i++){
		(*list)->elem[i] = (*list)->elem[i+1];
	}
	(*list)->count--;
}


