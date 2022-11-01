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
    AnimalArrayType* tempArr;
    initAnimalArray(tempArr,(arr->capacity)*2);
    for(int i=0;i<arr->capacity;i++){
      copyAnimal(((tempArr->elements)+i), ((arr->elements)+i));
    }
    cleanupAnimalArray(arr);
    arr=tempArr;
  }


//  (arr->elements)+(arr.size)=an;
}

void cleanupAnimalArray(AnimalArrayType* arr){
  free(arr);
}
