#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];
    char name[50];
    float marks;
};

struct Student students[100];
int count = 0;

void addStudent() {
    printf("\nEnter Student ID: ");
    scanf("%s", students[count].id);

    while(getchar() != '\n');

    printf("Enter Name: ");
    scanf("%[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    while(getchar() != '\n');

    count++;
    printf("Student added successfully.\n");
}

void viewStudents() {
    if(count == 0) {
        printf("\nNo students found.\n");
        return;
    }

    printf("\n===== Student List =====\n");
    for(int i = 0; i < count; i++) {
        printf("%d. ID: %s | Name: %s | Marks: %.2f\n",
               i+1,
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}

void searchStudent() {
    char id[20];

    printf("\nEnter Student ID to search: ");
    scanf("%s", id);

    for(int i = 0; i < count; i++) {
        if(strcmp(students[i].id, id) == 0) {
            printf("Found: ID: %s | Name: %s | Marks: %.2f\n",
                   students[i].id,
                   students[i].name,
                   students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

void deleteStudent() {
    char id[20];
    int found = 0;

    printf("\nEnter Student ID to delete: ");
    scanf("%s", id);

    for(int i = 0; i < count; i++) {
        if(strcmp(students[i].id, id) == 0) {
            found = 1;

            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if(!found) {
        printf("Student not found.\n");
    }
}

void updateStudent() {
    char id[20];
    int found = 0;

    printf("\nEnter Student ID to update: ");
    scanf("%s", id);

    while(getchar() != '\n');

    for(int i = 0; i < count; i++) {
        if(strcmp(students[i].id, id) == 0) {
            found = 1;

            printf("Enter new name: ");
            scanf("%[^\n]", students[i].name);

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            while(getchar() != '\n');

            printf("Student updated successfully.\n");
            break;
        }
    }

    if(!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        while(getchar() != '\n');

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                updateStudent();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 6);

    return 0;
}
