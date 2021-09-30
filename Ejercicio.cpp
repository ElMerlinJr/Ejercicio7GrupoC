//Ingresar la cantidad de pupusas que los clientes desean, si quiere que sean de arroz o de maíz, si las quieren con Coca-Cola o no, y de 
//que ingredientes las quieren, que permita agregarlas a las lista y mostrar las ordenes. Este sería el ejercicio opcional en lugar del 7

#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void menu();
void LlenarPedido(Nodo *&, int);
void MostrarPedido(Nodo *);

Nodo *lista = NULL;

int main(void)
{
    cout << endl;
    cout << "\tTAREA DE PED 3" << endl << endl;

    menu();

    return 0;
}

void menu()
{
    
    int opcion, dato, MaAr, cola;

    do
    {
        cout << "\tMenu pupusas" << endl;
        cout << "1. Cuantas pupusas desea pedir" << endl;
        cout << "2. Las quiere de maiz o de arroz?" << endl;
        cout << "3. Eliga un ingrediente" << endl;
        cout << "4. Desea agregar una coca cola en su pedido?" << endl;
        cout << "5. Mostrar el pedido" << endl;
        cout << "6. Terminar" << endl;
        cout << "\nOpcion: " << endl;
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
            case 1: 
                cout << "Digite la cantidad de pupusas que desea: ";
                cin >> dato;
                LlenarPedido(lista, dato);
            break;
            case 2:
                cout << "Ingrese el digito de la masa que desea: " << endl;
                cout << "1. Maiz" << endl;
                cout << "2. Arroz" << endl << endl;
                cin >> dato;
                LlenarPedido(lista, dato);
            break;
            case 3:
                cout << "Ingrese el digito del ingrediente que desea: " << endl;
                cout << "3. Queso" << endl;
                cout << "4. Frijol con queso" << endl;
                cout << "5. Revueltas" << endl << endl;
                cin >> dato;
                LlenarPedido(lista, dato);
            break;
            case 4:
                cout << "Ingrese el digito si desea una coca cola o no: " << endl;
                cout << "6. Con Coca cola" << endl;
                cout << "7. Sin Coca cola" << endl << endl;
                cin >> dato;
                LlenarPedido(lista, dato);
            break;
            case 5: 
                cout << "Pedido: ";
                MostrarPedido(lista);
                cout << endl << endl;
            break;
        }
    } while (opcion != 6);
    
}

void LlenarPedido(Nodo *&lista, int x)
{
    Nodo *nodo_nuevo = new Nodo();
    nodo_nuevo->dato = x;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < x))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista == aux1)
    {
        lista = nodo_nuevo;
    }
    else
    {
        aux2->siguiente = nodo_nuevo;
    }
    nodo_nuevo->siguiente = aux1;

    cout << "El dato " << x << " fue insertado correctamente." << endl << endl;
}

void MostrarPedido(Nodo *lista)
{
    Nodo *actual = new Nodo();
    actual = lista;

    while(actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
}