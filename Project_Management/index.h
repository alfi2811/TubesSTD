#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define info(P) P->info
#define prev(P) P->prev
#define next(P) P->next
#define last(L) L.last

using namespace std;

typedef struct elmListProg *addrProg;
typedef struct elmListProj *addrProj;
typedef struct elmListRes *address;

struct Programmer{
    string user;
    string pass;
    string nama;
    int total_tugas;
    string notelp;
};
struct Project{
    string judul;
    string deadline;
    string difficulty;
};
struct Relasi{
    int id;
    addrProg programmer;
    addrProj project;
    string status;
};


struct elmListProg{
    Programmer info;
    addrProg next;
};
struct elmListProj{
    Project info;
    addrProj next;
};
struct elmListRes{
    Relasi info;
    address next;
    address prev;
};


struct ListProg{
     addrProg first;
     addrProg last;
};
struct ListProj{
     addrProj first;
     addrProj last;
};
struct ListRelasi{
     address first;
};
void loadData(ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void Home(string msg, ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void login(ListProg &LP, ListProj &LPJ, ListRelasi &LR, string msg);
void regis(string &msg);
bool searchDataUser(string user, string pass, string lvl);
void loginProgrammer(string user, string pass);
void menuAdmin(ListProg &LP, ListProj &LPJ, ListRelasi &LR, string msg);
void menuDataProj(ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void menuDataProg(ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void insertDataProg(ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void insertDataProj(ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void menuManager(ListProg &LP, ListProj &LPJ, ListRelasi &LR);
void insertPenugasan(ListProg &LP, ListProj &LPJ, ListRelasi &LR);

void deleteTugasProject(ListRelasi &L, addrProj Proj);
void deleteTugasProgrammer(ListRelasi &L, addrProg Prog);

#endif // INDEX_H_INCLUDED
