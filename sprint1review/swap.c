//swaps two integers
//takes in the value at location p1 and
//value at location p2, and swaps them
void swap(int *p1, int *p2){
	int temp; //temp so you don't overwrite p1 or p2
	temp = *p2;
	*p2 = *p1;
	*p1 = temp;
}

//tests the swap by printing the results
int main(){
	int x = 10;
	int y = 20;
	swap(&x,&y);

	printf("x: %d, y: %d\n", x,y);
}