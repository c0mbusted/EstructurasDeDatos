#include <stdio.h>

struct student {
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

//prototype of our function here
void printStudent(struct student);

 int main (void) {
     struct student me={"Leticia","Palazuelos",1995,3.6};
     struct student you={"Rob","Young", 1997,2.8};

     printStudent(me);
     printStudent(you);

     return 0;
 }

 //function
 void printStudent(struct student stud) {
     printf("Name: %s %s\n",stud.firstName,stud.lastName);
     printf("BirthYear: %d\n",stud.birthYear);
     printf("Name: %.2lf\n",stud.aveGrade);
 }