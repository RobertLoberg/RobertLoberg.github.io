#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dialog
{
  char * keyWord;
  char * sentence;
  double systemRating;
  double occurances;
} speechInfo;

speechInfo *createDialog (char * keyWord, char * sentence, double systemRating, double occurances);

char * getKeyWord(speechInfo *dialog);
char * getSentence(speechInfo *dialog);
double getSystemRating(speechInfo *dialog);
int getOccurances(speechInfo *dialog);
void printDialog(void *data);
int compareDialog(const void *first,const void *second);
void delete (void * data);
