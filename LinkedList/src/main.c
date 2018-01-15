#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/LinkedListAPI.h"
#include "../include/car.h"

int main (int argc, char* argv[])
{
  char fpdir;
  char fpturn;
  double fpturnTime = 0;
  char *fileName = malloc(sizeof(char*) * 100);
  carInfo *car = malloc(sizeof(carInfo));
  Node *newNode = malloc(sizeof(newNode));
  FILE *fp;
  fileName = argv[1];
  fp = fopen(fileName, "r");

  List *North = initializeList(&printCar, &delete, &compareCar);
  List *East = initializeList(&printCar, &delete, &compareCar);
  List *South = initializeList(&printCar, &delete, &compareCar);
  List *West = initializeList(&printCar, &delete, &compareCar);

  if (fp == 0)
  {
    printf ("File was not found.\n");
    return 0;
  }

  else
  {
    while (!feof(fp))
    {
      fscanf(fp, "%c %c %lf", &fpdir, &fpturn, &fpturnTime);
      if (fpdir == 'N')
      {
        car = createCar(fpdir, fpturn, fpturnTime);
        newNode = initializeNode(car);
        insertFront (North, newNode->data);
      }
      else if (fpdir == 'E')
      {
        car = createCar(fpdir, fpturn, fpturnTime);
        newNode = initializeNode(car);
        insertFront (East, newNode->data);
      }
      else if (fpdir == 'S')
      {
        car = createCar(fpdir, fpturn, fpturnTime);
        newNode = initializeNode(car);
        insertFront (South, newNode->data);
      }
      else if (fpdir == 'W')
      {
        car = createCar(fpdir, fpturn, fpturnTime);
        newNode = initializeNode(car);
        insertFront (West, newNode->data);
      }
    }
    fclose(fp);
  }
  printf("Initial Vehicle Information Intersection Arrival Time Completed at Time\n");
  printForward(North);
  printForward(East);
  printForward(South);
  printForward(West);

}
