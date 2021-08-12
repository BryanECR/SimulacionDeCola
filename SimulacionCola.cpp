#include <iostream>
#include <fstream>

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
void graficar();

int main(){
    menu();
    return 0;
}

void menu(){
    int opcion;
    bool seguir = true;
    while(seguir){
        cout<<" ******** MENU ******** \n1- Ingresar Informacion\n2- Ver Informacion\n3- Eliminar el primero\n4- Graficar\n5- Salir\nIngrese el numero de la opcion que desea: ";
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
                graficar();
                system("pause");
            break;
            case 5:
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

void graficar(){
    nodo* actual = new nodo();
    actual = inicio;
    string texto = "";
    int contador = 0;
    if(inicio != NULL){
        while(actual != NULL){
            texto += "\tnodo"+to_string(contador)+"[shape=box label=\"Nombre: "+actual->nombre+"; Edad: "+to_string(actual->edad)+"\"];\n";
            actual = actual->siguiente;
            contador+=1;
        }
    }else{
        cout<<"la lista esta vacia\n";
    }

    for(int i = 0; i<contador; i++){
        if(i == 0){
            texto+="\tnodo"+to_string(i);
        }else{
            texto+="-> nodo"+to_string(i);
        }
    }

    // Archivo de texto para escribir el .dot
    ofstream archivo;
    archivo.open("Grafica.dot",ios::out);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    archivo<<"digraph G {\n"+texto+"\n}";
    archivo.close();
    system("dot -Tpng Grafica.dot -o Grafica.png");
}
/*
´´´´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´
´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´¶¶¶¶´´´´
´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶´´´´´´´’’¶¶¶¶¶¶¶¶¶´´´
´´´´´´´´´´´´´´´´´´´¶¶¶¶¶´´´´´´´´´´´´´´´¶¶¶¶´´´´´
´´´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´
´´´´´´´´´´´´´´´´´¶¶¶´´´´´´´´´´¶¶¶¶¶¶´´´´´´´´´´´´
´´´´´´´´´´´´´´´´¶¶¶´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´
´´´´´´´´´´´´´´¶¶¶¶´´´´´´´¶¶¶´´ ´´´´´´´´´¶¶¶´´´´´
´´´´´´´´´´´´´¶¶¶¶¶´´´´´´´¶¶¶´´´´´¶¶¶ ´´´¶¶¶´´´´´
´´´´´´´´´´´´¶¶¶¶¶¶´´´´´´´¶¶¶¶´´´ ¶¶¶ ´´´´¶¶¶´´´´
´´´´´´´´´´¶¶¶¶¶¶¶¶´´´´´´´´¶¶¶¶¶¶¶¶¶ ´´´´¶¶¶´´´´´
´´´´´´´´´¶¶¶¶´´¶¶¶¶´´´´´´´´´¶¶¶¶¶¶´´´´´¶¶¶´´´´´´
´´´´´´´´¶¶¶¶´´´´¶¶¶¶´´´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´
´´´´´¶¶¶¶´´´´´´´¶¶¶¶´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´´´
´´´´´¶¶¶¶´´´´´´´´´¶¶¶¶¶¶´´´´´´´´´´¶¶¶¶¶´´´´´´´´´
´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´
 */
