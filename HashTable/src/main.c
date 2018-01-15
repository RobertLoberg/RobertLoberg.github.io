#include <stdio.h>
#include <string.h>
#include "../include/hashAPI.h"

int main (int argc, char** argv) {

  char input[50] = "";
  char user[50] = "";
  char key[900] = "";
  char data[900] = "";
  int x = 1;

  HTable *hashTable = createTable(20, &hashNode, &destroyNodeData, &printNodeData);

  do {

    Node *node;

    printf ("--------------------------------\n");
    printf ("**************MENU**************\n");
    printf ("1. Add a word to Dictionary\n");
    printf ("2. Remove a word from Dictionary\n");
    printf ("3. Spell Check a file\n");
    printf ("4. Show Dictionary Words\n");
    printf ("5. Quit\n");

    fgets(input, 50, stdin);

    if (strcmp(input, "1\n") == 0) {

      printf("Please enter a word\n");
      strcpy(key,fgets(user, 50, stdin));
      strcpy(data,key);

      node = createNode(key,data);

      if (lookupData(hashTable,node->key) == NULL) {

        insertData(hashTable,node->key,node->data);
      }
      else {

        printf("word already exists\n");
      }
    }
    else if (strcmp(input, "2\n") == 0) {

      printf("Please search for a word\n");
      /*strcpy(key,*/fgets(user, 50, stdin);
      strcpy(data,key);

      //node = createNode(key,data);

      if (lookupData(hashTable,user) == NULL) {

        printf("Word does not exist\n");
      }
      else {

        removeData(hashTable,node->key);

        if (lookupData(hashTable,node->key) == NULL) {

          printf("Success\n");
        }
        else {

          printf("Failed\n");
        }
      }
    }
    else if (strcmp(input, "3\n") == 0) {

    }
    else if (strcmp(input, "4\n") == 0) {
      //printf("Index|Key|Word|\n");
      //for (int i = 0; i < hashTable->size; i++) {

        //Node *n = hashTable->table[i];
        //printf("%d|%s|%s\n", hashNode(hashTable->size, hashTable->table[i]->key),n->key,(char*)n->data);
      //}
    }
    else if (strcmp(input, "5\n") == 0) {

      x = 0;
      printf("Good bye\n");
    }
    else {

      printf("Invalid input\n");
    }
  }while (x == 1);
}
