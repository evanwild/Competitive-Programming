#include <cstdio>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int ans = 0;

    int input;
    for(int i = 0; i < n; i++) {
        scanf("%d", &input);
        ans ^= input;
    }

    printf("%d\n", ans);

    return 0;
}