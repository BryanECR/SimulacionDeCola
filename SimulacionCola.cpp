#include <iostream>

using namespace std;

struct nodo{
    int edad;
    string nombre;
    nodo* siguiente;

} *inicio, *fin;

void menu();
void agregar();
void eliminar();
void mostrar();

int main(){
    menu();
    return 0;
}

void menu(){
    int opcion;
    bool seguir = true;
    while(seguir){
        cout<<" ******** MENU ******** \n1- Ingresar Informacion\n2- Ver Informacion\n3- Eliminar el primero\n4- Salir\nIngrese el numero de la opcion que desea: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                agregar();
                system("pause");
            break;
            case 2:
                cout<<endl;
                mostrar();
                cout<<endl;
                system("pause");
            break;
            case 3:
                eliminar();
                system("pause");
            break;
            case 4:
                cout<<"¡HASTA LA PROXIMA!";
                seguir = false;
            break;
            default:
                cout<<"Esa opcion no se encuentra en el menu";
        }
        system("cls");
    }
}


void agregar(){
    nodo* nuevo = new nodo();
    cout<<"Ingrese el nombre: ";
    cin >> nuevo->nombre;
    cout<<"Ingrese la edad: ";
    cin >> nuevo->edad;

    if(inicio == NULL){
        inicio = nuevo;
        inicio->siguiente = NULL;
        fin = inicio;
    }else{
        fin->siguiente = nuevo;
        nuevo->siguiente = NULL;
        fin = nuevo;
    }
}

void eliminar(){
   // nodo* actual = new nodo();
    //actual = inicio;
    if(inicio == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        inicio = inicio->siguiente;
        cout<<"Eliminado con exito\n";
    }
}

void mostrar(){
    nodo* actual = new nodo();
    actual = inicio;
    if(inicio != NULL){
        while(actual != NULL){
            cout<<"Nombre: "+actual->nombre+" Edad: "+to_string(actual->edad)<<endl;
            actual = actual->siguiente;
        }
    }else{
        cout<<"la lista esta vacia\n";
    }
}