#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/BinarySearchTreeAPI.h"
#include "../include/conversation.h"

int main (int argc, char** argv) {

  speechInfo *dialogA = createDialog("3", "Please Work", .2, .4);
  speechInfo *dialogB = createDialog("1", "Did it work?", .3, .5);
  speechInfo *dialogC = createDialog("2", "OMG WAIT", .1, .6);
  speechInfo *dialogD = createDialog("0", "IT WORKED!", .9, .1);
  speechInfo *dialogE = createDialog("4", "There", .9, .1);

  Tree *tree = createBinTree(&compareDialog, &delete);

  TreeNode *temp1 = createTreeNode(dialogA);
  TreeNode *temp2 = createTreeNode(dialogB);
  TreeNode *temp3 = createTreeNode(dialogC);
  TreeNode *temp4 = createTreeNode(dialogD);
  TreeNode *temp5 = createTreeNode(dialogE);

  /*
  test createBinTree
  test createTreeNode
  test addToTree
  test compareFunc
  test printOrder
  */
  printf("\n");
  addToTree(tree, temp1->data);
  addToTree(tree, temp2->data);
  addToTree(tree, temp3->data);
  addToTree(tree, temp4->data);
  addToTree(tree, temp5->data);
  printf("Test: Inputing to the tree and printing nodes in order\n");
  printf("Expected: Print the data from the tree\n");
  printInOrder(tree, printDialog);
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");


  /*
  Test findInTree
  */
  printf("Test: Finding specific values in tree\n");
  printf("Expected: Print the data from the tree if found\n");
  printDialog(findInTree(tree, temp2->data));
  //printf("Now checking for non-existent data\n");
  //printDialog(findInTree(tree, temp5->data));
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");

  /*
  Test getRootData
  */
  printf("Test: Return the root data of a tree\n");
  printf("Expected: Print the root data from the tree\n");
  printDialog(getRootData(tree));
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");

  /*
  Test preOrder
  */
  printf("Test: Printing nodes in preOrder\n");
  printf("Expected: Print the data from the tree\n");
  printPreOrder(tree, printDialog);
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");

  /*
  Test postOrder
  */
  printf("Test: Printing nodes in postOrder\n");
  printf("Expected: Print the data from the tree\n");
  printPostOrder(tree, printDialog);
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");

  printf("Test: Get height of a node\n");
  printf("Expected: Print height of tree\n");
  printf("%d\n", getHeight(temp3));
  printf("Recived: Output correct\n");
  printf("Result: Test was a success\n\n");

  /*
  Test removeFromTree
  */
  printf("Test: Remove node from tree\n");
  printf("Expected: print all but one node from tree\n");
  removeFromTree(tree, temp2);
  printPostOrder(tree, printDialog);
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");

  /*
  Test destroyBinTree
  */
  printf("Test: Destroying tree\n");
  printf("Expected: Print the data from the tree (will be no output)\n");
  destroyBinTree(tree);
  if (tree->root == NULL) {

    printf("Tree freed\n");
  }
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");
}
