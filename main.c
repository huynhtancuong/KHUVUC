#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int farm[101][101];
int row, column, k;
int well, tomb;

int main(int argc, char *argv[]) {
	readFile();
	int d = 0;
	
	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= column; c++) {
			if (farm[r][c] == 1) {
				for (int i = -k; i <= k; i++)
					for (int j = -k; j <= k; j++) {
						if (r+i <= row && c+j <= column)
							if (farm[r+i][c+j] == 0) {
								farm[r+i][c+j] = 3;
								d++;
							}
					}
			}
		}
	}
	
	
	
	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= column; c++) printf("%d ", farm[r][c]);
		printf("\n");
	}
	
	printf("%d", d);
	
	FILE *file = fopen("KHUVUC.OUT", "w");
	
	fprintf(file, "%d", d);
	
	fclose(file);
	
	return 0;
}

int readFile() {
	FILE *file = fopen("KHUVUC.INP", "r");
	if (file == NULL) printf("Can't open file.\n");
	
	char strTemp[255];
	
	//read row, column, k
	fscanf(file, "%s", strTemp);
	row = atoi(strTemp);
	fscanf(file, "%s", strTemp);
	column = atoi(strTemp);
	fscanf(file, "%s", strTemp);
	k = atoi(strTemp);
	
	//read number of well, number of tomb
	fscanf(file, "%s", strTemp);
	well = atoi(strTemp);
	fscanf(file, "%s", strTemp);
	tomb = atoi(strTemp);
	
	//read well's location
	for (int i = 0; i < well; i++) {
		fscanf(file, "%s", strTemp);
		int row_well = atoi(strTemp);
		fscanf(file, "%s", strTemp);
		int column_well = atoi(strTemp);
		
		farm[row_well][column_well] = 1;
	}
	
	//read tomb's location
	for (int i = 0; i < tomb; i++) {
		fscanf(file, "%s", strTemp);
		int row_tomb = atoi(strTemp);
		fscanf(file, "%s", strTemp);
		int column_tomb = atoi(strTemp);
		
		farm[row_tomb][column_tomb] = 2;
	}
	
	//printf("%d %d %d %d %d\n", row, column, k, well, tomb);
	
	fclose(file);
	return 0;
}












































