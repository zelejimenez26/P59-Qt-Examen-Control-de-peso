#ifndef DATOS_H
#define DATOS_H

#include <QObject>

class Datos : public QObject
{
    Q_OBJECT
public:
    explicit Datos(QObject *parent = nullptr);
    Datos(int dia, int mes, int anio, double altura, double peso);

    int dia() const;
    void setDia(int newDia);
    int mes() const;
    void setMes(int newMes);
    int anio() const;
    void setAnio(int newAnio);
    double altura() const;
    void setAltura(double newAltura);
    double peso() const;
    void setPeso(double newPeso);
    double masaCorporal() const;
    void setMasaCorporal(double newMasaCorporal);

    QString toString();

signals:
private:
    int m_dia;
    int m_mes;
    int m_anio;

    double m_altura;
    double m_peso;

    double m_masaCorporal;

};

#endif // DATOS_H
