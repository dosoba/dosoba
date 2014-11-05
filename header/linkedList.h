#ifndef __LINKEDLIST__H
#define __LINKEDLIST__H

#define USE 1
#define NOT_USE 0

#define TRUE 1
#define FALSE 0

typedef struct ST_NODE NODE;
typedef struct ST_LINKEDLIST LINKEDLIST;

typedef struct ST_PERSONALINFO {
	char name[7];
	char phone[12];
	char address[50];
} PERSONALINFO;

typedef struct ST_NODE {
	PERSONALINFO *info;
	NODE *next;
} NODE;

typedef struct ST_LINKEDLIST {
	NODE *head;
	NODE *tail;
	NODE *pos;
	int length;

	//void (*createLinkedList)(LINKEDLIST*);
	//void (*destroyLinkedList)(LINKEDLIST*);
	int (*findNameLinkedList)(LINKEDLIST*, char*);
	void (*appendLinkedList)(LINKEDLIST*, PERSONALINFO*);
	void (*insertLinkedList)(LINKEDLIST*, int, PERSONALINFO*);
	void (*deleteLinkedList)(LINKEDLIST*, int);
	void (*deleteAllLinkedList)(LINKEDLIST*);
	NODE* (*moveFirstLinkedList)(LINKEDLIST*);
	NODE* (*moveLastLinkedList)(LINKEDLIST*);
	NODE* (*nextLinkedList)(LINKEDLIST*);
	NODE* (*moveToBeforeNodeLinkedList)(LINKEDLIST*, int);
	PERSONALINFO (*viewAtLinkedList)(LINKEDLIST*, int);
	int (*isTailLinkedList)(LINKEDLIST*);
	int (*getLengthLinkedList)(LINKEDLIST*);
	NODE* (*getNodeLinkedList)(LINKEDLIST*, int);
	void (*printHeaderLinkedList)(int);
	void (*printPersonInfoLinkedList)(PERSONALINFO*, int);
	void (*printLinedList)(LINKEDLIST*);
} LINKEDLIST;

void createLinkedList(LINKEDLIST *self);
void destroyLinkedList(LINKEDLIST *self);

int findNameLinkedList(LINKEDLIST *self, char* p_name);
void appendLinkedList(LINKEDLIST *self, PERSONALINFO* p_info);
void insertLinkedList(LINKEDLIST *self, int index, PERSONALINFO* p_info);
void deleteLinkedList(LINKEDLIST *self, int index);
void deleteAllLinkedList(LINKEDLIST *self);
NODE* moveFirstLinkedList(LINKEDLIST *self);
NODE* moveLastLinkedList(LINKEDLIST *self);
NODE* nextLinkedList(LINKEDLIST *self);
NODE* moveToBeforeNodeLinkedList(LINKEDLIST *self, int index);
PERSONALINFO viewAtLinkedList(LINKEDLIST *self, int index);
int isTailLinkedList(LINKEDLIST *self);
int getLengthLinkedList(LINKEDLIST *self);
NODE* getNodeLinkedList(LINKEDLIST *self, int index);
void printHeaderLinkedList(int printNum);
void printPersonInfoLinkedList(PERSONALINFO *info, int printNum);
void printLinedList(LINKEDLIST *self);

#endif //__LINKEDLIST__H
