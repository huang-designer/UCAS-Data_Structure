#include <stdio.h>
#define MAXSIZE 100  // 必须加

typedef struct{
  char data[MAXSIZE];
  int top;
}stack;

//初始化栈
void InitStack(stack *s){
  s->top=-1;
}
//判断栈是否为空
int IsEmpty(stack *s){
  return s->top == -1;
}
//压栈
int push(stack *s,char x){
  if(s->top == MAXSIZE-1){
    return 0;
  }
  s->data[++s->top]=x;
  return 1;
}
//出栈
int pop(stack *s,char *x){
  if(IsEmpty(s)) return 0;
  *x=s->data[s->top--];
  return 1;
}

int main(){
  stack s;
  InitStack(&s);  // 必须初始化！
  char x,m;
  int ok = 1;

  while(scanf("%c",&x)==1){
    if(x == '\n') break;  // 换行停止读取
    
    if(x == '('){
      push(&s, '(');
    }
    if(x == ')'){
      if(IsEmpty(&s)){   // 栈空 → 右括号多了，不匹配
        ok = 0;
        break;
      } else {
        pop(&s, &m);     // 匹配，出栈
      }
    }
  }

  // 最后栈空=完全匹配
  if(!IsEmpty(&s)) ok = 0;

  printf("%d", ok);  // 输出 1 或 0
  return 0;
}
