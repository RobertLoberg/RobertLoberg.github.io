#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/BinarySearchTreeAPI.h"
#include "../include/conversation.h"

int main (int argc, char** argv) {

  int x = 0;
  char user[100] = "";
  char key[100] = "";
  char sentence[100] = "";
  double rating = 0;
  double occurances = 0;

  Tree * tree = createBinTree(&compareDialog, &delete);

  while (x != 1) {

    printf("MENU:\n1. Add a new rule\n2. Remove a rule\n3. Display rules\n4. Modify rule rating\n5. Discuss\n9) Quit\n");
    fgets(user, 100, stdin);

    if (strcmp(user,"1\n") == 0) {

      printf("Please enter a keyWord\n");
      strcpy(key, fgets(user, 100, stdin));
      printf("Please enter a sentence\n");
      strcpy(sentence, fgets(user, 100, stdin));

      do {

        printf("Please enter importance (0-1)\n");
        rating = atol(fgets(user, 100, stdin));
      } while (rating > 1 || rating < 0);

      speechInfo * add = createDialog(key, sentence, rating, occurances);
      TreeNode *treeNode = createTreeNode(add);
      addToTree(tree, add);

    }
    else if (strcmp(user,"2\n") == 0) {


    }
    else if (strcmp(user,"3\n") == 0) {

      printInOrder(tree, printDialog);
    }
    else if (strcmp(user,"4\n") == 0) {


    }
    else if (strcmp(user,"5\n") == 0) {


    }
    else if (strcmp(user,"9\n") == 0) {

      x = 1;
    }
  }
  return 0;
}
