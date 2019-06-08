#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please Splecify Proper File Name\n");
		return 1;
	}
	char *fileName = argv[1];
	FILE *pFile = fopen(fileName,"r");
	if (pFile == NULL) perror("The following error occurred");
	else {
		fclose(pFile);
		printf("%s file successfully closed\n", fileName);
	}
	return 0;
}
