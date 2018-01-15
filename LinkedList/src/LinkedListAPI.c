#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
  List *listStart = malloc(sizeof(List));
  listStart->head = NULL;
  listStart->tail = NULL;
  listStart->deleteNode = deleteFunction;
  listStart->printNode = printFunction;
  listStart->compare = compareFunction;
  return listStart;
}

Node *initializeNode(void *data)
{
  Node *n = malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

void insertFront(List *list, void *toBeAdded)
{
  Node *newNode = initializeNode(toBeAdded);

  if (list->head == NULL)
  {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  list->head->previous = newNode;
  newNode->next = list->head;
  list->head = newNode;
}

void insertBack(List *list, void *toBeAdded)
{
  Node *otherNewNode = initializeNode(toBeAdded);
  Node *temp = list->head;

  list->tail = otherNewNode;

  if (list->head == NULL)
  {
    list->head = otherNewNode;
    list->tail = otherNewNode;
    return;
  }

  while (temp->next != NULL)
  {
    temp= temp->next;
  }

  temp->next = otherNewNode;
  otherNewNode->previous = temp;

}

void deleteList(List *list)
{
  Node *temp1 = malloc(sizeof(Node));
  Node *temp2 = malloc(sizeof(Node));

  temp1 = list->head;

  while (temp1 != NULL)
  {
    temp2 = temp1->next;
    free(temp1);
    temp1 = temp2;
  }
  list->head = NULL;
  list->tail = NULL;
}

/** Uses the comparison function in the List struct to place the element in the appropriate position in the list.
*this is intended to be used from the beginning in order to keep the list completely sorted.
*@pre List exists and has memory allocated to it. Node to be added is valid.
*@post The node to be added will be placed immediately before or after the first occurrence of a related node
*@param list a pointer to the dummy head of the list containing function pointers for delete and compare, as well
as a pointer to the first and last element of the list.
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertSorted(List *list, void *toBeAdded)
{

}
/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the
 *data structure.
 *@pre List must exist and have memory allocated to it
 *@post toBeDeleted will have its memory freed if it exists in the list.
 *@param list pointer to the dummy head of the list containing deleteFunction function pointer
 *@param toBeDeleted pointer to data that is to be removed from the list
 *@return returns EXIT_SUCCESS on success, and EXIT_FAILURE when empty. Returns -1 when the node cannot be found.
 **/
int deleteNodeFromList(List *list, void *toBeDeleted)
{
  Node *temp = malloc(sizeof(Node));
  temp = list->head;
  while (temp != NULL)
  {
    if (toBeDeleted == temp->data)
    {
      if (temp->previous == NULL)
      {
        list->head = temp->next;
        temp->next->previous =NULL;
        free(temp);
      }
      else if (temp->next == NULL)
      {
        list->tail = temp->previous;
        temp->previous->next = NULL;
        free(temp);
      }
      else
      {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        free(temp);
      }
    }
    temp = temp->next;
  }
  return 0;
}

/**Function to return the data at the front of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the head of the list
 *@return pointer to the data located at the head of the list
 **/
void *getFromFront(List *list)
{
  return list->head->data;
}

/**Function to return the data at the back of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the tail of the list
 *@return pointer to the data located at the tail of the list
 **/
void *getFromBack(List *list)
{
  return list->tail->data;
}

/**Function to print list from head to tail. This will utilize the list's printNode function pointer to print.
 *@pre List must exist, but does not have to have elements.
 *@param list Pointer to linked list dummy head.
 **/
void printForward(List *list)
{
  Node *newNode = malloc(sizeof(Node));
  newNode = list->head;
  while (newNode != NULL)
  {
    list->printNode(newNode->data);
    printf("\n");
    newNode = newNode->next;
  }
  if (list->head == NULL)
  {
    printf("List is empty.\n");
  }
}

/**Function to print list from tail to head. This will utilize the list's printNode function pointer to print.
 *@pre List must exist, but does not have to have elements.
 *@param list Pointer to linked list dummy head.
 **/
void printBackwards(List *list)
{
  Node *newNode = malloc(sizeof(Node));
  newNode = list->tail;
  while (newNode != NULL)
  {
    list->printNode(newNode->data);
    printf("\n");
    newNode = newNode->previous;
  }
  if (list->head == NULL)
  {
    printf("List is empty.\n");
  }
}


/**User defined function to delete linked list node based on the incoming data.
 *@pre Data must not already be freed or NULL
 *@param toBeDeleted Pointer to generic data to be deleted in the list.
 **/
void deleteListNode(void *toBeDeleted)
{

}

/**
 *User-defined comparison for two pointers to generic data. Must define an element of these pointers to use to compare
 *the two pointers with each other.
 *@pre first and second must be comparable.
 *@param first pointer to data to be compared with second.
 *@param second pointer to data to be compared with first.
 *@return for sorting purposes,
 *<0 The element pointed by 'first' goes before the element pointed by 'second'
 *0  The element pointed by 'first' is equivalent to the element pointed by 'second'
 *>0 The element pointed by 'first' goes after the element pointed by 'second'
 **/
int compare(void *first, void *second)
{
  return 0;
}

/**User defined function to print an element of the list.
 *@pre Data must be able to be printed via a standard print function
 *@param toBePrinted pointer to the data that is to be printed. Taken from a data structure.
 **/
void printNode(void *toBePrinted)
{

}
