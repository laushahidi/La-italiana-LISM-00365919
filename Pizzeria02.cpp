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
    cout << "\n6- Borrar pedidos.";
    cout << "\n7- Cambiar de usuario";
    cout << "\n8- Salir \n\nEliga una opcion (escriba el numero): ";
}

struct PAddress{
    float Nocasa;
    string residence, city, department;
};

struct Delivery{
    string name;
    PAddress address;
    double phone;
    int food, dish, drink, payment;
    float total;
};

struct Restaurant{
    string name2;
    int peoplepertable, food2, dish2, drink2, payment2;
    float total2;
};

// Funcion para agregar un pedido a domicilio
void addDelivery(struct Delivery *deliv, int *size){
    
    // Pidiendo los datos del pedido
    for(int i = 0; i < *size; i++){
        cout << "\nAgregar un pedido a domicilio\n";
        cin.ignore();
        cout << "Nombre: "; getline(cin, (deliv + i)->name);
        cout << "Numero de casa: "; cin >> (deliv + i)->address.Nocasa;
        cout << "Colonia: "; getline(cin, (deliv + i)->address.residence);
        cout << "Municipio: "; getline(cin, (deliv + i)->address.city);
        cout << "Departamento: "; getline(cin, (deliv + i)->address.department);
        cout << "Telefono: "; cin >> (deliv + i)->phone;
        cout << "\n1. Pizza \n2. Ensalada \n3. Pasta \n\nPlato principal (eliga la opcion segun numeral): ";
        cin >> (deliv + i)->food;
        cin.ignore();

        
        while(((deliv + i)->food > 3)||((deliv + i)->food == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 3: ";
            cin >> (deliv + i)->food;
        }
        
        cout << "\n1. Palitroques \n2. Dedos de queso \n\nEntrada (eliga la opcion segun numeral): ";
        cin >> (deliv + i)->dish;
        
        while(((deliv + i)->dish > 2)||((deliv + i)->dish == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
            cin >> (deliv + i)->dish;
        }
        
        cout << "\n1. Gaseosa \n2. Té \n\nBebida (eliga la opcion segun numeral): ";
        cin >> (deliv + i)->drink;
        
        while((deliv + i)->drink > 2 or ((deliv + i)->drink == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
            cin >> (deliv + i)->drink;
        }
        

        (deliv + i)->total = 9.50;  
        
        cout << "\nPlato principal $5 \nEntrada $3 \nBebida $1.50 \nTotal a pagar: $" << (deliv + i)->total;
        cout <<"\n\nTipo de pago: \n1. Tarjeta de credito/debito \n2. Efectivo \n\nSeleccione una opcion segun numeral: ";
        cin >> (deliv + i)->payment;
        
        while(((deliv + i)->payment > 2)||((deliv + i)->payment == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
            cin >> (deliv + i)->payment;
        }
    }
}

// Funcion para agregar un encargo de restaurante
void addRestOrder(struct Restaurant *rest, int *size2){
    
    // Pidiendo los datos del encargo
    for(int i = 0; i < *size2; i++){
        cout << "\nAgregar encargo en restaurante\n";
        cout << "Nombre: "; getline(cin, (rest + i)->name2);
        cout << "Personas por mesa: "; cin >> (rest + i)->peoplepertable;
        cout << "\n1. Pizza \n2. Ensalada \n3. Pasta \n\nPlato principal (eliga la opcion segun numeral): "; cin >> (rest + i)->food2;
        
        while(((rest + i)->food2 > 3)||((rest + i)->food2 == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 3: ";
            cin >> (rest + i)->food2;
        }
        
        cout << "\n1. Palitroques \n2. Dedos de queso \n\nEntrada (eliga la opcion segun numeral): ";
        cin >> (rest + i)->dish2;
        
        while(((rest + i)->dish2 > 2)||((rest + i)->dish2 == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
            cin >> (rest + i)->dish2;
        }
        
        cout << "\n1. Gaseosa \n2. Té \n\nBebida (eliga la opcion segun numeral): ";
        cin >> (rest + i)->drink2;
        
        while(((rest + i)->drink2 > 2)||((rest + i)->drink2 == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
            cin >> (rest + i)->drink2;
        }

        (rest + i)->total2 = (rest + i)->peoplepertable * 9.50;
        cout << "\nPlato principal $5 \nEntrada $3 \nBebida $1.50 \nTotal a pagar: $" << (rest + i)->total2;
        cout <<"\n\nTipo de pago: \n1. Tarjeta de credito/debito \n2. Efectivo \n\nSeleccione una opcion segun numeral: ";
        cin >> (rest + i)->payment2;
        
        while(((rest + i)->payment2 > 2)||((rest + i)->payment2 == 0)){
            cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 2: ";
            cin >> (rest + i)->payment2;
        }
    }
}

// Funcion para visualizar la orden a domicilio
void deliveryOrder(struct Delivery *deliv, int *size){
    cout << "\nPedidos adomicilio: " << *size << endl;

    for(int i = 0; i < *size; i++){
        cout << "\nNombre: " << (deliv + i)->name << endl << "Numero de casa: " << (deliv + i)->address.Nocasa << endl;
        cout << "Colonia: " << (deliv + i)->address.residence << endl << "Municipio: " << (deliv + i)->address.city << endl;
        cout << "Departamento: " << (deliv + i)->address.department << endl << "Telefono: " << (deliv + i)->phone << endl;
        cout << "Plato principal: ";
        
        // Decisiones dependiendo de la opcion que se haya ingresado de comida y bebida
        if((deliv + i)->food == 1){
            cout << "Pizza" << endl;
        }
        
        else if((deliv + i)->food == 2){
            cout << "Ensalada" << endl;
        }
        
        else{
            cout << "Pasta" << endl;
        }
        
        cout << "Entrada: ";
        
        if((deliv + i)->dish == 1){
            cout << "Palitroques" << endl;
        }
        
        else{
            cout << "Dedos de queso" << endl;
        }
        
        cout << "Bebida: ";
        
        if((deliv + i)->drink == 1){
            cout << "Gaseosa" << endl;
        }
        
        else{
            cout << "Té" << endl;
        }
        
        cout << "Tipo de pago: ";
        
        if((deliv + i)->payment == 1){
            cout << "Tarjeta de credito/debito" << endl;
        }
        
        else{
            cout << "Efectivo" << endl;
        }
        
        cout << "\nTotal a pagar: $9.50" << endl;
    }
}

// Funcion para visualizar la orden en restaurante
void restOrder(struct Restaurant *rest, int *size2){
    
    cout << "\nPedidos en restaurante: " << *size2 << endl;

    for(int i = 0; i < *size2; i++){
        cout << "\nNombre: " << (rest + i)->name2 << endl;
        cout << "Personas en la mesa: " << (rest + i)->peoplepertable << endl;
        cout << "Plato principal: ";
        
        if((rest + i)->food2 == 1){
            cout << "Pizza" << endl;
        }
        
        else if((rest + i)->food2 == 2){
            cout << "Ensalada" << endl;
        }
        
        else{
            cout << "Pasta" << endl;
        }
        
        cout << "Entrada: ";
        if((rest + i)->dish2 == 1){
            cout << "Palitroques" << endl;
        }
        
        else{
            cout << "Dedos de queso" << endl;
        }
        
        cout << "Bebida: ";
        if((rest + i)->drink2 == 1){
            cout << "Gaseosa" << endl;
        }
        
        else{
            cout << "Té" << endl;
        }
        
        cout << "Tipo de pago: ";
        if((rest + i)->payment2 == 1){
            cout << "Tarjeta de credito/debito" << endl;
        }
        
        else{
            cout << "Efectivo" << endl;
        }
        
        cout << "\nTotal a pagar: $" << (rest + i)->total2 << endl;
    }
    
}

// Funcion para visualizar el total de ventas
void totalOrders(struct Delivery *deliv, struct Restaurant *rest, int x, int y, int *size, int *size2){
    
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
            cout << "\nSe han realizado " << *size << " pedidos adomicilio: " << endl;
            for(int i = 0; i < *size; i++){
                cout << "\nPedido " << i+ 1 << " a domicilio: $" << (deliv + i)->total;
            }
        }
        
        if(y == 0){
            cout << "\nNo se han realizado encargos en restaurante." << endl;
        }
        else{
            cout << "\nSe han realizado " << *size2 << " pedidos adomicilio: " << endl;
            for(int i = 0; i < *size2; i++){
                cout << "\nPedido " << i + 1 << " en restaurante: $" << (rest + i)->total2 << endl;
            }
        }
    }
}

// Menu principal
int main()
{

    // Delcaracion de variables globales
    string password, user;
    int x, y, option, decision, AdminEmployee, size, size2;
    Delivery* deliv;
    Restaurant* rest;
    
    cout << "Sistema de despacho pizzeria La Italiana" << endl;
    cout << "1. Administrador \n2. Empleado \nIngrese 1 o 2: "; 
    cin >> AdminEmployee;

    while((AdminEmployee != 1) and (AdminEmployee != 2)){
        cout << "Ingrese 1 para administrador y 2 para empleado: "; 
        cin >> AdminEmployee;
    }


    if(AdminEmployee == 1){
        cout << "\nUsuario: ";
        cin >> user;        
        cout << "\nIngrese la contraseña: ";
        cin >> password;

        // Mientras la contraseña no sea correcta, la sigue pidiendo
        while(password != "header"){
            cout << "Contraseña incorrecta, por favor vuelva a ingresarla: ";
            cin >> password;
        }
    }

    else{
        cin.ignore();
        cout << "Usuario: "; getline(cin, user);
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
        
        while((option > 8)||(option < 1)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 8: ";
        cin >> option;
        }
        
        switch(option){
            case 1: 
            x = 1, cout << "Cantidad de ordenes a ingresar: "; cin >> size; deliv = new Delivery[size]; addDelivery(deliv, &size); break;
            case 2: 
            y = 1, cout << "Cantidad de ordenes a ingresar: "; cin >> size2; rest = new Restaurant[size2];addRestOrder(rest, &size2);
            cout << "\nLa orden ha sido registrada exitosamente. "; break;
            case 3: 
            if(x == 0){
                cout << "Aun no se ha registrado ningun pedido a domicilio. " << endl;
            }
            else{
                deliveryOrder(deliv, &size);
            } 
            break;
            case 4: 
            if(y == 0){
                cout << "Aun no se ha registrado ningun encargo en restaurante. " << endl;
            }
            else{
                restOrder(rest, &size2);
            }
            break;
            case 5: 
            totalOrders(deliv, rest, x, y, &size, &size2); break;
            case 6: 
            if(AdminEmployee == 1){
                //borrar pedido
            }
            else{
                cout << "\nNo tiene suficientes permisos" << endl;
            }

            break;
            case 7:
            cout << "\nCambio de usuario" << endl;
            cout << "\n1. Administrador \n2. Empleado \nIngrese 1 o 2: "; 
            cin >> AdminEmployee;

            while((AdminEmployee != 1) and (AdminEmployee != 2)){
            cout << "\nIngrese 1 para administrador y 2 para empleado: "; 
            cin >> AdminEmployee;
            }

            if(AdminEmployee == 1){
                cin.ignore();
                cout << "\nUsuario: "; getline(cin, user);
                cout << "\nContraseña: "; cin >> password;
                while(password != "header"){
                cout << "\nContraseña incorrecta, por favor vuelva a ingresarla: ";
                cin >> password;
                }
            }
            
            else{
                cout << "\nUsuario: "; getline(cin, user);
                cin.ignore();
            }            

            break;
            case 8: continuar = false;
        }

    }while(continuar);


    // Opcion 6 es para salir
    if(option == 8){
        cout << "\nSalida exitosa" << endl;
    }
       
    
    return 0;

}