#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_TRUE     1
#define C_FALSE    0

#define MAX_ARR  128
#define MAX_STR   32

#define NEXT_CUST_ID    4001
#define NEXT_ACCT_ID  700210

typedef enum { CHEQUING, SAVINGS, OTHER } AcctEnumType;

struct AcctList;

typedef struct {
  int  id;
  char name[MAX_STR];
  struct AcctList *accounts;
} CustomerType;

typedef struct {
  int          acctNum;
  AcctEnumType acctType;
  CustomerType *cust;
  float        balance;
} AccountType;

/*** Define the CustArrayType here ***/
typedef struct{
  CustomerType *data[MAX_ARR];
  int size;
}CustArrayType;

/*** Define the NodeType here ***/
typedef struct Node{
  AccountType *data;
  struct Node *next;
}NodeType;

/*** Complete the AcctListType here ***/
typedef struct AcctList {
  NodeType *head;
  NodeType *tail;
} AcctListType;

/*** Define the BankType here ***/
typedef struct {
  AcctListType accounts;
  CustArrayType customers;
}BankType;

void printMenu(int*);

//All the method declaration for the bank
void initBank(BankType *ptr);
void loadBankData(BankType *bank);
void cleanupBank(BankType *b);


//All the functions for customer
void initCustomer(int id, char *name, CustomerType **cust);
void initCustArray(CustArrayType *arr);
void addCustomer(CustArrayType *arr, CustomerType *c);
void printCustomers(CustArrayType *arr);
void cleanupCustArray(CustArrayType *arr);

//All the function of the account related
void initAccount(int n, AcctEnumType at, CustomerType *c, float b, AccountType **acct);
void initAcctList(AcctListType *list);
void addAccount(AcctListType *list, AccountType *acct);
void printAccount(AccountType *acct);
void printAccounts(AcctListType *list, int ends);
void cleanupAcctData(AcctListType *list);
void cleanupAcctList(AcctListType *list);
void printByBalance(AcctListType *orgList, int ends);
void addAccountByBalance(AcctListType *list, AccountType *acct);
