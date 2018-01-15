#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTreeAPI.h"
#include "../include/conversation.h"

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node.
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data) { //done

  TreeNode *n = malloc(sizeof(TreeNode));

  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del) { //done

  Tree *treeStart = malloc(sizeof(Tree));

  treeStart->root = NULL;
  treeStart->deleteFunc = del;
  treeStart->compareFunc = compare;
  return treeStart;
}

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy) {

  TreeNode * newTreeNode = toDestroy->root;

  destroy(newTreeNode, toDestroy);

  //sadness
  free(toDestroy->root->right);
  free(toDestroy->root->left);
  free(toDestroy);
}

TreeNode * destroy(TreeNode * node, Tree * tree) {

  if (node != NULL) {

    destroy(node->left, tree);
    destroy(node->right, tree);
    tree->deleteFunc(node->data);
  }

  return node;
}

/**
 * Add data to a tree
 * @param theTree
 * @param data
 */
void addToTree(Tree * theTree, TreeDataPtr data) { //done

  theTree->root = insert(theTree->root, data, theTree->compareFunc);
}

TreeNode * insert(TreeNode * root, TreeDataPtr data, CompareFunc compareFunc) { //done

  if (root == NULL) {

      //printf("does happen everytime\n");
      return createTreeNode(data);
  }
  if (compareFunc(data, root->data) > 0) {

    root->right = insert(root->right, data, compareFunc);
  }
  else {

    root->left = insert(root->left, data, compareFunc);
  }

  return root;
}

/**
 * Remove data from the tree
 * @param theTree
 * @param data
 */
void removeFromTree(Tree * theTree, TreeDataPtr data) {

  TreeNode * newTreeNode = removeNode(theTree->root, data, theTree->compareFunc);

  if (newTreeNode != NULL) {

    theTree->deleteFunc(newTreeNode);
    free(newTreeNode);
  }
}

TreeNode * removeNode(TreeNode * root, TreeDataPtr data, CompareFunc compareFunc) {

  if (root == NULL) {

    return NULL;
  }

  if (compareFunc(data, root->data) > 0) {

    root->right = removeNode(root->right, data, compareFunc);
  }
  else if (compareFunc(data,root->data) < 0) {

    root->left = removeNode(root->left, data, compareFunc);
  }
  else {

    return root;
  }

  return NULL;
}
/**
 * This function searches the tree for the target data
 * @param  theTree
 * @param  data
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data ) { //done

  if (theTree->root != NULL) {

    TreeNode * nodeData = search(theTree->root, data, theTree->compareFunc);

    return nodeData->data;
  }
  return NULL;
}

TreeNode * search(TreeNode * root, TreeDataPtr data, CompareFunc compareFunc) { //done

  TreeNode * newTreeNode = malloc(sizeof(TreeNode));

  newTreeNode =NULL;

  if (root != NULL) {

    if (compareFunc(data, root->data) > 0) {

      root->right = search(root->right, data, compareFunc);
      newTreeNode = root->right;
    }
    else if (compareFunc(data, root->data) < 0) {

      root->left = search(root->left, data, compareFunc);
      newTreeNode = root->left;
    }
    else if (compareFunc(data, root->data) == 0){

      newTreeNode = root;
      return newTreeNode;
    }
  }

  return newTreeNode;
}

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree) { //done

  return theTree->root->data;
}

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData) { //done

  inOrder(theTree->root, printData);
}

TreeNode * inOrder(TreeNode * node, PrintFunc printFunc) { //done

  if (node != NULL) {

    inOrder(node->left, printFunc);
    printFunc(node->data);
    inOrder(node->right, printFunc);
  }

  return NULL;
}

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData) {

  preOrder(theTree->root, printData);
}

TreeNode * preOrder(TreeNode * node, PrintFunc printData) {

  if (node != NULL) {

    printData(node->data);
    preOrder(node->left, printData);
    preOrder(node->right, printData);
  }

  return NULL;
}
/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData) {

  postOrder(theTree->root, printData);
}

TreeNode * postOrder(TreeNode * node, PrintFunc printData) {

  if (node != NULL) {

    postOrder(node->left, printData);
    postOrder(node->right, printData);
    printData(node->data);
  }

  return NULL;
}
/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTree) {

  if (theTree == NULL) {

    return 1;
  }

  return 0;
}


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode) {

  if (treeNode->right == NULL && treeNode->left == NULL) {

    return 1;
  }
  else {

    return 0;
  }
}

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode) {

  if (treeNode->right != NULL && treeNode->left != NULL) {

    return 1;
  }
  else {

    return 0;
  }
}

/**
 * Helper funciton Get the height of a particulat Node in the tree.
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree.
 */
int getHeight( TreeNode* treeNode ) {
/*
if (treeNode == NULL) {

  return NULL;
}

int left = getheight(treeNode->left);
int right = getheight(node->right);

return max(right,left) +1;
*/
  int left = 0;
  int right = 0;

  if (treeNode != NULL) {

    left = getHeight(treeNode->left);
    right = getHeight(treeNode->right);

    if (right > left) {

      return right + 1;
    }
    else {

      return left + 1;
    }
  }
  else {

    return 0;
  }
}
