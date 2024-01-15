#include <stdio.h>
#include <stdlib.h>

// 오일러 투어 : 오일러 투어를 통해서 각 부트리의 크기를 알 수 있다.
// 이진트리에 대한 일반순회

int k;
typedef struct treeNode
{
    int elem;
    treeNode *left;
    treeNode *right;
    int kleft;
    int size;
} treeNode;

treeNode *insertNode(int elem, treeNode *left, treeNode *right)
{
    treeNode *node = (treeNode *)malloc(sizeof(treeNode));
    node->elem = elem;
    node->left = left;
    node->right = right;
    node->kleft = 0;
    node->size = 0;

    return node;
}
void visit(treeNode *v)
{
    printf("%c ", v->elem);
}
void visit_size(treeNode* v)
{
    printf("%d ", v->size);
}
int isInternal(treeNode *v)
{
    return ((v->left != NULL) && (v->right != NULL));
}
int isExternal(treeNode *v)
{
    return ((v->left == NULL) && (v->right == NULL));
}
treeNode *leftChild(treeNode *v)
{
    return v->left;
}
treeNode *rightChild(treeNode *v)
{
    return v->right;
}

void invalidNodeException()
{
    printf("invalidNodeException\n");
    exit(1);
}

treeNode *findID(treeNode *v, int id)
{
    if (v != NULL)
    {
        if (v->elem == id)
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

void binaryPreOrder(treeNode* v)
{
    visit_size(v);
    if(isInternal(v))
    {
        binaryPreOrder(leftChild(v));
        binaryPreOrder(rightChild(v));
    }
}

treeNode *treeBuild()
{
    treeNode *n1 = insertNode('H', NULL, NULL);
    treeNode *n2 = insertNode('I', NULL, NULL);
    treeNode *n3 = insertNode('E', n1, n2);
    treeNode *n4 = insertNode('D', NULL, NULL);
    treeNode *n5 = insertNode('B', n4, n3);
    treeNode *n6 = insertNode('F', NULL, NULL);
    treeNode *n7 = insertNode('G', NULL, NULL);
    treeNode *n8 = insertNode('C', n6, n7);
    treeNode *n9 = insertNode('A', n5, n8);
    return n9;
}

void visitLeft(treeNode *v)
{
    k = k + 1;
    v->kleft = k;
}

void visitRight(treeNode *v)
{
    v->size = k - v->kleft + 1;
}

void visitBelow(treeNode *v)
{
    return;
}

void eulerTour(treeNode *v)
{
    visitLeft(v);
    if (isInternal(v))
        eulerTour(leftChild(v));
    visitBelow(v);
    if (isInternal(v))
        eulerTour(rightChild(v));
    visitRight(v);
}

void findSizeofSubtrees(treeNode *v)
{
    k = 0;
    eulerTour(v);
}

int main()
{
    treeNode *root = treeBuild();
    eulerTour(root);
    binaryPreOrder(root);
    // 오일러 투어 순회는 선위/중위/후위 순회를 모두 필요한 경우에 활용하면됨.

    return 0;
}