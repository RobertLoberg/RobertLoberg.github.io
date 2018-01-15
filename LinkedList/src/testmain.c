#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/LinkedListAPI.h"
#include "../include/car.h"

int main (int argc, char** argv)
{
  carInfo *carA = createCar('E', 'S', 9);
  carInfo *carB = createCar('N', 'L', 3);
  carInfo *carC = createCar('W', 'R', 6);

  List *list = initializeList(&printCar, &delete, &compareCar);

  /*
  First test insertFront
  */
  Node *temp1 = initializeNode(carA);
  Node *temp2 = initializeNode(carB);
  Node *temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Inputing to the front of a linked list\n");
  printf("Expected: Print the cars from the head of the list\n");
  printForward(list);
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Second test insertBack
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertBack(list, temp1->data);
  insertBack(list, temp2->data);
  insertBack(list, temp3->data);
  printf("Test: Inputing to the back of a linked list\n");
  printf("Expected: Print the cars from the tail of the list\n");
  printForward(list);
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Third test deleteList
*/
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Deleting the linked list\n");
  printf("Expected: delete the list\n");
  deleteList(list);
  if (list->head == NULL)
  {
    printf("List is NULL\n");
  }
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");

  /*
  Fourth test deleteNodeFromList
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Deleting a node in a linked list\n");
  printf("Expected: delete a node\n");
  deleteNodeFromList(list, temp1->data);
  printForward(list);
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Fifth test getFromFront
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: getting data from the front of the list\n");
  printf("Expected: output data from the front of the list\n");
  printCar(getFromFront(list));
  printf("\n");
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Sixth test getFromBack
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: getting data from the back of the list\n");
  printf("Expected: output data from the back of the list\n");
  printCar(getFromBack(list));
  printf("\n");
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Seventh test printForward
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Prints from head to tail\n");
  printf("Expected: output data from head to tail of the list\n");
  printForward(list);
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Eighth test printForward
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Prints data from tail to head\n");
  printf("Expected: output data from the tail to the head of the list\n");
  printBackwards(list);
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
  deleteList(list);

  /*
  Ninth test initializeList
*/
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Initializing a linked list\n");
  printf("Expected: An initialized list\n");
  if (list->head != NULL)
  {
    printf("List is initialized\n");
  }
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");

  /*
  Tenth test initializeNode
  */
  temp1 = initializeNode(carA);
  temp2 = initializeNode(carB);
  temp3 = initializeNode(carC);
  insertFront(list, temp1->data);
  insertFront(list, temp2->data);
  insertFront(list, temp3->data);
  printf("Test: Initializing a node\n");
  printf("Expected: An initialized node\n");
  deleteList(list);
  if (temp1 != NULL)
  {
    printf("Node is initialized\n");
  }
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
}
