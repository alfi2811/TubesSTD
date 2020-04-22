#include "project.h"

void createListProj(ListProj &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createElmProj(addrProj &P, string judul, string deadline, string difficulty){
    P = new elmListProj;
    info(P).judul = judul;
    info(P).deadline = deadline;
    info(P).difficulty = difficulty;
    next(P) = NULL;
}
void insertFirstProj(ListProj &L, addrProj P){
    if(first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void insertAfterProj(ListProj &L, addrProj Prec, addrProj P){
    if(first(L) != NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }else {
        first(L) = P;
    }
}
void insertLastProj(ListProj &L, addrProj &P){
    if(first(L) != NULL){
        addrProj last = first(L);
        while(next(last) != NULL){
            last = next(last);
        }
        next(last) = P;
        last(L) = P;
    }else {
        first(L) = P;
        last(L) = P;
    }
}
void deleteFirstProj(ListProj &L, addrProj &P){
    if(first(L) != NULL){
        first(L) =  next(P);
        next(P) = NULL;
    }
}
void deleteAfterProj(ListProj &L, addrProj Prec, addrProj &P){
    if(first(L) != NULL){
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void deleteLastProj(ListProj &L, addrProj &P){
    if(first(L) != NULL){
        addrProj last = first(L);
        while(next(next(last)) != NULL){
            last = next(last);
        }
        P = next(last);
        next(last) = NULL;
    }
}

addrProj searchProj(ListProj L, string nmProj){
    if(first(L) != NULL){
        if(info(first(L)).judul == nmProj){
            return first(L);
        } else if(info(last(L)).judul == nmProj){
            return last(L);
        } else {
            addrProj q = first(L);
            while (q != NULL){
                if(info(q).judul == nmProj){
                    return q;
                }
                q = next(q);
            }
            return NULL;
        }
    }
    return NULL;
}

void deleteProject(ListProj &L, ListRelasi &LR){

    addrProj p;
    string nProj;
    cout<<"======================================================"<<endl;
    cout<<"||                PROJECT MANAGEMENT                ||"<<endl;
    cout<<"||                DELETE PROGRAMMER                 ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(L) != NULL){
        cout<<"Nama Project : ";
        getline(cin, nProj);
        getline(cin, nProj);
        p = searchProj(L, nProj);
        if (p != NULL){
            if(first(L) == p){
                deleteFirstProj(L, p);
            } else if(last(L) == p){
                deleteLastProj(L, p);
            } else {
                addrProj q = first(L);
                while(next(q) != NULL && next(q) != p){
                    q = next(q);
                }
                deleteAfterProj(L, q, p);
            }
            deleteTugasProject(LR, p);
            cout<<endl;
            cout<<"Delete is Successfull";
        } else {
             cout<<"Username Tidak ditemukan";
        }
        cout<<endl;
    }

}

void updateDataProj(ListProj &L){
    int inputProj, difficultyNew;
    string jdlProj, jdlProjNew, deadlineNew;
    cout<<"Masukkan nama project yang akan diedit: ";
    getline(cin, jdlProj);
    getline(cin, jdlProj);
    addrProj found = searchProj(L, jdlProj);
    if(found != NULL){
        cout<<"Nama Project     : "<<info(found).judul<<endl;
        cout<<"Deadline Project : "<<info(found).deadline<<endl;
        cout<<"Difficulty       : "<<info(found).difficulty<<endl;
        cout<<endl;
        cout<<"Pilih data yang akan di edit"<<endl;
        cout<<"1. Nama project"<<endl;
        cout<<"2. Deadline Project"<<endl;
        cout<<"3. Difficulty"<<endl;
        cout<<"Pilihan: ";
        cin>>inputProj;
        if(inputProj == 1){
            cout<<"Nama project baru: ";
            getline(cin, jdlProjNew);
            getline(cin, jdlProjNew);
            info(found).judul = jdlProjNew;
        } else if(inputProj == 2){
            cout<<"Deadline baru: ";
            cin>>deadlineNew;
            info(found).deadline = deadlineNew;
            getline(cin, jdlProjNew);
        } else if(inputProj == 3){
            cout<<"Difficulty baru: ";
            cout<<"1. Hard"<<endl;
            cout<<"2. Medium"<<endl;
            cout<<"3. Easy"<<endl;
            cout<<"4. Tidak diketahui"<<endl;
            cout<<"Pilihan :";
            cin>>difficultyNew;
            switch(difficultyNew){
            case 1:
                info(found).difficulty = "Hard";
                break;
            case 2:
                info(found).difficulty = "Medium";
                break;
            case 3:
                info(found).difficulty = "Easy";
                break;
            case 4:
                info(found).difficulty = "Tidak diketahui";
                break;
            }
            getline(cin, jdlProjNew);
        }
        cout<<endl;
        cout<<"Pengubahan berhasil"<<endl;
    }
}


void viewDataProj(ListProj L){
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                VIEW PROGRAMMER                   ||"<<endl;
    cout<<"======================================================"<<endl;
    if(first(L) != NULL){
        addrProj P = first(L);
        while(P != NULL){
            cout<<"Nama Project     : "<<info(P).judul<<endl;
            cout<<"Deadline Project : "<<info(P).deadline<<endl;
            cout<<"Difficulty       : "<<info(P).difficulty<<endl;
            cout<<endl;
            P = next(P);
        }
    }else {
        cout<<"List Kosong"<<endl;
    }
    string a;
    getline(cin, a);

}
