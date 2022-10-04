#include <stdio.h>

#define MAX_SIZE  32
#define C_OK       0

int  initStuData(int*, float*);
void printStuData(int*, float*, int);
int  orderStuData(int*, float*, int);

int  findMaxIndex(float*, int);


int main()
{
  int studentNumbers[MAX_SIZE];
  float gPAs[MAX_SIZE];
  int nOfElement=initStuData(studentNumbers,gPAs);
  printf("\n\nPrinting Without Sorting\n\n");
  printStuData(studentNumbers,gPAs,nOfElement);
  printf("\n\n Printing in Decending Order \n\n" );
  orderStuData(studentNumbers,gPAs,nOfElement);
  printStuData(studentNumbers,gPAs,nOfElement);
  return(0);
}

/*
function: orderStuData
  in/out: studentNumbers,gPAs,nOfElement
  return: C_OK once everything goes well
*/
int orderStuData(int* studentNumbers, float* gPAs, int nOfElement){
  int tempStudentNumbers[nOfElement];
  float tempGPAS[nOfElement];
  for(int i=0;i<nOfElement;i++){
    tempStudentNumbers[i]=studentNumbers[i];
    tempGPAS[i]=gPAs[i];
  }

  for(int i=0;i<nOfElement;i++){
    int maxIndex=findMaxIndex(tempGPAS,nOfElement);
    studentNumbers[i]=tempStudentNumbers[maxIndex];
    gPAs[i]=tempGPAS[maxIndex];
    tempGPAS[maxIndex]=-1;
  }
  return C_OK;
}
/*
function: findMaxIndex
      in: gPAs, nOfElement
  return: index of the highest GPA
*/
int findMaxIndex(float *gPAs,int nOfElement){
  int max=0;
  for(int i=0;i<nOfElement;i++){
    if(gPAs[i]>gPAs[max]){
      max=i;
    }
  }
  return max;
}
/*
Function: printStuData
      in: Student numbers, gPAs, nOfElement
  return: void
*/
void printStuData(int *studentNumbers,float *gPAs, int nOfElement){
  printf("Student Number \t GPA\n");
  for(int i=0;i<nOfElement;i++){
    printf("%14d\t%1.2f\n" ,studentNumbers[i],gPAs[i] );
  }
}
/*
   Function:  initStuData
        out:  array of initialized student numbers
        out:  array of initialized student GPAs
     return:  number of data pairs initialized
*/
int initStuData(int *sn, float *gp)
{
  sn[0] = 100987777;
  gp[0] = 5.63;
  sn[1] = 100234555;
  gp[1] = 10.32;
  sn[2] = 100443665;
  gp[2] = 3.9;
  sn[3] = 100123444;
  gp[3] = 8.4;
  sn[4] = 101789000;
  gp[4] = 7.9;
  sn[5] = 100888779;
  gp[5] = 9.1;
  sn[6] = 100444888;
  gp[6] = 11.5;
  sn[7] = 101987222;
  gp[7] = 2.3;
  sn[8] = 100000787;
  gp[8] = 7.9;
  sn[9] = 101886644;
  gp[9] = 4.8;

  return(10);
}
