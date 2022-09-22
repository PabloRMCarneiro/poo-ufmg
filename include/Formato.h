#ifndef FORMATO_H_INCLUDED
#define FORMATO_H_INCLUDED
#include <string>
#include <string.h>
#include <vector>
#include "ExecaoCustomizada.h"

using namespace std;

class Formato
{
private:
    string nome;        //PT-BR ou EN-US
    string separadorData;     //Separador utilizado entre os valores de ano, mes e dia
    string separadorHorario;      //Separador utilizado entre os valores de hora, min e seg

public:
    Formato();      //Construtor default
    Formato(string valNome);     //Construtor com parametro de nome
    virtual ~Formato();     //Destrutor
    string getNome();
    string getSeparadorData();
    string getSeparadorHorario();
};

#endif // FORMATO_H_INCLUDED
