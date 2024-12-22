#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct attd {
 char stdName[10];
 int stdID;
 float subMarksE, subMarksM, subMarksSS, subMarksH, subMarksSc;
 struct attd *next;
};
struct attd *head = NULL;
struct attd *temp = NULL;
void insert() {
 int id;
 struct attd *student = (struct attd *)malloc(sizeof(struct attd));
 if (!student) {
  printf("Memory allocation failed.\n");
  return;
 }
 printf("Enter Student ID: ");
 scanf("%d", &id);
 for (temp = head; temp; temp = temp->next) {
  if (temp->stdID == id) {
   printf("Student with ID %d already exists.\n", id);
   free(student);
   return;
  }
 }
 student->stdID = id;
 printf("Enter student name: ");
 scanf("%s", student->stdName);
 printf("Enter marks for English (out of 50): ");
 scanf("%f", &student->subMarksE);
 printf("Enter marks for Maths (out of 50): ");
 scanf("%f", &student->subMarksM);
 printf("Enter marks for Social Studies (out of 50): ");
 scanf("%f", &student->subMarksSS);
 printf("Enter marks for Hindi (out of 50): ");
 scanf("%f", &student->subMarksH);
 printf("Enter marks for Science (out of 50): ");
 scanf("%f", &student->subMarksSc);
 student->next = head;
 head = student;
}

char grade(float marks) {
 if (marks >= 90) return 'A';
 if (marks >= 80) return 'B';
 if (marks >= 70) return 'C';
 if (marks >= 60) return 'D';
 return 'F';
}

void EReport() {
 int n, iD, found = 0;
 float mE, mM, mSS, mH, mSc;
 if (!head) {
  printf("Student list is empty.\n");
  return;
 }
 printf("Press 1 for individual report\nPress 2 for group report\n");
 scanf("%d", &n);
 if (n == 1) {
  printf("Enter student ID: ");
  scanf("%d", &iD);
  for (temp = head; temp; temp = temp->next) {
   if (temp->stdID == iD) {
    mE = temp->subMarksE * 2;
    mM = temp->subMarksM * 2;
    mSS = temp->subMarksSS * 2;
    mH = temp->subMarksH * 2;
    mSc = temp->subMarksSc * 2;
    printf("\nID: %d\nName: %s\n", temp->stdID, temp->stdName);
    printf("English: %.2f (Grade: %c)\n", mE, grade(mE));
    printf("Maths: %.2f (Grade: %c)\n", mM, grade(mM));
    printf("Social Studies: %.2f (Grade: %c)\n", mSS, grade(mSS));
    printf("Hindi: %.2f (Grade: %c)\n", mH, grade(mH));
    printf("Science: %.2f (Grade: %c)\n", mSc, grade(mSc));
    found = 1;
    break;
   }
  }
  if (!found) printf("Student with ID %d not found.\n", iD);
 } else if (n == 2) {
  for (temp = head; temp; temp = temp->next) {
   mE = temp->subMarksE * 2;
   mM = temp->subMarksM * 2;
   mSS = temp->subMarksSS * 2;
   mH = temp->subMarksH * 2;
   mSc = temp->subMarksSc * 2;
   printf("\nID: %d\nName: %s\n", temp->stdID, temp->stdName);
   printf("English: %.2f (Grade: %c)\n", mE, grade(mE));
   printf("Maths: %.2f (Grade: %c)\n", mM, grade(mM));
   printf("Social Studies: %.2f (Grade: %c)\n", mSS, grade(mSS));
   printf("Hindi: %.2f (Grade: %c)\n", mH, grade(mH));
   printf("Science: %.2f (Grade: %c)\n", mSc, grade(mSc));
  }
 }
}
void export() {
 FILE *fp = fopen("C:\\Users\\DELL\\OneDrive\\Desktop\\std.txt", "w");
 if (!fp) {
  printf("File could not be opened.\n");
  return;
 }
 fprintf(fp, "******** Student Examination Detail ********\n");
 if (!head) {
  fprintf(fp, "Student list is empty.\n");
  fclose(fp);
  return;
 }
 for (temp = head; temp; temp = temp->next) {
  fprintf(fp, "\nID: %d\nName: %s\n", temp->stdID, temp->stdName);
  fprintf(fp, "English: %.2f (Grade: %c)\n", temp->subMarksE * 2, grade(temp->subMarksE * 2));
  fprintf(fp, "Maths: %.2f (Grade: %c)\n", temp->subMarksM * 2, grade(temp->subMarksM * 2));
  fprintf(fp, "Social Studies: %.2f (Grade: %c)\n", temp->subMarksSS * 2, grade(temp->subMarksSS * 2));
  fprintf(fp, "Hindi: %.2f (Grade: %c)\n", temp->subMarksH * 2, grade(temp->subMarksH * 2));
  fprintf(fp, "Science: %.2f (Grade: %c)\n", temp->subMarksSc * 2, grade(temp->subMarksSc * 2));
 }
 fclose(fp);
}

int main() {
 int ch;
 printf("******** Student Examination Detail ********\n");
 do {
  printf("\n1) Enter Student Details\n2) View Evaluation Report\n3) Export to File\n4) Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &ch);
  switch(ch){
   case 1:
    insert();
    break;
   case 2:
    EReport();
    break;
   case 3:
    export();
    printf("exported to file located in desktop folder");
    break;
  }
 } while (ch != 4);
 return 0;
}
