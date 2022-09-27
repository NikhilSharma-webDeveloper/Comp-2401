#include <stdio.h>

#define MAX_SIZE  32

#define C_OK             0
#define C_ERR_ARR_FULL  -1

int  getStuData(int*, float*);
void printStuData(int*, float*, int);
void printErrorMsg(int);


int main()
{
  int student_ids[MAX_SIZE];
  float gpas[MAX_SIZE];
  int nOfElements=getStuData(student_ids,gpas);
  printStuData(student_ids,gpas,nOfElements);
  return(0);
}

int getStuData(int *student_ids, float *gpas){
  int nOfElements=0;
  int flag=0;

  do{
    printf("Please enter the student number and GPA of the student \n");
    int student_id=0;
    float gpa=0;
    scanf("%d %f",&student_id,&gpa);
    if(student_id==-1 || gpa==-1 ){
      flag=1;
    }else{
      student_ids[nOfElements]=student_id;
      gpas[nOfElements]=gpa;
      nOfElements++;
    }
  }while(flag!=1 || nOfElements==MAX_SIZE);
  return nOfElements;
}

void printStuData(int *student_ids, float *gpas, int nOfElements){

  printf("Student Numbers   GPA\n");
  for(int i=0;i<nOfElements;i++){
    printf("%15d %6.2f\n",student_ids[i], gpas[i]);
  }

}
