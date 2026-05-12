#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  char data;
  struct Node *next;
}Node,*LinkList;

LinkList CreatList(char arr[],int len){
  LinkList head=(LinkList)malloc(sizeof(Node));
  head->next=NULL;
  LinkList tail=head;
  for(int i=0;i<len;++i){
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=arr[i];
    NewNode->next=NULL;
    tail->next=NewNode;
    tail=NewNode;
  }
  return head;  
}

LinkList reverseList(LinkList L){
  LinkList pre = NULL; 
  LinkList cur = L->next;     
  LinkList next;         

  while(cur != NULL){
    next = cur->next;  
    cur->next = pre;   
    pre = cur;     
    cur = next;
  }
  L->next = pre;
  return L; 
}

void printList(LinkList hc) {
  if (hc == NULL) {
    printf("NULL\n");
    return;
    }
    Node *p = hc->next;
    while (p != NULL) {
        printf("%c", p->data);
        if (p->next != NULL)
            printf(",");
        p = p->next;
    }
    printf("\n");
}

int main(){
  char arr[100];
  char a;
  int len=0;
  while(scanf("%c",&a)==1){
    if(a == '\n') break;
    if(a == ',') continue;
    arr[len++] = a;
  }
  LinkList L=CreatList(arr,len);
  L = reverseList(L);
  printList(L);
  return 0;
 }
