#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef struct Node {
    char *key;
    char *value;

    struct Node *left;
    struct Node *right;
    struct Node *parent;

} Node;


typedef struct Tree {
    struct Node *root;

} Tree;

void freeNode(Node *pNode);



void freeNode(Node *pNode) {
    free(pNode->key);
    free(pNode->value);
    free(pNode);
}




#define true 1
#define false 0
#define boolean int

Node* createNode(char *key, char *value, Node* predecessor) {
    Node* newNode = malloc(sizeof(Node));
    newNode->parent = predecessor;
    newNode->key = key;
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

Node* innerInsert2(Node *node, char *key, char *value, Node* predecessor) {
    if(node == NULL) {
        return createNode(key, value, predecessor);
    }
    int compare = strcmp(key, node->key);
    if(compare < 0) {
        node->left = innerInsert2(node->left, key, value, node);
    }
    if(compare > 0) {
        node->right = innerInsert2(node->right, key, value, node);
    }

    return node;
}

int insert2(Tree *tree, char *key, char *info) {
    if(tree == NULL) return false;
    if(tree->root == NULL) {
        tree->root = createNode(key, info, NULL);
        return true;
    }
    innerInsert2(tree->root, key, info, NULL);

    return true;
}

Node* search2(Node* node, char* key) {
    if(node == NULL) return NULL;

    int compare = strcmp(key, node->key);

    if(compare < 0) {
        return search2(node->left, key);
    }
    if(compare > 0) {
        return search2(node->right, key);
    }
    if(compare == 0) {
        return node;
    }
}

Node *findMin(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


Node* innerDelete2(Node* node, char* key) {
    if(node == NULL) return NULL;

    int compare = strcmp(key, node->key);
    if(compare < 0) {
        node->left = innerDelete2(node->left, key);
    }
    if(compare > 0) {
        node->right = innerDelete2(node->right, key);
    }

    if(compare == 0) {
        if(node->left != NULL && node->right != NULL) {
            free(node->key);

            node->key = findMin(node->right)->key;

            node->right = innerDelete2(node->right, node->key); // now searching for the value we put to the end

        }
        else {
            if(node->left != NULL) {
                Node* save = node;
                node = node->left;
                freeNode(save);
            }
            if(node->right != NULL) {
                Node* save = node;
                node = node->right;
                freeNode(save);
            }
            if(node->right == NULL && node->left == NULL) {
                freeNode(node);
            }
        }
    }
    return node;
}

boolean delete(Tree* tree, char* key) {
    if(tree == NULL || key == NULL) return false;
    if(search2(tree->root, key) == NULL) return false;

    //innerDelete2(tree->root, key);
    return true;
}

char *copyString(char *string) {
    int length = strlen(string);
    char *result = calloc(length + 1, sizeof(char));
    for (int i = 0; i < length; i++) {
        result[i] = string[i];
    }
    return result;
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);

    freeNode(root);
}
#define DELTA 10

void printTreeRecursive(Node *root, int space) {
    if (root == NULL)
        return;
    space += DELTA;
    printTreeRecursive(root->right, space);
    printf("\n");
    for (int i = DELTA; i < space; i++) {
        printf(" ");
    }
    printf("%s,  %s\n", root->key, root->value);
    printTreeRecursive(root->left, space);
}

void printTreeVer2(Node *root) {
    printTreeRecursive(root, 0);
}

int main() {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    insert2(tree, copyString("boob"), copyString("what"));
    insert2(tree, copyString("boobrr"), copyString("w3eehat"));
    printTreeVer2(tree->root);
    delete(tree, "boob");
    delete(tree, "boobrr");

    freeTree(tree->root);
    free(tree);
}