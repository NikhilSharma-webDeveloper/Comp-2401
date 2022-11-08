#include <stdio.h>
#include <string.h>

#include "defs.h"

/*
Function:   main
 Purpose:   This function is the main function of the program control all the
            functionality of the program according to the user choice
  return:   Return 0 at the end of the program
*/
int main()
{
   AnimalArrayType allAnimals;
   AnimalArrayType *allAnimalsPtr=&allAnimals;

   initAnimalArray(allAnimalsPtr,MAX_CAP);

   loadAnimalData(allAnimalsPtr);
   int choice=-1;
   int *choicePtr=&choice;

   while(choice!=0){
    printMenu(choicePtr);
    switch (choice)
    {

    case 1:
    {
      int speciesChoice=0;
      SpeciesType s;
      SpeciesType *sPtr=&s;
      int months;
      int id;
      SpeciesType animalSp;
      char        name[MAX_STR];
      char        gender[MAX_STR];
      int         age;
      printf("\nEnter the Id of the Animal\n");
      scanf("%d",&id);

      speciesChoice=speciesMenu();
      int result=validateSpecies(speciesChoice,sPtr);

      if(result!=C_OK){
        printf("\n\n---------Wrong species Selected-----------------\n");
        break;
      }

      printf("\nEnter the name of the Animal\n");
      scanf("%s",name);

      printf("\nEnter the gender of the Animal\n");
      scanf("%s",gender);

      printf("\nEnter the age of the animal as years and months\n");
      scanf("%d",&age);
      scanf("%d",&months);
      age=(age*12)+months;

      AnimalType a;
      initAnimal(id,s,name,gender,age,&a);
      addAnimal(allAnimalsPtr,&a);

      break;
    }

    case 2:
    {
      int animalId=0;
      printf("\nPlease enter the id of the animal which you want to delete\n");
      scanf("%d",&animalId);
      int result=delAnimal(allAnimalsPtr,animalId);
      if(result==C_NOK){
        printf("\n\n------There is no Animal with Id %d--------\n\n",animalId);
      }else{
        printf("--------\n\nSuccessfully deleted the element with Id %d---------\n\n", animalId);
      }
      break;
    }

    case 3:
    {
    printAnimals(allAnimalsPtr);
    break;
    }


    case 4:
    {
    int speciesChoice=0;
    SpeciesType s;
    SpeciesType *sPtr=&s;
    speciesChoice=speciesMenu();
    int result=validateSpecies(speciesChoice,sPtr);

    if(result==C_OK){
      printf("%d",s);
      printAnimalsBySpecies(allAnimalsPtr,s);
    }else{
      printf("\n\n---------Wrong species Selected-----------------\n");
    }
    break;
    }

    default:
      break;
    }
  }
  free(allAnimalsPtr->elements);
  return(0);

}

/*
Function:   speciesMenu
 Purpose:   This function is used to give the species menu to the user and
            return the option selected by the user
  return:   Return the option selected by the user
*/
int speciesMenu(){

  int choice=0;
  printf("\nTo choose the Species \nPress (1) for dog\nPress (2) for Cat\nPress (3) for Others\n");
  scanf("%d",&choice);
  return choice;
}

/*
Function:   printMenu
 Purpose:   This function is used to give the user with option, what user want
            to do with the program
     out:   choice
*/
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
