#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK       0
#define C_NOK     -1

#define MAX_STR   32
#define MAX_CAP  128

typedef enum { C_CAT, C_DOG, C_OTHER } SpeciesType;

typedef struct {	// base code
  int         id;
  SpeciesType species;
  char        name[MAX_STR];
  char        gender[MAX_STR];
  int         age;
} AnimalType;

typedef struct {
  AnimalType *elements;
  int capacity;
  int size;
} AnimalArrayType;


void printMenu(int*);
void loadAnimalData(AnimalArrayType*);

void initAnimalArray(AnimalArrayType*, int);
void initAnimal(int, SpeciesType, char*, char*, int, AnimalType*);

void addAnimal(AnimalArrayType*, AnimalType*);
int  delAnimal(AnimalArrayType*, int);
void copyAnimal(AnimalType*, AnimalType*);
int  validateSpecies(int, SpeciesType*);
void convertSpecies(SpeciesType, char*);

void printAnimals(AnimalArrayType*);
void printAnimalsBySpecies(AnimalArrayType*, SpeciesType);
void cleanupAnimalArray(AnimalArrayType*);

void moveRight(int, AnimalArrayType*);

int speciesMenu();
