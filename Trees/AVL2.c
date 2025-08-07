#include <stdio.h>
#include <stdlib.h>
struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
    struct BinaryTree *parent;
    int height;

};
struct BinaryTree *root = NULL;

void updateHeight(struct BinaryTree *node)
{
    int hl = 0, hr = 0;

    // if left exists set hl
    if (node->left)
        hl = node->left->height;
    else
        hl = 0;

    // if right exists set hr
    if (node->right)
        hr = node->right->height;
    else
        hr = 0;

    // set height equals maximum height + 1
    if (hl > hr)
        node->height = hl + 1;
    else
        node->height = hr + 1;
}

struct BinaryTree* leftRotate(struct BinaryTree* x){
    struct BinaryTree* y = x->right;
    struct BinaryTree* t2 = y->left;

    y->left = x;
    x->right = t2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

struct BinaryTree* rightRotate(struct BinaryTree* y){
    struct BinaryTree* x = y->left;
    struct BinaryTree* t2 = x->right;

    x->right = y;
    y->left = t2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct BinaryTree* leftRightRotate(struct BinaryTree* z){
    z->left = leftRotate(z->left);
    return rightRotate(z);
}

struct BinaryTree* rightLeftRotate(struct BinaryTree* z){
    z->right = rightRotate(z->right);
    return leftRotate(z);
}

int getHeight(struct BinaryTree *node)
{
    if (node)
        return node->height;
    else
        return -1;
}

struct BinaryTree* create_node(int value)
{
    struct BinaryTree *NewNode;
    NewNode = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->parent = NULL;
    NewNode->height = 0;
    return NewNode;
}
void preorder(struct BinaryTree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct BinaryTree *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct BinaryTree *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
        
    }
}

int getBalanceFactor(struct BinaryTree* node){
    if(node == NULL)
        return -1;
    return getHeight(node->left) - getHeight(node->right);
}

struct BinaryTree* insert(struct BinaryTree* root, int value)
{
    if(root == NULL)
        root = create_node(value);
    if (value < root->data)
    {
        root->left = insert(root->left, value);
        root->left->parent = root;
    }
    if(value > root->data)
    {
        root->right = insert(root->right, value);
        root->right->parent = root;
    }

    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);
    printf("bf: %d", balanceFactor);

    // if left side is longer and new data is inserted to left of left
    if (balanceFactor > 1 && value < root->left->data)
        return rightRotate(root);

    // if right side is longer and new data is inserted to right of right
    if (balanceFactor < -1 && value > root->right->data)
        return leftRotate(root);

    // if left side is longer and new data is inserted to right of left
    if (balanceFactor > 1 && value > root->left->data)
        return leftRightRotate(root);

    // if right side is longer and new data is inserted to left of right
    if (balanceFactor < -1 && value < root->right->data)
        return rightLeftRotate(root);

    return root;
}
struct BinaryTree* search(struct BinaryTree *root, int key)
{
    if((root == NULL) || (key == root->data))
        return root;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct BinaryTree* find_min(struct BinaryTree *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}
struct BinaryTree* find_max(struct BinaryTree *root)
{
    while(root->right != NULL)
        root = root->right;
    return root;
}
struct BinaryTree* delete_node(struct BinaryTree *root, int value)
{
    if(root == NULL)
        return root;
    if(value < root->data)
    {
        root->left = delete_node(root->left, value);
        if(root->left) root->left->parent = root;
    }
    else if( value > root->data)
    {
        root->right = delete_node(root->right, value);
        if(root->right) root->right->parent = root;
    }
    else
    {
        // Case 1 and Case 2
        if(root->left == NULL)
        {
            struct BinaryTree *temp = root->right;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BinaryTree *temp = root->left;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        }
        else
        {
            // Case 3
            struct BinaryTree *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
            if(root->right) root->right->parent = root;
        }
    }
    return root;
}

int main()
{
    int i, element, choice;
    struct BinaryTree *temp;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    do
    {
        printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.INORDER\n");
        printf("5.PREORDER\n6.POSTORDER\n7.FIND MAX\n8.FIND MIN\n");
        printf("9.CREATE\n10.EXIT\nEnter your choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert ");
            scanf("%d",&element);
            root = insert(root, element);
            printf("%d INSERTED!\n",element);
            break;

        case 2:
            printf("Enter the element to delete ");
            scanf("%d",&element);
            root = delete_node(root, element);
            printf("%d DELETED!\n",element);
            break;

        case 3:
            printf("Enter the element to search ");
            scanf("%d",&element);
            temp = search(root, element);
            if(temp == NULL)
                printf("%d NOT FOUND!!\n",element);
            else
                printf("%d FOUND!\n",element);
            break;

        case 4:
            inorder(root);
            printf("\n");
            break;

        case 5:
            preorder(root);
            printf("\n");
            break;

        case 6:
            postorder(root);
            printf("\n");
            break;

        case 7:
            temp = find_max(root);
            if(temp != NULL)
                printf("%d IS THE LARGEST ELEMENT IN THE BST\n",temp->data);
            break;

        case 8:
            temp = find_min(root);
            if(temp != NULL)
                printf("%d IS THE SMALLEST ELEMENT IN THE BST\n",temp->data);
            break;

        case 9:
            for(i=0;i<9;i++)
                root = insert(root, arr[i]);
            printf("All elements inserted sucessfully!\n");
            break;
        
        case 10:
            printf("Bye!\n");

        }
    } while (choice!=10);
    return 0;
}