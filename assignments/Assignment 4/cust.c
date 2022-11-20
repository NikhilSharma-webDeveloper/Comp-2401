#include "defs.h"

void initCustArray(CustArrayType *arr){
  arr->size=0;
}

void initCustomer(int id, char *n, CustomerType **cust){
  *cust=malloc(sizeof(CustomerType));
  (*cust)->id=id;
  strcpy((*cust)->name,n);
}


void addCustomer(CustArrayType **arr, CustomerType *c){
  (*arr)->data[(*arr)->size]=c;
  (*arr)->size++;
}

void printCustomers(CustArrayType *arr){

}

void cleanupCustArray(CustArrayType *arr){

}
