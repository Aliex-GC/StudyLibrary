#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode *pa=list1;
	struct ListNode *pb=list2;
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *lastnode;
	lastnode=head;
	if(pa->data<pb->data)
	{
		lastnode=pa;
		lastnode=lastnode->next;
		pa=pa->next;
	}
	else
	{
		lastnode=pb;
		lastnode=lastnode->next;
		pb=pb->next;
	}
	if(!pa)
	{
		lastnode=pb->next;
	}
	else
	{
		lastnode=pa->next;
	}
	return head->next;
	
}
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
    
    return 0;
}

/* 你的代码将被嵌在这里 */

