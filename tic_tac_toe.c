#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void player1(char str[]);
void player2(char str[]);
int getdata(char str[], int t);
int win(char str[]);
int main() {
	int i, j, k = 0;
	char str[9], c = '1';
	for(i = 0; i < 9; i++) {
		str[i] = c;
		c++;
	}
	printf("\n=================================\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%c\t", str[k]);
			k++;
		}
		if(i != 2) 
			printf("\n\n\n\n");
	}
	printf("\n=================================\n");
	player1(str);
	return 0;
}
int getdata(char str[9], int t) {
	char str1[2];
	int s;
        l:	
	if(t == 1)
		printf("Player 1: Enter the square number.\n");
	else if(t == 2)
		printf("Player 2: Enter the square number.\n");
	
	scanf("%s", str1);
	s = atoi(str1);
        if((s > 0) && (s <= 9)) {
		if( str[(s-1)] == 'X' || str[(s-1)] == 'O') {
			printf("Error: Square is already marked. Enter another square number.\n");
			goto l;
		}
	}
     	else {
		printf("Error: Wrong input. Expected input is a number in between 1 to 9.\n");
		goto l;
	} 
	return s;
}  
void player1(char str[9]) {
	int s, r, i, j, k = 0;
	s = getdata(str, 1);
	str[(s-1)] = 'X';
	printf("\n=================================\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%c\t", str[k]);
			k++;
		}
		if(i != 2)
			printf("\n\n\n\n");
	}
	printf("\n=================================\n");
	r = win(str);
	if( r == 1) 
		printf("Winner: Player 1\n");
	else if(r == 3)
		printf("Game Tied\n");
	else 
		player2(str);
	return;
}
void player2(char str[9]) {
	int s, r, i, j, k = 0;
	s = getdata(str, 2); 
	str[(s-1)] = 'O';
	printf("\n=================================\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%c\t", str[k]);
			k++;
		}
		if(i != 2)
			printf("\n\n\n\n");
	}
	printf("\n=================================\n");
	r = win(str);
	if( r == 2) 
		printf("Winner: Player 2\n");
	else if(r == 3)
		printf("Game Tied\n");
	else 
		player1(str);
	return;
}
int win(char str[9]) {
	int i, count = 0;
	for(i = 0; i < 9; i++) {
		if(str[i] == 'X' || str[i] == 'O')
			count++;
	}
	if((str[0] == 'X' && str[1] == 'X' && str[2] == 'X') || (str[3] == 'X' && str[4] == 'X' && str[5] == 'X') || 
	   (str[6] == 'X' && str[7] == 'X' && str[8] == 'X') || (str[0] == 'X' && str[3] == 'X' && str[6] == 'X') || 
	   (str[1] == 'X' && str[4] == 'X' && str[7] == 'X') || (str[2] == 'X' && str[5] == 'X' && str[8] == 'X') || 
	   (str[0] == 'X' && str[4] == 'X' && str[8] == 'X') || (str[2] == 'X' && str[4] == 'X' && str[6] == 'X'))
		return 1;
	else if((str[0] == 'O' && str[1] == 'O' && str[2] == 'O') || (str[3] == 'O' && str[4] == 'O' && str[5] == 'O') || 
	        (str[6] == 'O' && str[7] == 'O' && str[8] == 'O') || (str[0] == 'O' && str[3] == 'O' && str[6] == 'O') || 
	        (str[1] == 'O' && str[4] == 'O' && str[7] == 'O') || (str[2] == 'O' && str[5] == 'O' && str[8] == 'O') || 
	        (str[0] == 'O' && str[4] == 'O' && str[8] == 'O') || (str[2] == 'O' && str[4] == 'O' && str[6] == 'O'))
		return 2;
	else if(count == 9)
		return 3;
	else 
		return 0;
}
