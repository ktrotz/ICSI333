#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_struct
{
    char name[16];
    int age;
    float gpa;
    struct student_struct *next;
} Student;

Student *head; //The head of the linked list

/* Given the student values, initialize a structure,
   and return a pointer to the struct */
Student *makeStudent(char name[16], int age, double gpa)
{
    Student *s = (Student *) malloc(sizeof(Student));
    strcpy(s->name, name);
    s->age = age;
    s->gpa = gpa;
    s->next = NULL;
    return s;  //Change return value....
}


/* Inserts an element to the front of the linkedList */
void push(Student *student)
{
    student->next=head;
    head = student;
     
    
}


/* Traverses the linked list and returns the student with the best GPA */
Student *findTopStudent()
{
    Student *max = head;
    Student *temp = head;
    while(temp !=NULL){
        if(temp->gpa > max->gpa){
          max = temp;  
        }
         temp = temp->next;
    }
    return max;
    
    
}

/* Traverses the linked list and returns the average GPA across all students */
float getAverageGPA()
{
    int i;
    float gpa = 0;
    Student *x = head;
    while (x != NULL){
         gpa = gpa + x->gpa;
        i++;
        x = x->next;
    }
    
    return gpa/i; 
}

int main(int argc, char **argv)
{
    if(argc != 2){
        perror("ERROR: Wrong number of command line args!\n");
        return -1;
    }

 //initialize that the linked list is empty.
    FILE * file;
    file = fopen(argv[1] , "r");
    if (!file){
        perror("ERROR opening file!\n");
        return -1;
    }

    //-------------------------------------------------
    // TODO:  Change main method code BELOW

    char name[16];
    int age;
    float gpa;
    fscanf(file, "%s %d %f", name,&age,&gpa);
        head = makeStudent(name, age, gpa);
        
    while (fscanf(file, "%s %d %f", name,&age,&gpa)!=EOF)
    {
        push(makeStudent(name, age, gpa));
            
    }
    fclose(file);

    // TODO:  Change main method code ABOVE
   //-------------------------------------------------

    Student *topStudent = findTopStudent();
    printf("The Student with the best GPA is: %s\n", topStudent->name);
    printf("The average GPA is: %.2f\n", getAverageGPA());

    return 0;
}