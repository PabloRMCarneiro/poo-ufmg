#include "../include/data.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
#include "../include/Empresa.h"

Data Data::dataDeHoje;

Data::Data()
{
        ano = 0;
        mes = 0;
        dia = 0;
        hora = 0;
        minuto = 0;
        segundo = 0;
}
Data::Data(int valDia, int valMes, int valAno)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.Data"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("Data", "Data");
        string mensagem = "Acesso negado a Data.Data";
        throw mensagem;
    }
    else
    {
        ano = valAno;
        mes = valMes;
        dia = valDia;
        hora = 0;
        minuto = 0;
        segundo = 0;
        LogEscrita *a = new LogEscrita("ano", "indefinido", to_string(ano), "data");
        LogEscrita *b = new LogEscrita("mes", "indefinido", to_string(mes), "data");
        LogEscrita *c = new LogEscrita("dia", "indefinido", to_string(dia), "data");
        LogEscrita *d = new LogEscrita("hora", "indefinido", "0", "data");
        LogEscrita *e = new LogEscrita("minuto", "indefinido", "0", "data");
        LogEscrita *f = new LogEscrita("segundo", "indefinido", "0 ", "data");
    }
}
Data::Data(int valDia, int valMes, int valAno, int valHora, int valMin, int valSeg)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.Data"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("Data", "Data");
        string mensagem = "Acesso negado a Data.Data";
        throw mensagem;
    }
    else
    {
        ano = valAno;
        mes = valMes;
        dia = valDia;
        hora = valHora;
        minuto = valMin;
        segundo = valSeg;
    }
}

int Data::getAno()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getAno"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getAno", "Data");
        string mensagem = "Acesso negado a Data.getAno";
        throw mensagem;
    }
    else
    {
        return ano;
        
    }
}

int Data::getMes()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getMes"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getMes", "Data");
        string mensagem = "Acesso negado a Data.getMes";
        throw mensagem;
    }
    else
    {
        return mes;
    }
    return mes;
}

int Data::getDia()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getDia"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getDia", "Data");
        string mensagem = "Acesso negado a Data.getDia";
        throw mensagem;
    }
    else
    {
        return dia;
    }
}

int Data::getHora()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getHora"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getHora", "Data");
        string mensagem = "Acesso negado a Data.getHora";
        throw mensagem;
    }
    else
    {
        return hora;
    }
}

int Data::getMin()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getMin"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getMin", "Data");
        string mensagem = "Acesso negado a Data.getMin";
        throw mensagem;
    }
    else
    {
        return minuto;
    }
}

int Data::getSeg()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getSeg"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getSeg", "Data");
        string mensagem = "Acesso negado a Data.getSeg";
        throw mensagem;
    }
    else
    {
        return segundo;
    }
}

void Data::setAno(int valAno)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.setAno"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setAno", "Data");
        string mensagem = "Acesso negado a Data.setAno";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dia", to_string(ano), to_string(valAno), "data");
        ano = valAno;
    }
}

void Data::setMes(int valMes)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.setMes"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setMes", "Data");
        string mensagem = "Acesso negado a Data.setMes";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dia", to_string(mes), to_string(valMes), "data");
        mes = valMes;
    }
}

void Data::setDia(int valDia)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.setDia"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setDia", "Data");
        string mensagem = "Acesso negado a Data.setDia";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dia", to_string(dia), to_string(valDia), "data");
        dia = valDia;
    }
}

void Data::setHora(int valHora)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.setHora"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setHora", "Data");
        string mensagem = "Acesso negado a Data.setHora";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dia", to_string(hora), to_string(valHora), "data");
        hora = valHora;
    }
}

void Data::setMin(int valMin)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.setMin"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setMin", "Data");
        string mensagem = "Acesso negado a Data.setMin";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dia", to_string(minuto), to_string(valMin), "data");
        minuto = valMin;
    }
}

void Data::setSeg(int valSeg)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.setSeg"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setSeg", "Data");
        string mensagem = "Acesso negado a Data.setSeg";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dia", to_string(segundo), to_string(valSeg), "data");
        segundo = valSeg;
    }
}
string Data::help(int num)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.help"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("help", "Data");
        string mensagem = "Acesso negado a Data.help";
        throw mensagem;
    }
    else
    {
        if (num < 10)
        {
            return ("0" + to_string(num));
        }
        return to_string(num);
    }
}
string Data::getData()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getData"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getData", "Data");
        string mensagem = "Acesso negado a Data.getData";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("data", "Data");
        string sDia = help(this->getDia()), sMes = help(this->getMes()), sAno = help(this->getAno());
        string sHora = help(this->getHora()), sMinuto = help(this->getMin()), sSegundo = help(this->getSeg());
        return (sDia + "/" + sMes + "/" + sAno + " às " + sHora + ":" + sMinuto + ":" + sSegundo);
    }
    
}
string Data::getHorario()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.getHorario"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getHorario", "Data");
        string mensagem = "Acesso negado a Data.getHorario";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("horario", "Data");
        string sHora = help(this->getHora()), sMinuto = help(this->getMin()), sSegundo = help(this->getSeg());
        return (sHora + ":" + sMinuto + ":" + sSegundo);
    }
    
}
bool Data::operator<(Data &d2)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.operator<"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("operator<", "Data");
        string mensagem = "Acesso negado a Data.operator<";
        throw mensagem;
    }
    else
    {
        return ((ano < d2.ano) || (ano == d2.ano && mes < d2.mes) || (ano == d2.ano && mes == d2.mes && dia < d2.dia) ||
            (ano == d2.ano && mes == d2.mes && dia == d2.dia && hora < d2.hora) || (ano == d2.ano && mes == d2.mes && dia == d2.dia && hora == d2.hora && minuto < d2.minuto) || (ano == d2.ano && mes == d2.mes && dia == d2.dia && hora == d2.hora && minuto == d2.minuto && segundo < d2.segundo));
    }
    
}
bool Data::operator==(Data &d2)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Data.operator=="))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("operator==", "Data");
        string mensagem = "Acesso negado a Data.operator==";
        throw mensagem;
    }
    else
    {
        return ((ano == d2.ano) && (mes == d2.mes) && (dia == d2.dia));
    }
}