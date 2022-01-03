#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"


int total_polinomios=0;

/**
 * @brief: Esta función pide al usuario que de el polinomio que desea agregar a la memoria, lo ordena por método BURBUJA y lo escribe en un archivo
 * @param: Recibe un polinomio
 * @return: Los polinomios creados en escritos en un archivo
 * @fecha:28/12/2022
 * @programador: Moreno Santoyo Mariana
 **/

polinomios * crear_polinomio()
{
    int i, j, band=0; // Esta función hace uso de banderas 
    polinomios *pol;
    int tot_p, tot_term;

    total_polinomios=0;

    do 
    {
        // Pregunta cuántos polinomios se desea crear 
        printf("Introduzca la cantidad de polinomios a crear: ");
        scanf("%d",&tot_p);
        system("cls");

        // Condición para establecer el número de polinomios que acepta la memoria 
        // Si ya está llena la memoria suelta advertencia 
        if((total_polinomios+tot_p)>10) 
        {
            printf("Memoria llena, no se pueden guardar esos polinomios\nEspacio libre: %d Polinomios",(10-total_polinomios));
            system("pause");
            system("cls");
        } 
        else 
        {
            band=1; // Establezco la bandera como verdadero
            pol = (polinomios *)malloc(tot_p * sizeof(polinomios));  // Reservo la memoria para guardar os polinomios 
            for(i=0; i<tot_p; i++)
            {
                // Pido los polinomios 
                //Pido la cantidad de coeficientes que se desea y la estructura de cada término
                printf("Introduzca la cantidad de coeficientes para el polinomio %d: ",(i+1));
                scanf("%d",&tot_term);
                system("cls");

                pol[i].tot_term = tot_term;
                pol[i].term = (terminos *)malloc(tot_term * sizeof(terminos));

                for(j=0; j<tot_term; j++) 
                {
                    printf("Coeficiente %d: ",(j+1));
                    scanf("%f",&pol[i].term[j].coef);

                    printf("Exponente %d: ",(j+1));
                    scanf("%d",&pol[i].term[j].exp);
                    system("cls");
                }
                system("cls");

                total_polinomios++;
            }
        }
    } while (band!=1);    // Repetir el ciclo mientras la bandera sea Falso 


/**
 * --------------------------------------------------
 *                  *BURBUJA*
 * --------------------------------------------------
 **/


    for(i=0; i< tot_p; i++)
    {
        for(int k=0; k< pol[i].tot_term; k++)
        {
            for(j=0; j< pol[i].tot_term-1; j++)
            {
                if(pol[i].term[j].exp < pol[i].term[j+1].exp)
                {
                    terminos temporal;
                    temporal.coef= pol[i].term[j].coef;
                    temporal.exp = pol[i].term[j].exp;
                    pol[i].term[j].exp = pol[i].term[j+1].exp;
                    pol[i].term[j].coef = pol[i].term[j+1].coef;
                    pol[i].term[j+1].exp = temporal.exp;
                    pol[i].term[j+1].coef =temporal.coef;
                }
            }
        }
    }

/**
 * --------------------------------------------------
 *      *ESCRIBIR LOS POLINOMIOS EN UN ACHIVO*
 * --------------------------------------------------
 **/

    printf("--------------------------------------------------\n");
    printf("*              POLINOMIOS CREADOS                *\n");
    printf("--------------------------------------------------\n\n");

    FILE *archivo;
    archivo = fopen("archivo.txt","w+"); // Se abre un archivo en modo de lectura y escritura 

    for(i=0;i<tot_p;i++)
    {
        // El número de polinomio 
        printf("%d)  ",(i+1));

        // Escribo mis polinomios en el archivo 
        fprintf(archivo, "%d,",pol[i].tot_term);

        for(j=0; j<pol[i].tot_term; j++) 
        {
            if(j==(pol[i].tot_term-1))
            {
                printf("%.3f X^%d\n",pol[i].term[j].coef, pol[i].term[j].exp);
                fprintf(archivo, "%f,%d\n",pol[i].term[j].coef,pol[i].term[j].exp);
            } 
            else 
            {
                printf("%.3f X^%d + ",pol[i].term[j].coef, pol[i].term[j].exp);
                fprintf(archivo, "%f,%d,",pol[i].term[j].coef,pol[i].term[j].exp);
            }
        }
    }
    fclose(archivo); // Cierro el archivo
    printf("\n\nPolinomios creados en archivo de manera exitosa\n\n");

    return pol;
}

/**
 * @brief: Lee los polinomios de el archivo
 * @param: No recibe nada 
 * @return: Muestra en pantalla los polinomios que se encuentran en el archivo
 * @fecha:16/12/2021
 * @programador: Moreno Santoyo Mariana 
 **/

polinomios * obtener_polinomios(){
    polinomios *pol;

    printf("--------------------------------------------------\n");
    printf("*              EXTRAE POLINOMIOS                 *\n");
    printf("--------------------------------------------------\n\n");
    FILE *archivo;
    int i, j, ext, tot_exp, tot_coef;
    int exp[10][50], tot_term[10];
    float coef[10][50];
    char datos[10][100];
    //Abrimos el archivo

    /**
     *  Se hace uso de la división de la cadena por la forma en la que los datos se escriben en el archivo
     **/

    archivo = fopen("archivo.txt","r");

    if(archivo != NULL) 
    {
        total_polinomios=0;
        // feof sirve para saber cuando se llega al final de un fichero,  si se no ha alcanzado el final del fichero es cero
        while (feof(archivo) == 0) 
        {
            //Leer cadenas desde el archivo
            fgets(datos[total_polinomios], 100, archivo);

            /**
             *  ---------------------------------- * STRTOK * ------------------------------------------
             * Se hace uso de strtok para separar la cadena por un delimitador 
             * Se le asigna a un token la cadena y la divide en el punto en el que se encuentra una coma 
             * Se declara de la siguiente forma 
             *      token = strtok (cadena, delimitador )
             * La separación de la cadena va a terminar cuánto el token sea igual a NULL 
             * ----------------------------------------------------------------------------------------
             **/

            char *tok1 = strtok(datos[total_polinomios], ",");
            if(tok1 != NULL)
            {
                ext=0;
                tot_exp=0;
                tot_coef=0;
                while(tok1 != NULL)
                {
                    if(ext==0) 
                    {
                        tot_term[total_polinomios]= atoi(tok1); // atoi convierte cadena a entero
                    } 
                    else if(ext % 2==0) 
                    {
                        exp[total_polinomios][tot_exp]= atoi(tok1);
                        tot_exp++;
                    } 
                    else
                    {
                        coef[total_polinomios][tot_coef]= atoi(tok1);
                        tot_coef++;
                    }

                    ext++;
                    tok1 = strtok(NULL, ","); // Para que la cadena continue dividiendose se pone en los argumentos NULL 
                }
            }

            if(tot_term[total_polinomios]>0)
            {
                total_polinomios++;
            }
        }
        fclose(archivo);

        pol = (polinomios *)malloc(total_polinomios * sizeof(polinomios));
        for(i=0; i<total_polinomios; i++) 
        {
            pol[i].term = (terminos *)malloc(tot_term[i] * sizeof(terminos));
            pol[i].tot_term=tot_term[i];

            for(j=0; j<tot_term[i]; j++) 
            {
                pol[i].term[j].coef=coef[i][j];
                pol[i].term[j].exp=exp[i][j];
            }
        }
        printf("POLINOMIOS CREADOS DE MANERA EXITOSA\n\n");
    } 
    else 
    {
        // Advertencia en caso de que no haya archivo
        printf("No se encontro archivo\n\n");
        return NULL;
    }
    
    /**
     * ------------------------------------------------------------
     *            *MOSTRAR LOS POLINOMIOS EN LA MEMORIA*
     * ------------------------------------------------------------
     **/

    printf("--------------------------------------------------\n");
    printf("*              POLINOMIOS CREADOS                *\n");
    printf("--------------------------------------------------\n\n");
    for(i=0;i<total_polinomios;i++)
    {
        printf("%d)  ",(i+1));
        for(j=0; j<pol[i].tot_term; j++) 
        {
            if(j==(pol[i].tot_term-1))
            {
                printf("%.3f X^%d\n",pol[i].term[j].coef, pol[i].term[j].exp);
            } 
            else 
            {
                printf("%.3f X^%d + ",pol[i].term[j].coef, pol[i].term[j].exp);
            }
        }
    }
    printf("\n\n");

    return pol;
}

/**
 * @brief: Imprime los polinomios 
 * @param: Apuntador de tipo polinomio  
 * @return: Muestra en pantalla los polinomios
 * @fecha:2/1/2024
 * @programador: Moreno Santoyo Mariana
 **/

void imprime_polinomios(polinomios *pol){
    printf("--------------------------------------------------\n");
    printf("*                  POLINOMIOS                    *\n");
    printf("--------------------------------------------------\n\n");
    for(int i=0;i<total_polinomios;i++) 
    {
        printf("%d) ",(i+1));
        for(int j=0; j<pol[i].tot_term; j++) 
        {
            if(j==(pol[i].tot_term-1)) 
            {
                printf("%.3f X^%d\n",pol[i].term[j].coef, pol[i].term[j].exp);
            }
            else
            {
                printf("%.3f X^%d + ",pol[i].term[j].coef, pol[i].term[j].exp);
            }
        }
    }

    printf("\n\n");
}

/**
 * @brief: Sumar dos polinomios 
 * @param: Los dos polinomios a sumar
 * @return: El polinomio resultante 
 * @fecha: 2/1/2022
 * @programador: Flores Melquiades Evelyn 
 **/

//aoa30

void suma(polinomios *pol)
{
    /**
     * En el caso de esta función las banderas se usan como un switch
     * Cuando la bandera es igual a cero es que los exponentes son diferentes y no suma los coeficientes
     * Caso contrario, la bandera es verdadera, los exponentes son iguales y los coeficientes se suman
     **/
    
    int i,j,k,band, pol1, pol2;
    polinomios *sum;
    float  suma_coef [100] ;
    int  suma_exp [100];
    int total_coef = 0;

    printf("--------------------------------------------------\n");
    printf("*                     SUMA                       *\n");
    printf("--------------------------------------------------\n\n");

    // Resibe que polinomios se van a sumar 
    printf("Que polinomios quieres sumar?\n\n");
    printf("Selecciona el polinomio 1: ");
    scanf("%d",&pol1);
    pol1--;

    printf("Selecciona el polinomio 2: ");
    scanf("%d",&pol2);
    pol2--;

    for(i=0;i< pol[pol1].tot_term; i++)
    {
        band = 0;
        for(j=0; j< pol[pol2].tot_term; j++)
        {
            if(pol[pol1].term[i].exp==pol[pol2].term[j].exp)
            {
                band = 1;
                // La bandera es verdadera cuando los exponentes de los coeficientes son los mismos 
            }
        }
    }

    // Reservo memoria para el resultado de la suma 
    sum = (polinomios *)malloc(1 * sizeof(polinomios));

    for(i=0;i< pol[pol1].tot_term; i++)
    {
        suma_exp[i]= pol[pol1].term[i].exp;
        suma_coef[i]= pol[pol1].term[i].coef;
    }
    total_coef = pol[pol1].tot_term;

    for(i=0;i< pol[pol2].tot_term; i++)
    {
        band =0;
        for(j=0; j< pol[pol1].tot_term; j++)
        {
            if(suma_exp[j]==pol[pol2].term[i].exp)
            {
                suma_coef[j] = suma_coef[j] + pol[pol2].term[i].coef;
                band = 1;
            }
        }
        if (band ==0)
        {
            suma_coef[total_coef]= pol[pol2].term[i].coef;
            suma_exp[total_coef]= pol[pol2].term[i].exp;
            total_coef = total_coef + 1;
        }
    }
    printf("\n\nResultado:\n");
    for(j=0; j<total_coef; j++)
    {
        if(j==(total_coef-1))
        {
            printf("%.3f X^%d\n\n",suma_coef[j], suma_exp[j]);
        }
        else
        {
            printf("%.3f X^%d + ",suma_coef[j], suma_exp[j]);
        }
    }
}

/**
 * @brief: Restar dos polinomios 
 * @param: Los dos polinomios a restar
 * @return: El polinomio resultante 
 * @fecha: 2/1/2022
 * @programador: Barcenas Torres David Farid 
 **/

void resta(polinomios *pol)
{
    /** 
     * Igual a la suma pero con diferente signo
     **/

    int i,j,k,band, pol1, pol2;
    float  resta_coef [100] ;
    int  resta_exp [100];
    int total_coef = 0;

    printf("--------------------------------------------------\n");
    printf("*                     RESTA                      *\n");
    printf("--------------------------------------------------\n\n");
    printf("Que polinomios quieres restar?\n\n");
    printf("Selecciona el polinomio 1: ");
    scanf("%d",&pol1);
    pol1--;

    printf("Selecciona el polinomio 2: ");
    scanf("%d",&pol2);
    pol2--;

    for(i=0;i< pol[pol1].tot_term; i++)
    {
        band = 0;
        for(j=0; j< pol[pol2].tot_term; j++)
        {
            if(pol[pol1].term[i].exp==pol[pol2].term[j].exp)
            {
                band = 1;
            }
        }
    }

    for(i=0;i< pol[pol1].tot_term; i++)
    {
        resta_exp[i]= pol[pol1].term[i].exp;
        resta_coef[i]= pol[pol1].term[i].coef;
    }
    total_coef = pol[pol1].tot_term;

    for(i=0;i< pol[pol2].tot_term; i++)
    {
        band =0;
        for(j=0; j< pol[pol1].tot_term; j++)
        {
            if(resta_exp[j]==pol[pol2].term[i].exp)
            {
                resta_coef[j] = resta_coef[j] - pol[pol2].term[i].coef;
                band = 1;
            }
        }
        if (band ==0)
        {

            resta_coef[total_coef]= pol[pol2].term[i].coef;
            resta_exp[total_coef]= pol[pol2].term[i].exp;
            total_coef = total_coef + 1;
        }
    }
    printf("\n\nResultado:\n");
    for(j=0; j<total_coef; j++)
    {
        if(j==(total_coef-1))
        {
            printf("%.3f X^%d\n\n",resta_coef[j], resta_exp[j]);
        }
        else
        {
            printf("%.3f X^%d + ",resta_coef[j], resta_exp[j]);
        }
    }
}

/**
 * @brief: Multplicar un polinomio por un escalar 
 * @param: Un polinomio y un escalar 
 * @return: El polinomio resultante 
 * @fecha: 19/12/2021
 * @programador: Haro Estrada Leonardo Damian
 **/

void multiplicacion_escalar(polinomios *pol) 
{
    int opc;
    float val;

    printf("--------------------------------------------------\n");
    printf("*                 MULTIPLICACION                 *\n");
    printf("--------------------------------------------------\n\n");

    printf("Que polinomio quieres multiplicar?\n\n");
    printf("Selecciona el polinomio: ");
    scanf("%d",&opc);

    printf("Introduce el valor a multiplicar: "); //Pido el escalar 
    scanf("%f",&val);

    float res;
    printf("\n\nResultado: \n");
    for(int i=0;i< pol[(opc-1)].tot_term; i++)
    {
        res= val * pol[(opc-1)].term[i].coef;
        printf("%.3f X^%d   ",res,pol[(opc-1)].term[i].exp);
    }
    printf("\n\n");
}

/**
 * @brief: Multplicar un polinomio por otro
 * @param:Dos polinomios a multiplicar 
 * @return: El polinomio resultante 
 * @fecha:30/24/2021
 * @programador: Barcenas Torres David Farid
 **/

void multiplicacion(polinomios *pol) {
    int i, j, opc1, opc2;
    float res[100] = {0};

    printf("--------------------------------------------------\n");
    printf("*                 MULTIPLICACION                 *\n");
    printf("--------------------------------------------------\n\n");

    printf("Selecciona el polinomio 1: ");
    scanf("%d",&opc1);
    opc1--;

    printf("Selecciona el polinomio 2: ");
    scanf("%d",&opc2);
    opc2--;
    system("cls");

    for(i=0; i<pol[opc1].tot_term; i++)
    {
        for(j=0; j<pol[opc2].tot_term; j++) 
        {
            res[(pol[opc1].term[i].exp + pol[opc2].term[j].exp)] += (pol[opc1].term[i].coef * pol[opc2].term[j].coef);
        }
    }

    printf("\n\nResultado: \n");
    for(i=99;i>=0; i--)
    {
        if(res[i]!=0)
        {
            printf("%.3f X^%d   ",res[i], i);
        }
    }
    printf("\n\n");
}

/**
 * @brief: Dividir dos polinomios 
 * @param:Dos polinomios a dividir 
 * @return: El polinomio resultante 
 * @fecha: 16/24/2021
 * @programador: Moreno Santoyo Mariana 
 **/

void division(polinomios *pol){
    int i,j,pol1, pol2;
    float  division_coef [100] ;
    int  division_exp [100];
    float div_res_coef [100];
    int div_res_exp[100];
    float temp_coef [100];
    int temp_exp[100];
    float residuo_coef ;
    int residuo_exp;
    int total = 0;
    int cont= 0;

    printf("--------------------------------------------------\n");
    printf("*                    DIVISION                    *\n");
    printf("--------------------------------------------------\n\n");

    printf("Que polinomios quieres dividir?\n\n");

    printf("Selecciona el polinomio divisor: ");
    scanf("%d",&pol1);
    pol1--;

    printf("Selecciona el polinomio dividendo: ");
    scanf("%d",&pol2);
    pol2--;

    total = pol[pol1].term[0].exp +1;
    cont = 0;
    i=0;
    do{

        if(i!=0)
        {
            if(division_exp[i-1] -1== pol[pol1].term[cont].exp )
            {
                division_exp[i]= pol[pol1].term[cont].exp;
                division_coef[i]= pol[pol1].term[cont].coef;
                i++;
                cont++;
            }
            else
            {
                division_exp[i]= division_exp[i-1] -1;
                division_coef[i]= 0;
                i++;
            }
        }
        else
        {
            division_exp[i]= pol[pol1].term[cont].exp;
            division_coef[i]= pol[pol1].term[cont].coef;
            i++;
            cont++;
        }
    }while(cont<total -1);

    cont =0;
    do
    {
        div_res_coef[cont] = division_coef[cont] / pol[pol2].term[0].coef;
        div_res_exp[cont] = division_exp[cont] - pol[pol2].term[0].exp;
        j=0;
        int k=cont;
        for(i=0; i< pol[pol2].tot_term; i++)
        {
            temp_coef[k]= division_coef[k] - (div_res_coef[cont] * pol[pol2].term[j].coef);
            if(division_exp[k] == (div_res_exp[cont] + pol[pol2].term[j].exp))
            temp_exp[k]= division_exp[k];
            residuo_coef=temp_coef[k];
            residuo_exp=temp_exp[k];
            division_coef[k] = temp_coef[k];
            division_exp[k] = temp_exp[k];
            j++;
            k++;
        }
        cont++; 
    }while(cont<total-1);
    cont=total-2;
    printf("\n\nResultado:\n");
    for(j=0; j<total-1; j++)
    {
        printf("%.3f X^%d + ",div_res_coef[j], div_res_exp[j]);
    }
    printf("( %.3f X^%d / ",residuo_coef, residuo_exp);
    for(j=0; j<pol[pol2].tot_term; j++)
    {
        if(j==(pol[pol2].tot_term-1))
        {
            printf("%.3f X^%d )\n\n",pol[pol2].term[j].coef, pol[pol2].term[j].exp);
        }
        else
        {
            printf("%.3f X^%d + ",pol[pol2].term[j].coef, pol[pol2].term[j].exp);
        }
    }
}
