#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header & trailer double linked list
struct node
{
    int elem;
    struct node *next;
    struct node *prev;
};

struct Set
{
    // boolean ==> int 1:true  0:false

    int n; // 현재 연결리스트에 추가된 노드의 수
    int N; // 연결 리스트로 추가할 수 있는 최대 노드의 수
    struct node *header;
    struct node *trailer;

    int isEmpty()
    {
        if (n == 0)
            return 1;
        else
            return 0;
    }
    int size()
    {
        return n;
    }
    int get(int r)
    {
        struct node *p = header;
        for (int i = 1; i <= r; i++)
        {
            p = p->next;
        }
        return p->elem;
    }
    void set(int r, int e)
    {
        struct node *p = header;
        for (int i = 1; i <= r; i++)
        {
            p = p->next;
        }
        p->elem = e;
    }
    void initialize()
    {
        header = (struct node *)malloc(sizeof(struct node) * 1);
        trailer = (struct node *)malloc(sizeof(struct node) * 1);
        header->next = trailer;
        header->prev = NULL;
        trailer->prev = header;
        trailer->next = NULL;
        n = 0;
        N = 100;
    }
    void invailidRankException()
    {
        printf("invalidRank\n");
    }
    void addNodeBefore(struct node *p, int e)
    {
        // getnode()
        struct node *q = (struct node *)malloc(sizeof(struct node) * 1);
        q->elem = e;

        // insert
        q->prev = p->prev;
        q->next = p;
        (p->prev)->next = q;
        p->prev = q;
    }

    void addNodeAfter(struct node *p, int e)
    {
        // getnode()
        struct node *q = (struct node *)malloc(sizeof(struct node) * 1);
        q->elem = e;

        // insert
        q->prev = p;
        q->next = p->next;
        (p->next)->prev = q;
        (p->next) = q;
    }

    void add(int r, int e)
    {
        if (r < 1 || r > N)
        {
            invailidRankException();
            return;
        }
        struct node *p = header;
        for (int i = 1; i <= r; i++)
        {
            p = p->next;
        }
        addNodeBefore(p, e);
        n = n + 1;
    }

    void addLast(int e)
    {
        if (n > N)
        {
            invailidRankException();
            return;
        }
        struct node *p = trailer;
        addNodeBefore(p, e);
        n = n + 1;
    }

    void addFirst(int e)
    {
        if (n > N)
        {
            invailidRankException();
            return;
        }
        struct node *p = header;

        addNodeAfter(p, e);
        n = n + 1;
    }

    void addElem(int e)
    {
        addLast(e);
    }

    int removeNode(struct node *p)
    {
        int e = p->elem;
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        // putnode(p)
        free(p);
        p = NULL;
        return e;
    }

    int remove(int r)
    {
        if (r < 1 || r > N)
        {
            invailidRankException();
            return -1;
        }
        struct node *p = header;
        for (int i = 1; i <= r; i++)
        {
            p = p->next;
        }
        int e = removeNode(p);
        n = n - 1;
        return e;
    }

    void removeLast()
    {
        if (n < 1)
        {
            invailidRankException();
            return;
        }
        remove(n);
    }

    void removeFirst()
    {
        if (n < 1)
        {
            invailidRankException();
            return;
        }
        remove(1);
    }

    void removeElem()
    {
        removeFirst();
    }

    void visit(int e)
    {
        printf("%d ", e);
    }
    void traverse()
    {
        struct node *p = header->next;
        while (p != trailer)
        {
            visit(p->elem);
            p = p->next;
        }
        printf("\n");
    }

    int member(int e)
    {
        if (n == 0)
            return 0;

        struct node *p = header->next; // 처음 부터 값이 존재할 때

        while (1)
        {
            int a = p->elem;
            if (a < e)
            {
                if (p->next == NULL)
                    return 0;
                else
                    p = p->next;
            }
            else if (a > e)
                return 0;
            else
                return 1;
        }
    }

    // 본 집합이 Set B의 부분집합이냐?
    int subset(Set B)
    {
        if (n == 0)
            return 1;

        struct node *p = header->next;
        while (1)
        {
            if (B.member(p->elem))
                if ((p->next)->next == NULL)
                    return 1;
                else
                    p = p->next;

            else
                return 0;
        }
    }
};
void test1()
{
    Set A;
    A.initialize();

    A.add(1, 1);
    A.traverse();
    A.add(1, 2);
    A.traverse();
    A.add(1, 3);
    A.traverse();
    A.add(1, 4);
    A.traverse();

    A.remove(1);
    A.traverse();
    A.remove(1);
    A.traverse();
    A.remove(1);
    A.traverse();
    A.remove(1);
    A.traverse();
}

Set my_union(Set A, Set B)
{
    // 1.
    Set C;
    C.initialize();

    // 2. while
    while (!A.isEmpty() & !B.isEmpty())
    {
        int a = A.get(1);
        int b = B.get(1);

        if (a < b)
        {
            C.addLast(a);
            A.removeFirst();
        }
        else if (a > b)
        {
            C.addLast(b);
            B.removeFirst();
        }
        else
        {
            C.addLast(a);
            A.removeFirst();
            B.removeFirst();
        }
    }

    // 3. while
    while (!A.isEmpty())
    {
        int a = A.get(1);
        C.addLast(a);
        A.removeFirst();
    }

    // 4. while
    while (!B.isEmpty())
    {
        int b = B.get(1);
        C.addLast(b);
        B.removeFirst();
    }
    return C;
}

Set my_intersect(Set A, Set B)
{
    Set C;
    C.initialize();
    while (!A.isEmpty() & !B.isEmpty())
    {
        int a = A.get(1);
        int b = B.get(1);

        if (a < b)
        {
            A.removeFirst();
        }
        else if (a > b)
        {
            B.removeFirst();
        }
        else
        {
            C.addLast(a);
            A.removeFirst();
            B.removeFirst();
        }
    }

    while (!A.isEmpty())
    {
        A.removeFirst();
    }
    while (!B.isEmpty())
    {
        B.removeFirst();
    }

    return C;
}

Set my_subtract(Set A, Set B)
{
    Set C;
    C.initialize();
    while (!A.isEmpty() & !B.isEmpty())
    {
        int a = A.get(1);
        int b = B.get(1);

        if (a < b)
        {
            C.addLast(a);
            A.removeFirst();
        }
        else if (a > b)
        {
            B.removeFirst();
        }
        else
        {
            A.removeFirst();
            B.removeFirst();
        }
    }

    while (!A.isEmpty())
    {
        int a = A.get(1);
        C.addLast(a);
        A.removeFirst();
    }
    while (!B.isEmpty())
    {
        B.removeFirst();
    }

    return C;
}

void test_set_subtract()
{
    Set A, B;
    A.initialize();
    B.initialize();

    A.addElem(1);
    A.addElem(2);
    A.addElem(3);
    A.addElem(4);

    printf("A: ");
    A.traverse();

    B.addElem(3);
    B.addElem(4);
    printf("B: ");
    B.traverse();

    Set C = my_subtract(A, B);
    C.traverse();
}

void test_set_intersect()
{
    Set A, B;
    A.initialize();
    B.initialize();

    A.addElem(1);
    A.addElem(2);
    A.addElem(3);
    A.addElem(4);

    printf("A: ");
    A.traverse();

    B.addElem(3);
    B.addElem(4);
    printf("B: ");
    B.traverse();

    Set C = my_intersect(A, B);
    C.traverse();
}

void test_set_union()
{
    Set A, B;
    A.initialize();
    B.initialize();

    A.addElem(1);
    A.addElem(2);
    printf("A: ");
    A.traverse();

    B.addElem(3);
    B.addElem(4);
    printf("B: ");
    B.traverse();
    printf("Set c : ");
    Set C = my_union(A, B);
    C.traverse();
    printf("순회 완료\n");
}

void test_set_subset()
{
    Set A, B;
    A.initialize();
    B.initialize();

    A.addElem(1);
    A.addElem(2);
    printf("A: ");
    A.traverse();

    B.addElem(1);
    B.addElem(2);
    B.addElem(3);
    B.addElem(4);
    printf("B: ");
    B.traverse();

    int ret = A.subset(B);
    if (ret == 1)
        printf("A < B\n");
    else
        printf("A </ B\n");
}

int main()
{
    // test1();
    // test_set_union();
    // test_set_intersect();
    test_set_subtract();
    test_set_subset();
}