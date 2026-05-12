#include<stdio.h>

int main() {
    int va[101];
    int n = 0;
    int x;
    char c;
    while (1) {
        scanf("%d", &va[n]);
        n++;
        if ((c = getchar()) == '\n') {
            break;
        }
    }
    scanf("%d", &x);
    int pos = n;
    for (int i = 0; i < n; i++) {
        if (va[i] > x) {
            pos = i;
            break;
        }
    }
    for (int i = n; i > pos; i--) {
        va[i] = va[i-1];
    }
    va[pos] = x;
    n++;
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", va[i]);
    }
    printf("\n");
    return 0;
}
