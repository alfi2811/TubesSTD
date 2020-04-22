#include <iostream>
#include "relasi.h"
#include <cstdlib>
#include <ctime>

void createList(ListRelasi &L){
    first(L) = NULL;
}
int generateID(){
    srand(time(0));
    int a = 0;
    int b;
    for (int i = 0; i < 2; i++){
        b = (1 + (rand() % 100));
        a = a + b;
    }
    return a;
}

void createElmRes(address &P, addrProg programmer, addrProj project){
    P = new elmListRes;
    int id = generateID();
    info(P).id = id;
    info(P).programmer = programmer;
    info(P).project = project;
    info(P).status = "Dalam Pengerjaan";
    next(P) = NULL;
    prev(P) = NULL;
}
void insertFirst(ListRelasi &L, address P){
    if(first(L) != NULL){
        next(prev(first(L))) = P;
        prev(P) = prev(first(L));
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    } else{
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
}
void insertLast(ListRelasi &L, address &P){
    if(first(L) != NULL){
        next(prev(first(L))) = P;
        prev(P) = prev(first(L));
        next(P) = first(L);
        prev(first(L)) = P;
    }
}
void viewData(ListRelasi L){
    string a;
    address P = first(L);
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                    VIEW TASK                     ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(L) != NULL){
        do{
            cout<<"ID              : "<<info(P).id<<endl;
            cout<<"Nama Programmer : "<<info(info(P).programmer).user<<endl;
            cout<<"Nama Project    : "<<info(info(P).project).judul<<endl;
            cout<<"Status          : "<<info(P).status<<endl;
            cout<<"Deadline        : "<<info(info(P).project).deadline<<endl;
            cout<<endl;
            P = next(P);
        }while(P != first(L));
    } else {
        cout<<"List Penugasan Kosong"<<endl;
    }
    cout<<endl;
    getline(cin, a);
}

address searchTugas(ListRelasi L, addrProg Prog, addrProj Proj){
    if(first(L) != NULL){
        address P = first(L);
        do{
            if(info(P).programmer == Prog && info(P).project == Proj){
                return P;
            }
            P = next(P);
        }while(P != first(L));
    }
    return NULL;
}

address searchRelasiProj(ListRelasi L, addrProj Proj){
    if(first(L) != NULL){
        address P = first(L);
        do{
            if(info(P).project == Proj){
                return P;
            }
            P = next(P);
        }while(P != first(L));
    }
    return NULL;
}

address searchRelasiProg(ListRelasi L, addrProg Prog){
    if(first(L) != NULL){
        address P = first(L);
        do{
            if(info(P).programmer == Prog){
                return P;
            }
            P = next(P);
        }while(P != first(L));
    }
    return NULL;
}


void updateStatus(ListRelasi &L, ListProg &LProg, ListProj &LProj){
    int inputStat;
    address foundTugas;
    addrProg foundProg;
    addrProj foundProj;
    string namaProjNew, namaProgNew;
    cout<<"Pilih nama project yang akan di ubah :";
    cin>>namaProjNew;
    cout<<endl;
    cout<<"Pilih nama programmer yang mengerjakan project tersebut :";
    cin>>namaProgNew;
    foundProj = searchProj(LProj, namaProjNew);
    foundProg = searchProg(LProg, namaProgNew);
    cout<<endl;
    foundTugas = searchTugas(L, foundProg, foundProj);
    if(foundTugas != NULL){
        cout<<"Nama Programmer : "<<info(info(foundTugas).programmer).user<<endl;
        cout<<"Nama Project    : "<<info(info(foundTugas).project).judul<<endl;
        cout<<"Status          : "<<info(foundTugas).status<<endl;
        cout<<"Deadline        : "<<info(info(foundTugas).project).deadline<<endl;
        cout<<endl;
        cout<<"Pilih status baru :"<<endl;
        cout<<"1. Dalam pengerjaan"<<endl;
        cout<<"2. Dalam deployment"<<endl;
        cout<<"3. Selesai"<<endl;
        cout<<"Pilihan: ";
        cin>>inputStat;

        if(inputStat == 1){
            info(foundTugas).status = "Dalam pengerjaan";
        } else if(inputStat == 2){
            info(foundTugas).status = "Dalam deployment";
        } else if(inputStat == 3){
            info(foundTugas).status = "Selesai";
        }
        cout<<endl;
        cout<<"Pengubahan berhasil"<<endl;
    }
}

void deleteFirst(ListRelasi &L, address &P){
    if(next(P) == first(L)){
        next(P) = NULL;
        first(L) = NULL;
    }else {
        P = first(L);
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter(address Prec, address &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteLast(ListRelasi &L, address &P){
    P = prev(first(L));
    prev(first(L)) = prev(P);
    next(prev(P)) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
}




void viewTaskForProg(ListProg LP, ListProj LPJ, ListRelasi LR){
    string uname;
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                    VIEW TASK                     ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(LR) != NULL){
        cout<<"Username Programmer: ";
        cin>>uname;
        addrProg p = searchProg(LP, uname);
        address q = first(LR);
        cout<<endl;
        if(p != NULL){
            cout<<"Tugas "<<info(p).nama<<" :"<<endl;
            do{
               if(p == info(q).programmer){
                    cout<<info(info(q).project).judul<<endl;
               }
               q = next(q);
            }while(q != first(LR));
        } else {
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    } else {
        cout<<"List Penugasan Kosong"<<endl;
    }
    cout<<endl;
    getline(cin, uname);
}

void viewTaskForProj(ListProg LP, ListProj LPJ, ListRelasi LR){
    string nmProj;
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                    VIEW TASK                     ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(LR) != NULL){
        cout<<"Nama Project: ";
        getline(cin, nmProj);
        getline(cin, nmProj);
        addrProj p = searchProj(LPJ, nmProj);
        address q = first(LR);
        cout<<endl;
        if(p != NULL){
            cout<<"Programmer yang Berkontribusi dalam Project "<<info(p).judul<<" :"<<endl;
            do{
               if(p == info(q).project){
                    cout<<info(info(q).programmer).nama<<endl;
               }
               q = next(q);
            }while(q != first(LR));
        } else {
            cout<<"Data Tidak Ditemukan"<<endl;
            getline(cin, nmProj);
        }
    } else {
        cout<<"List Penugasan Kosong"<<endl;
        getline(cin, nmProj);
    }
    cout<<endl;
}

void viewAllProgTask(ListRelasi LR, ListProg LP){
    int total = 0;
    addrProg P = first(LP);
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||               VIEW ALL PROGRAMMER                ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"List Programmer beserta Total Tugas: "<<endl;
    while(P != NULL){
        address Q = first(LR);
        if(Q != NULL){
            do {
                if(info(Q).programmer == P){
                    total += 1;
                }
                Q = next(Q);
            }while(Q != first(LR));
        }
        cout<<info(P).nama<<" Total Tugas: "<<total<<endl;
        total = 0;
        P = next(P);
    }
    cout<<endl;
}

void viewAllProjTask(ListRelasi LR, ListProj LPJ){
    int total = 0;
    addrProj P = first(LPJ);
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                VIEW ALL PROJECT                  ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"List Project beserta Total Programmer yang berkontribusi: "<<endl;
    while(P != NULL){
        address Q = first(LR);
        if(Q != NULL){
            do {
                if(info(Q).project == P){
                    total += 1;
                }
                Q = next(Q);
            }while(Q != first(LR));
        }
        cout<<info(P).judul<<" Total Programmer: "<<total<<endl;
        total = 0;
        P = next(P);
    }
    cout<<endl;
}

