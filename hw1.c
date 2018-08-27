#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) { /*argc holds the number of arguements and argv is an array of string pointers with indifinate size  */

	/*Check to see if no more than 4 arg entered */
	if(argc > 4 && argc > 0) {
		printf("Invalid number of arguements. No greater than 4");
		return 0;
	}
	FILE *fp;
	int i;
	
	fp = fopen("output.txt","w");
	/*writing to a file is fprintf()*/
	for(i = 1; i < argc; i++) {
		fprintf(fp, "%s", argv[i]); /* Remember to specify type of what is being returned*/
	}
	fclose(fp);
	return 0;
}
