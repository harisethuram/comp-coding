#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// declaration of what a node is
struct node
{
    // satellite data
    int data;
    // color of node. 'r' = red and 'b' = black
    char color;
    // left and right child pointers
    struct node *leftChild;
    struct node *rightChild;
    // parent pointer
    struct node *parent;
};

struct node *createNode(int data);
struct node *treeInsert(struct node *root, int data);
int printTree(struct node *root);
struct node *fixRBT (struct node *root, struct node *z);
struct node *rotate (struct node *root, struct node *ptr, char direction);
void leftRotate(struct node *ptr);
void rightRotate(struct node *ptr);


int main()
{
    //printf("Num. elements: ");
    int n = 0;
    printf("Number of elements: ");
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &nums[i]);
    }

    struct node *root = createNode(nums[0]);

    root->color = 'b';


    for(int j = 1; j < n; j++)
    {
        struct node *z = treeInsert(root, nums[j]);
        root = fixRBT(root, z);
    }
    printTree(root);

}

// create a node with satellite data 'data' and return a pointer to that node. All pointers are set default to NULL and color is set to red. Takes in an integer as satellite data.
struct node *createNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    newNode->color = 'r';
    return newNode;
}

// insert a node into a tree given the satellite data. Takes in root pointer and an integer for satellite data.
struct node *treeInsert(struct node *root, int data)
{
    // allocate memory for new node and assign values
    struct node *x = createNode(data);

    x->color = 'r';

    struct node *ptr = root;

    while (ptr != NULL)
    {
        if (x->data < ptr->data)
        {
            if (ptr->leftChild == NULL)
            {
                ptr->leftChild = x;
                x->parent = ptr;
                ptr = NULL;
            }
            else
                ptr = ptr->leftChild;
        }
        else
        {
            if (ptr->rightChild == NULL)
            {
                ptr->rightChild = x;
                x->parent = ptr;
                ptr = NULL;
            }
            else
                ptr = ptr->rightChild;
        }
    }
    return x;
}

// print all elements in the tree in ascending order. Takes in root pointer.
int printTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    printTree(root->leftChild);
    printf("%d, color: %c\n", root->data, root->color);
    printTree(root->rightChild);
    //printf("%d, ", root->data);

    return 1;
}

// fix the RBT after each insertion. Returns the root of the tree as the root can change. Takes in the root pointer and current node pointer.
struct node *fixRBT (struct node *root, struct node *z)
{
    while (z->parent != NULL && z->parent->color == 'r')
    {
        // case 1
        if (z->parent == z->parent->parent->leftChild)
        {
            struct node *y = z->parent->parent->rightChild;
            // case 1.1

            if (y != NULL && y->color == 'r')
            {
                    z->parent->color = 'b';
                    y->color = 'b';
                    z->parent->parent->color = 'r';
                    z = z->parent->parent;
            }
            else
            {
                // case 1.2
                if (z == z->parent->rightChild)
                {
                    z = z->parent;
                    root = rotate(root, z, 'l');
                }
                // case 1.3
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                root = rotate(root, z->parent->parent, 'r');

            }
        }
        // case 2
        else if (z->parent == z->parent->parent->rightChild)
        {
            struct node *y = z->parent->parent->leftChild;
            // case 2.1
            if (y != NULL && y->color == 'r')
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            }
            else
            {
                // case 2.2
                if (z == z->parent->leftChild)
                {
                    z = z->parent;
                    root = rotate(root, z, 'r');
                }
                // case 2.3

                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                root = rotate(root, z->parent->parent, 'l');

            }
        }
    }
    root->color = 'b';
    return root;
    //printf("Hello\n");
}

// r = right rotation, l = left rotation. Returns the root of the tree as the root can change. Takes in the root pointer, node-to-rotate pointer and direction char.
struct node *rotate (struct node *root, struct node *ptr, char direction)
{
    bool isRoot = false;
    if (ptr == root)
        isRoot = true;

    // left rotatation
    if (direction == 'l')
        leftRotate(ptr);

    // right rotation
    if (direction == 'r')
        rightRotate(ptr);

    if (isRoot == true)
        root = ptr->parent;

    return root;
}

// left rotation code.
void leftRotate(struct node *ptr)
{
    struct node *rightChild = ptr->rightChild;

    // You can do a rotation if the right child isn't NULL
    if (rightChild != NULL)
    {
        // Change the B subtree (Figure 2.30)
        struct node *B = ptr->rightChild->leftChild;
        ptr->rightChild = B;

        // if B isn't just a NULL node
        if (B != NULL)
        {
            B->parent = ptr;
        }

        // Edit the relative positions of ptr and its right child
        // Edit the right child's parent to be ptr's parent
        rightChild->parent = ptr->parent;

        // Edit rightChild's new parent's child to be rightChild
        if (rightChild->parent != NULL) // i.e. it is not a root node
        {
            if (rightChild->data > rightChild->parent->data)
                rightChild->parent->rightChild = rightChild;
            else
                rightChild->parent->leftChild = rightChild;
        }

        rightChild->leftChild = ptr;
        ptr->parent = rightChild;
    }
}

// right rotation code. Takes in the node-to-rotate pointer.
void rightRotate(struct node *ptr)
{
    struct node *leftChild = ptr->leftChild;

    // You can do a rotation if the left child isn't NULL
    if (leftChild != NULL)
    {
        // Change the B subtree (Figure 2.30)
        struct node *B = ptr->leftChild->rightChild;
        ptr->leftChild = B;

        // if B isn't just a NULL node
        if (B != NULL)
        {
            B->parent = ptr;
        }

        // Edit the relative positions of ptr and its right child
        // Edit the right child's parent to be ptr's parent
        leftChild->parent = ptr->parent;

        // Edit rightChild's new parent's child to be rightChild
        if (leftChild->parent != NULL) // i.e. it is not a root node
        {
            if (leftChild->data > leftChild->parent->data)
                leftChild->parent->rightChild = leftChild;
            else
                leftChild->parent->leftChild = leftChild;
        }

        leftChild->rightChild = ptr;
        ptr->parent = leftChild;
    }
}
