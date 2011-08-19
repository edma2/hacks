#include <stdio.h>
#include <stdlib.h>

enum {
	OP_ADD = 0,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_MAX
};

float goto_op(int op, float x, float y) {
        static void *table[OP_MAX] = {
		[OP_ADD] &&l_add,
		[OP_MUL] &&l_mul,
		[OP_SUB] &&l_sub,
		[OP_DIV] &&l_div
	};
	goto *table[op];
l_add:
	return x+y;
l_sub:
	return x-y;
l_mul:
	return x*y;
l_div:
	return x/y;
}

int main(int argc, char *argv[]) {
        float n[4];
        int i;
        int op1, op2, op3;
        int a, b, c, d;
        char sym[4] = {'+', '-', '*', '/'};

        if (argc != 5) {
                printf("Usage: %s n1 n2 n3 n4\n", argv[0]);
                return -1;
        }

        for (i = 0; i < 4; i++)
                n[i] = atof(argv[i+1]);
        for (i = 0; i < 64; i++) {
                op1 = i&3;
                op2 = (i>>2)&3;
                op3 = (i>>4)&3;
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
                                                if (goto_op(op3, goto_op(op2, goto_op(op1, n[a], n[b]), n[c]), n[d]) == 24.0)
                                                        printf("(((%d %c %d) %c %d) %c %d)\n", (int)n[a], sym[op1], (int)n[b], sym[op2], (int)n[c], sym[op3], (int)n[d]);
                                        }
                                }
                        }
                }
        }
        return 0;
}
