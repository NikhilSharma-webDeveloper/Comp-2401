#include <stdio.h>
#include <string.h>

#include "defs.h"

int main(){
  AnimalArrayType *allAnimalsPtr;

  initAnimalArray(allAnimalsPtr,2);
  loadAnimalData(allAnimalsPtr);

  int choice=-1;
  int *choicePtr=&choice;
  while(choice!=0){
    printMenu(choicePtr);
  }
  return(0);
}

void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 4;

  printf("\nMAIN MENU\n");
  printf("  (1) Add animal\n");
  printf("  (2) Delete animal\n");
  printf("  (3) Print all animals\n");
  printf("  (4) Print animals by species\n");
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
