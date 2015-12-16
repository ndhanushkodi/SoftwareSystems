#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char ch;
	int count = 0;
	FILE *fp;
	char writeOpt[4] = "w";
	while((ch = getopt(argc,argv, "a")) != EOF){
		switch(ch){
			case 'a':
				writeOpt="a";
			case 'w':
				writeOpt="w";
			default:
				fprintf(stderr, "Unknown option");
				writeOpt = "w";
				return 1;
		}
	}
	argv+=optind;
	argc-=optind;

	for(count = 0;count<argc;count++){
		puts(argv[count]);

	// 	FILE *file0 = readFile;
	}
	char buff[30];
	while(scanf("%s", &buff)){
		// fp = fopen(argv[0])
		// fprintf()
		puts("scanning");
	} 
	return 0;
}