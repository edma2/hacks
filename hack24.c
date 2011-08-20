#include <stdio.h>
#include <stdlib.h>

enum {OP_ADD = 0, OP_SUB, OP_MUL, OP_DIV, OP_MAX};

float op(int op, float x, float y) {
        static void *table[OP_MAX] = {
		[OP_ADD] &&l_add,
		[OP_MUL] &&l_mul,
		[OP_SUB] &&l_sub,
		[OP_DIV] &&l_div
	};
	goto *table[op];
l_add: return x+y;
l_sub: return x-y;
l_mul: return x*y;
l_div: return x/y;
}

int main(int argc, char *argv[]) {
        float n[4];
        char s[4] = {'+', '-', '*', '/'};
        int o1, o2, o3;
        int a, b, c, d;
        int i;

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
                                                if (op(o3, op(o2, op(o1, n[a], n[b]), n[c]), n[d]) == 24)
                                                        printf("((%.0f %c %.0f) %c %.0f) %c %.0f\n", n[a], s[o1], n[b], s[o2], n[c], s[o3], n[d]);
                                                if (op(o1, op(o2, n[a], n[b]), op(o3, n[c], n[d])) == 24)
                                                        printf("(%.0f %c %.0f) %c (%.0f %c %.0f)\n", n[a], s[o2], n[b], s[o1], n[c], s[o3], n[d]);
                                        }
                                }
                        }
                }
        }
        return 0;
}
