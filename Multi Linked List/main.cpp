#include <iostream>
#include "mullist.cpp"
using namespace std;
int main()
{
    adrN N;
    adrP P;
    adrR R;
    ListP ListPenulis;
    ListN ListNovel;
    ListR ListRelasi;
    createListNovel(ListNovel);
    createListPenulis(ListPenulis);
    createListRelasi(ListRelasi);
    bool statusLoop = true;
    while (statusLoop) {
        cout<<"===================="<<endl;
        cout<<"1. Add Penulis"<<endl;
        cout<<"2. Add Novel"<<endl;
        cout<<"3. Add Relasi"<<endl;
        cout<<"4. Delete Penulis"<<endl;
        cout<<"5. Delete Novel"<<endl;
        cout<<"6. Tampilkan"<<endl;
        cout<<"====================="<<endl;
        cout<<"Choose : ";
        int pil;
        cin>>pil;
        switch (pil)
        {
            case 1:
                system("CLS");
                addPenulis(P, ListPenulis);
                cin;
                break;

            case 2:
                system("CLS");
                addNovel(N, ListNovel);
                cin;
                break;

            case 3:
                addRelasi(N, P, R, ListRelasi, ListNovel, ListPenulis);
                cin;
                break;

            case 4:
                deletePenulis(ListPenulis,ListRelasi);
                cin;
                break;

            case 5:
                deleteNovel(ListNovel,ListRelasi);
                cin;
                break;

            case 6:
                system("CLS");
                ShowNovel(ListNovel);
                ShowPenulis(ListPenulis);
                cout<<"==================RELASI=================="<<endl;
                ShowRelasi(ListRelasi, ListNovel, ListPenulis);
                cin;
                break;

            case 99:
                statusLoop = false;
                break;
        }
    }
    return 0;
}
