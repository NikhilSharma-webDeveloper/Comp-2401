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
typedef struct{
  AcctListType *accounts;
  CustArrayType *customers;
}BankType;

void printMenu(int*);

void initAcctList(AcctListType *);
void initAccount(int n, AcctEnumType at, CustomerType *c, float b, AccountType **acct);
void addAccount(AcctListType *list, AccountType *acct);

void addAccountByBalance(AcctListType *list, AccountType *acct);
void printAccount(AccountType *acct);
void cleanupAcctData(AcctListType *list);
void cleanupAcctList(AcctListType *list);
void printByBalance(AcctListType *orgList, int ends);



void initCustArray(CustArrayType *arr);
void initCustomer(int id, char *n, CustomerType **cust);
void addCustomer(CustArrayType **arr, CustomerType *c);
void printCustomers(CustArrayType *arr);
void cleanupCustArray(CustArrayType *arr);

void initBank(BankType *b);
void cleanupBank(BankType *b);
void loadBankData(BankType *bank);
