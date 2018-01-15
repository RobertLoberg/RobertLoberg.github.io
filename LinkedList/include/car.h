#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car
{
  char direction;
  char turn;
  double turnTime;
} carInfo;

carInfo *createCar (char direction, char turn, int turnTime);

char getDirection(carInfo *car);
char getTurn(carInfo *car);
int getTurnTime(carInfo *car);
void printCar(void *data);
int compareCar(const void *first, const void *second);
void delete ();
