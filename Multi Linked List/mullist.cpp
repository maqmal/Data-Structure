#include "header.h"
adrN createNovel(int id, string judul){
    adrN N = new Novel;
    judul(N) = judul;
    id(N) = id;
    next(N) = NULL;
    return N;
}

adrP createPenulis(int id, string nama, string role){
    adrP P = new Penulis;
    nama(P) = nama;
    id(P) = id;
    role(P) = role;
    next(P) = NULL;
    return P;
}

adrR createRelasi(adrN N, adrP P){
    adrR R = new Relasi;
    next(R) = NULL;
    parent(R) = N;
    child(R) = P;
    return R;
}

void createListNovel(ListN &N){
    first(N) = NULL;
    last(N) = NULL;
}

void createListPenulis(ListP &P){
    first(P) = NULL;
    last(P) = NULL;
}

void createListRelasi(ListR &R){
    first(R) = NULL;
    last(R) = NULL;
}

void addRelasi(adrN Novel, adrP Penulis, adrR R,ListR &ListRelasi, ListN &ListNovel, ListP &ListPenulis){
    string judul,nama;
    cout<<"Judul Novel : ";
    cin>>judul;cout<<endl;
    cout<<"Nama Penulis : ";
    cin>>nama;cout<<endl;
    Penulis = findPenulisByName(ListPenulis, nama);
    Novel = findNovelByJudul(ListNovel, judul);
    if (Penulis==NULL || Novel==NULL){
        cout<<"Data Not Found"<<endl;
    }else{
        R = createRelasi(Novel,Penulis);
        if (first(ListRelasi)==NULL){
            first(ListRelasi) = R;
            last(ListRelasi) = R;
            next(R) = NULL;
        }else{
            next(R) = first(ListRelasi);
            first(ListRelasi) = R;
        }
        parent(R) = Novel;
        child(R) = Penulis;
    }
}

void addNovel(adrN Novel, ListN &ListNovel){
    string judul;
    int id;
    cout<<"==============="<<endl;
    cout<<"Insert Judul Novel : ";
    cin>>judul;
    cout<<endl;
    cout<<"ID : ";
    cin>>id;cout<<endl;
    Novel = createNovel(id,judul);
    insertNovel(Novel, ListNovel);
}

void addPenulis(adrP Penulis, ListP &ListPenulis){
    string nama, role;
    int id;
    cout<<"==============="<<endl;
    cout<<"Insert Nama Penulis : ";
    cin>>nama;cout<<endl;
    cout<<"Insert Role : ";
    cin>>role;cout<<endl;
    cout<<"Insert ID (UNIQUE) : ";
    cin>>id;cout<<endl;
    Penulis = createPenulis(id, nama, role );
    insertPenulis(Penulis, ListPenulis);
}

void insertNovel(adrN N,ListN &L){
    if (first(L)==NULL){
        first(L) = N;
        last(L) = N;
        next(N) = NULL;
    }else{
        next(N) = first(L);
        first(L) = N;
    }
}

void insertPenulis(adrP P,ListP &N){
    if (first(N)==NULL){
        first(N) = P;
        last(N) = P;
        next(P) = NULL;
    }else{
        next(P) = first(N);
        first(N) = P;
    }
}

adrP findPenulisByName(ListP P,string name){
    adrP Q = first(P);
    while (Q != NULL && nama(Q) != name) {
        Q = next(Q);
    }
    return Q;
}

adrP findPenulisByID(ListP P,int ID){
    adrP Q = first(P);
    while (Q != NULL && id(Q) != ID) {
        Q = next(Q);
    }
    return Q;
}

adrP findPrevPenulis(ListP P,adrP cur){
    adrP Q = first(P);
    while (Q != NULL && next(Q) != cur) {
        Q = next(Q);
    }
    return Q;
}

adrN findPrevNovel(ListN P,adrN cur){
    adrN Q = first(P);
    while (Q != NULL && next(Q) != cur) {
        Q = next(Q);
    }
    return Q;
}

adrN findNovelByJudul(ListN P,string judul){
    adrN Q = first(P);
    while (Q != NULL && judul(Q) != judul) {
        Q = next(Q);
    }
    return Q;
}

void deleteNovelByJudul(ListN &P,string judul){
    adrN Novel = findNovelByJudul(P, judul);
    if(Novel == first(P)){
        first(P) = next(Novel);
        Novel = NULL;
    }else if(Novel == last(P)){
        last(P) = findPrevNovel(P, Novel);
        next(last(P)) = NULL;
        Novel = NULL;
    }else{
        adrN prev = findPrevNovel(P, Novel);
        next(prev) = next(Novel);
        Novel = NULL;
    }
}

void deletePenulisByName(ListP &P, string name){
    adrP Penulis = findPenulisByName(P, name);
    if(Penulis == first(P)){
        first(P) = next(Penulis);
        next(Penulis) = NULL;
    }else if(Penulis == last(P)){
        last(P) = findPrevPenulis(P, Penulis);
        next(last(P)) = NULL;
        next(Penulis) = NULL;
    }else{
        adrP prev = findPrevPenulis(P, Penulis);
        next(prev) = next(Penulis);
        next(Penulis) = NULL;
    }
}

void deleteNovel(ListN &ListNovel, ListR &ListRelasi){
    string judul;
    cout<<"Delete Judul : ";
    cin>>judul;cout<<endl;
    DeleteRelasiNovel(ListNovel, ListRelasi, judul);
    deleteNovelByJudul(ListNovel, judul);
}

void deletePenulis(ListP &ListPenulis, ListR &ListRelasi){
    string nama;
    cout<<"Delete Nama Penulis : ";
    cin>>nama;cout<<endl;
    DeleteRelasiPenulis(ListPenulis,ListRelasi, nama);
    deletePenulisByName(ListPenulis, nama);
}

void ShowPenulis(ListP L){
    adrP P = first(L);
    while (P!=NULL){
        cout<<"========================="<<endl;
        cout<<"         PENULIS "<<endl;
        cout<<"ID : "<<id(P)<<endl;
        cout<<"Nama : "<<nama(P)<<endl;
        cout<<"Role : "<<role(P)<<endl;
        cout<<"========================="<<endl;
        P = next(P);
    }
}

void ShowNovel(ListN L){
    adrN P;
    P = first(L);
    while (P!=NULL){
        cout<<"========================="<<endl;
        cout<<"       JUDUL NOVEL "<<endl;
        cout<<"ID : "<<id(P)<<endl;
        cout<<"Judul : "<<judul(P)<<endl;
        cout<<"========================="<<endl;
        P = next(P);
    }
}

adrR findPrevRelasi(ListR &R, adrR cur){
    adrR Q = first(R);
    while (Q != NULL && next(Q) != cur ) {
        Q = next(Q);
    }
    return Q;
}

adrR findRelasiPenulis(ListR &R, string nama){
    adrR Q = first(R);
    while (Q != NULL && nama(child(Q)) != nama) {
        Q = next(Q);
    }
    return Q;
}

adrR findRelasiNovel(ListR &R, string judul){
    adrR Q = first(R);
    while (Q != NULL && judul(parent(Q)) != judul) {
        Q = next(Q);
    }
    return Q;
}

void DeleteRelasiNovel(ListN &ListNovel, ListR &ListRelasi, string judul){
    adrR R = first(ListRelasi);
    adrN Novel = findNovelByJudul(ListNovel, judul);
    while (R!=NULL){
        if (parent(R)== Novel){
            if(Novel == parent(first(ListRelasi))){
                first(ListRelasi) = next(R);
                next(R) = NULL;
            }else if(Novel == parent(last(ListRelasi))){
                adrR prev = findPrevRelasi(ListRelasi, R);
                last(ListRelasi) = prev;
                next(R) = NULL;
                next(last(ListRelasi)) = NULL;
            }else{
                adrR prev = findPrevRelasi(ListRelasi, R);
                next(prev) = next(R);
                next(R) = NULL;
            }
        }
        R = next(R);
    }
}

void DeleteRelasiPenulis(ListP &ListPenulis, ListR &ListRelasi, string namaPenulis){
    adrR R = first(ListRelasi);
    adrP Penulis = findPenulisByName(ListPenulis, namaPenulis);
    while (R!=NULL){
        if (child(R)== Penulis){
            if(Penulis == child(first(ListRelasi))){
                first(ListRelasi) = next(R);
                next(R) = NULL;
            }else if(Penulis == child(last(ListRelasi))){
                adrR prev = findPrevRelasi(ListRelasi, R);
                last(ListRelasi) = prev;
                next(R) = NULL;
                next(last(ListRelasi)) = NULL;
            }else{
                adrR prev = findPrevRelasi(ListRelasi, R);
                next(prev) = next(R);
                next(R) = NULL;
            }
        }
        R = next(R);
    }
}

void ShowRelasi(ListR ListRelasi, ListN N, ListP P){
    adrR Relasi = first(ListRelasi);
    while (Relasi!=NULL){
        cout<<"=========================================="<<endl;
        cout<<"                 PIVOT "<<endl;
        cout<<"Novel :  "<<judul(parent(Relasi))<<endl;
        cout<<"Penulis : "<<nama(child(Relasi))<<" - "<<role(child(Relasi))<<endl;
        cout<<"=========================================="<<endl;
        Relasi = next(Relasi);
    }
}
