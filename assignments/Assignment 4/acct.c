
#include "defs.h"


void initAcctList(AcctListType *list){
  list->head=NULL;
  list->tail=NULL;
}

void initAccount(int n, AcctEnumType at, CustomerType *c, float b, AccountType **acct){
  *acct=malloc(sizeof(AccountType));
  (*acct)->acctNum=n;
  (*acct)->acctType=at;
  (*acct)->cust=c;
  (*acct)->balance=b;

}

void addAccount(AcctListType *list, AccountType *acct){

}


void addAccountByBalance(AcctListType *list, AccountType *acct){

}

void printAccount(AccountType *acct){

}

void cleanupAcctData(AcctListType *list){

}

void cleanupAcctList(AcctListType *list){

}

void printByBalance(AcctListType *orgList, int ends){

}
