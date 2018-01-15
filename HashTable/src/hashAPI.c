#include <stdio.h>
#include <string.h>
#include "../include/hashAPI.h"

/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return pointer to the hash table
*@param size size of the hash table
*@param hashFunction function pointer to a function to hash the data
*@param destroyData function pointer to a function to delete a single piece of data from the hash table
*@param printNode function pointer to a function that prints out a data element of the table
**/
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, char *key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted)) { //check

  HTable *hashBrown = malloc(sizeof(HTable));

  hashBrown->size = size;
  hashBrown->table = malloc(sizeof(Node *) *hashBrown->size);
  hashBrown->destroyData = destroyData;
  hashBrown->printNode = printNode;
  hashBrown->hashFunction = hashFunction;

  return hashBrown;
}

/**Function for creating a node for the hash table.
*@pre Node must be cast to void pointer before being added.
*@post Node is valid and able to be added to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data is a generic pointer to any data type.
*@return returns a node for the hash table
**/
Node *createNode(char *key, void *data) { //check

  Node *n = malloc(sizeof(Node));

  n->data = data;
  n->key = key;
  n->next = NULL;

  return n;
}

/** Deletes the entire hash table and frees memory of every element.
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
**/
void destroyTable(HTable *hashTable) { //check

  for (int x = 0; x < hashTable->size; x++) {

    if (hashTable->table[x] != NULL) {

      Node *n = hashTable->table[x];
      //if (hashTable->table[x]->next != NULL) {

        while (n != NULL) {

          Node *m = n->next;
          free(n);
          n = m;
        }
      //}
      //else {

        //free(n);
      //}
    }
  }
  free(hashTable->table);
  free(hashTable);
  hashTable = NULL;
}

/**Inserts a Node in the hash table.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data pointer to generic data that is to be inserted into the list
**/
void insertData(HTable *hashTable, char *key, void *data) { //check

  int index = hashNode(hashTable->size, key);
  Node *n = createNode(key,data);

  //printf("%d\n", index);
  if (hashTable->table[index] == NULL) {

    hashTable->table[index] = n;
  }
  else {

    //printf("**SHIT WAS THERE**\n");
    Node *temp = hashTable->table[index]->next;
    Node *save;
    if (temp == NULL)
    {
      hashTable->table[index]->next = n;
    }
    else {
      while (temp != NULL) {
        //printf("**IN LOOP**\n");
        //if (temp->next != NULL)
        save = temp;
        temp = temp->next;


      }
      //printf("**PAST LOOP**\n");
      //temp = n;
      save->next = n;
    }
  }
}


/** THIS FUNCTION IS NOT MANDATORY, users call this function to insert a Node in the hash table.
* It's meant as a wrapper for insertData so the users don't need to generate the key when adding.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param data pointer to generic data that is to be inserted into the list
**/
//void insertDataInMap(HTable *hashTable, void *data) {


//}

/**Function to remove a node from the hash table
 *@pre Hash table must exist and have memory allocated to it
 *@post Node at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 **/
void removeData(HTable *hashTable, char *key) { //check

  int index = 0;
  index = hashNode(hashTable->size, key);

  if (hashTable->table[index] != NULL) {

    //printf("**INSERT IS BORKED**\n");
    Node *n = hashTable->table[index];

    if (strcmp(n->key, key) == 0) {

      n = NULL;
      free(n);
    }
    else {

      //printf("**DO WE DO?**\n");
      while (n != NULL) {
        //printf("**WE DO**\n");
        if (strcmp(n->key, key) == 0) {
          //printf("%s\n", n->key);
          //printf("**AND WE FIND**\n");
          n = NULL;
          free(n);
        }
        else {

          n = n->next;
        }
      }
    }


  }
  //else {
    //printf("**DOESNT WROK**\n");
  //}
}

/**Function to return the data from the key given.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.
 **/
void *lookupData(HTable *hashTable, char *key) { //check

  if (hashTable->size != 0) {
    int index = 0;
    index = hashNode(hashTable->size, key);

    if (hashTable->table[index] != NULL) {

      //printf("**INSERT IS BORKED**\n");
      Node *n = hashTable->table[index];
      if (strcmp(n->key, key) == 0)
      {
        return n;
      }

      //printf("**DO WE DO?**\n");
      while (n->next != NULL) {
        //printf("**WE DO**\n");
        if (strcmp(n->key, key) == 0) {
          //printf("%s\n", n->key);
          //printf("**AND WE FIND**\n");
          return n;
        }
        else {

          n = n->next;
        }
      }

    }
  }

  //else {
    //printf("**DOESNT WROK**\n");
    return NULL;
  //}
}

int hashNode(size_t tableSize, char *key) { //check

  int hash = 0;
  int arraySize = strlen(key);

  hash = ((key[0] * key[arraySize]) * 101) % tableSize;

  return hash;
}

void destroyNodeData(void *data) { //check

  data = NULL;
  free(data);
}

void printNodeData(void *toBePrinted) { //check
  //printf("**DIES BEFORE FUNCTION**\n");
  Node *n = (Node *)toBePrinted;
  //printf("**CASTS NICELY**\n");
  if (n != NULL) {

    printf("STACK:%s DATA:%s\n", n->key, (char *)n->data);
  }
}
