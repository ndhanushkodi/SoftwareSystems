#include <stdio.h>
#include <stdlib.h>

/* Prompts the user for input and puts the reply in the given buffer.
   User input is truncated to the first two characters.
   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name) {
	puts(prompt);
	scanf("%2s", card_name);
}





/* 
	Puts the value in val for whatever card name the user inputted
	card_name: card name input from user

	val: variable to store card value
*/
int card_value(char *card_name, int *val) {


	switch (card_name[0]) {

		case 'K':
		case 'Q':
		case 'J':
			*val = 10;
			break;
		case 'A':
			*val = 11;
			break;
		case 'X': 
			return 1;
		default: 
			*val = atoi(card_name);
			if ((*val < 1) || (*val > 10)) {
				puts("I don't understand that value!");
				return 1;
			}

	}
	return 0;

	
}



/* Takes in card value and updates the count
   val: value of the card
   ct: current count of the game 
*/
void update_count(int val, int *ct) {

	if ((val > 2) && (val < 7)) {
		(*ct)++;
	} 

	else if (val == 10) {
		(*ct)--;
	}

}



/*
	Runs the code.
	Prompts user input, calls
	getting the card name, figures out the value,
	updates the count, and prints it. 
*/
int main() 
{
	char card_name[3];
	char prompt[] = "Enter the card_name: ";
	int ct = 0;
	while (card_name[0] != 'X') {
		int val = 0;
		int toCont;

		get_card_name(prompt, card_name);
		toCont = card_value(card_name, &val);
		if (toCont) {
			continue;
		}

		update_count(val, &ct);
		printf("Current count: %i\n", ct);
	}
	return 0;
}
