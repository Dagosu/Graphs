#include <stdio.h>
#include <stdlib.h>

typedef struct muchii
{
	int v1, v2;
};

int main()
{
	FILE* fin = fopen("in.txt", "r");

	//Matrice de adiacenta
	int n, matAd[20][20] = { 0 }, m = 0;
	struct muchii listaMuchii[20];
	fscanf(fin, "%d", &n);

	int v1, v2;
	while (fscanf(fin, "%d", &v1) != EOF)
	{
		fscanf(fin, "%d", &v2);
		listaMuchii[m].v1 = v1;
		listaMuchii[m].v2 = v2;
		m++;
		matAd[v1-1][v2-1] = 1;
	}

	fclose(fin);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", matAd[i][j]);
		printf("\n");
	}

	//Matrice de adiacenta -> Lista de adiacenta
	int listAd[20][20] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int p = 0;
		for (int j = 0; j < n; j++)
		{
			if (matAd[i][j] == 1)
			{
				listAd[i][p] = j;
				p++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d: ", i + 1);
		for (int j = 0; j < n; j++)
		{
			if (listAd[i][j] == 0)
				break;
			printf("%d ", listAd[i][j] + 1);
		}
		printf("\n");
	}

	//Lista de adiacenta -> Matrice de incidenta
	int matInc[20][20] = { 0 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (listAd[i][j] == 0)
				break;
			for (int k = 0; k < m; k++)
			{
				if (listaMuchii[k].v1 == i + 1 && listaMuchii[k].v2 == listAd[i][j] + 1)
				{
					matInc[i][k] = 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", matInc[i][j]);
		printf("\n");
	}

	return 0;
}