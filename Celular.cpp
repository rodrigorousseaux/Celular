#include <iostream>
using namespace std;

void imprimirResultados(float masDiezCaracteres, int cantidadMensajes, int llamadaMasLarga){

    float promedioMensajes = 0;

    promedioMensajes = (masDiezCaracteres / cantidadMensajes) * 100;
    cout << "La llamada mas larga fue de: " << llamadaMasLarga << " minutos" << endl;
    cout << "El promedio de mensajes con más de diez caracteres es: " << promedioMensajes << "%" << endl;

    return;
}

void bateriaAgotada(int bateria){

    if (bateria < 1){
      cout << "-------------------" << endl;
      cout << "SE AGOTO LA BATERIA" << endl;
      cout << "-------------------" << endl;
    }

    return;
}

void actualizarBateria(int& valorBateriaActual){
    
    cout << "Bateria: " << valorBateriaActual << "%" << endl;
    cout << endl;

    return;
}

void tomarFoto(int& valorBateriaActual){

    int numero;

    if(valorBateriaActual < 6){
        cout << "No se puede tomar fotos. Bateria baja." << endl;
        cout << endl;
    }
    else{
        cout << "Ingrese '1' para tomar la foto: ";
        cin >> numero;

        cout << endl;
        cout << "********FOTO TOMADA********" << endl;
        cout << endl;

        valorBateriaActual = valorBateriaActual - (valorBateriaActual * 0,06);

        actualizarBateria(valorBateriaActual);
    }

    return;
}

void realizarLlamada(int& ultimaLlamada, int& llamadaMasLarga, int& valorBateriaActual){

    cout << "Cuanto minutos duró la llamada?: ";
    cin >> ultimaLlamada;
    const float BATERIA_POR_LLAMADA = ultimaLlamada * 0.08;

    if (ultimaLlamada > llamadaMasLarga){
        llamadaMasLarga = ultimaLlamada;
    }

    valorBateriaActual = valorBateriaActual - BATERIA_POR_LLAMADA;

    actualizarBateria(valorBateriaActual);

    return;
}

void enviarMensaje(float& masDiezCaracteres, float& cantidadMensajes, int& valorBateriaActual){
    
    int caracteres = 0;
    cout << "Cuantos caracteres tuvo el mensaje?: ";
    cin >> caracteres;

    if(caracteres > 10){
        masDiezCaracteres = masDiezCaracteres + 1;
    }

    cantidadMensajes = cantidadMensajes + 1;
    
    valorBateriaActual = valorBateriaActual - (valorBateriaActual * 0,01);

    actualizarBateria(valorBateriaActual);

    return;
}

int opciones(int numeroOpcion){

    cout << "1)Enviar un mensaje de texto." << endl;
    cout << "2)Realizar una llamada." << endl;
    cout << "3)Tomar fotos." << endl;
    cout << "4)Apagar." << endl;
    cout << endl;

    cout << "Ingrese la opcion que desee: ";
    cin >> numeroOpcion;

    return numeroOpcion;
}

void menu(int& valorBateriaActual, float& masDiezCaracteres, float& cantMensajes, int& llamadaMasLarga){

    int numeroOpcion = 0, ultimaLlamada;
    
    numeroOpcion = opciones(numeroOpcion);

    while(numeroOpcion != 4 && valorBateriaActual >= 1){

        switch(numeroOpcion){

          case 1:  enviarMensaje(masDiezCaracteres, cantMensajes, valorBateriaActual);
          break;
          case 2:  realizarLlamada(ultimaLlamada, llamadaMasLarga, valorBateriaActual);
          break;
          case 3:  tomarFoto(valorBateriaActual);
          break;
          default: break;
        }

        if(valorBateriaActual >= 1){
           numeroOpcion = opciones(numeroOpcion);
        }
        else{
           bateriaAgotada(valorBateriaActual);  
        }  
    }
    
    cout << endl;

    return;
}

int main(){

    int numeroOpcion, valorBateriaActual, llamadaMasLarga = 0;
    float masDiezCaracteres = 0, cantidadMensajes = 0;
    
    cout << "Bienvenido a su celular" << endl;
    cout << "-----------------------" << endl;

    cout << "Ingrese el valor inicial de la batería: ";
    cin >> valorBateriaActual;

    actualizarBateria(valorBateriaActual);

    menu(valorBateriaActual, masDiezCaracteres, cantidadMensajes, llamadaMasLarga);

    imprimirResultados(masDiezCaracteres, cantidadMensajes, llamadaMasLarga);
            
    return 0;
}
