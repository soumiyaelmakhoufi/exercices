#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int height;
    int value;
} Nd;
int max(int a, int b)
{
    return a > b ? a : b;
}
Nd* new_node(int value)
{
    Nd* node = (Nd*) malloc(sizeof(Nd));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->value = value;
    return node;
}
int height(Nd* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void right_rotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* left_child = root->left;
    Nd* left_child_right_child = left_child->right;
    left_child->right = root;
    root->left = left_child_right_child;
    root->height = max(height(root->left), height(root->right)) + 1;
    left_child->height = max(height(left_child->left), height(left_child->right)) + 1;
    *root_adr = left_child;
}
void left_rotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* right_child = root->right;
    Nd* right_child_left_child = right_child->left;
    right_child->left = root;
    root->right = right_child_left_child;
    root->height = max(height(root->left), height(root->right)) + 1;
    right_child->height = max(height(right_child->left), height(right_child->right)) + 1;
    *root_adr = right_child;
}
void insert(Nd** root_adr, int value)
{
    Nd* root = *root_adr;
    if (root == NULL)
    {
        root = new_node(value);
        *root_adr = root;
        return;
    }
    if (root->value > value)
        insert(&(root->left), value);
    else if (root->value < value)
        insert(&(root->right), value);
    else
        return;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = height(root->left) - height(root->right);
    if (balance > 1)
    {
        if (value > root->left->value)
        {
            left_rotation(&(root->left));
            right_rotation(&root);
        }
        else
            right_rotation(&root);
    }
    if (balance < -1)
    {
        if (value < root->right->value)
        {
            right_rotation(&(root->right));
            left_rotation(&root);
        }
        else
            left_rotation(&root);
    }
    *root_adr = root;
}

bool find(Nd* root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    else if (root->value > value)
        return find(root->left, value);
    else
        return find(root->right, value);
}

void free_tree(Nd* root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
} 
void erase(Nd** root_adr, int value)
{
    if (*root_adr == NULL)
    {
        return;
    }
    if (value < (*root_adr)->value)
    {
        erase(&((*root_adr)->left), value);
        return;
    }
    if (value > (*root_adr)->value)
    {
        erase(&((*root_adr)->right), value);
        return;
    }
    if ((*root_adr)->left == NULL)
    {
        Nd* ptr2 = (*root_adr)->right;
        free(*root_adr);
        *root_adr = ptr2;
    }
    else if ((*root_adr)->right == NULL)
    {
        Nd* ptr2 = (*root_adr)->left;
        free(*root_adr);
        *root_adr = ptr2;
    }
    else
    {
        Nd* ptr2 = (*root_adr)->right;
        while (ptr2->left != NULL)
            ptr2 = ptr2->left;
        (*root_adr)->value = ptr2->value;
        erase(&((*root_adr)->right), ptr2->value);
    }
    if (*root_adr != NULL)
    {
        int balance = height((*root_adr)->left) - height((*root_adr)->right);
        if (balance > 1 && height((*root_adr)->left->left) >= height((*root_adr)->left->right))
            right_rotation(root_adr);
        else if (balance > 1 && height((*root_adr)->left->left) < height((*root_adr)->left->right))
        {
            left_rotation(&((*root_adr)->left));
            right_rotation(root_adr);
        }
        else if (balance < -1 && height((*root_adr)->right->right) >= height((*root_adr)->right->left))
            left_rotation(root_adr);
        else if (balance < -1 && height((*root_adr)->right->right) < height((*root_adr)->right->left))
        {
            right_rotation(&((*root_adr)->right));
            left_rotation(root_adr);
        }
        (*root_adr)->height = max(height((*root_adr)->left), height((*root_adr)->right)) + 1;
    }
}            
