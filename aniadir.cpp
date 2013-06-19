#include "aniadir.h"
#include "ui_aniadir.h"

aniadir::aniadir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aniadir)
{
    ui->setupUi(this);
}

aniadir::~aniadir()
{
    delete ui;
}

/*!
 * \brief aniadir::setDate -> recoge el dia seleccionado y lo introduce dentro de las cajas dia, mes y anio.
 * \param date pasa la variable del calendario, parámetro de entrada.
 */

void aniadir::setDate(QDate date){

    ui->anadir_dia->setValue(date.day());
    ui->anadir_mes->setValue(date.month());
    ui->anadir_anio->setValue(date.year());

}

/*!
 * \brief aniadir::getdia -> recoge el dia de la tarea a añadir
 * \return -> devuelve el dia como entero, parámetro de salida.
 */

int aniadir::getdia(){
     return ui->anadir_dia->text().toInt();
}

/*!
 * \brief aniadir::getmes -> recoge por teclado el mes de la tarea a añadir
 * \return-> devuelve el mes como entero, parámetro de salida.
 */

int aniadir::getmes(){
    //@param recoge y devuelve el mes
     return ui->anadir_mes->text().toInt();
}

/*!
 * \brief aniadir::getanio -> recoge por teclado el año de la tarea a añadir
 * \return devuelve el año como entero, parámetro de salida.
 */

int aniadir::getanio(){
     return ui->anadir_anio->text().toInt();
}

/*!
 * \brief aniadir::gethora -> recoge por teclado la hora de la tarea a añadir
 * \return devuelve el hora como entero, parámetro de salida.
 */

int aniadir::gethora(){
     return ui->anadir_hora->text().toInt();
}

/*!
 * \brief aniadir::getminuto -> recoge por teclado el minuto de la tarea a añadir
 * \return devuelve el minuto como entero, parámetro de salida.
 */

int aniadir::getminuto(){
     return ui->anadir_minuto->text().toInt();
}

/*!
 * \brief aniadir::getdescripcion -> recoge la descripcion de la tarea a añadir
 * \return devuelve el string de descripcion, como parámetro de salida.
 */

QString aniadir::getdescripcion(){
    return ui->add_description->toPlainText();
}

/*!
 * \brief aniadir::getprioridad -> recoge la prioridad de la tarea a añadir
 * \return devuelve la prioridad como entero, parámetro de salida.
 */

int aniadir::getprioridad(){
    //@param recoge y devuelve la prioridad
    return ui->anadir_prioridad->text().toInt();
}
