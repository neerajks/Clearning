#include <stdio.h>
#define N 8

void printSln(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%2d", sol[i][j]);
		}
		printf("\n");
	}
}

bool solveQ(int x, int y, int sol[N][N], int queenCounter){
	//Mark current with 1 and Row Column and Diagnols with 0
	if (queenCounter == 7) return true;
	sol[x][y] = 1;
	for (int i = 0; i < N; i++)
	{
		if (sol[x][i] == -1)
			sol[x][i] = 0;
		if (sol[i][y] == -1)
			sol[i][y] = 0;
	}
	int i = x, j = y;
	while (i > -1 && j > -1)
	{
		sol[--i][--j] = 0;
	}
	i = x, j = y;
	while (i < N && j < N)
	{
		sol[++i][++j] = 0;
	}
	i = x, j = y;
	while (i < N && j < N)
	{
		sol[++i][--j] = 0;
	}
	i = x, j = y;
	while (i < N && j < N)
	{
		sol[--i][++j] = 0;
	}

	//Nove to next unsolved X and Y increment X and find Unsolved Y
	x += 1;
	int k = 0;
	bool yFound = false;
	while (k < 8 && (sol[x][(y + k) % 8]) != -1)
	{
		k++;
	}
	if (k < 8)
		yFound = true;
	else
		return false;
	return solveQ(x, (y + k) % 8, sol, queenCounter + 1);
}

bool solveQ(){
	//init sol
	int sol[N][N];
	int queenCounter = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sol[i][j] = -1;
		}
	}

	if (solveQ(0, 0, sol, queenCounter) == true){
		printSln(sol);
	}
	else{
		printf("Cound not solve with start %2d, %2d\n", 0, 0);
		printSln(sol);
	}
	return true;
}

int main(){
	solveQ();
	return 0;
}