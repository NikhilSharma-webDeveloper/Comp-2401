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

/*
Function:   main
 Purpose:   This is the main function of the program which will first of all get
            student Number as well as gpas of the student then print
            all the data entered by the user if it encounter any error it does
            stop the program and print the error message on the screen
  return:   int or the success flag
*/
int main()
{
 int studentIDS[MAX_SIZE];
 float gpas[MAX_SIZE];

 int nOfElements=getStuData(studentIDS,gpas);
 if(nOfElements>=0){
   printf("\n\n\n *** ORIGINAL DATA: ***\n\n\n");
   printStuData(studentIDS,gpas,nOfElements);
   orderStuData(studentIDS,gpas,nOfElements);
   printf("\n\n\n *** ORDERED DATA: ***\n\n\n");
   printStuData(studentIDS,gpas,nOfElements);

 }else{
   if(nOfElements<-1){
     printErrorMsg(nOfElements);
   }else{
     printErrorMsg(nOfElements);
     printf("\n\n\n *** ORIGINAL DATA: ***\n\n\n");
     printStuData(studentIDS,gpas,nOfElements);
     orderStuData(studentIDS,gpas,nOfElements);
     printf("\n\n\n *** ORDERED DATA: ***\n\n\n");
     printStuData(studentIDS,gpas,nOfElements);
   }

 }
 return(0);

}

/*
  Function:   getStuData
   Purpose:   This method is used to get the data from the user after getting
              the data it will validate if the studentNumber as well as gpa is
              in the correct range, if it is not in the correct range or if the
              array get full it will return the corresponding errorCode and if
              array get full it will return C_ERR_ARR_FULL. Or if user enter -1
              then it will stop and return the size of the array
       Out:   studentIds, gpas
    Return:   If the array will get full or with the invalid user input it will
              return the corresponding errorCode
              If user enter the -1, it will return the number of the elements
              we have entered in the Array
*/
int getStuData(int *studentIDS, float *gpas){
   int nOfElements=0;
   int flag=0;

   do{
      printf("\n Please enter a student number and GPA of the student (-1 -1 to end) : \t");
      int studentId=0;
      float gpa=0;
      scanf("%d %f",&studentId,&gpa);
      int validGPA=validateGPA(gpa);
      int validStudentId=validateSN(studentId);
   if(studentId== -1 || gpa== -1 ){
      flag=1;
   }else if(validGPA == C_OK && validStudentId == C_OK){
      studentIDS[nOfElements]=studentId;
      gpas[nOfElements]=gpa;
      nOfElements++;
   }else{
      if(validGPA!=C_OK){
         return validGPA;
      }else{
         return validStudentId;
      }
   }
   }while(flag!=1 && nOfElements!=MAX_SIZE);
   return nOfElements;
}

/*
  Function:   printStuData
   Purpose:   This method is used to print all the data entered by the user
        In:   student_ids, gpas, nOfElements
*/
void printStuData(int *student_ids, float *gpas, int nOfElements){
   printf("Student Numbers   GPA\n");
   for(int i=0;i<nOfElements;i++){
      printf("%15d %6.2f\n",student_ids[i], gpas[i]);
   }
   printf("\nWe read %d student record",nOfElements);
}

/*
  Function:   validateSN
   Purpose:   This method is used to check if the student number entered by the
              user is in the range of (100000000 and 199999999) inclusively
        In:   studentNumber
    Return:   If the student number is in correct range it return C_OK else
              C_ERR_BAD_SN
*/
int validateSN(int studentNumber){
   if(studentNumber>=100000000 && studentNumber <= 199999999){
      return C_OK;
   }else{
      return C_ERR_BAD_SN;
   }
}

/*
  Function:   validGPA
   Purpose:   This method is used to check if the GPA entered by the user is
              in the range of (0 and 12) inclusively
        In:   gpa
    Return:   If the gpa is in correct range it return C_OK else C_ERR_BAD_GPA
*/
int validateGPA(float gpa){
   if(gpa>=0 && gpa <=12){
      return C_OK;
   }else{
      return C_ERR_BAD_GPA;
   }
}

/*
  Function:   printErrorMsg
   Purpose:   This method is used to print the corresponding error message
              according
        In:   studentNumber
    Return:   If the student number is in correct range it return C_OK else
              C_ERR_BAD_SN
*/
void printErrorMsg(int errorCode){

   if(errorCode== C_ERR_BAD_SN){
      printf("ERROR: Student number is not in the correct Range \n");
   }else if(errorCode== C_ERR_BAD_GPA){
      printf("Error: GPA is not in the correct Range \n");
   }else{
      printf("Error: No more element can be added \n");
   }
}

/*
  Function:   orderStuData
   Purpose:   This function will sort both the gpas as well as corresponding
              studentId in the descending order
    In/Out:   studentIds, gpas
       In:    numberOfElements
    Return:   It will return the C_OK once the sorting is done
*/
int orderStuData(int* studentIds, float* gpas, int numberOfElements){
   int duplicateStudentIds[numberOfElements];
   float duplicateGPAs[numberOfElements];

   for(int i=0;i<numberOfElements;i++){
      duplicateGPAs[i]=gpas[i];
      duplicateStudentIds[i]=studentIds[i];
   }

   for(int i=0;i<numberOfElements;i++){
      int index=findMaxIndex(duplicateGPAs,numberOfElements);
      studentIds[i]=duplicateStudentIds[index];
      gpas[i]=duplicateGPAs[index];
      duplicateGPAs[index]=-1;
   }

   return C_OK;
}

/*
  Function:   findMaxIndex
   Purpose:   This method will find the index of the greatest gpa
        In:   gpas, numberOfElements
    Return:   It will return the index of the largest GPA
*/
int findMaxIndex(float *gpas, int numberOfElements){
   int maxElementIndex=0;
   for(int i=0;i<numberOfElements;i++){
      if(gpas[i]>gpas[maxElementIndex]){
         maxElementIndex=i;
      }
   }
   return maxElementIndex;
}
