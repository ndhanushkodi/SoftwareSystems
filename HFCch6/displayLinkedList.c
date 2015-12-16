#include <stdio.h>
#include <stdlib.h>



typedef struct island{ //give it name in here because recursive struct
	char *name;
	char *opens;
	char *closes;
	struct island *next; //pointer to next island in 
	//struct, can't be actual island, only pointer
} island;

void display(island *start){
	island *i = start;
	for(;i!=NULL;i=i->next){
		printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
	}
}

int main(int argc, char *argv[]){
	island amity = {"Amity", "09:00", "17:00", NULL};
	island craggy = {"Craggy", "09:00", "17:00", NULL};
	island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
	island shutter = {"Shutter", "09:00", "17:00", NULL};
	//stored in stack, because stack has memory for local variables
	
	amity.next = &craggy; //pointer to next island is address of craggy
	craggy.next = &isla_nublar;
	isla_nublar.next = &shutter;

	//inserts skull between isla nublar and shutter
	island skull = {"Skull", "09:00", "17:00", NULL};
	isla_nublar.next = &skull;
	skull.next = &shutter; 

	display(&amity);
}