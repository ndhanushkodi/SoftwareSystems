#include <stdlib.h>


typedef struct island{ //give it name in here because recursive struct
	char *name;
	char *opens;
	char *closes;
	struct island *next; //pointer to next island in 
	//struct, can't be actual island, only pointer
} island;

int main(int argc, char *argv[]){
	// malloc(sizeof(island));

	//create enough space for island, and store address in p
	island *p = malloc (sizeof(island));

	//free the address, release memory allocated from heap address p. 
	free(p);
}