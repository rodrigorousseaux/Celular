#include <stdio.h>

void imprimirResultados(float masDiezCaracteres, int cantidadMensajes, int llamadaMasLarga){

    float promedioMensajes = 0;

    promedioMensajes = (masDiezCaracteres / cantidadMensajes) * 100;

    printf("\nLa llamada mas larga fue de: %i minutos \n", llamadaMasLarga);
    printf("El promedio de mensajes con más de diez caracteres es: %f % \n", promedioMensajes);

    return;
}

void bateriaAgotada(){

    printf("-------------------");
    printf("SE AGOTO LA BATERIA");
    printf("-------------------");

    return;
}

void actualizarBateria(int *valorBateriaActual){
    
    printf("\nBateria: %d %\n", *valorBateriaActual);
    printf("\n");

    return;
}

void tomarFoto(int *valorBateriaActual){

    int numero;

    if(*valorBateriaActual < 6){
        printf("\n********NO SE PUEDE TOMAR FOTOS. BATERIA BAJA********\n");
        printf("\n");
    }
    else{
        printf("Ingrese '1' para tomar la foto: ");
        scanf("%i", &numero);

        printf("\n");
        printf("********FOTO TOMADA********");
        printf("\n");

        *valorBateriaActual = *valorBateriaActual - (*valorBateriaActual * 0,06);

        actualizarBateria(&*valorBateriaActual);
    }

    return;
}

void realizarLlamada(int *llamadaMasLarga, int *valorBateriaActual){

    int ultimaLlamada = 0;

    printf("Cuanto minutos duro la llamada?: ");
    scanf("%i", &ultimaLlamada);

    const float BATERIA_POR_LLAMADA = ultimaLlamada * 0.08;

    if (ultimaLlamada > *llamadaMasLarga){
        *llamadaMasLarga = ultimaLlamada;
    }

    *valorBateriaActual -= BATERIA_POR_LLAMADA;

    actualizarBateria(valorBateriaActual);

    return;
}

void enviarMensaje(float *masDiezCaracteres, float *cantidadMensajes, int *valorBateriaActual){
    
    int caracteres = 0;
    printf("Cuantos caracteres tuvo el mensaje?: ");
    scanf("%i", &caracteres);

    if(caracteres > 10){
        *masDiezCaracteres += 1;
    }

    *cantidadMensajes += 1;
    
    *valorBateriaActual = *valorBateriaActual - (*valorBateriaActual * 0,01);

    actualizarBateria(&*valorBateriaActual);

    return;
}

int opciones(int numeroOpcion){

    printf("1)Enviar un mensaje de texto.\n");
    printf("2)Realizar una llamada.\n");
    printf("3)Tomar fotos.\n");
    printf("4)Apagar.\n");
    printf("\n");

    printf("Ingrese la opcion que desee: ");
    scanf("%i", &numeroOpcion);

    return numeroOpcion;
}

void menu(int *valorBateriaActual, float *masDiezCaracteres, float *cantMensajes, int *llamadaMasLarga){

    int numeroOpcion = 0;
    
    numeroOpcion = opciones(numeroOpcion);

    while(numeroOpcion != 4 && *valorBateriaActual >= 1){

        switch(numeroOpcion){

          case 1:  enviarMensaje(&*masDiezCaracteres, &*cantMensajes, &*valorBateriaActual);
          break;
          case 2:  realizarLlamada(&*llamadaMasLarga, &*valorBateriaActual);
          break;
          case 3:  tomarFoto(&*valorBateriaActual);
          break;
          default: break;
        }

        if(*valorBateriaActual >= 1){
           numeroOpcion = opciones(numeroOpcion);
        }
        else{
           bateriaAgotada();  
        }  
    }
    
    printf("\n");

    return;
}

int main(){

    int numeroOpcion, valorBateriaActual, llamadaMasLarga = 0;
    float masDiezCaracteres = 0, cantidadMensajes = 0;
    
    printf("Bienvenido a su celular\n");
    printf("-----------------------\n");

    printf("Ingrese el valor inicial de la bateria: ");
    scanf("%i", &valorBateriaActual);

    actualizarBateria(&valorBateriaActual);

    menu(&valorBateriaActual, &masDiezCaracteres, &cantidadMensajes, &llamadaMasLarga);

    imprimirResultados(masDiezCaracteres, cantidadMensajes, llamadaMasLarga);
            
    return 0;
}
