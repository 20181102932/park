#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print()
{
    for(int i=0;i<60;i++)
    {
        printf("*");
    }
    printf("\n");
}
struct car
{
    char ad;
    int card;
    int arrivetime;
    int departuretime;
    
};
struct stopcar  //Õ£≥µ≥°
{
    struct car *Data;
    int MaxSize;
    int top;
};
struct testopcar //¡Ÿ ±Õ£≥µ≥°
{
    struct car *Data;
    int MaxSize;
    int top1;
};
struct Node
{
    struct car Data;
    struct Node *next;
};
struct QNode  //∂”¡–
{
    struct Node *front,*rear;
};
struct stopcar *create(int MaxSize)    //¥¥Ω®ø’µƒÕ£≥µ≥°’ª
{
    struct stopcar *S;
    S=(struct stopcar*)malloc(sizeof(struct stopcar));
    S->Data=(struct car*)malloc(MaxSize*sizeof(struct car));
    S->MaxSize=MaxSize;
    S->top=-1;
    return S;
}
struct testopcar *createtestop(int MaxSize) //¥¥Ω®ø’µƒ¡Ÿ ±’ª
{
    struct testopcar *S;
    S=(struct testopcar*)malloc(sizeof(struct stopcar));
    S->Data=(struct car*)malloc(MaxSize*sizeof(struct car));
    S->MaxSize=MaxSize;
    S->top1=-1;
    return S;
}
struct QNode *createQ()    //¥¥Ω®“ª∏ˆø’∂”¡–
{
    struct QNode * Q;
    Q=(struct QNode *)malloc(sizeof(struct QNode ));
    Q->front=Q->rear=(struct Node *)malloc(sizeof(struct Node ));
    Q->front=Q->rear=NULL;
    return Q;
}
void addQ(struct QNode *Q,char ad,int card,int arrivetime)
{
    struct Node *p;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->Data.ad=ad;
    p->Data.card=card;
    p->Data.arrivetime=arrivetime;
    p->next=NULL;
    if(Q->front==NULL)
    {
        Q->front=Q->rear=p;
    }
    else
    {
        Q->rear->next=p;
        Q->rear=Q->rear->next;
    }
    printf("≥µ≈∆∫≈Œ™%dµƒ≥µ¡æ“—æ≠Õ£»Î±„µ¿\n",Q->rear->Data.card);
}
void add(struct stopcar *S,struct QNode *Q,char ad,int card,int arrivetime)
{
    if(S->top==S->MaxSize-1)
    {
        print();
        printf("Õ£≥µ≥°“—¬˙£°«ÎÕ£»Î±„µ¿£¨∏––ªƒ˙µƒ≈‰∫œ£°\n\n");
        addQ(Q, ad, card, arrivetime);
        return;
    }
    else
    {
        int i=++S->top;
        S->Data[i].ad=ad;
        S->Data[i].card=card;
        S->Data[i].arrivetime=arrivetime;
        printf("ƒ˙µƒ≥µ“—æ≠Õ£»Î%d∫≈Õ£≥µŒª\n",S->top+1);
    }
}
void DeleteQ(struct stopcar *S,struct QNode *Q,int arrivetime)
{
    int i=++S->top;
    S->Data[i].ad=Q->front->Data.ad;
    S->Data[i].card=Q->front->Data.card;
    S->Data[i].arrivetime=arrivetime;
    Q->front=Q->front->next;
    printf("π˝µ¿µƒµ⁄“ª¡æ≥µ“—æ≠Ω¯»ÎÕ£≥µ≥°\n");
    print();
}
void depart(struct stopcar *S,struct testopcar *S1,struct QNode *Q,char ad,int card,int  departuretime )
{
    int i=0;
    while(i<=S->top)
    {
        if(S->Data[i].card==card)
        {
            break;
        }
        i++;
    }
    S->Data[i].departuretime=departuretime;
    while(S->top>i)
    {
        S1->Data[++S1->top1]=S->Data[S->top--];
    }
    int k=S->top--;
    print();
    printf("≥µ≈∆Œ™%dµƒ≥µ¡æÕ£≥µ ±º‰Œ™%d∑÷÷”,”¶Ω…ƒ…∑—”√%d\n",S->Data[k].card,S->Data[k].departuretime-S->Data[k].arrivetime,2*(S->Data[k].departuretime-S->Data[k].arrivetime));
    print();
    while(S1->top1>=0)
    {
        S->Data[++S->top]=S1->Data[S1->top1--];
    }
    if(Q->front!=NULL)
        DeleteQ(S,Q,departuretime);
}
int main()
{
    print();
    printf("«Î ‰»ÎÕ£≥µ≥°µƒ◊Ó¥ÛÕ£≥µ ˝¡ø:\n");
    int number;
    scanf("%d",&number);
    print();
    getchar();
    struct stopcar *S;
    struct testopcar *S1;
    struct QNode *Q;
    S=create(number);
    S1=createtestop(number);
    Q=createQ();
    char ad;
    int card;
    int time;
    printf("Õ£≥µ≥°ø™ ºπ§◊˜£¨ø…“‘»Î≥°Õ£≥µ£°\n");
    print();
    while(1)
    {
        scanf("%c %d %d",&ad,&card,&time);
        getchar();
        if(ad=='E')
        {
            break;
        }
        if(ad=='A')
        {
            add(S,Q,ad,card,time);
        }
        if(ad=='D')
        {
            depart(S,S1,Q,ad,card,time);
        }
    }
    printf(" «∑Ò–Ë“™≤Èø¥Õ£≥µ≥°µƒÕ£≥µ–≈œ¢:\n");
    char sf[10];
    scanf("%s",sf);
    if(strcmp(sf," «")==0)
    {
        for(int i=0;i<=S->top;i++)
        {
            printf("%d∫≈Õ£≥µŒªµƒ–≈œ¢Œ™:\n",i+1);
            printf("≥µ≈∆∫≈Œ™:  %d Ω¯»ÎÕ£≥µ≥°µƒ ±º‰Œ™Œ™:  %d \n",S->Data[i].card,S->Data[i].arrivetime);
            print();
        }
    }
    printf(" «∑Ò–Ë“™≤Èø¥π˝µ¿µƒÕ£≥µœ˚œ¢œ˚œ¢\n");
    char sf1[10];
    scanf("%s",sf1);
    if(strcmp(sf1," «")==0)
    {
        if(Q->front==NULL)
        {
            printf("π˝µ¿√ª”–¥Ì≥µ¡æ\n");
        }
        while(Q->front!=NULL)
        {
            int i=0;
            printf("π˝µ¿÷–µ⁄%d¡æ≥µµƒ–≈œ¢Œ™:\n",i+1);
            printf("≥µ≈∆∫≈Œ™:%d Ω¯»Îπ˝µ¿µƒ ±º‰Œ™Œ™:%d \n",Q->front->Data.card,Q->front->Data.arrivetime);
            Q->front=Q->front->next;
            i++;
        }
    }
    return 0;
}


