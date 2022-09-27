#include <stdio.h>

#define MAX_SIZE  32

#define C_OK             0	// Success flag
#define C_ERR_ARR_FULL  -1	// Error code for array is full
#define C_ERR_BAD_SN    -2	// Error code for a bad student number
#define C_ERR_BAD_GPA   -3	// Error code for a bad GPA

int  getStuData(int*, float*);
void printStuData(int*, float*, int);
int  orderStuData(int*, float*, int);

int  validateSN(int);
int  validateGPA(float);
void printErrorMsg(int);
int  findMaxIndex(float*, int);


int main()
{

  return(0);
}


