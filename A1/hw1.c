/*
 *	Sai Peri
 *	Homework 1
 *	8/27/2018
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]) { /*argc holds the number of arguements and argv is an array of string pointers with indifinate size  */

	/*Check to see if no more than 4 arg entered */
	if(argc > 5 && argc > 0) {
		printf("Invalid number of arguements. No greater than 4");
		return 0;
	}
	FILE *fp; // only creating file pointer so the output file is rewritten each runtime. Otherwise it appends
	int i;
	char temp[128]; // char array in order to append output.

	fp = fopen("output.txt", "w"); //Rewriting to file when command runs

	for(i = 1; i < argc; i++) {
		sprintf(temp, "%s >> output.txt", argv[i]); //Appending piping (C right-shift operator?)
		system(temp); // System command in order to run queries
	}
	fclose(fp); // Closing file
	return 0;
}
