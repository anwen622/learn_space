/*
 * fib.c - 打印前 N 个斐波那契数，用来练习「新建文件 -> 生成补丁 -> 打补丁」流程。
 */

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_COUNT	10
#define MAX_COUNT	90	/* 再大 unsigned long 就溢出了 */

/**
 * 打印前 n 个斐波那契数。
 * @param n 打印个数；n <= 0 时不输出任何内容。
 */
static void print_fib(int n)
{
	unsigned long a = 0;
	unsigned long b = 1;
	int i;

	for (i = 0; i < n; i++) {
		unsigned long next = a + b;

		printf("%lu\n", a);
		a = b;
		b = next;
	}
}

int main(int argc, char **argv)
{
	char *end;
	long val;
	int n = DEFAULT_COUNT;

	if (argc > 1) {
		val = strtol(argv[1], &end, 10);
		if (*end != '\0' || val < 0 || val > MAX_COUNT) {
			fprintf(stderr, "usage: %s [count]\n", argv[0]);
			return EXIT_FAILURE;
		}
		n = (int)val;
	}

	print_fib(n);
	return EXIT_SUCCESS;
}
