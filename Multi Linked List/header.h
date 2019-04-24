#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string>
#include <iostream>
#include <cstdlib>

#define next(P) P->next
#define parent(P) P->parent
#define child(P) P->child
#define first(L) L.first
#define last(L) L.last
#define judul(N) N->judul
#define id(N) N->id
#define nama(P) P->nama
#define role(P) P->role

using namespace std;
typedef struct Penulis *adrP;
typedef struct Novel *adrN;
typedef struct Relasi *adrR;

struct Penulis{
    int id;
    string nama;
    string role;
    adrP next;
};
struct Relasi{
    adrR next;
    adrN parent;
    adrP child;
};
struct Novel{
    int id;
    string judul;
    adrN next;
};
struct ListR{
    adrR first;
    adrR last;
};
struct ListP{
    adrP first;
    adrP last;
};
struct ListN{
    adrN first;
    adrN last;
};
adrN createNovel(int id, string judul);
adrP createPenulis(int id, string nama, string role);
adrR createRelasi(adrN N, adrP P);
void addRelasi(adrN Novel, adrP Penulis, adrR R,ListR &ListRelasi, ListN &ListNovel, ListP &ListPenulis);
void createListNovel(ListN &N);
void createListPenulis(ListP &P);
void createListRelasi(ListR &R);
void addNovel(adrN Novel, ListN &ListNovel);
void addPenulis(adrP Penulis, ListP &ListPenulis);
void insertNovel(adrN N,ListN &L);
void insertPenulis(adrP P, ListP &N);


adrP findPenulisByName(ListP P,string name);
adrP findPenulisByID(ListP P,int ID);
adrN findNovelByJudul(ListN P,string judul);


adrP findPrevPenulis(ListP P,adrP cur);
adrN findPrevNovel(ListN P,adrN cur);


void deleteNovelByJudul(ListN &P,string judul);
void deletePenulisByName(ListP &P, string name);


adrR findRelasiPenulis(ListR &R, string nama);
adrR findRelasiNovel(ListR &R, string judul);
adrR findPrevRelasi(ListR &R, adrR cur);


void deleteNovel(ListN &ListNovel, ListR &ListRelasi);
void DeleteRelasiNovel(ListN &ListNovel, ListR &ListRelasi, string judul);
void deletePenulis(ListP &ListPenulis,ListR &ListRelasi);
void DeleteRelasiPenulis(ListP &ListPenulis, ListR &ListRelasi, string namaPenulis);


void ShowRelasi(ListR ListRelasi, ListN N, ListP P);
void ShowPenulis(ListP L);
void ShowNovel(ListN L);
#endif // HEADER_H_INCLUDED
