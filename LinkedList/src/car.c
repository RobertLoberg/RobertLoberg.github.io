#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/car.h"

carInfo *createCar (char direction, char turn, int turnTime)
{
  carInfo *car = malloc(sizeof(car));
  car->direction = direction;
  car->turn = turn;
  car->turnTime = turnTime;

  return car;
}
char getDirection(carInfo *car)
{
  return (car->direction);
}
char getTurn(carInfo *car)
{
  return (car->turn);
}
int getTurnTime(carInfo *car)
{
  return (car->turnTime);
}
void printCar(void *data)
{
  carInfo *car = (carInfo *)data;
  printf("%c %c %1.1lf\t", car->direction, car->turn, car->turnTime);
  if (car->turnTime < 10)
  {
    printf ("\t");
  }
}
int compareCar(const void *first,const void *second)
{
  carInfo *a = (carInfo *)first;
  carInfo *b = (carInfo *)second;
  if (a->turnTime > b->turnTime)
  {
    return (1);
  }
  else if (b->turnTime > a->turnTime)
  {
    return (-1);
  }

  return 0;
}
void delete ()
{

}
