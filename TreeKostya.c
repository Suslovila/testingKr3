//#include <stdio.h>
//
//#include <stdlib.h>
//
//#include <string.h>
//
//typedef struct TreeNode {
//
//  struct TreeNode * left;
//  struct TreeNode * right;
//  struct TreeNode * parent;
//
//  char * key;
//
//} TreeNode;
//void freeNode(TreeNode * node);
//typedef struct Tree {
//  TreeNode * root;
//} Tree;
//
//char *copyString(char *string) {
//    int length = strlen(string);
//    char *result = calloc(length + 1, sizeof(char));
//    for (int i = 0; i < length; i++) {
//        result[i] = string[i];
//    }
//    return result;
//}
//
//TreeNode * search(TreeNode * root, char * key) {
//  if (root == NULL || strcmp(root -> key, key) == 0)
//    return root;
//
//  if (strcmp(key, root -> key) > 0)
//    return search(root -> right, key);
//  else return search(root -> left, key);
//
//}
//
//TreeNode * min(TreeNode * root) {
//  if (root -> left != NULL)
//    return min(root -> left);
//  return root;
//}
//
//TreeNode * createNewNode(char * key, TreeNode * parent, TreeNode * left, TreeNode * right) {
//  TreeNode * new = (TreeNode *) malloc(sizeof(TreeNode) * 1);
//  new -> key = key;
//  new -> parent = parent;
//  new -> left = left;
//  new -> right = right;
//  return new;
//}
//
//TreeNode * insertInner(TreeNode ** root, TreeNode * parent, char * key) {
//  if (* root == NULL)
//    * root = createNewNode(key, parent, NULL, NULL);
//  else if (strcmp(key, (* root) -> key) > 0)
//    insertInner(& ( (* root) -> right), * root, key);
//  else insertInner(& ( (* root) -> left), * root, key);
//}
//
//int insert(Tree * tree, char *  key) {
//  if (tree == NULL || key == NULL || search(tree -> root, key) != NULL)
//    return 1;
//  insertInner(&(tree -> root), NULL, key);
//  return 0;
//}
//
//void printTree(TreeNode * root, int depth) {
//  if (root == NULL)
//    return;
//
//  printTree(root -> right, depth + 1);
//  for (int i = 0; i < depth; i++)
//    printf("      ");
//  printf("%s\n", root -> key);
//  printTree(root -> left, depth + 1);
//}
//
//TreeNode * innerDelete(TreeNode * root, char * key) {
//  if (root == NULL)
//    return NULL;
//
//  if (strcmp(key, root -> key) < 0) {
//    root -> left = innerDelete(root -> left, key);
//  } else if (strcmp(key, root -> key) > 0) {
//    root -> right = innerDelete(root -> right, key);
//  } else {
//
//    if (root -> left == NULL || root -> right == NULL) {
//      if (root -> left == NULL && root -> right == NULL) {
//        freeNode(root);
//        root = NULL;
//      } else if (root -> left == NULL) {
//        TreeNode * tmp = root;
//        root = root -> right;
//        free(tmp);
//      } else if (root -> right == NULL) {
//        TreeNode * tmp = root;
//        root = root -> left;
//        free(tmp);
//      }
//    } else {
//      TreeNode * mn = min(root -> right);
//      root -> key = mn -> key;
//      root -> right = innerDelete(root -> right, mn -> key);
//    }
//  }
//
//  return root;
//}
//
//int delete(Tree * tree, char * key) {
//  if (tree == NULL || key == NULL || search(tree -> root, key) == 0)
//    return 1;
//  tree -> root = innerDelete(tree -> root, key);
//  return 0;
//}
//
//void freeNode(TreeNode * node) {
//  if (node == NULL)
//    return;
//
//  freeNode(node -> left);
//  freeNode(node -> right);
//  free(node);
//}
//
//void freeTree(Tree * tree) {
//  if (tree == NULL)
//    return;
//
//  freeNode(tree -> root);
//
//  free(tree);
//}
//
//int main() {
//  Tree * tree = (Tree *) malloc(sizeof(Tree) * 1);
//  tree -> root = NULL;
//
//  insert(tree, "a");
//  insert(tree, "b");
//  insert(tree, "c");
//  insert(tree, "d");
//  insert(tree, "ab");
//  insert(tree, "bc");
//  insert(tree, "ac");
//  insert(tree, "ad");
//  insert(tree, "bd");
//  insert(tree, "cd");
//  insert(tree, "1");
//  insert(tree, "2");
//  insert(tree, "3");
//  printTree(tree -> root, 0);
//  delete(tree, "2");
//  delete(tree, "3");
//  delete(tree, "a");
//  delete(tree, "a");
//  delete(tree, "bd");
//  delete(tree, "ad");
//  delete(tree, "2");
//  delete(tree, "bc");
//  delete(tree, "1");
//  delete(tree, "d");
//  delete(tree, "b");
//  delete(tree, "c");
//  delete(tree, "ab");
//  delete(tree, "ac");
//  delete(tree, "cd");
//  printTree(tree -> root, 0);
//  freeTree(tree);
//}