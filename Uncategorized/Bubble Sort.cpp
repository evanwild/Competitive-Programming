#include <cstdio>

int main() {

    int n;
    scanf("%d",&n);

    int t[20];
    for(int i = 0; i < n; i++) {
        scanf("%d",&t[i]);
        printf("%d ",t[i]);
    }
    printf("\n");

    for(int p = 0; p < n; p++) {
        bool sorted = true;
        for(int i = 1; i < n; i++) {
            if(t[i-1]>t[i]) {
                int temp = t[i];
                t[i] = t[i-1];
                t[i-1] = temp;
                sorted = false;
                for(int i = 0; i < n; i++) {
                    printf("%d ",t[i]);
                }
                printf("\n");
            }
        }
        if(sorted) break;
    }

    return 0;
}