#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct persona{
    char nombre[200];
    int id, edad, cedula;
    float peso, altura;
    char genero;
}p;

int main(){
    fstream FILE(".archivo.bin", ios::in| ios::binary);
    FILE.seekg(sizeof(p)*0, ios::beg);
    cout<<FILE.tellg()<<endl;
    FILE.read(reinterpret_cast<char *>(&p), sizeof(p));
    cout<< "=============" <<endl
    <<"ID: " <<p.id<<endl
    <<"Nombre: "<<p.nombre<<endl
    <<"Genero: "<<p.genero<<endl
    <<"Cedula: "<<p.cedula<<endl
    <<"Edad: "<<p.edad<<endl
    <<"Peso: "<< p.peso<<endl
    <<"Altura: "<<p.altura<<endl
    <<"============="<<endl;
    FILE.close();
   return 0;
}