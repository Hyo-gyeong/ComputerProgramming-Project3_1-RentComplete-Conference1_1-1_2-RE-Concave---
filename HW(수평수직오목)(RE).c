#include <stdio.h>
#define BOARD_SIZE 6  

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
	int hSum = 0;
	int vSum = 0;
	char player = b[r][c];
	int ri = r, ci = c;

	while (ci != -1 && b[r][ci] == player){
		hSum++;
		ci--;
	}
	ci = c+1;
	while (ci != BOARD_SIZE && b[r][ci] == player){
		hSum++;
		ci++;
	}	
	if (hSum == 5)
		return 1;

	while (ri != -1 && b[ri][c] == player){
		vSum++;
		ri--;
	}
	ri = r+1;
	while (ri != BOARD_SIZE && b[ri][c] == player){
		vSum++;
		ri++;
	}
	if (vSum == 5)
		return 1;
	return 0;
}
void display(char b[][BOARD_SIZE]) 
{
	char ch;
	int i, j; 
	
	printf("     ");
	for (i= 0; i< BOARD_SIZE; i++)
		printf("%2d", i); 
	printf("\n     ---------------------\n");
	for (i= 0; i< BOARD_SIZE; i++) { 
		printf("%3d |", i); 
		for (j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]); 
		printf("\n");
	} 
}
void main() 
{
	char board[BOARD_SIZE][BOARD_SIZE]; 
	char turn = 'X'; 
	int r, c;
	int i, j;
	int count;
	int win = 0;

	for(i=0; i< BOARD_SIZE ; i++ ) 
		for(j = 0 ; j < BOARD_SIZE ; j++)
			board[i][j] = ' ';

	count = 1; 
	display(board); 
	do { 
		printf("Player %c(Заї­):", turn); 
		scanf("%d %d", &r, &c);
		if (board[r][c] != ' ') 
			continue;
		board[r][c] = turn;
		display(board);

		if (winCheck(board, r, c)){
			printf("Player %c wins!\n", board[r][c]);
			break;
		}
		turn = (turn == 'X'? 'O':'X'); 
		count++;
		
	} while(!win && count <= BOARD_SIZE * BOARD_SIZE);

	if (!win && count == BOARD_SIZE * BOARD_SIZE)
		printf("Nobody wins\n");
}