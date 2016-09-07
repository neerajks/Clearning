#include <stdio.h>
#define N 8

int printSln(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%2d", sol[i][j]);
		}
		printf("\n");
	}
	return 0;
}

bool solveQUtil(int x, int y, int sol[N][N], int queenCounter){
	int k = 0, l=0;
	bool yFound = false;
	int i = x, j = y;

	//Mark current with 1 and Row Column and Diagnols with 0
	if (queenCounter == 7) return true;
	sol[x][y] = 1;
	for (l = 0;l < N; l++)
	{
		if (sol[x][l] == -1)
			sol[x][l] = 0;
		if (sol[l][y] == -1)
			sol[l][y] = 0;
	}
	
	while (l > -1 && j > -1)
	{
		sol[--l][--j] = 0;
	}
	l = x, j = y;
	while (l < N && j < N)
	{
		sol[++l][++j] = 0;
	}
	l = x, j = y;
	while (l < N && j > -1)
	{
		sol[++l][--j] = 0;
	}
	l = x, j = y;
	while (l > -1 && j < N)
	{
		sol[--l][++j] = 0;
	}

	//Nove to next unsolved X and Y increment X and find Unsolved Y
	x += 1;
	
	while (k < 8 && (sol[x][(y + k) % 8]) != -1)
	{
		k++;
	}
	if (k < 8)
		yFound = true;
	else
		return false;
	return solveQUtil(x, (y + k) % 8, sol, queenCounter + 1); //TODO: Change this to solve this for other possible values of y
}

bool solveQ(){
	//init sol
	int sol[N][N];
	
	for (int k = 0; k < N; k++)
	{
		int queenCounter = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				sol[i][j] = -1;
			}
		}

		if (solveQUtil(0, k, sol, queenCounter) == true){
			printSln(sol);
		}
		else{
			printf("Cound not solve with start %2d, %2d\n", 0, k);
			printSln(sol);
		}
	}
	
	return true;
 }

int main(){
	if (solveQ()){
		printf("Solved !!!");
	}
	return 0;
}