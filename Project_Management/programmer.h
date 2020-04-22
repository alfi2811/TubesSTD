#ifndef PROGRAMMER_H_INCLUDED
#define PROGRAMMER_H_INCLUDED

#include <iostream>
#include "index.h"

void createListProg(ListProg &L);
void createElmProg(addrProg &P, string user, string pass, string nama, string notelp);
void insertFirstProg(ListProg &L, addrProg P);
void insertAfterProg(ListProg &L, addrProg Prec, addrProg P);
void insertLastProg(ListProg &L, addrProg &P);
void insertProgrammer(ListProg &L, addrProg P);
void updateDataProg(ListProg &L);

void deleteFirstProg(ListProg &L, addrProg &P);
void deleteAfterProg(ListProg &L, addrProg Prec, addrProg &P);
void deleteLastProg(ListProg &L, addrProg &P);
void deleteProgrammer(ListProg &L, ListRelasi &LR);

addrProg searchProg(ListProg L, string user);
void viewDataProg(ListProg L);


#endif // PROGRAMMER_H_INCLUDED
