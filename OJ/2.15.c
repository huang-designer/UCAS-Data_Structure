#include <stdio.h>
#include <stdlib.h>
// 单链表节点结构定义
typedef struct Node {
    int data;               // 数据域
    struct Node *next;      // 指针域
} Node, *LinkList;

//创建链表
LinkList InitList(int arr[],int len){
  LinkList head=(LinkList)malloc(sizeof(Node));
  head->next = NULL;
  Node *tail = head;

  for (int i = 0; i < len; i++) {
      Node *newNode = (Node*)malloc(sizeof(Node));
      newNode->data = arr[i];
      newNode->next = NULL;

      tail->next = newNode;
      tail = newNode;
    }
    return head;
}

//链接链表
LinkList ConnectList(LinkList ha,LinkList hb){
  LinkList hc=ha;
  while(ha->next!=NULL){
    ha=ha->next;
  }
  ha->next=hb->next;
  free(hb);
  return hc;
}

//输出链表
void printList(LinkList hc){
  Node *p=hc->next;
  while(p!=NULL){
    printf("%d",p->data);
    if (p->next != NULL) 
      printf(" ");
    p = p->next;
  }
  printf("\n");
}

int main(){
  int m,n;
  scanf("%d %d", &m,&n);
  int arrm[100],arrn[100];
  for (int i = 0; i < m; i++) {
    scanf("%d", &arrm[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &arrn[i]);
  }
  LinkList ha = InitList(arrm, m);
  LinkList hb = InitList(arrn, n);
  LinkList hc;
  if(m<=n)
    hc=ConnectList(ha,hb);
  else
    hc=ConnectList(hb,ha);
  printList(hc);
}
