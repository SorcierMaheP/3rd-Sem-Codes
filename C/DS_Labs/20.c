#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (ikey < ptr->info)
        ptr->lchild = insert(ptr->lchild, ikey);
    else if (ikey > ptr->info)
        ptr->rchild = insert(ptr->rchild, ikey);
    else
        printf("Duplicate key.\n");
    return ptr;
}

struct node *search(struct node *ptr, int skey)
{
    if (ptr == NULL)
    {
        printf("Key not found in tree.\n");
        return NULL;
    }
    else if (skey < ptr->info)
        return search(ptr->lchild, skey);
    else if (skey > ptr->info)
        return search(ptr->rchild, skey);
    else
        return ptr;
}

struct node *del(struct node *ptr, int dkey)
{
    struct node *tmp, *succ;
    if (ptr == NULL)
    {
        printf("Element %d not present in the tree.\n", dkey);
        return ptr;
    }
    if (dkey < ptr->info)
        ptr->lchild = del(ptr->lchild, dkey);
    else if (dkey > ptr->info)
        ptr->rchild = del(ptr->rchild, dkey);
    else
    {
        if (ptr->lchild != NULL && ptr->rchild != NULL)
        {
            succ = ptr->rchild;
            while (succ->lchild != NULL)
                succ = succ->lchild;
            ptr->info = succ->info;
            ptr->rchild = del(ptr->rchild, succ->info);
        }
        else
        {
            tmp = ptr;
            if (ptr->lchild != NULL)
                ptr = ptr->lchild;
            else if (ptr->rchild != NULL)
                ptr = ptr->rchild;
            else
                ptr = NULL;
            free(tmp);
        }
    }
    return ptr;
}

int height(struct node *ptr)
{
    int h_left, h_right;
    if (ptr == NULL)
        return 0;
    h_left = height(ptr->lchild);
    h_right = height(ptr->rchild);
    if (h_left > h_right)
        return 1 + h_left;
    else
        return 1 + h_right;
}

void displaygivenlevel(struct node *ptr, int level)
{
    if (ptr == NULL)
        return;
    if (level == 1)
        printf("%d ", ptr->info);
    else if (level > 1)
    {
        displaygivenlevel(ptr->lchild, level - 1);
        displaygivenlevel(ptr->rchild, level - 1);
    }
}

void levelorder(struct node *ptr)
{
    int h = height(ptr);
    int i;
    for (i = 1; i <= h; i++)
        displaygivenlevel(ptr, i);
}

void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ", ptr->info);
    inorder(ptr->rchild);
}

void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->info);
}

int main()
{
    int ch, elem;
    struct node *root = NULL, *tmp = NULL;
    while (1)
    {
        printf("\n1.Insertion.\n2.Deletion.\n3.Searching.\n4.Levelorder.\n5.Preorder.\n6.Postorder.\n7.Inorder.\n8.Exit.\n");
        printf("Enter your choice.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be inserted.\n");
            scanf("%d", &elem);
            root = insert(root, elem);
            break;
        case 2:
            printf("Enter element to be deleted.\n");
            scanf("%d", &elem);
            root = del(root, elem);
            break;
        case 3:
            printf("Enter element to be searched.\n");
            scanf("%d", &elem);
            tmp = search(root, elem);
            if (tmp != NULL)
                printf("Key found in tree.\n");
            break;
        case 4:
            printf("Levelorder traversal is:\n");
            levelorder(root);
            break;
        case 5:
            printf("Preorder traversal is:\n");
            preorder(root);
            break;
        case 6:
            printf("Postorder traversal is:\n");
            postorder(root);
            break;
        case 7:
            printf("Inorder traversal is:\n");
            inorder(root);
            break;
        case 8:
            exit(1);
        default:
            printf("Erroneous input.\n");
        }
    }
    return 0;
}
