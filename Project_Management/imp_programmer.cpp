#include "programmer.h"

void createElmProg(addrProg &P, string user, string pass, string nama, string notelp){
    P = new elmListProg;
    info(P).user = user;
    info(P).pass = pass;
    info(P).nama = nama;
    info(P).notelp = notelp;
    info(P).total_tugas = 0;
    next(P) = NULL;
}
void createListProg(ListProg &L){
    first(L) = NULL;
    last(L) = NULL;
}
void insertFirstProg(ListProg &L, addrProg P){
    if(first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = NULL;
        last(L) = P;
    }
}
void insertAfterProg(ListProg &L, addrProg Prec, addrProg P){
    if(first(L) != NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }else {
        first(L) = P;
    }
}
void insertLastProg(ListProg &L, addrProg &P){
    if(first(L) != NULL){
        addrProg last = first(L);
        while(next(last) != NULL){
            last = next(last);
        }
        next(last) = P;
        last(L) = P;
    } else{
        first(L) = P;
    }
}

void insertProgrammer(ListProg &L, addrProg P){

    if(first(L) != NULL){
        if(info(P).user <= info(first(L)).user  ){
            insertFirstProg(L, P);
        } else if(info(P).user >= info(last(L)).user){
            insertLastProg(L, P);
        } else {
            addrProg q = first(L);
            while (next(q) != NULL && info(P).user >= info(next(q)).user ){
                q = next(q);
            }
            if(next(q) != NULL){
                insertAfterProg(L, q, P);
            }
        }
    } else {
      insertFirstProg(L, P);
    }
}

void deleteFirstProg(ListProg &L, addrProg &P){
    if(first(L) != NULL){
        first(L) =  next(P);
        next(P) = NULL;
    }else {
        cout<<"List Kosong"<<endl;
    }
}
void deleteAfterProg(ListProg &L, addrProg Prec, addrProg &P){
    if(first(L) != NULL){
        next(Prec) = next(P);
        next(P) = NULL;
    }else {
        cout<<"List Kosong"<<endl;
    }
}
void deleteLastProg(ListProg &L, addrProg &P){
    if(first(L) != NULL){
        addrProg last = first(L);
        while(next(next(last)) != NULL){
            last = next(last);
        }
        P = next(last);
        next(last) = NULL;
    }else {
        cout<<"List Kosong"<<endl;
    }
}

void deleteProgrammer(ListProg &L, ListRelasi &LR){

    addrProg p;
    string uname;
    cout<<"======================================================"<<endl;
    cout<<"||                PROJECT MANAGEMENT                ||"<<endl;
    cout<<"||                DELETE PROGRAMMER                 ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(L) != NULL){
        cout<<"Username : ";
        cin>>uname;
        p = searchProg(L, uname);
        if (p != NULL){
            if(first(L) == p){
                deleteFirstProg(L, p);
            } else if(last(L) == p){
                deleteLastProg(L, p);
            } else {
                addrProg q = first(L);
                while(next(q) != NULL && next(q) != p){
                    q = next(q);
                }
                deleteAfterProg(L, q, p);
            }
            deleteTugasProgrammer(LR, p);
            cout<<endl;
            cout<<"Delete is Successfull";
        } else {
            cout<<"Username Tidak ditemukan";
        }
        cout<<endl;
    }

}


addrProg searchProg(ListProg L, string user){
    if(first(L) != NULL){
        if(info(first(L)).user == user){
            return first(L);
        } else if(info(last(L)).user == user){
            return last(L);
        } else {
            addrProg q = first(L);
            while (q != NULL){
                if(info(q).user == user){
                    return q;
                }
                q = next(q);
            }
            return NULL;
        }
    }
    return NULL;
}

void updateDataProg(ListProg &L){
    int inputProg;
    string user, userNew, passNew, namaNew, notelNew;
    cout<<"Masukkan username programmer yang akan diedit: ";
    cin>>user;
    addrProg found = searchProg(L, user);
    if(found != NULL){
        cout<<"Nama     : "<<info(found).nama<<endl;
        cout<<"Username : "<<info(found).user<<endl;
        cout<<"Password : "<<info(found).pass<<endl;
        cout<<"Telepon  : "<<info(found).notelp<<endl;
        cout<<endl;
        cout<<"Pilih data yang akan di edit"<<endl;
        cout<<"1. Nama programmer"<<endl;
        cout<<"2. Username"<<endl;
        cout<<"3. Password"<<endl;
        cout<<"4. Telepon"<<endl;
        cout<<"Pilihan: ";
        cin>>inputProg;

        if(inputProg == 1){
            cout<<"Nama programmer baru: ";
            cin>>namaNew;
            info(found).nama = namaNew;
        } else if(inputProg == 2){
            cout<<"Username baru: ";
            cin>>userNew;
            info(found).user = userNew;
        } else if(inputProg == 3){
            cout<<"Password baru: ";
            cin>>passNew;
            info(found).pass = passNew;
        } else if(inputProg == 4){
            cout<<"No.Telepon baru: "<<endl;
            cin>>notelNew;
            info(found).notelp = notelNew;
        }
        cout<<endl;
        cout<<"Pengubahan berhasil"<<endl;
    }
}



void viewDataProg(ListProg L){
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                VIEW PROGRAMMER                   ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(L) != NULL){
        addrProg P = first(L);
        while(P != NULL){
            cout<<"Nama     : "<<info(P).nama<<endl;
            cout<<"Username : "<<info(P).user<<endl;
            cout<<"Password : "<<info(P).pass<<endl;
            cout<<"Telepon  : "<<info(P).notelp<<endl;
            cout<<endl;
            P = next(P);
        }
    }
    else{
        cout<<"List Kosong"<<endl;
    }
}
