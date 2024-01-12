#include <stdio.h>
#include <stdlib.h>
// 적정트리란? : 내부노드가 두개의 자식노드를 반드시 가져야 한다.

// 내부 노드? : 자식노드가 있는 노드
// 외부 노드? : 외부노드는 자식노드가 없는 노드

// 실습 2 : 이진 트리 ( 적정트리 X)
typedef struct treeNode
{
    int data;
    int id;
    treeNode *left;
    treeNode *right;
} treeNode;

treeNode *insertNode(int id, int data, treeNode *left, treeNode *right)
{
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));

    newNode->id = id;
    newNode->data = data;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// input 없고
// output 루트노드의 주소
treeNode *treeBuild()
{
    treeNode *n7 = insertNode(7, 130, NULL, NULL);
    treeNode *n8 = insertNode(8, 80, NULL, NULL);
    treeNode *n6 = insertNode(6, 120, n7, n8);

    treeNode *n4 = insertNode(4, 70, NULL, NULL);
    treeNode *n5 = insertNode(5, 90, NULL, NULL);

    treeNode *n2 = insertNode(2, 30, n4, n5);
    treeNode *n3 = insertNode(3, 50, NULL, n6);

    treeNode *n1 = insertNode(1, 20, n2, n3);

    return n1;
}

// traverse
// preOrder / postOrder / inOrder
void visit(treeNode *v)
{
    printf("%d ", v->data);
}

int isInternal(treeNode *v)
{
    return ((v->left != NULL) && (v->right != NULL));
}

treeNode *leftChild(treeNode *v)
{
    return v->left;
}

treeNode *rightChild(treeNode *v)
{
    return v->right;
}

void binaryPreOrder(treeNode *v)
{
    if (v != NULL)
    {
        visit(v);
        binaryPreOrder(leftChild(v));
        binaryPreOrder(rightChild(v));
    }
}

void binaryPostOrder(treeNode *v)
{
    if (v != NULL)
    {
        binaryPostOrder(leftChild(v));
        binaryPostOrder(rightChild(v));
        visit(v);
    }
}

void binaryInOrder(treeNode *v)
{
    if (v != NULL)
    {
        binaryInOrder(leftChild(v));
        visit(v);
        binaryInOrder(rightChild(v));
    }
}

treeNode *findID(treeNode *v, int id)
{
    if (v != NULL)
    {
        if (v->id == id)
            return v;

        treeNode *p = NULL;
        p = findID(leftChild(v), id);
        if (p != NULL)
            return p;
        p = findID(rightChild(v), id);
        if (p != NULL)
            return p;
    }
    return NULL;
}

int main()
{
    treeNode *root = treeBuild();

    int id, type;
    scanf("%d %d", &type, &id);

    treeNode *p = findID(root, id);

    if (p != NULL)
    {
        if (type == 1)
            binaryPreOrder(p);
        else if (type == 2)
            binaryInOrder(p);
        else if (type == 3)
            binaryPostOrder(p);
    }
    else
    {
        printf("-1");
    }
    printf("\n");
    return 0;
}