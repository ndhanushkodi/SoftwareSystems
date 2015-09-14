#include <stdio.h>
#include <stdlib.h>

int assign_val(){
	char card_name[3];
	int count = 0;
	while(card_name[0] != 'X'){
		
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		int val;
		val=0;

		switch(card_name[0]){
			case 'K':
			case 'Q':
			case 'J':
				val=10;
				break;
			case 'A':
				val =11;
				break;
			case 'X':
				continue;


			default:
				val = atoi(card_name);
				if((val<1) || (val>10)){
					puts("Naaaahhhh");
					continue;
				}

		
			

		}
		check_val(&val);

	}
}

/* Check if value is 3 to 6 */
void check_val(int* val){
		int count = 0;
		if((*val>2)&&(*val<7))
			count++;
		else if(*val == 10)
			count--;
		printf("Count %i\n", count);
}

int main()
{
	int card_val = assign_val();



	
	return 0;
}
