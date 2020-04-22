#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "index.h"

void createList(ListRelasi &L);
int generateID();
void createElmRes(address &P, addrProg programmer, addrProj project);
void insertFirst(ListRelasi &L, address P);
void insertLast(ListRelasi &L, address &P);

address searchTugas(ListRelasi L, addrProg Prog, addrProj Proj);
address searchRelasiProj(ListRelasi L, addrProj Proj);
address searchRelasiProg(ListRelasi L, addrProg Prog);
void updateStatus(ListRelasi &L, ListProg &LProg, ListProj &LProj);

void deleteFirst(ListRelasi &L, address &P);
void deleteAfter(address Prec, address &P);
void deleteLast(ListRelasi &L, address &P);

void viewData(ListRelasi L);
void viewTaskForProg(ListProg LP, ListProj LPJ, ListRelasi LR);
void viewTaskForProj(ListProg LP, ListProj LPJ, ListRelasi LR);
void viewAllProgTask(ListRelasi LR, ListProg LP);
void viewAllProjTask(ListRelasi LR, ListProj LPJ);


#endif // RELASI_H_INCLUDED
