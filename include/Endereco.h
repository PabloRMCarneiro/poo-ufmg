#ifndef ENDERECO_H_INCLUDED
#define ENDERECO_H_INCLUDED
#include <string>

using namespace std;

class Endereco{
    private:
        string endereco;
        double x, y;
    public:
    //construtor
        Endereco(string valEndereco, double valX, double valY);
        Endereco();
    //metodos set
        void setEndereco(string valEndereco);
        void setX(double valX);
        void setY(double valY);
    //metodos get
        string getEndereco();
        double getX();
        double getY();
        double getDistancia(double x2, double y2);
};
#endif //ENDERECO_H_INCLUDED