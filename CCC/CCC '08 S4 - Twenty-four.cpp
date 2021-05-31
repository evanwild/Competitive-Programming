#include <bits/stdc++.h>
using namespace std;

int N, C[4], vals[5];

int do_op(int a, char op, int b) {
    if (op == 1) return a + b;
    if (op == 2) return a - b;
    if (op == 3) return a * b;
    if (b == 0 || a % b != 0) return -20000;
    return a / b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        for (int i = 0; i < 4; i++) cin >> C[i];
        int ans = 0;
        do {
            for (int op1 = 1; op1 <= 4; op1++) {
                for (int op2 = 1; op2 <= 4; op2++) {
                    for (int op3 = 1; op3 <= 4; op3++) {
                        int l = do_op(C[0], op1, C[1]);
                        int m = do_op(C[1], op2, C[2]);
                        int r = do_op(C[2], op3, C[3]);

                        vals[0] = do_op(do_op(l, op2, C[2]), op3, C[3]);
                        vals[1] = do_op(l, op2, r);
                        vals[2] = do_op(C[0], op1, do_op(C[1], op2, r));
                        vals[3] = do_op(C[0], op1, do_op(m, op3, C[3]));
                        vals[4] = do_op(do_op(C[0], op1, m), op3, C[3]);

                        for (int i = 0; i < 5; i++)
                            if (vals[i] <= 24) ans = max(ans, vals[i]);
                    }
                }
            }

        } while (next_permutation(C, C + 4));
        cout << ans << '\n';
    }
}