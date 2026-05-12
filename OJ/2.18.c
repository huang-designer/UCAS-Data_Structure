#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node,*LinkList;

LinkList CreatList(int arr[],int len){
  if (len == 0) return NULL;
  LinkList head=(LinkList)malloc(sizeof(Node));
  head->data = arr[0];
  head->next = NULL;
  LinkList p = head;
  for(int i=1;i<len;i++){
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=arr[i];
    p->next=NewNode;
    NewNode->next=NULL;
    p=NewNode;
  }
  return head;
}

LinkList DELETE(LinkList L,int i){
  if (L == NULL) return NULL;
  LinkList p=L;
  if(i==0){
    L=L->next;
    free(p);
  }
  else{
    for(int j=1;j<i;j++){
      p=p->next;
    }
    LinkList q=p->next;
    p->next =q->next;
    free(q);
  }
  return L;
}

void printList(LinkList hc) {
  if (hc == NULL) {
    printf("NULL\n");
    return;
    }
    Node *p = hc;
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL)
            printf(" ");
        p = p->next;
    }
    printf("\n");
}

int main(){
  int arr[100];
  int num;
  char ch;
  int len=0;
  while (scanf("%d%c", &num, &ch) == 2) {
    arr[len++] = num;
    if (ch == '\n') break;
  }
  int i;
  scanf("%d",&i);
  LinkList L=CreatList(arr,len);
  L=DELETE(L,i);
  printList(L);
  return 0;
}
