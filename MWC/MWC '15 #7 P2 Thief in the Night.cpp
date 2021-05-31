#include <cstdio>

using namespace std;

int f, r;
int cds[6][10005];

void make_prefix_sum() {
    for(int floor = 1; floor <= 5; floor++) {
        for(int apt = 2; apt <= r; apt++) {
            cds[floor][apt] += cds[floor][apt-1];
        }
    }
}

int main() {

    scanf("%d%d", &f, &r);

    for(int i = 1; i <= f; i++) {
        for(int j = 1; j <= r; j++) {
            scanf("%d", &cds[i][j]);
        }
    }

    make_prefix_sum();

    int q;
    scanf("%d", &q);

    int a, b, c;
    while(q--) {
        scanf("%d%d%d", &a, &b, &c);

        if(a == 1) {
            printf("%d\n", cds[c][b]);
        }else {
            printf("%d\n", cds[c][b] - cds[c][a-1]);
        }
    }

    return 0;
}