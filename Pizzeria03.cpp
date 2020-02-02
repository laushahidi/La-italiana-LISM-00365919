#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Declaracion de un define
#define PASSWORD "header"

using namespace std;

// Probando comentario

enum paymentType {cash, card};

// Declaraciones de estructuras
struct address
{
    string settlement, municipality, department;
    int houseNumber;
};

struct mainInfo
{
    string name;
    int qPizza;
    int qPasta;
    int qLasagna;
    int qBeer;
    int qSoda;
    int qTea;
    int qGarlic;
    int qPizzaRolls;
    int qCheese;
    paymentType pay;
    int idOrder;
    float total;

};

struct delivery
{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
};

struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
};

//variables globales

bool isAdmin = false;
int idOrder = 1;

//prototipos
bool loginUser(void);
void printMenu(void);
void addOrder(vector <delivery> *delOrder);
void addOrder(vector <houseOrder> *hOrder);
//void seeOrders(vector <delivery> *delOrder);
//void seeOrders(vector <houseOrder> *hOrder);


//if(!s)  if(s == NULL)
//if(s)   if(s != NULL)

int main(void)
{
    // Declaracion de variables y arreglos a usar
    delivery *dArray = NULL;
    houseOrder *hArray = NULL;
    vector <delivery> delOrder;
    vector <houseOrder> hOrder;
    
    int option = 0;
    // if(loginUser())       if(loginUser() == true)

    // Verificacion para iniciar sesion
    if (!loginUser()) //if(loginUser() == false)
        return 0;

    // Logica principal para la ejecucion del programa (menu)
    do
    {
        printMenu();
        cin >> option;
        cin.ignore();

        switch (option)
        {
        // Agregar ordenes a domicilio
        case 1:
            addOrder(&delOrder);
            break;
        // Agregar ordenes en restaurante
        case 2:
            addOrder(&hOrder);
            break;
        case 3:
            // ver ordenes a domicilio
            //seeOrders(&delOrder);
            for(int i = 0; i < delOrder.size(); i++){
                cout << endl << "Nombre:\t" << delOrder[i].deliveryInfo.name << endl;
            }
            
            break;
        case 4:
            // ver ordenes en restaurante
            //seeOrders(&hOrder);
            break;
        case 5:
            // Despachar ordenes a domicilio
            break;
        case 6:
            // Despachar ordenes en restaurante
            break;
        case 7:
            // Tiempo promedio de espera a domicilio
            break;
        case 8:
            // Tiempo promedio de espera en restaurante
            break;
        case 9:
            // Cancelar orden a domicilio o restaurante, solo admin
            break;
        case 10:
            // Calcular total de ventas
            break;
        case 11:
            // Cambiar de usuario
            break;
        case 12:
            cout << "Salida exitosa, gracias por preferirnos!" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }

    } while (option != 12);

    return 0;
}

bool loginUser(void)
{
    string enterPass = "";
    char option;
    cout << "INICIO DE SESION" << endl;
    cout << "A - Administrador" << endl;
    cout << "E - Empleado" << endl;
    cout << "Su opcion:\t";
    cin >> option;

    switch (option)
    {
    case 'a':
    case 'A':
        cout << "Digite contraseña: ";
        cin >> enterPass;

        if (enterPass.compare(PASSWORD) == 0)
        {
            isAdmin = true;
            return true;
        }
        else
        {
            cout << "Contraseña incorrecta" << endl;
        }

        break;
    case 'e':
    case 'E':
        isAdmin = false;
        return true;
        break;
    }
    return false;
}

void printMenu(void)
{
    cout << endl << "SISTEMA DE DESPACHO PIZZERIA LA ITALIANA" << endl;
    cout << "1. Agregar ordenes a domicilio" << endl;
    cout << "2. Agregar ordenes en restaurante" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurante" << endl;
    cout << "5. Despachar ordenes a domicilio" << endl;
    cout << "6. Despachar ordenes a restaurante" << endl;
    cout << "7. Ver tiempo promedio de espera domicilio" << endl;
    cout << "8. Ver tiempo promedio de espera restaurante" << endl;
    cout << "9. Cancelar orden (domicilio o restaurante, solo admin)" << endl;
    cout << "10. Calcular total de ventas" << endl;
    cout << "11. Cambiar de usuario" << endl;
    cout << "12. Salir" << endl;
    cout << "Su option:\t";
}

void addOrder(vector <delivery> *delOrder)
{
    delivery oneOrder;

    int aux = 0;
    cout << endl << "Nombre:\t";
    getline(cin, oneOrder.deliveryInfo.name);
    cout << "Telefono: ";
    cin >> oneOrder.cellphone;
    cin.ignore();
    cout << "Direccion" << endl;
    cout << "Colonia:\t";
    getline(cin, oneOrder.deliveryAddress.settlement);
    cout << "Municipio:\t";
    getline(cin, oneOrder.deliveryAddress.municipality);
    cout << "Departamento:\t";
    getline(cin, oneOrder.deliveryAddress.department);
    cout << "No. casa:\t";
    cin >> oneOrder.deliveryAddress.houseNumber;
    cin.ignore();

    cout << "Entrada" << endl;
    cout << "Pan con ajo. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qGarlic;
    cin.ignore();
    cout << "Pizza rolls. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qPizzaRolls;
    cin.ignore();
    cout << "Palitos de queso. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qCheese;
    cin.ignore();

    cout << "Plato principal" << endl;
    cout << "Pizza. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qPizza;
    cin.ignore();
    cout << "Pasta. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qPasta;
    cin.ignore();
    cout << "Lasagna. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qLasagna;
    cin.ignore();

    cout << "Bebida" << endl;
    cout << "Cerveza. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qBeer;
    cin.ignore();
    cout << "Soda. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qSoda;
    cin.ignore();
    cout << "Te helado. Cantidad: ";
    cin >> oneOrder.deliveryInfo.qTea;
    cin.ignore();

    oneOrder.deliveryInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1 - Tarjeta" << endl;
    cout << "2 - Efectivo" << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        oneOrder.deliveryInfo.pay = card;
    else if (aux == 2)
        oneOrder.deliveryInfo.pay = cash;

    oneOrder.deliveryInfo.total = ((oneOrder.deliveryInfo.qGarlic * 3.99) + (oneOrder.deliveryInfo.qPizzaRolls * 4.99) + (oneOrder.deliveryInfo.qCheese * 3.75) + (oneOrder.deliveryInfo.qPizza * 13.99) + (oneOrder.deliveryInfo.qPasta * 5.55) + (oneOrder.deliveryInfo.qLasagna * 6.25) + (oneOrder.deliveryInfo.qBeer * 1.99) + (oneOrder.deliveryInfo.qSoda * 0.95) + (oneOrder.deliveryInfo.qTea *1.15));
    cout << "Monto: " << oneOrder.deliveryInfo.total + (oneOrder.deliveryInfo.total * 0.13) << endl;
    delOrder->insert(delOrder->end(), oneOrder);

    
}

void addOrder(vector <houseOrder> *hOrder)
{
    houseOrder oneOrder;
    int aux = 0;
    cout << endl << "Nombre:\t";
    getline(cin, oneOrder.houseInfo.name);
    cout << "Personas por mesa:\t";
    cin, oneOrder.pTable;
    cin.ignore();

    cout << "Entrada" << endl;
    cout << "Pan con ajo. Cantidad: ";
    cin >> oneOrder.houseInfo.qGarlic;
    cin.ignore();
    cout << "Pizza rolls. Cantidad: ";
    cin >> oneOrder.houseInfo.qPizzaRolls;
    cin.ignore();
    cout << "Palitos de queso. Cantidad: " << endl;
    cin >> oneOrder.houseInfo.qCheese;
    cin.ignore();

    cout << "Plato principal" << endl;
    cout << "Pizza. Cantidad: ";
    cin >> oneOrder.houseInfo.qPizza;
    cin.ignore();
    cout << "Pasta. Cantidad: ";
    cin >> oneOrder.houseInfo.qPasta;
    cin.ignore();
    cout << "Lasagna. Cantidad: ";
    cin >> oneOrder.houseInfo.qLasagna;
    cin.ignore();

    cout << "Bebida" << endl;
    cout << "Cerveza. Cantidad: ";
    cin >> oneOrder.houseInfo.qBeer;
    cin.ignore();
    cout << "Soda. Cantidad: ";
    cin >> oneOrder.houseInfo.qSoda;
    cin.ignore();
    cout << "Te helado. Cantidad: ";
    cin >> oneOrder.houseInfo.qTea;
    cin.ignore();
    oneOrder.houseInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1 - Tarjeta" << endl;
    cout << "2 - Efectivo" << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        oneOrder.houseInfo.pay = card;
    else if (aux == 2)
        oneOrder.houseInfo.pay = cash;

    oneOrder.houseInfo.total = ((oneOrder.houseInfo.qGarlic * 3.99) + (oneOrder.houseInfo.qPizzaRolls * 4.99) + (oneOrder.houseInfo.qCheese * 3.75) + (oneOrder.houseInfo.qPizza * 13.99) + (oneOrder.houseInfo.qPasta * 5.55) + (oneOrder.houseInfo.qLasagna * 6.25) + (oneOrder.houseInfo.qBeer * 1.99) + (oneOrder.houseInfo.qSoda * 0.95) + (oneOrder.houseInfo.qTea *1.15));
    cout << "Monto: $" << oneOrder.houseInfo.total + (oneOrder.houseInfo.total * 0.13) << endl;
    hOrder->insert(hOrder->end(), oneOrder);

}

/*void seeOrders(vector <delivery> *delOrder){
    for(int i = 0; i < delOrder->size(); i++){
        cout << endl << "Nombre:\t" << (delOrder + i)->deliveryInfo.name << endl;
        cout << "Telefono: " << (delOrder + i)->cellphone << endl;
        cout << "Direccion" << endl;
        cout << "Colonia:\t" << (delOrder[i])->deliveryAddress.settlement << endl;
        cout << "Municipio:\t" << delOrder[i].deliveryAddress.municipality << endl;
        cout << "Departamento:\t" << delOrder[i].deliveryAddress.department << endl;
        cout << "No. casa:\t" << delOrder[i].deliveryAddress.houseNumber << endl;

        cout << "Entrada" << endl;
        cout << "Pan con ajo. Cantidad: " << delOrder[i].deliveryInfo.qGarlic << endl;
        cout << "Pizza rolls. Cantidad: " << delOrder[i].deliveryInfo.qPizzaRolls << endl;
        cout << "Palitos de queso. Cantidad: " << delOrder[i].deliveryInfo.qCheese << endl;

        cout << "Plato principal" << endl;
        cout << "Pizza. Cantidad: " << delOrder[i].deliveryInfo.qPizza << endl;
        cout << "Pasta. Cantidad: " << delOrder[i].deliveryInfo.qPasta << endl;
        cout << "Lasagna. Cantidad: " << delOrder[i].deliveryInfo.qLasagna << endl;

        cout << "Bebida" << endl;
        cout << "Cerveza. Cantidad: " << delOrder[i].deliveryInfo.qBeer << endl;
        cout << "Soda. Cantidad: " << delOrder[i].deliveryInfo.qSoda << endl;
        cout << "Te helado. Cantidad: " << delOrder[i].deliveryInfo.qTea << endl;

        cout << delOrder[i].deliveryInfo.idOrder << endl;

        cout << "Tipo de pago: " << delOrder[i].deliveryInfo.pay << endl;

        cout << "Monto: " << delOrder[i].deliveryInfo.total << endl;
    }

}

void seeOrders(vector <houseOrder> *hOrder){

}

/*void searchByName(delivery *array, int size)
{
    bool userExists = false;
    string aux = "";
    cout << "Nombre a buscar: ";
    getline(cin, aux);

    for (int i = 0; i < size; i++)
    {
        if (aux.compare(oneOrder.deliveryInfo.name) == 0)
        {
            //Imprimir datos
            userExists = true;
        }
    }

    (!userExists) ? cout << "No existe el usuario" : cout << "";
}

void searchByName(houseOrder *array, int size)
{
    bool userExists = false;
    string aux = "";
    cout << "Nombre a buscar: ";
    getline(cin, aux);

    for (int i = 0; i < size; i++)
    {
        if (aux.compare(oneOrder.houseInfo.name) == 0)
        {
            //Imprimir datos quitar direccion, telefono y agregar personas por mesa
            userExists = true;
        }
    }

    (!userExists) ? cout << "No existe el usuario" : cout << "";
}*/