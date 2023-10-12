#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void updateFile(char *oldCourse, char *newCourse);

int main() {
	updateFile("BSCS", "BSCOMM");
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
void updateFile(char *oldCourse, char *newCourse) {
	FILE *fp;
	char filename[50];
	Studtype student;
	printf("Choose a file to open: ");
	scanf("%s", filename);
	fp = fopen(filename, "rb+");
	if(fp != NULL) {
		while(fread(&student, sizeof(Studtype), 1, fp) == 1) {
			if(strcmp(student.course, oldCourse) == 0) {
				strcpy(student.course, newCourse);
				fseek(fp, sizeof(Studtype) * -1, SEEK_CUR);
				fwrite(&student, sizeof(Studtype), 1, fp);
				fseek(fp, 0, SEEK_CUR);
			}
		}
		fclose(fp);
	}
}
