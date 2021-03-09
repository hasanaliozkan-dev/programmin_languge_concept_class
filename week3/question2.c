#include <stdio.h> 
#include <stdlib.h>
#define MAXCRS 3 
#define MAXCAMPUS 2
void enrollStudents(int arr[MAXCRS][MAXCAMPUS][4]);
void displayNoStudentsInEachCourse(const int arr[MAXCRS][MAXCAMPUS][4]); 
void displayNoStudentsInEachCampus(const int arr[MAXCRS][MAXCAMPUS][4]); 
int find_students(int arr[MAXCRS][MAXCAMPUS][4], int rank, int course);
int main(void) {
int enroll [MAXCRS] [MAXCAMPUS] [4];
enrollStudents(enroll);
displayNoStudentsInEachCourse(enroll);
displayNoStudentsInEachCampus(enroll);

return 0; }

void enrollStudents(int arr[MAXCRS][MAXCAMPUS][4]){

    int a=0,b,c;
    while(a<MAXCRS){
        printf("Processing course number %d: \n",a);
        b=0;
        while (b<MAXCAMPUS)
        {
            printf("Campus %d \n",b);
            c =0;
            while (c<4)
            {
                printf(" Enter number of "); 
                switch (c){
                    case 0 :
                        printf("Freshmen > ");
                        break; 
                    case 1 :
                        printf("Sophomores > ");
                        break; 
                    case 2 :
                        printf("Juniors > ");
                        break; 
                    case 3 :
                        printf("Seniors > "); 
                }   
                scanf("%d", &arr[a][b][c]);
                c++;
                }
            b++;
            }
        a++;
        }
    }

void displayNoStudentsInEachCourse(const int arr[MAXCRS][MAXCAMPUS][4]){
    
    for (int i = 0; i< MAXCRS;++i){
        int sum = 0;
        for(int j = 0;j<MAXCAMPUS;j++){
            for(int k = 0;k<4;++k){
                sum += arr[i][j][k];
            }
        }
        printf("Number of students in course %d is %d\n",i,sum);
   }
}

void displayNoStudentsInEachCampus(const int arr[MAXCRS][MAXCAMPUS][4]){
    
    for (int i = 0; i < MAXCAMPUS; i++)
    {   
        int sum =0;
        for (int j = 0; j< MAXCRS; j++)
        {   
            for (int k = 0; k < 4; k++)
            {
                sum += arr[j][i][k];
            }
        
        }
        printf("Number of students in campus %d is %d\n",i,sum);
    }
    






}