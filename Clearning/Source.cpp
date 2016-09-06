#include <stdio.h>
#define N 8

//These xy compbinations define all possible moves of a Knight
//int xMove[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
//int yMove[8] = { 1, -1, 2, -2, 2, -2, -1, 1 };
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int counter = 0;

bool isSafe(int x, int y, int sol[N][N]){
	return (x < N && x > -1 && y < N && y > -1 && sol[x][y] == -1);
}

void printSln(int sol[N][N]){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %2d ", sol[i][j]);
		}
		printf("\n");
	}
}

bool solveKTUtil(int x, int y, int movi, int sol[N][N]){
	int next_x, next_y;
	if (movi == N*N) return true;

	//Try all moves
	for (int k = 0; k < 8; k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)){
			sol[next_x][next_y] = movi;
			if (solveKTUtil(next_x, next_y, movi + 1, sol) == true){
				return true;
			}
			else{
				sol[next_x][next_y] = -1;
			}
		}
	}
	return false;
}

bool solveKT(){
	int sol[N][N];
	//Initialize sol 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sol[i][j] = -1;

	int start_x = 0, start_y = 0;
	sol[start_x][start_y] = 0;
	if (solveKTUtil(0, 0, 1, sol) == false){
		printf("solution does not exist!! Start Point: %2d  %2d ", start_x, start_y);
	}
	else
	{
		printSln(sol);
	}
	return true;
}


int main(){
	solveKT();
	return 0;
}

