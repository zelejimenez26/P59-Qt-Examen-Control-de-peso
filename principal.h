#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QFile>
#include "controlador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_btnCalcular_clicked();

    void on_actionNuevo_triggered();

    void on_btnGuardar_clicked();

private:
    Ui::Principal *ui;
    Controlador *m_controlador;
    void calcular();
    void limpiar();
    void guardar();

    //Para la grafica
    QPixmap lienzo;
    void dibujar();


};
#endif // PRINCIPAL_H
