#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    char LN[16], FN[24], MI;
    char course[8];
    int yearLevel;
} Studrec;

typedef struct node {
    Studrec stud;
    struct node *link;
} *StudList;

void insertFirst(StudList *A, Studrec stud) {
    StudList trav = *A;

    while (trav != NULL && trav->stud.ID != stud.ID) {
        trav = trav->link;
    }

    if (trav == NULL) {
        StudList node = (StudList)malloc(sizeof(struct node));
        if (node != NULL) {
            node->stud = stud;
            node->link = *A;
            *A = node;
        }
    }
}

void displayList(StudList trav) {
    while (trav != NULL) {
        printf("ID: %d\nName: %s, %s %c.\nCourse: %s\nYear Level:%d\n\n",
               trav->stud.ID, trav->stud.LN, trav->stud.FN, trav->stud.MI,
               trav->stud.course, trav->stud.yearLevel);
        trav = trav->link;
    }
}

int main(void) {
    StudList head = NULL;
    Studrec stud1 = {1, "Bernate", "Karylle", 'B', "BS-IT", 2};
    Studrec stud2 = {2, "Magdadaro", "Matt Vincent", 'E', "BS-IT", 2};
    Studrec stud3 = {3, "Snow", "Kobe", 'B', "BS-DOG", 4};

    insertFirst(&head, stud1);
    insertFirst(&head, stud2);
    insertFirst(&head, stud3);

    displayList(head);

    return 0;
}
