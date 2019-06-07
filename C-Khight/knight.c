#include <stdio.h>
#include <stdlib.h>
#define INF 1

int		**createBuf(int n, int m)
{
	int **buf = malloc(sizeof(int*) * n);
	int i = -1;
	while (++i < n)
	{
		buf[i] = malloc(sizeof(int) * m);
		int j = -1;
		while (++j < m)
			buf[i][j] = -INF;
	}
	return (buf);
}

int		ways(int x, int y, int n, int m, int **buf)
{
	if (x == n - 1 && y == m - 1)
		return (1);
	int res = 0;
	if (x + 2 < n && y + 1 < m)
	{
		if (buf[x + 2][y + 1] == -INF)
			buf[x + 2][y + 1] = ways(x + 2, y + 1, n, m, buf);
		res += buf[x + 2][y + 1];
	}
	if (x + 1 < n && y + 2 < m)
	{
		if (buf[x + 1][y + 2] == -INF)
			buf[x + 1][y + 2] = ways(x + 1, y + 2, n, m, buf);
		res += buf[x + 1][y + 2];
	}
	return (res);
}

int		main(void)
{
	FILE *in = fopen("knight.in", "r");
	int n; fscanf(in, "%d ", &n);
	int m; fscanf(in, "%d", &m);
	FILE *out = fopen("knight.out", "w");
	int **buf = createBuf(n, m);
	fprintf(out, "%d\n", ways(0, 0, n, m, buf));
	// printf("%d\n", ways(0, 0, n, m));
}