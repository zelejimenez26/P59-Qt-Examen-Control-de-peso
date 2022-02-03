#include "controlador.h"

Controlador::Controlador(QObject *parent) : QObject(parent)
{
    this->m_datos=nullptr;
    this->m_masaCorporal=0;
    //this->m_obsPeso="";
}

bool Controlador::agregarDatos(int dia, int mes, int anio, double altura, double peso)
{
    this->m_datos=new Datos(dia, mes, anio, altura, peso);
    return true;
}

bool Controlador::calcularMasaCorporal()
{
    if(this->m_datos==nullptr){
        return false;
    }
    double imc=m_datos->peso()/(m_datos->altura()*m_datos->altura());
    //qDebug()<<imc;
    m_datos->setMasaCorporal(imc);
    m_masaCorporal=imc;
    return true;
}

QString Controlador::ObservacionPeso()
{
    QString obpeso;
    if(m_masaCorporal<15){
        obpeso="Delgadez extrema";
    }
    else{
        if((m_masaCorporal>=15)&&(m_masaCorporal<=16)){
            obpeso="Bajo peso";
        }
        if((m_masaCorporal>16)&&(m_masaCorporal<=18.5)){
            obpeso="Delgadez saludable";
        }
        if((m_masaCorporal>18.5)&&(m_masaCorporal<=25)){
            obpeso="Normal";
        }
        if((m_masaCorporal>25)&&(m_masaCorporal<=30)){
            obpeso="Sobrepeso";
        }
        if((m_masaCorporal>30)&&(m_masaCorporal<=35)){
            obpeso="Obesidad";
        }
        if((m_masaCorporal>35)&&(m_masaCorporal<=40)){
            obpeso="Obesidad extrema";
        }
    }
    qDebug()<<obpeso;
    return obpeso;
}

Datos *Controlador::datos() const
{
    return m_datos;
}
