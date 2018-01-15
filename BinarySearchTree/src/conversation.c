#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/conversation.h"

speechInfo *createDialog (char * keyWord, char * sentence, double systemRating, double occurances) {

  speechInfo *dialog = malloc(sizeof(dialog));

  dialog->keyWord = malloc(sizeof(keyWord));
  strcpy(dialog->keyWord, keyWord);

  dialog->sentence = malloc(sizeof(sentence));
  strcpy(dialog->sentence, sentence);

  dialog->systemRating = systemRating;
  dialog->occurances = occurances;

  return dialog;
}

char * getKeyWord(speechInfo *dialog) {

  return (dialog->keyWord);
}

char * getSentence(speechInfo *dialog) {

  return (dialog->sentence);
}

double getSystemRating(speechInfo *dialog) {

  return (dialog->systemRating);
}

int getOccurances(speechInfo *dialog) {

  return (dialog->occurances);
}

void printDialog(void *data) {

  if (data != NULL) {

    speechInfo *dialog = (speechInfo *)data;

    printf("%s %s %1.1lf %1.1lf\t", dialog->keyWord, dialog->sentence, dialog->systemRating, dialog->occurances);
    printf("\n");
  }
}

int compareDialog(const void *first,const void *second) {

  speechInfo *a = (speechInfo *)first;
  speechInfo *b = (speechInfo *)second;

  if (a == NULL && b == NULL) {

    return 0;
  }
  else if (b == NULL) {

    return 1;
  }
  else if (a == NULL) {

    return -1;
  }
  else {

    return strcmp(a->keyWord, b->keyWord);
  }
}

void delete (void * data) {
  //printf("inside delete func that frees\n");
  speechInfo *done = (speechInfo *)data;

  done = NULL;
  free(done);

  //printf("free'd data inside\n");
}
