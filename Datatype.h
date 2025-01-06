#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int classroomId;
    char gender[10];
    char email[50];
    char phone[20];
    int listofcourseIDs [100];
    int numofregistered ;
} Student;

typedef struct {
	int id;
	char name[50];
    char gender[10];
    char email[50];
    char phone[20];
    int listIDs[100];
	int numofSubject;
	 
} Teacher;

typedef struct {
    int id;
    char classroomName[50];
    int studentCount;
    char teacher[50];
} Classroom; 
