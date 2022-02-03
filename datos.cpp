#include "datos.h"

Datos::Datos(QObject *parent) : QObject(parent)
{
    this->m_dia=0;
    this->m_mes=0;
    this->m_anio=0;
    this->m_altura=0;
    this->m_peso=0;

}

Datos::Datos(int dia, int mes, int anio, double altura, double peso) :
    m_dia(dia),
    m_mes(mes),
    m_anio(anio),
    m_altura(altura),
    m_peso(peso)
{}

int Datos::dia() const
{
    return m_dia;
}

void Datos::setDia(int newDia)
{
    m_dia = newDia;
}

int Datos::mes() const
{
    return m_mes;
}

void Datos::setMes(int newMes)
{
    m_mes = newMes;
}

int Datos::anio() const
{
    return m_anio;
}

void Datos::setAnio(int newAnio)
{
    m_anio = newAnio;
}

double Datos::altura() const
{
    return m_altura;
}

void Datos::setAltura(double newAltura)
{
    m_altura = newAltura;
}

double Datos::peso() const
{
    return m_peso;
}

void Datos::setPeso(double newPeso)
{
    m_peso = newPeso;
}

double Datos::masaCorporal() const
{
    return m_masaCorporal;
}

void Datos::setMasaCorporal(double newMasaCorporal)
{
    m_masaCorporal = newMasaCorporal;
}

QString Datos::toString()
{
    QString str="";
    str.append(QString::number(m_dia+m_mes+m_anio)+ "\t");
    str.append(QString::number(m_altura)+ "\t");
    str.append(QString::number(m_peso)+ "\t");
    str.append(QString::number(m_masaCorporal))+"\n";
    return str;
}
