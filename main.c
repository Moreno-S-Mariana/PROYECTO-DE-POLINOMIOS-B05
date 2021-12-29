
#include "funciones.c"

int  menu();
void ayuda ();

int main() {
    int opc, res;
    polinomios *pol;

    do {
        menu();
        fflush( stdin );
        scanf("%d",&opc);
        system("cls");

        if(total_polinomios<=0 && opc!=1 && opc!=2 && opc!=8){
            printf("No existen polinomios primero cree alguno\n\n");
        } else {
            switch(opc) {
                case 1:
                    pol= crear_polinomio();
                    break;
                case 2:
                    pol= obtener_polinomios();
                    break;
                case 3:
                    imprime_polinomios(pol);
                    suma(pol);
                    break;
                case 4:
                    imprime_polinomios(pol);
                    resta(pol);
                    break;
                case 5:
                    imprime_polinomios(pol);
                    multiplicacion_escalar(pol);
                    break;
                case 6:
                    imprime_polinomios(pol);
                    multiplicacion(pol);
                    break;
                case 7:
                    imprime_polinomios(pol);
                    division(pol);
                    break;
                case 8:
                    ayuda ();
                    break;
                case 9:
                    printf("Gracias por usar\n\n");
                    break;
                default:
                    printf("Introduzca una opcion valida\n\n");
            }
        }
        if(opc!=9) {
            system("pause");
            system("cls");
        }
    } while (opc!=9);

    return 0;
}

int menu() 
{
    int opc;
    printf("--------------------------------------------------\n");
    printf("*          CALCULADORA DE POLINOMIOS             *\n");
    printf("--------------------------------------------------\n\n");
    printf("\t \t ** Presiona el numero de la que quieres y da enter ** \n\n ");
    printf("1. Crear/Guardar polinomios\n");
    printf("2. Obtener polinomios de archivo\n");
    printf("3. Suma polinomios\n");
    printf("4. Resta polinomios\n");
    printf("5. Multiplicacion por un escaclar\n");
    printf("6. Multiplicacion\n");
    printf("7. Division\n");
    printf("8. Manual de usuario\n");
    printf("9. Salir \n\n");
    printf("Seleccione una opcion: ");


    return opc;
}

void ayuda ()
{ 
    int ayuda;
    do 
    {
        printf("--------------------------------------------------------\n");
        printf(" *                 MANUAL DE USUARIO                * \n");
        printf("--------------------------------------------------------\n\n");
        printf("\t \t ** Presiona el numero de la que quieres y da enter ** \n\n ");
        printf("1. Crear/Guardar polinomios\n");
        printf("2. Obtener polinomios de archivo\n");
        printf("3. Suma polinomios\n");
        printf("4. Resta polinomios\n");
        printf("5. Multiplicacion por un escaclar\n");
        printf("6. Multiplicacion\n");
        printf("7. Division\n");
        printf("8. Manual de usuario\n");
        printf("9. Salir \n\n");
        printf("10. Ya no necesito ayuda \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &ayuda); 
    
        switch (ayuda)
        {
            case 1:
                printf("----------------------------------------------\n");
                printf(" *       CREAR/ GUARDAR POLINOMIO           * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Ingresa el numero de polinomios que quieres crear y da enter. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * Para cada uno de los polinomios que quieres crear: \n ");
                printf("\t \t \t + Ingresa la cantidad de coeficientes de tu polinomio y da enter. \n ");
                printf("\t \t \t \t  - Para cada coeficiente:  \n ");
                printf("\t \t \t \t \t  * Ingresa el coeficiente y da enter.  \n ");
                printf("\t \t \t \t \t  * Ingresa el exponente y da enter.  \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * En pantalla apareceran los polinomios ingresados ordenados por sus exponentes de mayor a menor. \n ");
                printf ("\t - Paso 4: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 2:
                printf("----------------------------------------------\n");
                printf(" *     OBTENER POLINOMIOS DE ARCHIVO        * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * En pantalla apareceran los polinomios ingresados ordenados por sus exponentes de mayor a menor. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 3:
                printf("----------------------------------------------\n");
                printf(" *                    SUMA                  * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Con base en los polinomios previamente ingresados que aparecen en pantalla: \n ");
                printf("\t \t \t + Escribe el numero del primer polinomio y da enter. \n ");
                printf("\t \t \t + Escribe el numero del segundo polinomio y da enter. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * En pantalla aparecera el resultado de la suma. \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 4:
                printf("----------------------------------------------\n");
                printf(" *                    RESTA                 * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Con base en los polinomios previamente ingresados que aparecen en pantalla: \n ");
                printf("\t \t \t + Escribe el numero del primer polinomio y da enter. \n ");
                printf("\t \t \t + Escribe el numero del segundo polinomio y da enter. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * En pantalla aparecera el resultado de la resta. \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 5:
                printf("----------------------------------------------\n");
                printf(" *       MULTIPLICACION POR ESCALAR         * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Con base en los polinomios previamente ingresados que aparecen en pantalla: \n ");
                printf("\t \t \t + Escribe el numero del polinomio y da enter. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * Escribe el escalar y da enter \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * En pantalla aparecera el resultado de la multiplicacion. \n ");
                printf ("\t - Paso 4: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 6:
                printf("----------------------------------------------\n");
                printf(" *               MULTIPLICACION             * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Con base en los polinomios previamente ingresados que aparecen en pantalla: \n ");
                printf("\t \t \t + Escribe el numero del primer polinomio y da enter. \n ");
                printf("\t \t \t + Escribe el numero del segundo polinomio y da enter. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * En pantalla aparecera el resultado de la multiplicacion. \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 7:
                printf("----------------------------------------------\n");
                printf(" *               DIVISION             * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Con base en los polinomios previamente ingresados que aparecen en pantalla: \n ");
                printf("\t \t \t + Escribe el numero del DIVISOR y da enter. \n ");
                printf("\t \t \t + Escribe el numero del DIVIDENDO y da enter. \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * En pantalla aparecera el resultado de la division. \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 8:
                printf("----------------------------------------------\n");
                printf(" *                   MANUAL                 * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Escribe el numero de la opcion en la que nesecitas ayuda y da enter  \n ");
                printf ("\t - Paso 2: \n");
                printf("\t \t * En pantalla aparecera la ayuda solicitada \n ");
                printf ("\t - Paso 3: \n");
                printf("\t \t * Presiona cualquier tecla. \n ");
                break;
            case 9:
                printf("----------------------------------------------\n");
                printf(" *                   SALIR                  * \n");
                printf("----------------------------------------------\n\n");
                printf ("\t - Paso 1: \n");
                printf("\t \t * Para terminar con la ejecucion del programa escribe el numero 9 y da enter  \n ");
                break;
            case 10:
                printf("Gracias por preguntar \n");
                break;
            default:
                printf("Introduzca una opcion valida\n\n");
        }
        if (ayuda !=10)
        {
            system("pause");
            system("cls");
        }
    } while ( ayuda != 10);
    return 0; 
}