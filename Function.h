#include "Datatype.h"
// Nguyen mau ham Student  
void pressToExitOrReturn();

void inputStudent(Student students[], int *n);

void printStudent(Student students[], int n);

void deleteStudent(Student students[], int *n);

void updateStudent(Student students[], int n);

void sortStudentsById(Student students[],int  n);

void displaySortStudentsMenu(Student students[], int n);

void searchStudent(Student students[], int n);

void saveStudentsToFile(Student students[], int n);

void loadStudentsFromFile(Student students[], int *n);

void displayStudentsMenu();

// Teacher 
 
void inputTeacher(Teacher teachers[], int *n);

void printTeacher(Teacher teachers[], int n);

void deleteTeacher(Teacher teachers[], int *n);

void updateTeacher(Teacher teachers[], int n);

void sortTeacherByName(Teacher teachers[],int  n);

void sortTeacherById(Teacher teachers[],int  n);

void displaySortTeacherMenu(Teacher teachers[], int n);

void searchTeacher(Teacher teachers[], int n);

void saveTeachersToFile(Teacher teachers[], int n);

void loadTeachersFromFile(Teacher teachers[], int *n);

void displayTeachersMenu();


// Classroom  

void inputClassroom(Classroom classrooms[], int *n);

void updateClassroom(Classroom classrooms[], int n);

void printClassroom(Classroom classrooms[], int n);

void sortClassroomsByName(Classroom classrooms[], int n);

void sortClassroomsById(Classroom classrooms[], int n);

void deleteClassroom(Classroom classrooms[], int *n);

void saveClassroomsToFile(Classroom classrooms[], int n);

void displaySortClassroomsMenu(Classroom classrooms[], int n);

void loadClassroomsFromFile(Classroom classrooms[], int *n);

void displayClassroomsMenu();


