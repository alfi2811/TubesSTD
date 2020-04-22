#include "index.h"
#include <stdlib.h>

void loadData(ListProg &LP, ListProj &LPJ, ListRelasi &LR){
    createList(LR);
    createListProg(LP);
    createListProj(LPJ);
}

void Home(string msg, ListProg &LP, ListProj &LPJ, ListRelasi &LR){
    system("cls");
    if(msg != "NULL"){
        cout << "|| "<< msg << " ||"<< endl;
    }
    int chs;
    string a;
    cout <<"======================================================"<<endl;
    cout <<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout <<"||                     HOME                         ||"<<endl;
    cout <<"======================================================"<<endl;
    cout <<"\t\t 1. Regis"<< endl;
    cout <<"\t\t 2. Login"<< endl;
    cout << "Pilih: ";
    cin >> chs;

    if (chs == 1){
        regis(msg);
    }
    else if (chs == 2){
        cout << "Login As:" << endl;
        cout << "1. Admin/Manager"<< endl;
        cout << "2. Programmer"<< endl;
        cout << "Pilih: ";
        cin >> chs;
        if( chs == 1){
            login(LP, LPJ, LR, "nil");
        } else {
            cout<<"==== Coming Soon, Stay Tune! ===="<<endl;
            cout<<"Click Enter to back";
            getline(cin,a);
            getline(cin,a);
        }
    }

    Home(msg, LP, LPJ, LR);
}

bool searchDataUser(string user, string pass, string lvl){
    string username, password, level;
    ifstream myfile("data/dataUser.txt");
    if (myfile.is_open())
    {
        while (myfile >> username >> password >> level)
        {
            if (user == username && pass == password && lvl == level)
            {
                myfile.close();
                return true;
                break;
            }
        }
        if (user != username && pass != password && lvl != level)
        {
            myfile.close();
            return false;
        }

    }
    return false;
}

void regis(string &msg){

    string un, pw, lvl, aa, pilih;
    int plh;
    ofstream myfile("data/dataUser.txt", ios::out | ios::app);
    system("cls");
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||             REGISTER ADMIN/MANAGER               ||"<<endl;
    cout<<"======================================================"<<endl;
    cout << "Enter Username = ";
    getline(cin, aa);
    getline(cin, un);
    cout << "Enter Password = ";
    getline(cin, pw);
    cout << "Level :"<<endl;
    cout << "1. Admin"<<endl;
    cout << "2. Manager"<<endl;
    cout << "Pilih : ";
    cin  >> plh;
    if(plh == 1){
        lvl = "admin";
    } else if (plh == 2){
        lvl = "manager";
    }
    bool cek = searchDataUser(un, pw, lvl);
    if (cek == false){
        myfile << un << " " << pw << " "<< lvl << endl;
        myfile.close();
        msg  = " Register Successfully. ";
    } else {
        msg = "Sudah ada Akunnya";
    }
}

void login(ListProg &LP, ListProj &LPJ, ListRelasi &LR, string msg){

    system("cls");
    if(msg != "nil"){
        cout<<"** "<<msg<<" **"<<endl;
    }
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||             LOGIN FOR ADMIN/MANAGER              ||"<<endl;
    cout<<"======================================================"<<endl;
    string uname, pword;
    string username, password, level;
    cout << "enter username: ";
    cin >> uname;
    cout << "enter password: " ;
    cin >> pword;
    ifstream myfile("data/dataUser.txt");

    if (myfile.is_open())
    {
        while (myfile >> username >> password >> level)
        {
            if (uname == username && pword == password)
            {
                if(level == "admin"){
                    msg = "Login Successful";
                    menuAdmin(LP, LPJ, LR, msg);
                } else if(level == "manager") {
                    menuManager(LP, LPJ, LR);
                }

                break;
            }
        }
        if (uname != username && pword != password)
        {
            msg = "Wrong Username and Password";
            login(LP, LPJ, LR, msg);
        }
        else {
            msg = "Wrong Input";
            login(LP, LPJ, LR, msg);
        }
        myfile.close();
    }
}



void menuAdmin(ListProg &LP, ListProj &LPJ, ListRelasi &LR, string msg){

    int chs;
    system("cls");
    if(msg != "nil"){
        cout<<"|| "<<msg<<" ||"<<endl;
    }
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                    MENU ADMIN                    ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"\t\t 1. Data Programmer                               "<<endl;
    cout<<"\t\t 2. Data Project                                  "<<endl;
    cout<<"\t\t 3. Back                                          "<<endl;
    cout << "Pilih : ";
    cin >> chs;
    cout << endl;
    if(chs == 1){
        menuDataProg(LP, LPJ, LR);
    } else if(chs == 2){
        menuDataProj(LP, LPJ, LR);
    } else if(chs == 3){
        login(LP, LPJ, LR, "Logout Success");
    }

}
void menuDataProj(ListProg &LP, ListProj &LPJ, ListRelasi &LR){
    int chs;
    string a;
    system("cls");
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||               MENU DATA PROJECT                  ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"\t\t 1. Insert Data                                   "<<endl;
    cout<<"\t\t 2. Delete Data                                   "<<endl;
    cout<<"\t\t 3. Update Data                                   "<<endl;
    cout<<"\t\t 4. View   Data                                   "<<endl;
    cout<<"\t\t 5. Back                                          "<<endl;
    cout << "Pilih: ";
    cin >> chs;
    switch(chs){
    case 1:
        insertDataProj(LP, LPJ, LR);
        break;
    case 2:
        deleteProject(LPJ, LR);
        break;
    case 3:
        updateDataProj(LPJ);
        break;
    case 4:
        viewDataProj(LPJ);
        break;
    case 5:
        menuAdmin(LP, LPJ, LR, "nil");
    }
    cout<<"Click Enter to back";
    getline(cin, a);
    menuDataProj(LP, LPJ, LR);
}

void insertDataProj(ListProg &LP, ListProj &LPJ, ListRelasi &LR){

    addrProj P;
    int plh;
    string nmProject, tglDeadline, difc;
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                 INSERT PROJECT                   ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"Nama Project: ";
    getline(cin, nmProject);
    getline(cin, nmProject);
    cout<<"Deadline Project(DD/MM/YYYY): ";
    cin>>tglDeadline;
    cout<<"Kesulitan Project: "<<endl;
    cout<<"1. Hard"<<endl;
    cout<<"2. Medium"<<endl;
    cout<<"3. Easy"<<endl;
    cout<<"Pilih: ";
    cin>>plh;
    switch(plh){
    case 1:
        difc = "Hard";
        break;
    case 2:
        difc = "Medium";
        break;
    case 3:
        difc = "Easy";
        break;
    default:
        difc = "Tidak Diketahui";
        break;
    }
    createElmProj(P, nmProject, tglDeadline, difc );
    insertLastProj(LPJ, P);
    cout<<endl;
    cout<<"Insert is Successfull"<<endl;
    getline(cin, difc);

}

void menuDataProg(ListProg &LP, ListProj &LPJ, ListRelasi &LR){

    int chs;
    string a;
    system("cls");
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||              MENU DATA PROGRAMMER                ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"\t\t 1. Insert Data                                   "<<endl;
    cout<<"\t\t 2. Delete Data                                   "<<endl;
    cout<<"\t\t 3. Update Data                                   "<<endl;
    cout<<"\t\t 4. View   Data                                   "<<endl;
    cout<<"\t\t 5. Back                                          "<<endl;
    cout << "Pilih: ";
    cin >> chs;
    switch(chs){
    case 1:
        insertDataProg(LP, LPJ, LR);
        break;
    case 2:
        deleteProgrammer(LP, LR);
        break;
    case 3:
        updateDataProg(LP);
        break;
    case 4:
        viewDataProg(LP);
        break;
    case 5:
        menuAdmin(LP, LPJ, LR, "nil");
    }
    cout<<"Click Enter to back";
    getline(cin, a);
    getline(cin, a);
    menuDataProg(LP, LPJ, LR);
}

void insertDataProg(ListProg &LP, ListProj &LPJ, ListRelasi &LR){

    addrProg P1;
    string username, pass, name, telp;
    cout<<"======================================================"<<endl;
    cout<<"||                PROJECT MANAGEMENT                ||"<<endl;
    cout<<"||                INSERT PROGRAMMER                 ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"Create Username : ";
    cin>>username;
    cout<<"Create Password : ";
    cin>>pass;
    cout<<"Input Name      : ";
    getline(cin, name);
    getline(cin, name);
    cout<<"Input Telepon   : ";
    cin>>telp;
    createElmProg(P1, username, pass, name, telp);
    insertProgrammer(LP, P1);
    cout<<endl;
    cout<<"Insert is Successfull"<<endl;
}

void menuManager(ListProg &LP, ListProj &LPJ, ListRelasi &LR){
    int chs;
    string a;
    system("cls");
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                  MENU MANAGER                    ||"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"    1. Insert Penugasan                              "<<endl;
    cout<<"    2. View   List Relasi                            "<<endl;
    cout<<"    3. View   Penugasan Setiap Programmer            "<<endl;
    cout<<"    4. View   Penugasan Setiap Project               "<<endl;
    cout<<"    5. View   All Programmer dan Total Tugas         "<<endl;
    cout<<"    6. View   All Project    dan Total Programmer    "<<endl;
    cout<<"    7. Update Status                                 "<<endl;
    cout<<"    8. Hapus  Tugas Untuk Programmer                 "<<endl;
    cout<<"    9. Back                                          "<<endl;
    cout << "Pilih: ";
    cin >> chs;
    switch(chs){
    case 1:
        insertPenugasan(LP, LPJ, LR);
        break;
    case 2:
        viewData(LR);
        break;
    case 3:
        viewTaskForProg(LP, LPJ, LR);
        break;
    case 4:
        viewTaskForProj(LP, LPJ, LR);
        break;
    case 5:
        viewAllProgTask(LR, LP);
        getline(cin, a);
        break;
    case 6:
        viewAllProjTask(LR, LPJ);
        getline(cin, a);
        break;
    case 7:
        updateStatus(LR, LP, LPJ);
        getline(cin, a);
        break;
    case 8:
        cout<<"Coming Soon"<<endl;
        getline(cin, a);
        break;
    case 9:
        login(LP, LPJ, LR, "Logout Success");
        break;
    }
    cout<<"Click Enter to Back";
    getline(cin, a);
    menuManager(LP, LPJ, LR);
}

void insertPenugasan(ListProg &LP, ListProj &LPJ, ListRelasi &LR){
    address P2;
    string uname, nProj;
    cout<<endl;
    cout<<"======================================================"<<endl;
    cout<<"||               PROJECT MANAGEMENT                 ||"<<endl;
    cout<<"||                INSERT PENUGASAN                  ||"<<endl;
    cout<<"======================================================"<<endl;
    cout << "Username Programmer : ";
    cin >> uname;
    cout << "Nama Project        : ";
    getline(cin, nProj);
    getline(cin, nProj);
    addrProg prog = searchProg(LP, uname);
    addrProj proj = searchProj(LPJ, nProj);

    cout<<endl;
    if(prog != NULL && proj != NULL){
        address tgs = searchTugas(LR, prog, proj);
        if(tgs == NULL){
            createElmRes(P2, prog , proj);
            insertFirst(LR, P2);
            cout<<"Insert is Successfull"<<endl;
        } else {
            cout<<"Data Sudah Ada"<<endl;
        }
    } else {
        cout<<"Data Tidak ditemukan"<<endl;
    }
}


void deleteTugasProject(ListRelasi &L, addrProj Proj){
    if(first(L) != NULL){
        address P = searchRelasiProj(L, Proj);
        while(P != NULL){
            if(P == first(L)){
                deleteFirst(L, P);
            }
            else if(next(P) == first(L)){
                deleteLast(L, P);
            } else {
                address Q = next(first(L));
                while(P != first(L) && Q != P){
                    Q = next(Q);
                }
                deleteAfter(prev(Q), P);
            }
            P = searchRelasiProj(L, Proj);
        }
    }
}


void deleteTugasProgrammer(ListRelasi &L, addrProg Prog){
    if(first(L) != NULL){
        address P = searchRelasiProg(L, Prog);
        while(P != NULL){
            if(P == first(L)){
                deleteFirst(L, P);
            }
            else if(next(P) == first(L)){
                deleteLast(L, P);
            } else {
                address Q = next(first(L));
                while(P != first(L) && Q != P){
                    Q = next(Q);
                }
                deleteAfter(prev(Q), P);
            }
            P = searchRelasiProg(L, Prog);
        }
    }
}


