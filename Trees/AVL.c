#include <stdio.h>
#include <stdlib.h>
struct BinaryTree
{
    int data;
    int height;
    struct BinaryTree *left;
    struct BinaryTree *right;
    struct BinaryTree *parent;
};
struct BinaryTree *root = NULL;
struct BinaryTree *create_node(int value)
{
    struct BinaryTree *NewNode;
    NewNode = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    NewNode->height = 0;
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->parent = NULL;
    return NewNode;
}
void preorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

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

void display(struct BinaryTree *root)
{
    // if (root == NULL)
    // {
    //     return;
    // }

    // printf("Value: %d \t height: %d \t", root->data, root->height);
    // if (root->left)
    //     printf("Left: %d \t", root->left->data);
    // else
    //     printf("Left: Null \t");

    // if (root->right)
    //     printf("Right: %d \n", root->right->data);
    // else
    //     printf("Right: Null \n");

    // display(root->left);
    // display(root->right);
}

struct BinaryTree *leftRotate(struct BinaryTree *node)
{
    struct BinaryTree *node_right = node->right;
    struct BinaryTree *left_of_right = node_right->left;

    node_right->left = node;
    node_right->parent = node->parent;

    if(node->parent->left == node)
        node->parent->left = node_right;
    else
        node->parent->right = node_right;

    node->parent = node_right;
    node->right = left_of_right;
    left_of_right->parent = node;

    updateHeight(node);
    updateHeight(node_right);
    return node_right;
}

struct BinaryTree *rightRotate(struct BinaryTree *node)
{
    struct BinaryTree *node_left = node->left;
    struct BinaryTree *right_of_left = node_left->right;

    node_left->right = node;
    node_left->parent = node->parent;

    if(node->parent->left == node)
        node->parent->left = node_left;
    else
        node->parent->right = node_left;
    
    node->parent = node_left;
    node->left = right_of_left;
    right_of_left->parent = node;

    updateHeight(node);
    updateHeight(node_left);
    return node_left;
}

struct BinaryTree *rightLeftRotation(struct BinaryTree *node)
{
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

struct BinaryTree *leftRightRotation(struct BinaryTree *node)
{
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

int getHeight(struct BinaryTree *node)
{
    if (node)
        return node->height;
    else
        return 0;
}

struct BinaryTree *insert(struct BinaryTree *root, int value)
{
    if (root == NULL)
        root = create_node(value);
    if (value < root->data)
    {
        root->left = insert(root->left, value);
        root->left->parent = root;
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
        root->right->parent = root;
    }
    else
    {
        return root;
    }

    updateHeight(root);
    int balance = getHeight(root->left) - getHeight(root->right);
    printf("%d", balance);

    // if left side is longer and new data is inserted to left of left
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // if right side is longer and new data is inserted to right of right
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // if left side is longer and new data is inserted to right of left
    if (balance > 1 && value > root->left->data)
        return leftRightRotation(root);

    // if right side is longer and new data is inserted to left of right
    if (balance < -1 && value < root->right->data)
        return rightLeftRotation(root);

    return root;
}

struct BinaryTree *search(struct BinaryTree *root, int key)
{
    if ((root == NULL) || (key == root->data))
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct BinaryTree *find_min(struct BinaryTree *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct BinaryTree *find_max(struct BinaryTree *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
struct BinaryTree *delete_node(struct BinaryTree *root, int value)
{
    if (root == NULL)
        return root;
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
        if (root->left)
            root->left->parent = root;
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
        if (root->right)
            root->right->parent = root;
    }
    else
    {
        // Case 1 and Case 2
        if (root->left == NULL)
        {
            struct BinaryTree *temp = root->right;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BinaryTree *temp = root->left;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else
        {
            // Case 3
            struct BinaryTree *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
            if (root->right)
                root->right->parent = root;
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
        printf("9.CREATE\n10.DISPLAY\n11.EXIT\nEnter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert ");
            scanf("%d", &element);
            root = insert(root, element);
            printf("%d INSERTED!\n", element);
            break;

        case 2:
            printf("Enter the element to delete ");
            scanf("%d", &element);
            root = delete_node(root, element);
            printf("%d DELETED!\n", element);
            break;

        case 3:
            printf("Enter the element to search ");
            scanf("%d", &element);
            temp = search(root, element);
            if (temp == NULL)
                printf("%d NOT FOUND!!\n", element);
            else
                printf("%d FOUND!\n", element);
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
            if (temp != NULL)
                printf("%d IS THE LARGEST ELEMENT IN THE BST\n", temp->data);
            break;

        case 8:
            temp = find_min(root);
            if (temp != NULL)
                printf("%d IS THE SMALLEST ELEMENT IN THE BST\n", temp->data);
            break;

        case 9:
            for (i = 0; i < 9; i++)
                root = insert(root, arr[i]);
            printf("All elements inserted sucessfully!\n");
            break;

        case 10:
            display(root);
            break;

        case 11:
            printf("Bye!\n");
            break;
        
        default:
            printf("Invalid option");

        }

    } while (choice != 11);
    return 0;
}