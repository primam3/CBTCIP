#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SUBJECTS];
    float average;
    int highest;
    int lowest;
} Student;

void calculateStatistics(Student *student, int numSubjects) {
    int total = 0;
    student->highest = student->scores[0];
    student->lowest = student->scores[0];

    for (int k = 0; k < numSubjects; k++) {
        total += student->scores[k];
        if (student->scores[k] > student->highest) {
            student->highest = student->scores[k];
        }
        if (student->scores[k] < student->lowest) {
            student->lowest = student->scores[k];
        }
    }

    student->average = (float) total / numSubjects;
}

void inputStudentInfo(Student *student, int numSubjects) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    for (int k = 0; k < numSubjects; k++) {
        printf("Enter score for subject %d: ", k + 1);
        scanf("%d", &student->scores[k]);
    }

    calculateStatistics(student, numSubjects);
}

void displayStudentInfo(Student *student, int numSubjects) {
    printf("\nEnter student Name: %s", student->name);
    printf("\nScores: ");
    for (int k= 0; k < numSubjects; k++) {
        printf("%d ", student->scores[k]);
    }
    printf("\n");
    printf("Average Score: %.2f\n Highest Score: %d\n Lowest Score: %d\n", student->average,student->highest,student->lowest);
}

int main() {
    int numStudents, numSubjects;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students is %d\n", MAX_STUDENTS);
        return 1;
    }

    printf("Enter number of subjects: ");
    scanf("%d", &numSubjects);

    if (numSubjects > MAX_SUBJECTS) {
        printf("Maximum number of subjects is %d\n", MAX_SUBJECTS);
        return 1;
    }

    Student students[MAX_STUDENTS];

    for (int i = 0; i < numStudents; i++) {
        printf("Enter information for student %d:\n", i + 1);
        inputStudentInfo(&students[i], numSubjects);
    }

    printf("\nStudents' Performance Summary:");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudentInfo(&students[i], numSubjects);
    }
    return 0;
}