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
    //TODO: Implement this function
    
    //use malloc because you don't need to know how much memory you need
    //as in how many Students in each text file
    
    //covert double gpa to float    
    float fgpa = (float) gpa;    
    
    //sizeof reads bytes
    //allocate space off the heap to store variables of type Student and the cast Student to a pointer (student)    
    Student *student = (Student *) malloc(sizeof(Student));

    //*student should point to Student variables to assign the input param values to each element 
    strcpy(student->name, name);
    student->age = age;
    student->gpa = fgpa;
    
    //point(set) next element of Linked List to null. NOTE: next is a pointer of type student_struct
    student->next = NULL;
    
    return student;   
}



/* Inserts an element to the front of the linkedList */
void push(Student *student)
{
    //TODO: Implement this function
    
    //head equals pointer of type Student
  
    //point next to old head
    student->next = head;
   
    //set head to new student node
    head = student;
}



/* Traverses the linked list and returns the student with the best GPA */
Student *findTopStudent()
{
    //TODO: Implement this function
    
    //pointers to compare values
    Student *topStudent = head;
    Student *nextStudent = head;
   
    //check if topStudent has a value
    while(nextStudent != NULL)
    {
        //compare gpa scores
        if(nextStudent->gpa > topStudent->gpa)
        {
            //set new topStudent based on gpa
            topStudent = nextStudent;
        }
       
        nextStudent = nextStudent->next;  
     }
    
     return topStudent; 
}



/* Traverses the linked list and returns the average GPA across all students */
float getAverageGPA()
{
    //TODO: Implement this function

    int numOfStudents = 0; //for average
    float totalGPA = 0;
   
    //point student to first element of linked list
    Student *student = head;

    //check is student has a value
    while(student != NULL)
    {        
        totalGPA = totalGPA + student->gpa;

        //point student to next value in linked list
        student = student->next;         
                
        numOfStudents++;                  
    }
    
    float average = totalGPA/numOfStudents;

    return average; 
}



int main(int argc, char **argv)
{
    if(argc != 2){
        perror("ERROR: Wrong number of command line args!\n");
        return -1;
    }

    //head->next = NULL; //initialize that the linked list is empty.
    FILE * file;
    file = fopen(argv[1] , "r");
    if (!file){
        perror("ERROR opening file!\n");
        return -1;
    }

    //-------------------------------------------------
    // TODO:  Change main method code BELOW

    char s1[16];
    int s2;
    double s3; //pass s3 as double and then convert to float within method makeStudent
    
    //Call *makeStudent passing the address of the param

    //head points to first element
    head = makeStudent(s1, s2, s3); //*makeStudent returns a pointer of type Student
    
    printf("\n");
    
    //fscanf read based on the address of the variable
    while (fscanf(file, "%s %d %lf", s1, &s2, &s3)!=EOF)
    {
        printf("READING FILE LINE: %s %d %lf\n", s1, s2, s3);
        
        //makeStudent returns pointer         
        Student *student = makeStudent(s1, s2, s3);
        
        //add student to the front of the linked list
        push(student);         
    }
    
    printf("\n");
    
    fclose(file);

    // TODO:  Change main method code ABOVE
   //-------------------------------------------------

    Student *topStudent = findTopStudent();
    printf("The Student with the best GPA is: %s\n", topStudent->name);
    printf("The average GPA is: %.2f\n", getAverageGPA());

    return 0;
}