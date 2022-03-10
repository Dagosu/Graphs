#include <stdio.h>

void moore(int x[20][20], int n, int sursa, int l[20], int p[20])
{
	l[sursa] = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != sursa)
		{
			l[i] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		p[i] = -1;
	}

	int q[20], sf = 0;
	q[sf] = sursa;
	while (sf >= 0)
	{
		int v = q[sf];
		sf--;
		for (int i = 0; i < n; i++)
		{
			if (x[v][i] == 1)
			{
				if (l[i] == -1)
				{
					p[i] = v;
					l[i] = l[v] + 1;
					sf++;
					q[sf] = i;
				}
			}
		}
	}
	p[sursa] = -1;
}

int main()
{
	FILE* fin = fopen("in.txt", "r");

	int n, x[20][20] = { 0 }, m = 0, sursa, l[20] = { 0 }, p[20] = { 0 };
	fscanf(fin, "%d", &n);

	int v1, v2;
	while (fscanf(fin, "%d", &v1) != EOF)
	{
		fscanf(fin, "%d", &v2);
		x[v1 - 1][v2 - 1] = 1;
		x[v2 - 1][v1 - 1] = 1;
	}

	fclose(fin);

	scanf("%d", &sursa);
	sursa--;

	moore(x, n, sursa, l, p);
	for (int i = 0; i < n; i++)
		printf("%d ", l[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
		
	printf("\n");


}