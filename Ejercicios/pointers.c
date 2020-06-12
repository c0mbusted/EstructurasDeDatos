#include <stdio.h>

struct student {
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

//prototype of our function here
void printStudent(struct student);
void readStudent(struct student *studptr);

 int main (void) {
     struct student me;//we dont initialize it

     readStudent(&me);
     printStudent(me);
     //printStudent(you);

     return 0;
 }

 //function
 void readStudent(struct student *studptr) {
     printf("Enter first name: \n");
     scanf("%s", (*studptr).firstName);
     //dereference structure  () and modify component .firstName
     printf("Enter last name: \n");
     scanf("%s", (*studptr).lastName);
     printf("Enter b year: \n");
     scanf("%d", &(*studptr).birthYear);//we got to mem add , deref value and modify value
     printf("grade: \n");
     scanf("%lf", &(*studptr).aveGrade);


 }
 void printStudent(struct student stud) {
     printf("Name: %s %s\n",stud.firstName,stud.lastName);
     printf("BirthYear: %d\n",stud.birthYear);
     printf("Grade: %.2lf\n",stud.aveGrade);
 }