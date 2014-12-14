#include<iostream>
#include<cstdlib>
using namespace std;
struct osoba{
 char ime[20],prezime[20];
    char spol[2];
    int dan, mj, god;
    int ai, bi, ci, di;
};
struct que{
osoba osobe[10000];
int front, rear;
};
int AddOne(int n){
return ((n+1)%10000);
}
que *InitQ(que *Q){
Q = new que;
Q->front = 0;
Q->rear = 9999;
return Q;
}
bool IsEmptyQ(que *Q){

if(AddOne(Q->rear) == Q->front) return true;
else return false;
}
osoba FrontQ(que *Q){
if(IsEmptyQ(Q)) cout << "Red je prazan!\n";
else return Q->osobe[Q->front];
}
void EnQueueQ(osoba x, que *Q){
int n;
if(Q->rear==9999) n=0;
else n = Q->rear+1;
Q->osobe[n] = x;
Q->rear = n;
}
void DeQueueQ(que *Q){
if(IsEmptyQ(Q)) cout << "Red je prazan!\n";
else {
if(Q->front==9999) Q->front=0;
else Q->front++;
}
}
