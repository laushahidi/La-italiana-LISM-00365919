// Librerias utilizadas
#include <iostream> // Cout y cin
#include <vector> // Para crear listas y utilizar las funciones de la libreria vector
#include <algorithm> 
#include <cmath> // Para utilizar ceiling
#include <string> // Para utilizar strings en el programa

// Declaracion de un define para la contraseña del administrador
#define PASSWORD "header"

using namespace std;

// Utilizando enum para el tipo de pago
enum paymentType {cash, card};

// Declaraciones de estructuras

// Sub estructura para almacenar datos de direccion
struct address
{
    string settlement, municipality, department;
    int houseNumber;
};

// Sub estructura para almacenar datos generales a domicilio y en restaurante
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
    float waitingTime;

};

// Estructura para pedidos a domicilio
struct delivery
{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
};

// Estructura para pedidos en restaurante
struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
};

//variables globales
bool isAdmin = false;
int idOrder = 1;

//Declaraciones de prototipos
bool loginUser(void);
void printMenu(void);
void addOrder(vector <delivery> &delOrder);
void addOrder(vector <houseOrder> &hOrder);
void seeOrders(int pos, vector <delivery> &delOrder);
void seeOrders(int pos, vector <houseOrder> &hOrder);
void done(vector <delivery> &delOrder, vector <delivery> &delDone, int id);
void done(vector <houseOrder> &hOrder, vector <houseOrder> &hDone, int id);
void waitTime(vector <delivery> &delOrder);
void waitTime(vector <houseOrder> &hOrder);
void cancelOrder(vector <delivery> &delOrder, int id);
void cancelOrder(vector <houseOrder> &hOrder, int id);
void total(vector <delivery> &delDone, vector <houseOrder> &hDone);

// Programa principal
int main(void)
{
    // Declaracion de variables y vectores a utilizar
    vector <delivery> delOrder;
    vector <houseOrder> hOrder;
    vector <delivery> delDone;
    vector <houseOrder> hDone;
    int idAuxD = 0, idAuxH = 0, cancelidD = 0, cancelidH = 0, orderType = 0;
    int option = 0;

    // Verificacion para iniciar sesion
    cout << "INICIO DE SESION" << endl;
    if (!loginUser()) 
        return 0;

    // Logica principal para la ejecucion del programa (menu)
    do
    {
        printMenu();
        cin >> option;
        cin.ignore();

        switch (option){
        
            case 1:

                // Agregar ordenes a domicilio
                addOrder(delOrder);

            break;
        
            case 2:

                // Agregar ordenes en restaurante
                addOrder(hOrder);

            break;

            case 3:

                // Ver ordenes a domicilio
                if(delOrder.empty()){
                    cout << endl << "No se han agregado ordenes a domicilio nuevas" << endl;
                }
                else{
                    seeOrders(0, delOrder); 
                }
                       
            break;

            case 4:

                // Ver ordenes en restaurante
                if(hOrder.empty()){
                    cout << endl << "No se han agregado ordenes en restaurante nuevas" << endl;
                }
                else{
                    seeOrders(0, hOrder);            
                }
            
            break;

            case 5:

                // Despachar ordenes a domicilio segun numero de orden
                if(delOrder.empty()){
                    cout << endl << "No hay ordenes en espera" << endl;
                }
                else{
                    cout << "¿Que numero de orden a domicilio desea despachar?" << endl;
                    cin >> idAuxD; cin.ignore();
                    done(delOrder, delDone, idAuxD); 
                }
            
            break;

            case 6:

                // Despachar ordenes en restaurante segun numero de orden
                if(delOrder.empty()){
                    cout << endl << "No hay ordenes en espera" << endl;
                }
                else{
                    cout << "¿Que numero de orden en restaurante desea despachar? " << endl;
                    cin >> idAuxH; cin.ignore();
                    done(delOrder, delDone, idAuxH);
                }
            
            break;

            case 7:

                // Tiempo promedio de espera a domicilio de las que no han sido despachadas
                cout << endl << "Tiempo de espera de ordenes a domicilio no despachadas: ";
                waitTime(delOrder);

            break;

            case 8:

                // Tiempo promedio de espera en restaurante de las que no han sido despachadas
                cout << endl << "Tiempo de espera de ordenes en restaurante no despachadas: ";
                waitTime(hOrder);

            break;

            case 9:

                // Cancelar orden a domicilio o restaurante, solo admin
                if(isAdmin == true){

                    cout << "¿Que tipo de orden desea cancelar? \n 1. A domicilio\n 2.Restaurante\n Su opcion: " << endl;
                    cin >> orderType; cin.ignore();
                    while(orderType != 1 && orderType != 2){
                        cout << "Opcion invalida, escriba 1 para a domicilio y 2 para restaurante: "; cin >> orderType; cin.ignore();
                    }
                    if(orderType == 1){
                        if(delOrder.empty()){
                            cout << endl << "No se han agregado ordenes a domicilio nuevas" << endl;
                        }
                        else{
                            cout << "¿Que numero de orden desea cancelar? " << endl;
                            cin >> cancelidD; cin.ignore();
                            cancelOrder(delOrder, cancelidD);
                        }
                    }
                    else{
                        if(hOrder.empty()){
                            cout << endl << "No se han agregado ordenes en restaurante nuevas" << endl;
                        }
                        else{
                            cout << "¿Que numero de orden desea cancelar? " << endl;
                            cin >> cancelidH; cin.ignore();
                            cancelOrder(hOrder, cancelidH);           
                        }
                    }
                    
                }

                else{
                    cout << endl << "No tiene suficientes permisos!" << endl;
                }
            
            break;

            case 10:

                // Calcular total de ventas a domicilio + restaurante ordenes despachadas 2 vectores aux sumados de total
                total(delDone, hDone);

            break;
        
            case 11:

                // Cambiar de usuario
                cout << endl << "CAMBIAR DE USUARIO" << endl;
                if (!loginUser()) 
                    return 0;

            break;

            case 12:

                // Mensaje de salida
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
            while(enterPass.compare(PASSWORD) != 0){
                cout << "Contraseña incorrecta" << endl;
                cout << "Ingrese su contraseña: "; cin >> enterPass;
                if (enterPass.compare(PASSWORD) == 0)
                {
                    isAdmin = true;
                    return true;
                }
            }
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
    cout << endl << "BIENVENIDO AL SISTEMA DE DESPACHO DE LA PIZZERIA LA ITALIANA" << endl;
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
    cout << "Su opcion:\t";
}

void addOrder(vector <delivery> &delOrder)
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
    cout << "Monto: $" << oneOrder.deliveryInfo.total << endl;
    cout << "Total con IVA: $" << (oneOrder.deliveryInfo.total * 1.13) << endl;
    cout << "Numero de orden: " << oneOrder.deliveryInfo.idOrder << endl;
    oneOrder.deliveryInfo.waitingTime = (((oneOrder.deliveryInfo.qGarlic + oneOrder.deliveryInfo.qPizzaRolls + oneOrder.deliveryInfo.qCheese) * 1.10) + ((oneOrder.deliveryInfo.qPizza + oneOrder.deliveryInfo.qPasta + oneOrder.deliveryInfo.qLasagna) * 1.5) + ((oneOrder.deliveryInfo.qBeer + oneOrder.deliveryInfo.qSoda + oneOrder.deliveryInfo.qTea) * 1.35) + 15);
    cout << "Tiempo de espera en minutos: " << ceil(oneOrder.deliveryInfo.waitingTime) << endl;
    delOrder.push_back(oneOrder);

    //Domicilio: (cantidad de entradas * 1.10 + cantidad de platos principales * 1.5 + cantidad de bebidas * 1.35) + 15


    
}

void addOrder(vector <houseOrder> &hOrder)
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
    cout << "Monto: $" << oneOrder.houseInfo.total << endl;
    cout << "Total con IVA: $" << (oneOrder.houseInfo.total * 1.13) << endl;
    cout << "Numero de orden: " << oneOrder.houseInfo.idOrder << endl;

    oneOrder.houseInfo.waitingTime = (((oneOrder.houseInfo.qGarlic + oneOrder.houseInfo.qPizzaRolls + oneOrder.houseInfo.qCheese) * 1.10) + ((oneOrder.houseInfo.qPizza + oneOrder.houseInfo.qPasta + oneOrder.houseInfo.qLasagna) * 1.5) + ((oneOrder.houseInfo.qBeer + oneOrder.houseInfo.qSoda + oneOrder.houseInfo.qTea) * 1.35));
    cout << "Tiempo de espera en minutos: " << ceil(oneOrder.houseInfo.waitingTime) << endl;
    hOrder.push_back(oneOrder);
    //Restaurante: (cantidad de entradas * 1.10 + cantidad de platos principales * 1.5 + cantidad de bebidas * 1.35)

}

void seeOrders(int pos, vector <delivery> &delOrder){
    if(pos == delOrder.size())
        return;
    else{

        cout << endl << "Nombre:\t" << delOrder[pos].deliveryInfo.name << endl;
        cout << "Telefono: " << delOrder[pos].cellphone << endl;
        cout << "Direccion" << endl;
        cout << "Colonia:\t" << delOrder[pos].deliveryAddress.settlement << endl;
        cout << "Municipio:\t" << delOrder[pos].deliveryAddress.municipality << endl;
        cout << "Departamento:\t" << delOrder[pos].deliveryAddress.department << endl;
        cout << "No. casa:\t" << delOrder[pos].deliveryAddress.houseNumber << endl;

        cout << "Entrada" << endl;
        cout << "Pan con ajo. Cantidad: " << delOrder[pos].deliveryInfo.qGarlic << endl;
        cout << "Pizza rolls. Cantidad: " << delOrder[pos].deliveryInfo.qPizzaRolls << endl;
        cout << "Palitos de queso. Cantidad: " << delOrder[pos].deliveryInfo.qCheese << endl;

        cout << "Plato principal" << endl;
        cout << "Pizza. Cantidad: " << delOrder[pos].deliveryInfo.qPizza << endl;
        cout << "Pasta. Cantidad: " << delOrder[pos].deliveryInfo.qPasta << endl;
        cout << "Lasagna. Cantidad: " << delOrder[pos].deliveryInfo.qLasagna << endl;

        cout << "Bebida" << endl;
        cout << "Cerveza. Cantidad: " << delOrder[pos].deliveryInfo.qBeer << endl;
        cout << "Soda. Cantidad: " << delOrder[pos].deliveryInfo.qSoda << endl;
        cout << "Te helado. Cantidad: " << delOrder[pos].deliveryInfo.qTea << endl;

        cout << "Numero de orden: " << delOrder[pos].deliveryInfo.idOrder << endl;

        cout << "Tipo de pago: " << delOrder[pos].deliveryInfo.pay << endl;

        cout << "Monto: " << delOrder[pos].deliveryInfo.total << endl;
        cout << "Tiempo de espera en minutos: " << ceil(delOrder[pos].deliveryInfo.waitingTime) << endl;
        return seeOrders(pos + 1, delOrder);
    }

}

void seeOrders(int pos, vector <houseOrder> &hOrder){
    if(pos == hOrder.size())
        return;
    else{
    
        cout << endl << "Nombre:\t" << hOrder[pos].houseInfo.name << endl;
        
        cout << "Entrada" << endl;
        cout << "Pan con ajo. Cantidad: " << hOrder[pos].houseInfo.qGarlic << endl;
        cout << "Pizza rolls. Cantidad: " << hOrder[pos].houseInfo.qPizzaRolls << endl;
        cout << "Palitos de queso. Cantidad: " << hOrder[pos].houseInfo.qCheese << endl;

        cout << "Plato principal" << endl;
        cout << "Pizza. Cantidad: " << hOrder[pos].houseInfo.qPizza << endl;
        cout << "Pasta. Cantidad: " << hOrder[pos].houseInfo.qPasta << endl;
        cout << "Lasagna. Cantidad: " << hOrder[pos].houseInfo.qLasagna << endl;

        cout << "Bebida" << endl;
        cout << "Cerveza. Cantidad: " << hOrder[pos].houseInfo.qBeer << endl;
        cout << "Soda. Cantidad: " << hOrder[pos].houseInfo.qSoda << endl;
        cout << "Te helado. Cantidad: " << hOrder[pos].houseInfo.qTea << endl;

        cout << "Numero de orden: " << hOrder[pos].houseInfo.idOrder << endl;

        cout << "Tipo de pago: " << hOrder[pos].houseInfo.pay << endl;

        cout << "Monto: " << hOrder[pos].houseInfo.total << endl;
        cout << "Tiempo de espera en minutos: " << ceil(hOrder[pos].houseInfo.waitingTime) << endl;
        return seeOrders(pos + 1, hOrder);
    }
}

void done(vector <delivery> &delOrder, vector <delivery> &delDone, int id){
    cout << endl << "Despachando orden a domicilio.." << endl;
    // for o while !empty
    int i = 0;
    for(auto iter = delOrder.begin(); iter != delOrder.end(); iter++){
        if(iter->deliveryInfo.idOrder == id){
            delDone.push_back(delOrder.at(i));
            iter = delOrder.erase(iter);
        }
        i++;
    }

    cout << "Orden " << id << " a domicilio despachada" << endl;


}

void done(vector <houseOrder> &hOrder, vector <houseOrder> &hDone, int id){
    cout << endl << "Despachando orden en restaurante.." << endl;
    // for o while !empty
    int i = 0;
    for(auto iter = hOrder.begin(); iter != hOrder.end(); ++iter){
        if(iter->houseInfo.idOrder == id){
            hDone.push_back(hOrder.at(i));
            iter = hOrder.erase(iter);
        }
        i++;
    }

    cout << "Orden " << id << " en restaurante despachada" << endl;

}

void waitTime(vector <delivery> &delOrder){
    float waitingTimeTotal = 0;
    for(int i = 0; i < delOrder.size(); i++){
        waitingTimeTotal += delOrder[i].deliveryInfo.waitingTime;
    }
    cout << ceil(waitingTimeTotal) << " minutos" << endl;
}

void waitTime(vector <houseOrder> &hOrder){
    float waitingTimeTotal = 0;
    for(int i = 0; i < hOrder.size(); i++){
        waitingTimeTotal += hOrder[i].houseInfo.waitingTime;
    }
    cout << ceil(waitingTimeTotal) << " minutos" << endl;
}

void cancelOrder(vector <delivery> &delOrder, int id){

    int i = 0;
    for(auto iter = delOrder.begin(); iter != delOrder.end(); iter++){
        if(iter->deliveryInfo.idOrder == id){
            iter = delOrder.erase(iter);
        }
        i++;       
    }
}

void cancelOrder(vector <houseOrder> &hOrder, int id){

    int i = 0;
    for(auto iter = hOrder.begin(); iter != hOrder.end(); iter++){
        if(iter->houseInfo.idOrder == id){
            iter = hOrder.erase(iter);
        }
        i++;       
    }
}
void total(vector <delivery> &delDone, vector <houseOrder> &hDone){
    
    float totalDel = 0, totalH = 0;
    for(int i = 0; i < delDone.size(); i++){
        totalDel += delDone[i].deliveryInfo.total;
    }
    cout << endl << "Monto total de ordenes despachadas a domicilio: $" << totalDel << endl;
    cout << "Total con IVA: $" << totalDel * 1.13 << endl;

    for(int i = 0; i < hDone.size(); i++){
        totalH += hDone[i].houseInfo.total;
    }
    cout << endl << "Monto total de ordenes despachadas en restaurante: $" << totalH << endl;
    cout << "Total con IVA: $" << totalH * 1.13 << endl;

    cout << endl << "Total de ordenes despachadas: $" << totalDel + totalH << endl;
    cout << "Total con IVA: $" << (totalDel + totalH) * 1.13 << endl;
}

