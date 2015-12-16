#include <stdio.h>
#include <stdlib.h>

typedef struct island{ //give it name in here because recursive struct
	char *name;
	char *opens;
	char *closes;
	struct island *next; //pointer to next island in 
	//struct, can't be actual island, only pointer
} island;

island* create(char *name){
	island *i = malloc(sizeof(island)); //create space for island
	//store address in i

	i->name = name;
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i; //create returns address of the new struct
}

void display(island *start){
	island *i = start;
	for(;i!=NULL;i=i->next){
		printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
	}
}

int main(int argc, char *argv[]){
	char name[80];
	fgets(name, 80, stdin);
	island *p_island0 = create(name);

	fgets(name, 80, stdin);
	island *p_island1 = create(name);
	p_island0->next = p_island1;

	display(p_island0);
}