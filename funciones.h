#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__


/**
 * -------------------------------------------
 *              *ESTRUCTURAS*
 * -------------------------------------------
 **/

//------- * TERMINOS DEL POLINOMIO * ---------
typedef struct {
    float coef;
    int exp;
} terminos;


//-------------- * POLINOMIO * ---------------
typedef struct {
    int tot_term;
    terminos *term;
} polinomios;


/**
 * ---------------------------------------------
 *          * FUNCIONES DE MEMORIA *
 * ---------------------------------------------
 **/

polinomios * crear_polinomio();
polinomios * obtener_polinomios();
void imprime_polinomios(polinomios *pol);


/**
 * ---------------------------------------------------------
 *          * FUNCIONES DE OPERACIONES BÁSICAS  *
 * ---------------------------------------------------------
 **/

void suma(polinomios *pol);
void resta(polinomios *pol);
void multiplicacion_escalar(polinomios *pol);
void multiplicacion(polinomios *pol);
void division(polinomios *pol); 

#endif // COMPLEX_H_INCLUDED
