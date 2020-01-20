#include <iostream>
#include <string> 
using namespace std;

// Funcion para mostrar menu principal
void Menu(){
    cout << "\nMenu principal: \n";
    cout << "\n1- Agregar un pedido a domicilio.";
    cout << "\n2- Agregar un encargo en restaurante.";
    cout << "\n3- Ver pedidos a domicilio.";
    cout << "\n4- Ver encargos en el restaurante.";
    cout << "\n5- Ver total de venta.";
    cout << "\n6- Buscar orden a domicilio por nombre de cliente.";
    cout << "\n7- Buscar orden en restaurante por nombre de cliente.";
    cout << "\n8- Borrar orden a domicilio.";
    cout << "\n9- Borrar orden de restaurante.";
    cout << "\n10- Cambiar de usuario.";
    cout << "\n11- Salir \n\nEliga una opcion (escriba el numero): ";
}

struct PAddress{
    float Nocasa;
    string residence, city, department;
};

struct Delivery{
    string name, code;
    PAddress address;
    double phone;
    int food, dish, drink, payment;
    float total;
};

struct Restaurant{
    string name2, code2;
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
        cin.ignore();
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
        (deliv + i)->code = 'D' + to_string(i+1);
    }
}

// Funcion para agregar un encargo de restaurante
void addRestOrder(struct Restaurant *rest, int *size2){
   
    // Pidiendo los datos del encargo
    for(int i = 0; i < *size2; i++){
        cout << "\nAgregar encargo en restaurante\n";
        cin.ignore();
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
        (rest + i)->code2 = 'R' + to_string(i+1);
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

        cout << "\nNumero de orden: " << (deliv + i)->code << endl;
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
        cout << "\nNumero de orden: " << (rest + i)->code2 << endl;
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
            cout << "\nSe han realizado " << *size << " pedidos a domicilio: " << endl;
            for(int i = 0; i < *size; i++){
                cout << "\nPedido " << i+ 1 << " a domicilio: $" << (deliv + i)->total;
            }
        }
       
        if(y == 0){
            cout << "\nNo se han realizado encargos en restaurante." << endl;
        }
        else{
            cout << "\nSe han realizado " << *size2 << " pedidos en restaurante: " << endl;
            for(int i = 0; i < *size2; i++){
                cout << "\nPedido " << i + 1 << " en restaurante: $" << (rest + i)->total2 << endl;
            }
        }
    }
}


int buscarPedidoDelivery(struct Delivery *deliv, int *size){
    string unNombre;
    cout << "Nombre a buscar: ";
    getline(cin, unNombre);
   
    // Si se encuentra en el resgistro, se muestra y termina funcion
    for (int i = 0; i < *size; i++) {
        if(unNombre.compare((deliv + i)->name) == 0){
            cout << "Pedido encontrado:\n";
            cout << "\nNombre: " << (deliv + i)->name << endl;
            cout << "Numero de casa: " << (deliv + i)->address.Nocasa << endl;
            cout << "Colonia: " << (deliv + i)->address.residence << endl;
            cout << "Municipio: " << (deliv + i)->address.city << endl;
            cout << "Departamento: " << (deliv + i)->address.department << endl;
            cout << "Telefono: " << (deliv + i)->phone << endl;
            cout << "Plato principal: ";
       
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
            cout << "\nNumero de orden: " << (deliv + i)->code << endl;
            // Un return dentro de una funcion hace que esta termine
            return i;
        }
    }
   
    // Si se busco en todas las casillas y no se encontro:
    cout << "\nNo se encontró ningún pedido bajo ese nombre.\n";
    return -1;

}

int buscarPedidoRestaurant(struct Restaurant *rest, int *size2){
    string unNombre;
    cout << "Nombre a buscar: ";
    getline(cin, unNombre);
   
    // Si se encuentra en el resgistro, se muestra y termina funcion
    for (int i = 0; i < *size2; i++) {
        if(unNombre.compare((rest + i)->name2) == 0){
            cout << "Pedido encontrado:\n";
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
            cout << "\nNumero de orden: " << (rest + i)->code2 << endl;
            // Un return dentro de una funcion hace que esta termine
            return i;
        }
    }
   
    // Si se busco en todas las casillas y no se encontro:
    cout << "\nNo se encontró ningún pedido bajo ese nombre.\n";
    return -1;

}

void borrarPedidoDelivery(struct Delivery *deliv, int *size){
    int des, x = buscarPedidoDelivery(deliv, size);
    if(x >= 0){
        cout << "¿Desea eliminar el pedido? \nSi (1) \nNo (2)" << endl;
        cin >> des;
        while((des != 1) and (des != 2)){
            cout << "Ingrese '1' para si y '2' para no";
            cin >> des;
        }
        if(des == 1){
            for(int i = x; i < *size-1; i++){
                (deliv + i)->name = (deliv + (i+1))->name;
                (deliv + i)->address.Nocasa = (deliv + (i+1))->address.Nocasa;
                (deliv + i)->address.residence = (deliv + (i+1))->address.residence;
                (deliv + i)->address.city = (deliv + (i+1))->address.city;
                (deliv + i)->address.department = (deliv + (i+1))->address.department;
                (deliv + i)->phone = (deliv + (i+1))->phone;
                (deliv + i)->food = (deliv + (i+1))->food;
                (deliv + i)->dish = (deliv + (i+1))->dish;
                (deliv + i)->drink = (deliv + (i+1))->drink;     
                (deliv + i)->total = (deliv + (i+1))->total;  
                (deliv + i)->payment = (deliv + (i+1))->payment;
                (deliv + i)->code = (deliv + (i+1))->code;

            }
            *size = *size -1;
        }
        else{
            cout << "\nEl pedido no se ha borrado." << endl;
        }
    }
}

void borrarPedidoRestaurant(struct Restaurant *rest, int *size2){
    int des, x = buscarPedidoRestaurant(rest, size2);
    if(x >= 0){
        cout << "¿Desea eliminar el pedido? \nSi (1) \nNo (2)" << endl;
        cin >> des;
        while((des != 1) and (des != 2)){
            cout << "Ingrese '1' para si y '2' para no";
            cin >> des;
        }
        if(des == 1){
            for(int i = x; i < *size2-1; i++){
                (rest + i)->name2 = (rest + (i+1))->name2;
                (rest + i)->peoplepertable = (rest + (i+1))->peoplepertable;
                (rest + i)->food2 = (rest + (i+1))->food2;
                (rest + i)->dish2 = (rest + (i+1))->dish2;
                (rest + i)->payment2 = (rest + (i+1))->payment2;
                (rest + i)->total2 = (rest + (i+1))->total2;
                (rest + i)->code2 = (rest + (i+1))->code2;

            }
            *size2 = *size2 - 1;
        }
        else{
            cout << "\nEl pedido no se ha borrado." << endl;
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
       
        while((option > 11)||(option < 1)){
        cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 11: ";
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
                cout << "\nAun no se ha registrado ningun pedido a domicilio. " << endl;
            }
            else{
                deliveryOrder(deliv, &size);
            }
            break;
            case 4:
            if(y == 0){
                cout << "\nAun no se ha registrado ningun encargo en restaurante. " << endl;
            }
            else{
                restOrder(rest, &size2);
            }
            break;
            case 5:
            totalOrders(deliv, rest, x, y, &size, &size2); break;
            case 6:
            if(x == 0){
                cout << "\nAun no se ha registrado ningun pedido a domicilio. " << endl;
            }
            else{
                cout << "\nBuscar pedido a domicilio por nombre de cliente: " << endl;
                buscarPedidoDelivery(deliv, &size);
            }
            break;
            case 7:
            if(y == 0){
                cout << "\nAun no se ha registrado ningun pedido en restaurante. " << endl;
            }
            else{
                cout << "\nBuscar pedido en restaurante por nombre de cliente: " << endl;
                buscarPedidoRestaurant(rest, &size2); 
            }
            break;
            case 8:
            if(AdminEmployee == 1){
                if(x == 0){
                cout << "\nAun no se ha registrado ningun pedido a domicilio. " << endl;
                }
                else{
                borrarPedidoDelivery(deliv, &size);
                }
            }
            else{
                cout << "\nNo tiene suficientes permisos" << endl;
            }
            break;
            case 9:
            if(AdminEmployee == 1){
                if(y == 0){
                cout << "\nAun no se ha registrado ningun pedido en restaurante. " << endl;
                }
                else{
                borrarPedidoRestaurant(rest, &size2);
                }
            }
            else{
                cout << "\nNo tiene suficientes permisos" << endl;
            }
            break;
            case 10:
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
                cin.ignore();
                cout << "\nUsuario: "; getline(cin, user);
            }      
            break;
            case 11: continuar = false;
        }

    }while(continuar);


    // Opcion 6 es para salir
    if(option == 11){
        cout << "\nSalida exitosa" << endl;
    }
       
   
    return 0;

}