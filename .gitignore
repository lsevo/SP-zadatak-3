#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
//#include "red_pokazivac.h"
#include "red_polje.h"
using namespace std;
osoba *cetvorke;
//zadatak 3.a
void prioritet(int ci)
{
    cout<<"\tci: ";
    switch(ci)
    {
    case 1:
        cout<<"VIP klijent"<<endl;
        break;
    case 2:
        cout<<"invalid"<<endl;
        break;
    case 3:
        cout<<"trudnice"<<endl;
        break;
    case 4:
        cout<<"umirovljenici"<<endl;
        break;
    case 5:
        cout<<"ostali klijenti"<<endl;
        break;
    }
}
void vrsta_usluge(int di)
{
    cout<<"\tdi: ";
    switch(di)
    {
    case 1:
        cout<<"predaja/preuzimanje pošiljke"<<endl;
        break;
    case 2:
        cout<<"plaćanje računa"<<endl;
        break;
    case 3:
        cout<<"uplata lutrije"<<endl;
        break;
    case 4:
        cout<<"Western Union"<<endl;
        break;
    case 5:
        cout<<"Evotv"<<endl;
        break;
    }
}
void cetvorke_ispis(int ai,int bi,int ci,int di)
{
    cout<<"\tai: "<<ai<<endl;
    cout<<"\tbi: "<<bi<<endl;
    prioritet(ci);
    vrsta_usluge(di);
}
void generirat_N(int N)
{
    cetvorke=new osoba[N];
    for(int i=0; i<N; i++)
    {
        rand();
        cetvorke[i].ai=rand()%491+10;
        cetvorke[i].bi=rand()%721+80;
        cetvorke[i].ci=rand()%5+1;
        cetvorke[i].di=rand()%5+1;
        cout<<"Kombinacija br: "<<i+1<<endl;
        cetvorke_ispis(cetvorke[i].ai,cetvorke[i].bi,cetvorke[i].ci,cetvorke[i].di);
    }
}//kraj 3.a zadatka

//zadatak 3.b
void dodaj_pocetak(osoba o,que* red)
{
    que *Pomocni=InitQ(Pomocni);
    EnQueueQ(o,Pomocni);
    osoba tmp;
    while(!IsEmptyQ(red))
    {
        tmp=FrontQ(red);
        DeQueueQ(red);
        EnQueueQ(tmp,Pomocni);
    }
    while(!IsEmptyQ(Pomocni))
    {
        tmp=FrontQ(Pomocni);
        DeQueueQ(Pomocni);
        EnQueueQ(tmp,red);
    }
}
void dodaj_ispred(osoba o,que* red)
{
    que *Pomocni=InitQ(Pomocni);
    osoba tmp;
    int dodano=0;
    while(!IsEmptyQ(red))
    {
        if(tmp.ci!=o.ci) break;
        tmp=FrontQ(red);
        DeQueueQ(red);
        EnQueueQ(tmp,Pomocni);
    }
    EnQueueQ(o,Pomocni);
    while(!IsEmptyQ(red))
    {
        tmp=FrontQ(red);
        DeQueueQ(red);
        EnQueueQ(tmp,Pomocni);
    }
    while(!IsEmptyQ(Pomocni))
    {
        tmp=FrontQ(Pomocni);
        DeQueueQ(Pomocni);
        EnQueueQ(tmp,red);
    }
}

void dodavanje_zapisa(que* red,int n)
{
    char m_ime[5][20]= {"Ivan","Marko","Luka","Petar","Sasa"};
    char z_ime[5][20]= {"Ivana","Nikolina","Ivka","Maja","Ana"};
    char prezime[5][20]= {"Milic","Slavuj","Grdic","Kitic","Hrgovic"};
    char spol[2][2]= {"m","z"};
    for(int i=0; i<n; i++)
    {
        cout<<"Kombinacija br: "<<i+1<<endl;
        cetvorke_ispis(cetvorke[i].ai,cetvorke[i].bi,cetvorke[i].ci,cetvorke[i].di);
        osoba dodaj;
        int j=0;
        for(j=0; j<5; j++)
        {
            rand();
            dodaj.ai=cetvorke[i].ai;
            dodaj.bi=cetvorke[i].bi;
            dodaj.ci=cetvorke[i].ci;
            dodaj.di=cetvorke[i].di;
            strcpy(dodaj.prezime,prezime[rand()%5]);
            if(dodaj.ci==3) strcpy(dodaj.spol,spol[1]);
            else strcpy(dodaj.spol,spol[rand()%2]);
            if(strcmp(dodaj.spol,"z")==0) strcpy(dodaj.ime,z_ime[rand()%5]);
            else strcpy(dodaj.ime,m_ime[rand()%5]);
            dodaj.mj=rand()%12+1;
            dodaj.dan=rand()%31+1;
            if(dodaj.ci==4) dodaj.god=rand()%20+1940;
            else if(dodaj.ci==3 ) dodaj.god=rand()%24+1975;
            else dodaj.god=rand()%55+1960;

            if(dodaj.ci<FrontQ(red).ci) dodaj_pocetak(dodaj,red);
            else if(dodaj.ci==FrontQ(red).ci) dodaj_ispred(dodaj,red);
            else EnQueueQ(dodaj,red);
        }
        cout<<"Izgenerirano je: "<<j<<" osoba za "<<i+1<<" kombinaciju"<<endl;
    }
}
bool provjera_jarca(osoba o)
{
    if((o.dan>=22 && o.mj==12) || (o.dan<=20 && o.mj==1) && o.di==3 && (2014-o.god)<40) return true;
    else return false;
}
void ispis_jarca(que* red)
{
    que *Pomocni=InitQ(Pomocni);
    osoba tmp;
    bool postoji=false;
    cout<<"Ispis osoba koji su jarac, mladi od 40 i cekaju da uplate lutriju"<<endl;
    while(!IsEmptyQ(red))
    {
        tmp=FrontQ(red);
        if(provjera_jarca(tmp))
        {
            cout<<"Ime i prezime: "<<tmp.ime<<" "<<tmp.prezime<<endl;
            cout<<"Spol: "<<tmp.spol<<endl;
            cout<<"Datum rod: "<<tmp.dan<<"."<<tmp.mj<<"."<<tmp.god<<endl;
            postoji=true;
        }
        DeQueueQ(red);
        EnQueueQ(tmp,Pomocni);
    }
    while(!IsEmptyQ(Pomocni))
    {
        tmp=FrontQ(Pomocni);
        DeQueueQ(Pomocni);
        EnQueueQ(tmp,red);
    }
    if(!postoji) cout<<"Nema takve osobe u redu"<<endl;
}// kraj 3.b zadatka

// zadatak 3.c
void trudnice_odlazak(que* red)
{
    que *Pomocni=InitQ(Pomocni);
    osoba tmp;
    while(!IsEmptyQ(red))
    {
        tmp=FrontQ(red);
        DeQueueQ(red);
        if(tmp.ci!=3 || tmp.di!=5) EnQueueQ(tmp,Pomocni);
    }
    while(!IsEmptyQ(Pomocni))
    {
        tmp=FrontQ(Pomocni);
        DeQueueQ(Pomocni);
        EnQueueQ(tmp,red);
    }
}//kraj zadatka 3.c
void ispis_reda(que* red,int N)
{
    que *Pomocni=InitQ(Pomocni);
    osoba tmp;
    int br=1;
    while(!IsEmptyQ(red))
    {
        tmp=FrontQ(red);
        cout<<"Osoba br: "<<br<<endl;
        cout<<"\tIme i prezime: "<<tmp.ime<<" "<<tmp.prezime<<endl;
        cout<<"\tSpol: "<<tmp.spol<<endl;
        cout<<"\tDatum rod: "<<tmp.dan<<"."<<tmp.mj<<"."<<tmp.god<<endl;
        cetvorke_ispis(tmp.ai,tmp.bi,tmp.ci,tmp.di);
        cout<<endl;
        DeQueueQ(red);
        EnQueueQ(tmp,Pomocni);
        br++;
    }
    while(!IsEmptyQ(Pomocni))
    {
        tmp=FrontQ(Pomocni);
        DeQueueQ(Pomocni);
        EnQueueQ(tmp,red);
    }
}
void izbrisi(que* red)
{
    while(!IsEmptyQ(red)) DeQueueQ(red);
}
int main()
{
    srand(time(NULL));
    rand();
    que *red=InitQ(red);

    int izbor;
    do
    {
        cout<<"IZBORNIK"<<endl;
        cout<<"1. Generiranje N cetvorki"<<endl;
        cout<<"2. Generiranje 5 osoba za svaku kombinaciju"<<endl;
        cout<<"3. Odlazak trudnica koje su se dosle raspitati o EvoTV usluzi"<<endl;
        cout<<"4. Ispis primarnog reda"<<endl;
        cout<<"5. Izbrisi red"<<endl;
        cout<<"9. Izlaz iz programa"<<endl;
        cout<<"Unesi svoj izbor: ";
        cin>>izbor;
        switch(izbor)
        {
        case 1:
            cout<<"Kolko N cetvorki zelis izgenerirat: ";
            int N;
            cin>>N;
            generirat_N(N);
            break;
        case 2:
            if(N==0) break;
            dodavanje_zapisa(red,N);
            ispis_jarca(red);
            break;
        case 3:
            if(IsEmptyQ(red)==true) cout<<"Red je prazan"<<endl;
            trudnice_odlazak(red);
            ispis_reda(red,N);
            break;
        case 5:
            if(IsEmptyQ(red)==true) cout<<"Red je prazan"<<endl;
            izbrisi(red);
            break;
        case 4:
            if(IsEmptyQ(red)==true) cout<<"Red je prazan"<<endl;
            ispis_reda(red,N);
            break;
        }
    }
    while(izbor!=9);
    return 0;
}
