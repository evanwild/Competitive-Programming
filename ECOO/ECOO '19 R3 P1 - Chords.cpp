#include <cstdio>

using namespace std;

int main() {

    int test_cases = 10;

    while(test_cases--) {

        int n;
        scanf("%d", &n);

        bool f[1000001] = {false};

        int freq;
        int max_freq = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &freq);
            f[freq] = true;
            if(freq > max_freq) max_freq = freq;
        }

        int answer = 0;

        for(int i = 1; i < max_freq; i++) {
            if(f[i]) {
                for(int j = i+i; j <= max_freq; j+=i) {
                    if(j > max_freq) {
                        break;
                    }
                    if(f[j]) {
                        answer++;
                    }
                }
            }
        }
        printf("%d\n", answer);
    }

    return 0;
}