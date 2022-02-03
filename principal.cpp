#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    m_controlador=new Controlador(); //Insticiar objeto
    //Para la grafica
    lienzo = QPixmap(400,100);
    this->dibujar();
    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::calcular()
{
    //Obtener datos de la GUI
    int dia= ui->inDia->value();
    int mes=ui->inMes->value();
    int anio=ui->inAnio->value();
    double peso=ui->inPeso->value();
    double altura=ui->inAltura->value();
    //Validar datos correctos - mostrar cuadro de dialogo
    if(dia==0||mes==0||anio==0||peso==0||altura==0){
        QMessageBox::warning(this, "Advertencia", "Existen campos vacios");
        return;
    }
    m_controlador->agregarDatos(dia, mes, anio, altura, peso);
    if(m_controlador->calcularMasaCorporal()){
        ui->outIMC->setText(QString::number(m_controlador->m_masaCorporal, 'f', 2) + " kg/m^2");
        ui->outDetalleMasa->setText(m_controlador->ObservacionPeso());
        ui->outAltura->setText(QString::number(ui->inAltura->value())+ " m");
        ui->outPactual->setText(QString::number(peso) + " kg");
        ui->outPmax->setText(QString::number(peso) + " kg");
        ui->outPmin->setText(QString::number(peso)+" kg");

    }else{
        QMessageBox::critical(
                    this,
                    "Error",
                    "Error en el calculo de IMC."
                    );
    }
}

void Principal::limpiar()
{
    ui->inDia->setValue(0);
    ui->inMes->setValue(0);
    ui->inAnio->setValue(0);
    ui->inAltura->setValue(0);
    ui->inPeso->setValue(0);

    ui->outIMC->setText("0.0");


}

void Principal::guardar()
{
    QFile archivo("resulatdo.txt");
    if(archivo.open(QIODevice::Append|QIODevice::Text)){
        QTextStream salida(&archivo);
        salida<<m_controlador->datos()->toString();
    }
    //cerrar archivo
    archivo.close();

}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(2);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setBrush(Qt::red);

    // Dibujar primera barra
    painter.drawRect(x+10, y+10,10,90);

}


void Principal::on_btnCalcular_clicked()
{
    calcular();
}


void Principal::on_actionNuevo_triggered()
{
    limpiar();
}


void Principal::on_btnGuardar_clicked()
{
    guardar();
}

