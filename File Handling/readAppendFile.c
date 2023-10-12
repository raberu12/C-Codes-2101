#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char FN[24]; //firstname
	char MI; //middle initial
	char LN[16]; //lastname
} Nametype;

typedef struct {
	Nametype name;
	int ID;
	char course[8]; //BSCS, BSIS, BSIT
	int yrLevel;
} Studtype;

void displayHeader();
void displayStudent(Studtype S);
void readAppendFile();

int main() {
	readAppendFile();
}

void displayHeader() {
	printf("\n\n");
	printf("%-10s", "ID No.");
	printf("%-16s", "Lastname");
	printf("%-24s", "Firstname");
	printf("%-3s", "MI");
	printf("%-8s", "Course");
	printf("%5s", "Year");
	printf("\n");
	printf("%-10s", "======");
	printf("%-16s", "========");
	printf("%-24s", "=========");
	printf("%-3s", "==");
	printf("%-8s", "======");
	printf("%5s", "====");
}

void displayStudent(Studtype S) {
	printf("\n");
	printf("%-10d", S.ID);
	printf("%-16s", S.name.LN);
	printf("%-24s", S.name.FN);
	printf("%-3c", S.name.MI);
	printf("%-8s", S.course);
	printf("%5d", S.yrLevel);
}
void readAppendFile() {
	FILE *fp;
	FILE *fp2;
	char filename[50];
	char filename2[50];
	Studtype S;
	printf("Enter file you want to copy from: ");
	scanf("%s", filename);
	printf("Enter file you want to copy to: ");
	scanf("%s", filename2);
	
	fp = fopen(filename, "rb");
	fp2 = fopen(filename2, "ab");
	
	if(fp != NULL && fp2 != NULL) {
		displayHeader();
		while(fread(&S, sizeof(Studtype), 1, fp) != 0){
			displayStudent(S);
			fwrite(&S, sizeof(Studtype), 1, fp2);
		}
		fclose(fp);
		fclose(fp2);
	}
}
