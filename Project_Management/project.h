#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#include "index.h"


void createListProj(ListProj &L);
void createElmProj(addrProj &P, string judul, string deadline, string difficulty);
void insertFirstProj(ListProj &L, addrProj P);
void insertAfterProj(ListProj &L, addrProj Prec, addrProj P);
void insertLastProj(ListProj &L, addrProj &P);
void updateDataProj(ListProj &L);

void deleteFirstProj(ListProj &L, addrProj &P);
void deleteAfterProj(addrProj Prec, addrProj &P);
void deleteLastProj(ListProj &L, addrProj &P);
void deleteProject(ListProj &L, ListRelasi &LR);

addrProj searchProj(ListProj L, string nmProj);
void viewDataProj(ListProj L);






#endif // PROJECT_H_INCLUDED
