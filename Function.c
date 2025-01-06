#include <stdio.h>
#include <string.h>
#include "Function.h"
void pressToExitOrReturn() {
    char choice;
    printf("\nPress \t[0]Exit            [b]Return ");
    scanf(" %c", &choice);
    if (choice == '0') {
        printf("Exiting the program...\n");
        exit(0);
    } else if (choice == 'b' || choice == 'B') {
        printf("Returning to the menu...\n");
        return; 
    } else {
        printf("Invalid input. Returning to the menu...\n");
        return; 
    }
}
void displayMainMenu() {
    printf("\n             *** MAIN MENU ***\n");
    printf("\n"); 
    printf("            1. Manage Students.\n");
    printf("            2. Manage Teacher.\n");
    printf("            3. Manage Classroom.\n");
    printf("            0. Exit Program.\n");
    printf("            ====================\n");
    printf("            Your choice: ");
}
void inputStudent(Student students[], int *n) {
    int num;
    printf("Enter the number of students to add: ");  // N
    scanf("%d", &num);                            
    getchar(); 
     for (int i = 0; i < num; i++) {
        int duplicate = 1;
            while (duplicate) {
            printf("Enter student ID: "); 
            scanf("%d", &students[*n].id);
            getchar();  
            duplicate = 0;
            for (int j = 0; j < *n; j++) {
                if (students[j].id == students[*n].id) {
                    printf("ID already exists.\n");
                    duplicate = 1;
                    break;
                    }
                }
            }
           while (1) {
            printf("Enter student name : ");
            fgets(students[*n].name, 50, stdin);
            students[*n].name[strcspn(students[*n].name, "\n")] = '\0'; 
            if (strlen(students[*n].name)== 0) {
                printf("Name cannot be empty.\n");
            } else if (strlen(students[*n].name)>20) {
                printf("Name is too long.\n");
            } else {
                break;
            }
            }
            printf("Enter classroom ID: ");
            scanf("%d", &students[*n].classroomId);
            getchar();
           while (1) {
            printf("Enter gender : ");
            fgets(students[*n].gender, 10, stdin);
            students[*n].gender[strcspn(students[*n].gender, "\n")] = '\0'; 
            int lenght = strlen(students[*n].gender);
            if (lenght == 0) {
                printf("Gender cannot be empty.\n");
            } else if (lenght > 10) {
                printf("Gender is too long.\n");
            } else {
                break;
            }
            }
           while (1) {
            printf("Enter email : ");
            fgets(students[*n].email, 50, stdin);
            students[*n].email[strcspn(students[*n].email, "\n")] = '\0'; 
            int lenght = strlen(students[*n].email);
            if (lenght == 0) {
                printf("Email cannot be empty.\n");
            } else if (lenght > 30) {
                printf("Email is too long.\n");
            } else {
                int emailDuplicate = 0;
                for (int j = 0; j < *n; j++) {
                    if (strcmp(students[j].email, students[*n].email) == 0) {
                        printf("Email already exists.\n");
                        emailDuplicate = 1;
                        break;
                    }
                }
                if (emailDuplicate == 0) {
                    break;
                }
            }
           }
            while (1) {
            printf("Enter phone number (1-10 characters): ");
            fgets(students[*n].phone, 20, stdin);
            students[*n].phone[strcspn(students[*n].phone, "\n")] = '\0'; 
            int lenght = strlen(students[*n].phone);
            if (lenght == 0) {
                printf("Phone number cannot be empty.\n");
            } else if (lenght > 11) {
                printf("Phone number is too long.\n");
            } else {
                int phoneDuplicate = 0;
                for (int j = 0; j < *n; j++) {
                    if (strcmp(students[j].phone, students[*n].phone) == 0) {
                        printf("Phone number already exists.\n");
                        phoneDuplicate = 1;
                        break;
                    }
                }
                if (phoneDuplicate == 0) {
                    break;
                }
            }			
        }

        (*n)++;
    }
    printf("%d students have been added to the list.\n", num);
    pressToExitOrReturn();
}
void printStudent(Student students[], int n) {
    printf("\nStudent List:\n");
    printf("ID   | Name                 | Classroom | Gender    | Email                   | Phone\n");
    printf("-----------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-20s | %-9d | %-9s | %-23s | %-15s\n",
               students[i].id, students[i].name, students[i].classroomId, students[i].gender,
               students[i].email, students[i].phone);
    }
    pressToExitOrReturn();
}
void updateStudent(Student students[], int n) {
    int id;
    printf("Enter the ID of the student to update: ");
    scanf("%d", &id);
    getchar(); 
    int i;
    for (i = 0; i < n; i++) {
        if (students[i].id == id) {
            break;
        }
    }
    if (i == n) {
        printf("Student with ID %d does not exist.\n", id);
    } else {
        while (1) {
            printf("Enter new name : ");
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            int lenght = strlen(students[i].name);
            if (lenght == 0) {
                printf("Name cannot be empty.\n");
            } else if (lenght > 20) {
                printf("Name is too long.\n");
            } else {
                break;
            }
        }
        printf("Enter new classroom ID: ");
        scanf("%d", &students[i].classroomId);
        getchar();
        while (1) {
            printf("Enter new gender : ");
            fgets(students[i].gender, 10, stdin);
            students[i].gender[strcspn(students[i].gender, "\n")] = '\0';
            int lenght = strlen(students[i].gender);
            if (lenght == 0) {
                printf("Gender cannot be empty.\n");
            } else if (lenght > 10) {
                printf("Gender is too long.\n");
            } else {
                break;
            }
           }
          while (1) {
            printf("Enter new email : ");
            fgets(students[i].email, 50, stdin);
            students[i].email[strcspn(students[i].email, "\n")] = '\0';
            int lenght = strlen(students[i].email);
            if (lenght == 0) {
                printf("Email cannot be empty.\n");
            } else if (lenght > 30) {
                printf("Email is too long.\n");
            } else {
                int emailDuplicate = 0;
                for (int j = 0; j < n; j++) {
                    if (j != i && strcmp(students[j].email, students[i].email) == 0) {
                        printf("Email already exists.\n");
                        emailDuplicate = 1;
                        break;
                    }
                }
                if (emailDuplicate == 0) {
                    break;
                }
            }
          }
           while (1) {
            printf("Enter new phone number : ");
            fgets(students[i].phone, 20, stdin);
            students[i].phone[strcspn(students[i].phone, "\n")] = '\0';
            int lenght = strlen(students[i].phone);
            if (lenght == 0) {
                printf("Phone number cannot be emtpy.\n");
            } else if (lenght > 11) {
                printf("Phone number is too long.\n");
            } else {
                int phoneDuplicate = 0;
                for (int j = 0; j < n; j++) {
                    if (j != i && strcmp(students[j].phone, students[i].phone) == 0) {
                        printf("Phone number already exists.\n");
                        phoneDuplicate = 1;
                        break;
                    }
                }
                if (phoneDuplicate == 0) {
                    break;
                }
            }
        }

        printf("Student information updated successfully.\n");
    }
    pressToExitOrReturn();
}
void deleteStudent(Student students[], int *n) {
    int id;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);
    getchar(); 
    int i;
    for (i = 0; i < *n; i++) {
        if (students[i].id == id) {
            break;
        }
    }
    if (i == *n) {
        printf("Student with ID %d does not exist.\n", id);
    } else {
    	char confirm; 
    	printf("Are you sure want to delete this ID (y/n): ");
    	scanf("%c",&confirm);
    	getchar(); 
		if(confirm == 'y' || confirm == 'Y') {
        	for (int j = i; j < *n - 1; j++) {
            	students[j] = students[j + 1];
        	}
        	(*n)--;
        	printf("Student with ID %d has been deleted.\n", id);
    	}else{
    		printf("Cancel");
    	} 
    }
    pressToExitOrReturn();
}
void sortStudentsByName(Student students[], int n) {
    }
  void sortStudentsById(Student students[], int n) {
     for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].id > students[j].id) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
void displaySortStudentsMenu(Student students[], int n) {
    int sort;
    printf("\nChoose sorting by:\n");
    printf("[1] Sort by Name\n");
    printf("[2] Sort by ID\n");
    printf("Enter your choice: ");
    scanf("%d", &sort);
    getchar();  
    if (sort == 1) {
        sortStudentsByName(students, n);
    } else if (sort == 2) {
        sortStudentsById(students, n);
    } else {
        printf("Invalid criteria chosen.\n");
        return;
    }
    printf("Student list sorted successfully.\n");
    printStudent(students, n);
}
void searchStudent(Student students[], int n) {
    char searchName[50];
    int found = 0;
    printf("Enter the name of the student to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  
    printf("\nSearch Results:\n");
    printf("ID   | Name                | Classroom | Gender    | Email                   | Phone\n");
    printf("-----------------------------------------------------------------------------------\n");
   for (int i = 0; i < n; i++) {
        if (strstr(students[i].name, searchName) != NULL) {
            printf("%-4d | %-20s | %-9d | %-9s | %-23s | %-15s\n",
                   students[i].id, students[i].name, students[i].classroomId,
                   students[i].gender, students[i].email, students[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found matching the name \"%s\".\n", searchName);
    }
    pressToExitOrReturn();
}
  void saveStudentsToFile(Student students[], int n) {
    FILE *file = fopen("student.bin", "wb");
    if (file == NULL) {
        printf("Dont open file.\n");
        return;
    }
    fwrite(students, sizeof(Student), n, file);
    fclose(file);
    printf("Student information saved successfully.\n");
}
  void loadStudentsFromFile(Student students[], int *n) {
    FILE *file = fopen("student.bin", "rb");
    if (file == NULL) {
        printf("Dont open file.\n");
        return;
    }
    *n = fread(students, sizeof(Student), 100, file);
    fclose(file);
    printf("Student data loaded successfully.\n");
}
  void displayStudentsMenu() {
	Student students[100];
	int n;
    int studentChoice;
    loadStudentsFromFile(students, &n);
    do {
        printf("\n*** Student Management System Using C ***\n");
		printf(" \n");
		printf("         =========MENU=========\n");
		printf("         [1] Input A New Student.\n");
		printf("         [2] Show All Students.\n");
		printf("         [3] Update A Student.\n");
		printf("         [4] Delete A Student.\n");
		printf("         [5] Arrange Students.\n");
		printf("         [6] Search A Student.\n");
		printf("         [0] Go Back.\n");
		printf("         ======================\n");
		printf("         Enter Your Choice: ");
        scanf("%d", &studentChoice);
        getchar();
        switch (studentChoice) {
            case 1:
                inputStudent(students, &n);
                saveStudentsToFile(students, n);
                break;
            case 2:
                printStudent(students, n);
                break;
            case 3:
                updateStudent(students, n);
                saveStudentsToFile(students, n);
                break;
            case 4:
                deleteStudent(students, &n);
                saveStudentsToFile(students, n);
                break;
            case 5:
                displaySortStudentsMenu(students, n);
                saveStudentsToFile(students, n);
                break;
            case 6:
				searchStudent(students, n); 
				break; 
			case 7: 
			    
			    break; 
            case 0:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (studentChoice != 0);
}
// CLASSROOM  
void inputClassroom(Classroom classrooms[], int *n) {
    int num;
    printf("Enter the number of classrooms to add: ");
    scanf("%d", &num);
    getchar(); 
    pressToExitOrReturn();
}
void printClassroom(Classroom classrooms[], int n) {
    printf("\nClassroom List:\n");
    printf("ID   | Classroom Name        | Students | Teacher\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-20s | %-9d | %-20s\n",
               classrooms[i].id, classrooms[i].classroomName, classrooms[i].studentCount, classrooms[i].classroomName);
    }
    pressToExitOrReturn();
}
void updateClassroom(Classroom classrooms[], int n) {
    int id;
    printf("Enter the ID of the classroom to update: ");
    scanf("%d", &id);
    getchar(); 
    int i;
    for (i = 0; i < n; i++) {
        if (classrooms[i].id == id) {
            break;
        }
    }
    if (i == n) {
        printf("Classroom with ID %d does not exist.\n", id);
    } else {
        while (1) {
            printf("Enter new classroom name : ");
            fgets(classrooms[i].classroomName, 50, stdin);
            classrooms[i].classroomName[strcspn(classrooms[i].classroomName, "\n")] = '\0';
            int length = strlen(classrooms[i].classroomName);
            if (length == 0) {
                printf("Classroom name cannot be empty.\n");
            } else if (length > 50) {
                printf("Classroom name is too long.\n");
            } else {
                break;
            }
        }
        printf("Enter new number of students: ");
        scanf("%d", &classrooms[i].studentCount);  
        getchar();
          while (1) {
            printf("Enter new teacher name : ");
            getchar() ;
            fgets(classrooms[i].classroomName, 50, stdin);
            classrooms[i].classroomName[strcspn(classrooms[i].classroomName, "\n")] = '\0';
            int length = strlen(classrooms[i].classroomName);
            if (length == 0) {
                printf("Teacher name cannot be empty.\n");
            } else if (length > 50) {
                printf("Teacher name is too long.\n");
            } else {
                break;
            }
        }
        printf("Classroom information updated successfully.\n");
    }
    pressToExitOrReturn();
}
void deleteClassroom(Classroom classrooms[], int *n) {
    int id;
    printf("Enter the ID of the classroom to delete: ");
    scanf("%d", &id);
    getchar(); 
    int i;
    for (i = 0; i < *n; i++) {
        if (classrooms[i].id == id) {
            break;
        }
    }
    if (i == *n) {
        printf("Classroom with ID %d does not exist.\n", id);
    } else {
    	char confirm; 
    	printf("Are you sure you want to delete this classroom (y/n): ");
    	scanf("%c",&confirm);
    	getchar(); 
		if(confirm == 'y' || confirm == 'Y') {
        	for (int j = i; j < *n - 1; j++) {
            	classrooms[j] = classrooms[j + 1];
        	}
        	(*n)--; 
        	printf("Classroom with ID %d has been deleted.\n", id);
    	}else{
    		printf("Cancel\n");
    	} 
    }
    pressToExitOrReturn();
}
void sortClassroomsByClassroom(Classroom classrooms[], int n){}

void sortClassroomsById(Classroom classrooms[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (classrooms[i].id > classrooms[j].id) {
                Classroom temp = classrooms[i];
                classrooms[i] = classrooms[j];
                classrooms[j] = temp;
            }
        }
    }
}
void displaySortClassroomsMenu(Classroom classrooms[], int n) {
    int sort;
    printf("\nChoose sorting by:\n");
    printf("[1] Sort by Classroom Name\n");
    printf("[2] Sort by ID\n");
    printf("Enter your choice: ");
    scanf("%d", &sort);
    getchar();
    if (sort == 1) {
        sortClassroomsByClassroom(classrooms, n);
    } else if (sort == 2) {
        sortClassroomsById(classrooms, n);
    } else {
        printf("Invalid choice.\n");
        return;
    }

    printf("Classroom list sorted successfully.\n");
    printClassroom(classrooms, n);
    pressToExitOrReturn();
}
void searchClassroom(Classroom classrooms[], int n) {

    pressToExitOrReturn();
}
void saveClassroomsToFile(Classroom classrooms[], int n) {
    FILE *file = fopen("classroom.bin", "wb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    fwrite(classrooms, sizeof(Classroom), n, file);
    fclose(file);
    printf("Classroom information saved successfully.\n");
}
void loadClassroomsFromFile(Classroom classrooms[], int *n) {
    FILE *file = fopen("classroom.bin", "rb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    *n = fread(classrooms, sizeof(Classroom), 100, file);
    fclose(file);
    printf("Classroom data loaded successfully.\n");
}
void displayClassroomsMenu() {
    Classroom classrooms[100];
    int n;
    int classroomChoice;
    loadClassroomsFromFile(classrooms, &n);
    do {
        printf("\n*** Classroom Management System ***\n");
        printf("         =========MENU=========\n");
        printf("         [1] Add A New Classroom.\n");
        printf("         [2] Show All Classrooms.\n");
        printf("         [3] Update A Classroom.\n");
        printf("         [4] Delete A Classroom.\n");
        printf("         [5] Sort classrooms.\n");
        printf("         [6] Search classrooms.\n");
        printf("         [0] Exit.\n");
        printf("         ======================\n");
        printf("         Enter Your Choice: ");
        scanf("%d", &classroomChoice);
        getchar();

        switch (classroomChoice) {
            case 1:
                inputClassroom(classrooms, &n);
                saveClassroomsToFile(classrooms, n);
                break;
            case 2:
                printClassroom(classrooms, n);
                break;
            case 3:
                updateClassroom(classrooms, n);
                saveClassroomsToFile(classrooms, n);
                break;
            case 4:
                deleteClassroom(classrooms, &n);
                saveClassroomsToFile(classrooms, n);
                break;
            case 5:
                displaySortClassroomsMenu(classrooms, n);
                break;
            case 6:
                searchClassroom(classrooms, n);
                break;
            case 0:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (classroomChoice != 0);
}
// TEACHER 
void inputTeacher(Teacher teachers[], int *n) {
    pressToExitOrReturn();
}
void printTeacher(Teacher teachers[], int n) {
    printf("\nTeacher List:\n");
    printf("ID   | Name                | Gender    | Email                   | Phone\n");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-20s | %-9s | %-23s | %-15s\n",
               teachers[i].id, teachers[i].name, teachers[i].gender,
               teachers[i].email, teachers[i].phone);
    }
    pressToExitOrReturn();
}
void updateTeacher(Teacher teachers[], int n) {
    int id;
    printf("Enter the ID of the Teacher to update: ");
    scanf("%d", &id);
    getchar(); 
    int i;
    for (i = 0; i < n; i++) {
        if (teachers[i].id == id) {
            break;
        }
    }

    pressToExitOrReturn();
}
void deleteTeacher(Teacher teachers[], int *n) {
    int id;
    printf("Enter the ID of the Teacher to delete: ");
    scanf("%d", &id);
    getchar(); 
    int i;
    pressToExitOrReturn();
}
void sortTeachersByName(Teacher teachers[],int  n) {}
void sortTeachersById(Teacher teachers[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (teachers[i].id > teachers[j].id) {
                Teacher temp = teachers[i];
                teachers[i] = teachers[j];
                teachers[j] = temp;
            }
        }
    }
}
void displaySortTeachersMenu(Teacher teachers[], int n) {
    int sort;
    printf("\nChoose sorting by:\n");
    printf("[1] Sort by Name\n");
    printf("[2] Sort by ID\n");
    printf("Enter your choice: ");
    scanf("%d", &sort);
    getchar();  
    if (sort == 1) {
        sortTeachersByName(teachers, n);
    } else if (sort == 2) {
        sortTeachersById(teachers, n);
    } else {
        printf("Invalid choice.\n");
        return;
    }
    printf("Teacher list sorted successfully.\n");
    printTeacher(teachers, n);
}

void searchTeacher(Teacher teachers[], int n) {
    char searchName[50];
    int found = 0;

    printf("Enter the name of the teacher to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  

    printf("\nSearch Results:\n");
    printf("ID   | Name                | Gender    | Email                   | Phone\n");
    printf("----------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (strstr(teachers[i].name, searchName) != NULL) {
            printf("%-4d | %-20s | %-9s | %-23s | %-15s\n",
                   teachers[i].id, teachers[i].name,
                   teachers[i].gender, teachers[i].email, teachers[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No teacher found matching the name.\n");
    }

    pressToExitOrReturn();
}

void saveTeachersToFile(Teacher teachers[], int n) {
    FILE *file = fopen("teacher.bin", "wb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    fwrite(teachers, sizeof(Teacher), n, file);
    fclose(file);
    printf("Teacher information saved successfully.\n");
}

void loadTeachersFromFile(Teacher teachers[], int *n) {
    FILE *file = fopen("teacher.bin", "rb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    *n = fread(teachers, sizeof(Teacher), 100, file);
    fclose(file);
    printf("Teacher data loaded successfully.\n");
}

void displayTeachersMenu() {
    Teacher teachers[100];
    int n = 0;
    int teacherChoice;
    loadTeachersFromFile(teachers, &n);
    do {
        printf("\n*** Student Management System Using C ***\n");
		printf(" \n");
		printf("         =========MENU=========\n");
		printf("         [1] Input A New Teacher.\n");
		printf("         [2] Show All Teachers.\n");
		printf("         [3] Update A Teacher.\n");
		printf("         [4] Delete A Teacher.\n");
		printf("         [5] Arrange Teacher.\n");
		printf("         [6] Search A Teacher.\n");
		printf("         [0] Go Back.\n");
		printf("         ======================\n");
		printf("         Enter Your Choice: ");
        scanf("%d", &teacherChoice);
        getchar();

        switch (teacherChoice) {
            case 1:
                inputTeacher(teachers, &n);
                saveTeachersToFile(teachers, n);
                break;
            case 2:
                printTeacher(teachers, n);
                break;
            case 3:
                updateTeacher(teachers, n);
                saveTeachersToFile(teachers, n);
                break;
            case 4:
                deleteTeacher(teachers, &n);
                saveTeachersToFile(teachers, n);
                break;
            case 5:
                displaySortTeachersMenu(teachers, n);
                saveTeachersToFile(teachers, n);
                break;
            case 6:
				searchTeacher(teachers, n); 
				break; 
            case 0:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (teacherChoice != 0);
}
