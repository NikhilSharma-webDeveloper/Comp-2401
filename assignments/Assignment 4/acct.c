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
  NodeType *newNode;
  NodeType *currNode;

  newNode = malloc(sizeof(NodeType));
  newNode->data = acct;
  newNode->next = NULL;

  currNode = list->head;
  while (currNode != list->tail) {
    currNode = currNode->next; 
  }

    if(currNode==NULL){
        list->head=newNode;
        list->tail=newNode;
    }else{
        list->tail->next=newNode;
        list->tail=newNode;
    }
}

void printAccount(AccountType *acct){
    char acctType[10];
    if(acct->acctType==0){
        strcpy(acctType,"CHEQUING");
    }else if(acct->acctType==1){
        strcpy(acctType,"SAVINGS");
    }else{
        strcpy(acctType, "OTHERS");
    }

    if(acct->cust == NULL){
        printf("Acct Num:  %-8d \tType:%10s \tOwner:    UnKnown \tBalance: $ %-.2f\n",acct->acctNum,acctType, acct->balance);
        return;
    }
    printf("Acct Num:  %-8d \tType:%10s \tOwner: %10s \tBalance: $ %.2f\n",acct->acctNum,acctType,acct->cust->name, acct->balance);
}

void printAccounts(AcctListType *list, int ends){

    if(list->head==NULL){
        printf("-------No Accounts--------\n");
        return;
    }

    NodeType *current=list->head;
    while((current)!=NULL){
           printAccount(current->data);
           current=current->next;
        }

     if(ends==C_TRUE){
        printf("-- HEAD --");
        printAccount(list->head->data);
         printf("-- TAIL --");
        printAccount(list->tail->data);
     }   
}


void cleanupAcctData(AcctListType *list){
    NodeType *current=list->head;
    while(current != NULL){
       free(current->data);
       current=current->next; 
    }
}

void cleanupAcctList(AcctListType *list){
    NodeType *current=list->head;
    NodeType *next=NULL;
    while(current != NULL){
       next=current->next;
       free(current);
       current=next; 
    }
}

void addAccountByBalance(AcctListType *list, AccountType *acct){
  NodeType *newNode;
  NodeType *currNode;
  NodeType *prevNode=NULL;

  newNode = malloc(sizeof(NodeType));
  newNode->data = acct;
  newNode->next = NULL;

  currNode = list->head;
  
  while ((currNode != NULL) && ((currNode->data->balance)>(acct->balance))) {
    prevNode=currNode;
    currNode = currNode->next; 
  }

    if(prevNode==NULL && currNode==NULL){
        list->head=newNode;
        list->tail=newNode;
    }else if(currNode==NULL && prevNode!= NULL) {
        prevNode->next=newNode;
        list->tail=newNode;
    }else if(prevNode==NULL && currNode!=NULL){
        newNode->next=currNode;
        list->head=newNode;
    }else{
        prevNode->next=newNode;
        newNode->next=currNode;
    }
        
}


void printByBalance(AcctListType *orgList, int ends){
    AcctListType temp;
    initAcctList(&temp);
    NodeType *current= orgList->head;
    while(current!=NULL){
        addAccountByBalance(&temp,current->data);
        current=current->next;
    }
     printAccounts(&temp,1);
     cleanupAcctList(&temp);
    
}