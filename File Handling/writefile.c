#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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
void writeFile();

int main() {
	writeFile();
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

void writeFile() {
	Studtype S;
	int count;
	FILE *fp;
	fp = fopen("test.dat", "wb");
	if(fp != NULL) {
		for(count = 0; count < MAX; count++) {
			printf("IMO ID: ");
			scanf(" %d", &S.ID);
			printf("IMO APILYEDO: ");
			scanf(" %[^\n]", S.name.LN);
			printf("IMO NGAN: ");
			scanf(" %[^\n]", S.name.FN);
			printf("IMO MIDDLE INITIAL: ");
			scanf(" %c", &S.name.MI);
			printf("IMO KURSO: ");
			scanf(" %[^\n]", S.course);
			printf("IMO YEAR: ");
			scanf(" %d", &S.yrLevel);
			fwrite(&S, sizeof(Studtype), 1, fp);
		}
		fclose(fp);
		fp = fopen("test.dat", "rb");
		if(fp != NULL) {
			rewind(fp);
			displayHeader();
			while(fread(&S, sizeof(Studtype), 1, fp) != 0) {
				displayStudent(S);
			}
		}
		fclose(fp);
	}
}
