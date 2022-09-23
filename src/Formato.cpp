#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <cstddef>
#include "Formato.h"
#include "ExecaoCustomizada.h"

using namespace std;

/**
 * Formato::Formato()
 */
Formato::Formato()
{
    nome= "PT-BR";
    separadorData= '/';
    separadorHorario= ':';
}
/**
 * Formato::Formato(string valNome)
 * 
 * The above function is a constructor for the Formato class. It takes a string as a parameter and
 * assigns it to the nome variable. It then checks to see if the string is equal to "PT-BR" or "EN-US"
 * and assigns the separadorData variable accordingly. It then assigns the separadorHorario variable to
 * ':'
 * 
 * @param valNome The name of the format.
 */
Formato::Formato(string valNome)
{
    nome= valNome;
    if (strcmp(valNome.c_str(),"PT-BR")==0)
        separadorData= '/';
    else if (strcmp(valNome.c_str(),"EN-US")==0)
        separadorData= '-';
    separadorHorario= ':';
}
/**
 * A destructor.
 */
Formato::~Formato()
{

}
/**
 * It returns the name of the format.
 * 
 * @return The name of the format.
 */
string Formato::getNome()
{
    return nome;
}
/**
 * It returns the separadorData variable.
 * 
 * @return The separator of the date.
 */
string Formato::getSeparadorData()
{
    return separadorData;
}
/**
 * It returns the separadorHorario variable.
 * 
 * @return The separator of the time.
 */
string Formato::getSeparadorHorario()
{
    return separadorHorario;
}
