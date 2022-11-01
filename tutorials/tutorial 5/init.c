#include "defs.h"

void loadAnimalData(AnimalArrayType *arr)
{
  AnimalType a;

  initAnimal(1008, C_DOG, "Lily", "F", 18, &a);
  addAnimal(arr, &a);
  initAnimal(1001, C_DOG, "Betsy", "F", 60, &a);
  addAnimal(arr, &a);
  initAnimal(1017, C_CAT, "Luka", "M", 84, &a);
  addAnimal(arr, &a);
  initAnimal(1002, C_DOG, "Killer", "F", 41, &a);
  addAnimal(arr, &a);
  initAnimal(1032, C_OTHER, "Gruyere", "M", 3, &a);
  addAnimal(arr, &a);
  initAnimal(1004, C_DOG, "Fluffy", "M", 31, &a);
  addAnimal(arr, &a);
  initAnimal(1013, C_CAT, "Lady", "F", 121, &a);
  addAnimal(arr, &a);
  initAnimal(1018, C_CAT, "Fiona", "F", 96, &a);
  addAnimal(arr, &a);
  initAnimal(1029, C_OTHER, "Pecorino", "M", 3, &a);
  addAnimal(arr, &a);
  initAnimal(1007, C_DOG, "Leon", "M", 48, &a);
  addAnimal(arr, &a);
  initAnimal(1027, C_OTHER, "Quasar", "M", 16, &a);
  addAnimal(arr, &a);
  initAnimal(1016, C_CAT, "Shadow", "M", 62, &a);
  addAnimal(arr, &a);
  initAnimal(1024, C_OTHER, "Quark", "M", 108, &a);
  addAnimal(arr, &a);
  initAnimal(1021, C_CAT, "Ruby", "F", 60, &a);
  addAnimal(arr, &a);
  initAnimal(1023, C_OTHER, "Ziggy", "F", 44, &a);
  addAnimal(arr, &a);
  initAnimal(1033, C_OTHER, "Limburger", "M", 3, &a);
  addAnimal(arr, &a);
}
