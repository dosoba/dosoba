#ifndef __LINKEDLIST__
#define __LINKEDLIST__

void createLinkedList(LINKEDLIST *self) ;
void destroyLinkedList(LINKEDLIST *self);

int findNameLinkedList(LINKEDLIST *self, char* p_name);

void appendLinkedList(LINKEDLIST *self, PERSONALINFO* p_info);
void insertLinkedList(LINKEDLIST *self, int index, PERSONALINFO* p_info) ;
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

#endif //__LINKEDLIST
