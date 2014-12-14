#include<iostream>
#include<cstdlib>
using namespace std;
struct osoba
{
    char ime[20],prezime[20];
    char spol[2];
    int dan, mj, god;
    int ai, bi, ci, di;
};
struct qu
{
    osoba value;
    qu *sljedeci;
};
struct que
{
    qu *front, *rear;
};
que *InitQ(que *Q)
{
    Q = new que;
    qu *novi = new qu;
    novi->sljedeci = NULL;
    Q->front = novi;
    Q->rear = novi;
    return Q;
}
bool IsEmptyQ(que *Q)
{
    return Q->front == Q->rear;
}
osoba FrontQ(que *Q)
{
    if(IsEmptyQ(Q)) cout << "Red je prazan!\n";
    else return Q->front->sljedeci->value;
}
void EnQueueQ(osoba x, que *Q)
{
    qu *novi = new qu;
    novi->value = x;
    novi->sljedeci = NULL;
    Q->rear->sljedeci = novi;
    Q->rear = novi;
}
void DeQueueQ(que *Q)
{
    if(IsEmptyQ(Q)) cout << "Red je prazan!\n";
    else
    {
        qu *brisi = Q->front;
        Q->front = Q->front->sljedeci;
        delete brisi;
    }
}
