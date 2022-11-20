#include "defs.h"

int main()
{
  BankType bank;
  BankType *bankPtr=&bank;

  initBank(bankPtr);
  loadBankData(bankPtr);
//printf("%d\n",bankPtr->customers);

  int choice=1;
  while(choice!=0){
    printMenu(&choice);
    if(choice==1){

    }else if(choice ==2){

    }else if(choice==3){

    }else{
      break;
    }
  }
  return(0);
}

void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print customers\n");
  printf("  (2) Print accounts\n");
  printf("  (3) Print accounts by balance\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}
