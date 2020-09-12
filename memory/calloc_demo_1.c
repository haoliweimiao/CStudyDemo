#include <stdio.h>
#include <stdlib.h>

int main() {

    int i,n;
    int *a;

    printf("please input number: ");
    scanf("%d",&n);

    a = (int*)calloc(n, sizeof(int));
    printf("input %d number: \n", n);

    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    printf("输入的数字为: ");

    for(i=0; i<n; i++) {
        printf("%d",a[i]);
    }

    free(a);

    return 0;
}
