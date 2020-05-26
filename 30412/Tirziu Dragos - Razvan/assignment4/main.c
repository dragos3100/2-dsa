#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right, *left;
    int height;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;
    return newNode;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    else return node->height;
}

int getBalance(Node *node) {
    if (node == NULL)
        return 0;
    else return (height(node->right) - height(node->left));
}

int max(int a, int b) {
    if (a > b)
        return a;
    else return b;
}

Node *rotateRight(Node *root) {
    Node *aux1 = root->left;
    Node *aux2 = aux1->right;
    aux1->right = root;
    root->left = aux2;
    root->height = max(height(root->left), height(root->right)) + 1;
    aux1->height = max(height(aux1->left), height(aux1->right)) + 1;
    return aux1;
}

Node *rotateLeft(Node *root) {
    Node *aux1 = root->right;
    Node *aux2 = aux1->left;
    aux1->left = root;
    root->right = aux2;
    root->height = max(height(root->left), height(root->right)) + 1;
    aux1->height = max(height(aux1->left), height(aux1->right)) + 1;
    return aux1;
}

Node *insert(Node *root, int data) {
    if (root == NULL)
        return (createNode(data));
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    root->height = 1 + max(height(root->left), height(root->right));
    if (getBalance(root) < -1 && data < root->left->data)
        root = rotateRight(root);
    else if (getBalance(root) < -1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    } else if (getBalance(root) > 1 && data > root->right->data)
        root = rotateLeft(root);
    else if (getBalance(root) > 1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

void prettyPrint(Node *root, int level) {
    if (root->right != NULL)
        prettyPrint(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->data);
    if (root->left != NULL)
        prettyPrint(root->left, level + 1);
}

Node *findSuccesor(Node *root) {
    Node *succesor = root->right;
    if(succesor==NULL)
        return NULL;
    while (succesor->left != NULL)
        succesor = succesor->left;
    return succesor;
}

Node *findPredecesor(Node *root) {
    Node *predecesor = root->left;
    if(predecesor==NULL)
        return NULL;
    while (predecesor->right != NULL)
        predecesor = predecesor->right;
    return predecesor;
}

Node *delete(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            if(findSuccesor(root)!=NULL){
                Node *replacement=findSuccesor(root);
                root->data=replacement->data;
                root->right=delete(root->right,replacement->data);
            }
            else{
                Node *replacement=findPredecesor(root);
                root->data=replacement->data;
                root->left=delete(root->left,replacement->data);
            }
        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
    if (getBalance(root) < -1 && data < root->left->data)
        root = rotateRight(root);
    else if (getBalance(root) < -1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    } else if (getBalance(root) > 1 && data > root->right->data)
        root = rotateLeft(root);
    else if (getBalance(root) > 1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

int main() {
    Node *root = NULL;
    root = insert(root, 0);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, -1);
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, -2);
    prettyPrint(root,0);
    root=delete(root,8);
    root=delete(root,4);
    root=delete(root,10);
    prettyPrint(root, 0);
    return 0;
}
