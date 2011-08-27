#include <stdio.h>
#include <stdlib.h>

enum {OP_ADD = 0, OP_SUB, OP_MUL, OP_DIV, OP_MAX};
float op(int op, float x, float y) {
        switch(op) {
                case OP_ADD: return x+y;
                case OP_SUB: return x-y;
                case OP_MUL: return x*y;
                case OP_DIV: return x/y;
        }
        return -1;
}

int main(int argc, char *argv[]) {
        float n[4], ans;
        char s[4] = {'+', '-', '*', '/'};
        int o1, o2, o3, a, b, c, d, i;

        if (argc != 5) {
                printf("Usage: %s n1 n2 n3 n4\n", argv[0]);
                return -1;
        }
        for (i = 0; i < 4; i++)
                n[i] = atof(argv[i+1]);
        for (i = 0; i < 64; i++) {
                o1 = i & 3;
                o2 = (i >> 2) & 3;
                o3 = (i >> 4) & 3;
                for (a = 0; a < 4; a++) {
                        for (b = 0; b < 4; b++) {
                                if (b == a)
                                        continue;
                                for (c = 0; c < 4; c++) {
                                        if (c == a || c == b)
                                                continue;
                                        for (d = 0; d < 4; d++) {
                                                if (d == a || d == b || d == c)
                                                        continue;
                                                ans = op(o3, op(o2, op(o1, n[a], n[b]), n[c]), n[d]);
                                                if (ans >= 23.999999 && ans <= 24.0000001)
                                                        printf("((%.1f %c %.1f) %c %.1f) %c %.1f\n", n[a], s[o1], n[b], s[o2], n[c], s[o3], n[d]);
                                                ans = op(o2, op(o1, n[a], n[b]), op(o3, n[c], n[d]));
                                                if (ans >= 23.999999 && ans <= 24.0000001)
                                                        printf("(%.1f %c %.1f) %c (%.1f %c %.1f)\n", n[a], s[o1], n[b], s[o2], n[c], s[o3], n[d]);
                                        }
                                }
                        }
                }
        }
        return 0;
}
