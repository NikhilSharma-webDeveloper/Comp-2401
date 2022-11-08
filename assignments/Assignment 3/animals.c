#include <stdio.h>
#include <string.h>

#include "defs.h"



/*
Function:   initAnimalArray
 Purpose:   This function is used to dynamically allocate the space for the
            Array in the AnimalArrayType Struct and initlize so of Others
            essential variables too.
  in/out:   AnimalArrayType* arr
      in:   capacity
*/
void initAnimalArray(AnimalArrayType* arr, int capacity){

  arr->elements=calloc(capacity,sizeof(AnimalType));
  arr->capacity=capacity;
  arr->size=0;

}
/*
Function:   initAnimal
 Purpose:   This function just initlize all the variables in the AnimalType
            Struct with the data entered by the users
      in:   i,s,n,g,a
     out:   an
*/
void initAnimal(int i, SpeciesType s, char* n, char* g, int a, AnimalType* an){
  an->id=i;
  an->species=s;
  strcpy(an->name,n);
  strcpy(an->gender,g);
  an->age=a;
}

/*
Function:   copyAnimal
 Purpose:   This function is used to do the deep copy of the element in the
  in/out:   newAn, oldAn
*/
void copyAnimal(AnimalType *newAn, AnimalType* oldAn){
  (*newAn).id=oldAn->id;
  (*newAn).species=oldAn->species;
  strcpy((*newAn).name,oldAn->name);
  strcpy((*newAn).gender,oldAn->gender);
  (*newAn).age=oldAn->age;
}

/*
Function:   addAnimal
 Purpose:   This function is used to add the new data in Animals array in sorted
            order, if array is full it do not add the element and print the
            error message
      in:   an
  in/out:   arr
*/
void addAnimal(AnimalArrayType* arr, AnimalType* an){

  if(arr->capacity==arr->size){
    printf("\n\n-------MAX CAPACITY REACHED ----------\n\n");
    return;
  }

  for(int i=0;i<(arr->size);i++){
    //if species you want to add should be before the species present
    if(an->species<(arr->elements)[i].species){
      moveRight(i,arr);

       copyAnimal(((arr->elements)+(i)),an);
      ++(arr->size);
      return;
    }

    //If there is already an element with the same species in our storage
    if(an->species==(arr->elements)[i].species){

      int j=0;
      for(j=i;j<(arr->size) && an->species==(arr->elements)[j].species;j++){
        if(an->age >(arr->elements)[j].age){
          moveRight(j,arr);
          copyAnimal(((arr->elements)+(j)),an);
          ++(arr->size);
          return;
        }
      }

      moveRight(j,arr);
      copyAnimal(((arr->elements)+(j)),an);
      ++(arr->size);
      return;
    }

  }
     copyAnimal(((arr->elements)+(arr->size)),an);
      ++(arr->size);
}
/*
Function:   moveRight
 Purpose:   These function is used to shift the element towards right mostly
            used when we are trying to add the elements
      in:   end
  in/out:   arr
*/
void moveRight(int end, AnimalArrayType* arr){
  for(int k=arr->size;k>end && k>0;k--){
    copyAnimal(&((arr->elements)[k]), &((arr->elements)[k-1]));
    }
}
/*
Function:   cleanupAnimalArray
 Purpose:   This function is used to deallocate the dynamically allocated space
  in/out:   arr
*/
void cleanupAnimalArray(AnimalArrayType* arr){
  free(arr->elements);
}
/*
Function:   printAnimals
 Purpose:   This function is used to print all the animals in the order they are
            stored
      in:   data
*/
void printAnimals(AnimalArrayType* data){
  printf("\n");
  for(int i=0;i<data->size;i++){

    AnimalType *pointer=(data->elements)+i;
    char species[7];
    switch (pointer->species)
    {
    case 0:
      strcpy(species,"CAT");
      break;
    case 1:
      strcpy(species,"DOG");
      break;
    case 2:
      strcpy(species,"OTHERS");
      break;

    default:
      break;
    }
    int age=(pointer->age)/12;
    int months=(pointer->age)%12;
    printf("Id: %-4d\tSps: %-7s\tName: %-10s\tGender: %-1s\tAge: %-2d yrs, %-2d mths \n",pointer->id,species,pointer->name,pointer->gender,age, months);

  }
}

/*
Function:   printAnimalsBySpecies
 Purpose:   This function is used to print the animals of the requested species
      in:   data,species
*/
void printAnimalsBySpecies(AnimalArrayType* data, SpeciesType species){
  AnimalArrayType temp;
  AnimalArrayType* tempPtr=&temp;

  initAnimalArray(tempPtr,MAX_CAP);

  for(int i=0,j=0;i<(data->size);i++){
    if((data->elements[i]).species==species){
      addAnimal(tempPtr,&(data->elements[i]));
    }
  }

  printAnimals(tempPtr);
  cleanupAnimalArray(tempPtr);

}
/*
Function:   validateSpecies
 Purpose:   This function is used to validate the species entered by the user
            and store the correct species to the SpeciesType* s
      in:   choice
     out:   s
  return:   if correct species selected by user then C_OK else C_NOK
*/
int validateSpecies(int choice , SpeciesType* s){
  switch (choice)
  {
  case 1:
  *s=C_DOG;
    break;

  case 2:
  *s=C_CAT;
    break;

  case 3:
  *s=C_OTHER;
    break;

   default:
   return C_NOK;
   break;
  }
  return C_OK;
}

/*
Function:   delAnimal
 Purpose:   It is used to delete the animal with the Id from the collection of
            animals
      in:   id
  in/out:   data
  return:   It does return C_OK if we are able to find the element and delete it
            else return C_NOK
*/
int delAnimal(AnimalArrayType* data, int id){
   for(int i=0;i<data->size;i++){
    if((data->elements)[i].id==id){
      for(int j=i+1;j<data->size;j++){
        copyAnimal(&((data->elements)[j-1]),&((data->elements)[j]));
      }
      --(data->size);
      return C_OK;
    }
   }
   return C_NOK;
}
