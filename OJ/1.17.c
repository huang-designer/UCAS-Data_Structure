#include<stdio.h>

int main(){
  int k,m,i;
  scanf("%d %d",&k,&m);
  int s[1000] = {0};
  s[k-1]=1;
  for(i=k;i<=m;++i){
    for(int j=i-k;j<i;++j){
      s[i]+=s[j];
    }
  }
  printf("%d",s[m]);
  return 0;
}
