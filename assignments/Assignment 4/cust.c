#include "defs.h"


void initCustArray(CustArrayType *arr){
    arr->size=0;
}

void initCustomer(int id, char *name, CustomerType **cust){
    *cust=malloc(sizeof(CustomerType));
    (*cust)->id=id;
    strcpy((*cust)->name,name);
    (*cust)->accounts=malloc(sizeof(struct AcctList));
}

void addCustomer(CustArrayType *arr, CustomerType *c){
  ((arr)->data)[(arr)->size]=c;
  (arr)->size++;
}

void printCustomers(CustArrayType *arr){
    for(int i=0;i<arr->size;i++){
       printf("\n%-10d%s\n",arr->data[i]->id,arr->data[i]->name);
       printAccounts((arr->data[i]->accounts),0);
    }
}

void cleanupCustArray(CustArrayType *arr){
    for(int i=0;i<(arr->size);++i){
        cleanupAcctList((((arr->data)[i])->accounts));
        free((arr->data)[i]->accounts);
        free(((arr->data)[i]));
    }
}
