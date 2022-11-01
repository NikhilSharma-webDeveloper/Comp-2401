#include <stdio.h>
#include <string.h>

#include "defs.h"


void initAnimalArray(AnimalArrayType* arr, int capacity){

  arr->elements=calloc(capacity,sizeof(AnimalType));
  arr->capacity=capacity;
  arr->size=0;

}

void initAnimal(int i, SpeciesType s, char* n, char* g, int a, AnimalType* an){
  (*an).id=i;
  (*an).species=s;
  strcpy((*an).name,n);
  strcpy((*an).gender,g);
  (*an).age=a;
}

void copyAnimal(AnimalType *newAn, AnimalType* oldAn){
  (*newAn).id=oldAn->id;
  (*newAn).species=oldAn->species;
  strcpy((*newAn).name,oldAn->name);
  strcpy((*newAn).gender,oldAn->gender);
  (*newAn).age=oldAn->age;
}
void addAnimal(AnimalArrayType* arr, AnimalType* an){
  if(arr->size==arr->capacity){
    AnimalArrayType tempArr;
    AnimalArrayType* tempArrPtr=&tempArr;
    initAnimalArray(tempArrPtr,(arr->capacity)*2);

    for(int i=0;i<arr->capacity;i++){
      copyAnimal(((tempArrPtr->elements)+i), ((arr->elements)+i));
    }
    cleanupAnimalArray(arr);

    arr->elements=tempArrPtr->elements;
    arr->capacity=tempArrPtr->capacity;
  }
    copyAnimal(&((arr->elements)[(arr->size)]),an);
    arr->size=++(arr->size);
}

void cleanupAnimalArray(AnimalArrayType* arr){
  free(arr->elements);
}

void printAnimals(AnimalArrayType* data){
  printf("Animal Id \t Species \t Name \t Gender \t age\n");
  for(int i=0;i<data->size;i++){
    AnimalType *pointer=data->elements;
    printf("%9d \t %3d \t %10s \t %6s \t %d\n",(pointer+i)->id,
    (pointer+i)->species,(pointer+i)->name,(pointer+i)->gender, (pointer+i)->age);
  }
}
