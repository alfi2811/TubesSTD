#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "imp_project.cpp"
#include "imp_programmer.cpp"
#include "imp_relasi.cpp"
#include "imp_index.cpp"

using namespace std;

int main()
{
    string pesan = "MOHON BACA PANDUAN PENGGUNAAN DI DALAM FOLDER BERBENTUK .txt";
    ListProg LP;
    ListProj LPJ;
    ListRelasi LR;
    loadData(LP, LPJ, LR);
    Home(pesan, LP, LPJ, LR);



    return 0;
}
