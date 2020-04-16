#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial Link;
};

void PrintPoly(Polynomial P)
{
    Polynomial Temp = P;

    printf("f(x) = ");
    if (!P)
        printf(" 0 ");
    while (Temp->Link != NULL)
    {
        printf("%dx^%d ",Temp->coef,Temp->expon);
        Temp = Temp->Link;
        if (Temp->coef > 0)
            printf("+");
    }
    printf("%dx^%d",Temp->coef,Temp->expon);
}

int main()
{
    Polynomial Head, Tail, Poly;
    Head = (Polynomial)malloc(sizeof(struct PolyNode)); //©ум╥╫з╣Ц
    Tail = Head;
    for (int i=-9; i<0; i++)
    {
        Tail->Link = (Polynomial)malloc(sizeof(struct PolyNode));
        Tail = Tail->Link;
        Tail->coef = Tail->expon = i;
    }
    Tail->Link =NULL;
    Poly = Head->Link;
    free(Head);

    PrintPoly(Poly);
    return 0;
}
