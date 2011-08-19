#include <stdio.h>
#include <stdlib.h>

enum {OP_ADD = 0, OP_SUB, OP_MUL, OP_DIV, OP_MAX};

float goto_op(int op, float x, float y) {
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
        char sym[4] = {'+', '-', '*', '/'};
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
                                                if (goto_op(o3, goto_op(o2, goto_op(o1, n[a], n[b]), n[c]), n[d]) == 24)
                                                        printf("(((%d %c %d) %c %d) %c %d)\n", (int)n[a], sym[o1], (int)n[b], sym[o2], (int)n[c], sym[o3], (int)n[d]);
                                        }
                                }
                        }
                }
        }
        return 0;
}
