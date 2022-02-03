#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QtMath>
#include <QDebug>
#include "datos.h"

class Controlador : public QObject
{
    Q_OBJECT
public:
    explicit Controlador(QObject *parent = nullptr);
    bool agregarDatos(int dia, int mes, int anio, double altura, double peso);
    bool calcularMasaCorporal();
    QString ObservacionPeso();

    Datos *datos() const;

    double m_masaCorporal;

signals:
private:
    Datos *m_datos;



};

#endif // CONTROLADOR_H
