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
    int x;
    fstream FILE(".archivo.bin", ios::out| ios::binary);

    cout<<"ingrese la cantidad de registros desea ingresar: ";
    cin>>x;

    for(int i=0;i<x;i++){
        p.id=i+1;
        cout<<"ingrese el nombre: ";
        cin>>p.nombre;
        cout<<"Ingrese la cedula: ";
        cin>>p.cedula;
        cout<<"Ingrese la edad: ";
        cin>>p.edad;
        cout<<"Ingrese el peso en kilogramos: ";
        cin>>p.peso;
        cout<<"Ingrese la altura en centimetros: ";
        cin>>p.altura;
        cout<<"Es masculino(M) o femenino(F): ";
        cin>>p.genero;
        cout<<endl;
        FILE.write(reinterpret_cast<char *>(&p), sizeof(p));

    }
    FILE.close();
    return 0;
}