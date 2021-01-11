#include <stdio.h>  //input output
#include <string.h> // strcpy
#include <stdlib.h> // dynamic memory allocation

struct Course {
    char ID[10];
    int score;
};

struct Student {
    char name[255];
    double GPA;
    Course c;   //object Course
};

int plus (int a, int b) {
    return a+b;
}
//  tipe data yang di return int
//  nama function: plus
//  parameter: a dan b
//  createStudent akan mereturn pointer yang mengarah ke Student
//  const char *name sama aja seperti char name[]

Student *createStudent(const char *name, double GPA, const char *ID, int score) {
    //alokasi memory
    Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent -> name, name);  //strcpy((*newStudent).name,name)
    //(*newStudent).attributnya sama aja dengan newStudent->atributnya
    newStudent->GPA = GPA;
    strcpy(newStudent->c.ID, ID);
    newStudent->c.score = score;
    return newStudent;
}
//  tipe data yang di return Student*
//   nama function: createStudent
//  parameter: name, GPA, course (ID dan score)

void removeStudent(Student *s) {
    free(s);    // buang memory yang sudah dialokasikan
    s = NULL;   // kosongkan nilainya
}

void printStudent(Student *s) {
    printf("Name: %s\n",s->name);
    printf("GPA: %lf\n",s->GPA);
    printf("Course ID: %s\n",s->c.ID);
    printf("Score: %d\n", s->c.score);
}

int main() {
    
    // Student students[10]; //static memory Allocation
    //printf("%lu\n", sizeof(Student));
    Student *s1 = createStudent("Budi", 3.90, "COMP6048", 100);
    Student *s2 = createStudent("Abdul", 4.00, "COMP6049", 85);
    // Student *s3 = createStudent(name,gpa,id,score);
    //s1 megarah ke student yang direturn oleh createStudent
    
    printf("BEFORE REMOVE\n");
    printStudent(s1);
    removeStudent(s1);
    printf("AFTER REMOVE\n");
    printStudent(s1);
    //  ga ada garbage collector undefined behaviour

    return 0;
}