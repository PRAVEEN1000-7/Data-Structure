#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[50];
    int id;
    char grade;
} Student;

typedef struct {
    Student s[MAX];
    int cnt;
} StudentList;

void init(StudentList *l) {
    l->cnt = 0;
}

void add(StudentList *l) {
    if (l->cnt >= MAX) {
        printf("List is full.\n");
        return;
    }

    Student st;
    printf("Name: ");
    scanf("%s", st.name);
    printf("ID: ");
    scanf("%d", &st.id);
    printf("Grade: ");
    scanf(" %c", &st.grade);

    l->s[l->cnt++] = st;
}

void removestud(StudentList *l) {
    int id, i, j;
    printf("ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < l->cnt; ++i) {
        if (l->s[i].id == id) {
            for (j = i; j < l->cnt - 1; ++j) {
                l->s[j] = l->s[j + 1];
            }
            l->cnt--;
            return;
        }
    }

    printf("Student not found.\n");
}

void update(StudentList *l) {
    int id;
    char grade;
    printf("ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < l->cnt; ++i) {
        if (l->s[i].id == id) {
            printf("New grade: ");
            scanf(" %c", &grade);
            l->s[i].grade = grade;
            return;
        }
    }

    printf("Student not found.\n");
}

void display(StudentList *l) {
    for (int i = 0; i < l->cnt; ++i) {
        printf("Name: %s, ID: %d, Grade: %c\n",
               l->s[i].name, l->s[i].id, l->s[i].grade);
    }
}

int main() {
    StudentList sl;
    init(&sl);

    int choice;
    while (1) {
        
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student to List\n");
        printf("2. Remove Student from List\n");
        printf("3. Update Student Grade\n");
        printf("4. Display All Students in List\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(&sl);
                break;
            case 2:
                removestud(&sl);
                break;
            case 3:
                update(&sl);
                break;
            case 4:
                display(&sl);
                break;
            case 5:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
