#include <stdio.h>
#include <malloc.h>
#define INF 100

int		*readValues(int n, FILE *fd)
{
	int *values = malloc(sizeof(int) * n);
	int i = -1;
	while (++i < n)
	{
		char c;
		fscanf(fd, "%c", &c);
		if (c == '.')
			values[i] = 0;
		else if (c == '"')
			values[i] = 1;
		else if (c == 'w')
			values[i] = -1;
	}
	return (values);
}

int		*createBuf(int n)
{
	int *buf = malloc(sizeof(int) * n);
	int i = -1;
	while (++i < n)
		buf[i] = -INF;
	return (buf);
}

int		maxValue(int val1, int val2, int val3)
{
	int max = val1;
	if (val2 > max)
		max = val2;
	if (val3 > max)
		max = val3;
	return (max);
}

int		collect(int pos, int *values, int n, int *buf)
{
	if (pos == n - 1)
		return (values[n - 1]);
	else if (buf[pos] == -INF)
	{
		int jump1 = -1, jump3 = -1, jump5 = -1;
		if (pos + 1 < n && values[pos + 1] != -1)
			jump1 = collect(pos + 1, values, n, buf);
		if (pos + 3 < n && values[pos + 3] != -1)
			jump3 = collect(pos + 3, values, n, buf);
		if (pos + 5 < n && values[pos + 5] != -1)
			jump5 = collect(pos + 5, values, n, buf);

		int max = maxValue(jump1, jump3, jump5);
		if (max == -1)
			buf[pos] = -1;
		else
			buf[pos] = values[pos] + max;
	}
	return (buf[pos]);
}

int		main(void)
{
	FILE *in = fopen("lepus.in", "r");
	int n; fscanf(in, "%d\n", &n);
	int *values = readValues(n, in);
	int *buf = createBuf(n);
	// printf("%d\n", collect(0, values, n, buf));
	FILE *out = fopen("lepus.out", "w");
	fprintf(out, "%d\n", collect(0, values, n, buf));
}