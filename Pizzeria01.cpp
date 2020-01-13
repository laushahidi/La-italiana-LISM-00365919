#include <iostream>
using namespace std;

// Funcion para mostrar menu principal
void Menu(){
    cout << "\nMenu principal: ";
    cout << "\n1- Agregar un pedido a domicilio.";
    cout << "\n2- Agregar un encargo en restaurante.";
    cout << "\n3- Ver pedidos a domicilio.";
    cout << "\n4- Ver encargos en el restaurante.";
    cout << "\n5- Ver total de venta.";
    cout << "\n6- Salir \n\nEliga una opcion (escriba el numero): ";
}

// Funcion para agregar un pedido a domicilio
void addDelivery(string *name, string *address, int *phone, int *food, int *dish, int *drink, float *total, int *payment){
    
    // Pidiendo los datos del pedido
    cout << "\nAgregar un pedido a domicilio\n";
    cout << "Nombre: ";
    cin >> *name;
    cin.ignore();
    cout << "Direccion: ";
    getline(cin, *address);
    cout << "Telefono: ";
    cin >> *phone;
    cout << "\n1. Pizza \n2. Ensalada \n3. Pasta \n\nPlato principal (eliga la opcion segun numeral): ";
    cin >> *food;
    
    while((*food > 3)||(*food == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 3: ";
        cin >> *food;
    }
    
    cout << "\n1. Palitroques \n2. Dedos de queso \n\nEntrada (eliga la opcion segun numeral): ";
    cin >> *dish;
    
    while((*dish > 2)||(*dish == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
        cin >> *dish;
    }
    
    cout << "\n1. Gaseosa \n2. Té \n\nBebida (eliga la opcion segun numeral): ";
    cin >> *drink;
    
    while((*drink > 2)||(*drink == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
        cin >> *drink;
    }
    

    *total = 9.50;  
    
    cout << "\nPlato principal $5 \nEntrada $3 \nBebida $1.50 \nTotal a pagar: $" << *total;
    cout <<"\n\nTipo de pago: \n1. Tarjeta de credito/debito \n2. Efectivo \n\nSeleccione una opcion segun numeral: ";
    cin >> *payment;
    
    while((*payment > 2)||(*payment == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
        cin >> *payment;
    }
}

// Funcion para agregar un encargo de restaurante
void addRestOrder(string *name2, int *peoplepertable, int *food2, int *dish2, int *drink2, float *total2, int *payment2){

    // Pidiendo los datos del encargo
    cout << "\nAgregar encargo en restaurante\n";
    cout << "Nombre: ";
    cin >> *name2;
    cout << "Personas por mesa: ";
    cin >> *peoplepertable;
    cout << "\n1. Pizza \n2. Ensalada \n3. Pasta \n\nPlato principal (eliga la opcion segun numeral): ";
    cin >> *food2;
    
    while((*food2 > 3)||(*food2 == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 3: ";
        cin >> *food2;
    }
    
    cout << "\n1. Palitroques \n2. Dedos de queso \n\nEntrada (eliga la opcion segun numeral): ";
    cin >> *dish2;
    
    while((*dish2 > 2)||(*dish2 == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
        cin >> *dish2;
    }
    
    cout << "\n1. Gaseosa \n2. Té \n\nBebida (eliga la opcion segun numeral): ";
    cin >> *drink2;
    
    while((*drink2 > 2)||(*drink2 == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
        cin >> *drink2;
    }

    *total2 = *peoplepertable * 9.50;
    cout << "\nPlato principal $5 \nEntrada $3 \nBebida $1.50 \nTotal a pagar: $" << *total2;
    cout <<"\n\nTipo de pago: \n1. Tarjeta de credito/debito \n2. Efectivo \n\nSeleccione una opcion segun numeral: ";
    cin >> *payment2;
    
    while((*payment2 > 2)||(*payment2 == 0)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
        cin >> *payment2;
    }
}

// Funcion para visualizar la orden a domicilio
void deliveryOrder(string *name, string *address, int *phone, int *food, int *dish, int *drink, float *total, int *payment){
    cout << "\nPedido adomicilio: 1" << endl;
    cout << "\nNombre: " << *name << endl << "Direccion: " << *address << endl << "Telefono: " << *phone << endl;
    cout << "Plato principal: ";
    
    // Decisiones dependiendo de la opcion que se haya ingresado de comida y bebida
    if(*food == 1){
        cout << "Pizza" << endl;
    }
    
    else if(*food == 2){
        cout << "Ensalada" << endl;
    }
    
    else{
        cout << "Pasta" << endl;
    }
    
    cout << "Entrada: ";
    
    if(*dish == 1){
        cout << "Palitroques" << endl;
    }
    
    else{
        cout << "Dedos de queso" << endl;
    }
    
    cout << "Bebida: ";
    
    if(*drink == 1){
        cout << "Gaseosa" << endl;
    }
    
    else{
        cout << "Té" << endl;
    }
    
    cout << "Tipo de pago: ";
    
    if(*payment == 1){
        cout << "Tarjeta de credito/debito" << endl;
    }
    
    else{
        cout << "Efectivo" << endl;
    }
    
    cout << "\nTotal a pagar: $9.50" << endl;
}

// Funcion para visualizar la orden en restaurante
void restOrder(string *name2, int *peoplepertable, int *food2, int *dish2, int *drink2, float *total2, int *payment2){
    
    cout << "\nPedido en restaurante: 1" << endl;
    cout << "\nNombre: " << *name2 << endl;
    cout << "Personas en la mesa: " << *peoplepertable << endl;
    cout << "Plato principal: ";
    
    if(*food2 == 1){
        cout << "Pizza" << endl;
    }
    
    else if(*food2 == 2){
        cout << "Ensalada" << endl;
    }
    
    else{
        cout << "Pasta" << endl;
    }
    
    cout << "Entrada: ";
    if(*dish2 == 1){
        cout << "Palitroques" << endl;
    }
    
    else{
        cout << "Dedos de queso" << endl;
    }
    
    cout << "Bebida: ";
    if(*drink2 == 1){
        cout << "Gaseosa" << endl;
    }
    
    else{
        cout << "Té" << endl;
    }
    
    cout << "Tipo de pago: ";
    if(*payment2 == 1){
        cout << "Tarjeta de credito/debito" << endl;
    }
    
    else{
        cout << "Efectivo" << endl;
    }
    
    cout << "\nTotal a pagar: $" << *total2 << endl;
    
}

// Funcion para visualizar el total de ventas
void totalOrders(float *total, float *total2, int x, int y){
    
    cout << "\nTotal de ventas: " << endl;
    
    // Decisiones dependiendo que tipo de pedido se ha realizado o no
    if((x == 0) and (y == 0)){
        cout << "\nNo se han realizado pedidos aun." << endl;
    }
    else{
        if(x == 0){
            cout << "\nNo se han realizado pedidos a domicilio." << endl;
        }
        else{
            cout << "\nPedidos a domicilio: $" << *total;
        }
        
        if(y == 0){
            cout << "\nNo se han realizado encargos en restaurante." << endl;
        }
        else{
            cout << "\nPedidos en restaurante: $" << *total2 << endl;
        }
    }
}

// Menu principal
int main()
{

    // Delcaracion de variables globales
    string password, name, name2, address = "";
    int x, y, option, phone, food, food2, dish, dish2,  drink, drink2, payment, payment2, peoplepertable, decision;
    float total, total2;
    
    cout << "Sistema de despacho pizzeria La Italiana \nIngrese la contraseña: ";
    cin >> password;
    
    // Mientras la contraseña no sea correcta, la sigue pidiendo
    while(password != "header"){
        cout << "Contraseña incorrecta, por favor vuelva a ingresarla: ";
        cin >> password;
    }
    
    // Contadores "y" y "x" para registrar si se realizaron pedidos a domicilio y de restaurante, se utilizan para las opciones 3, 4 y 5 del menu
    y = 0;
    x = 0;
    
    // Decision segun menu principal
    bool continuar = true;
    do{
        option = 0;
        Menu();
        cin >> option;
        cin.ignore();
        
        while((option > 6)||(option < 1)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 6: ";
        cin >> option;
        }
        
        switch(option){
            case 1: 
            x = 1, addDelivery(&name, &address, &phone, &food, &dish, &drink, &total, &payment); break;
            case 2: 
            y = 1, addRestOrder(&name2, &peoplepertable, &food2, &dish2, &drink2, &total2, &payment2);
            cout << "\nLa orden ha sido registrada exitosamente. "; break;
            case 3: 
            if(x == 0){
                cout << "Aun no se ha registrado ningun pedido a domicilio. " << endl;
            }
            else{
                deliveryOrder(&name, &address, &phone, &food, &dish, &drink, &total, &payment);
            } 
            break;
            case 4: 
            if(y == 0){
                cout << "Aun no se ha registrado ningun encargo en restaurante. " << endl;
            }
            else{
                restOrder(&name2, &peoplepertable, &food2, &dish2, &drink2, &total2, &payment2);
            }
            break;
            case 5: 
            totalOrders(&total, &total2, x, y); break;
            case 6: continuar = false;
        }
    }while(continuar);

    
    // Opcion 6 es para salir
    if(option == 6){
        cout << "\nSalida exitosa" << endl;
    }
    
    
    return 0;

}