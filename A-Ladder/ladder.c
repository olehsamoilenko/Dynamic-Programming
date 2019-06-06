#include <stdio.h>
#include <stdlib.h>
#define INF 2000000000

int		*readValues(int n, FILE *in)
{
	int *values = malloc(sizeof(int) * (n + 1));
	values[0] = 0;
	int i = 0;
	while (++i <= n)
		fscanf(in, "%d", &values[i]);
	return (values);
}

int		*bufArray(int n)
{
	int *buf = malloc(sizeof(int) * (n + 1));
	int i = -1;
	while (++i <= n)
		buf[i] = -INF;
	return (buf);
}

int		sum(int pos, int *values, int *buf, int n)
{
	if (pos >= n)
		return (values[n]);
	else
	{
		if (buf[pos] == -INF)
		{
			buf[pos] = values[pos];
			if (sum(pos + 1, values, buf, n) > sum(pos + 2, values, buf, n))
				buf[pos] += sum(pos + 1, values, buf, n);
			else
				buf[pos] += sum(pos + 2, values, buf, n);
		}
		return (buf[pos]);
	}
}

int		main(void)
{
	FILE *in = fopen("ladder.in", "r");
	int n; fscanf(in, "%d\n", &n);
	int *values = readValues(n, in);
	int *buf = bufArray(n);
	FILE *out = fopen("ladder.out", "w");
	fprintf(out, "%d\n", sum(0, values, buf, n));
	// printf("%d\n", sum(0, values, buf, n));
	return (0);
}