#include "mostrar.h"
#include "ui_mostrar.h"

mostrar::mostrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mostrar)
{
    ui->setupUi(this);
}

mostrar::~mostrar()
{
    delete ui;
}

void mostrar::setParametros(tlista lista){

    if(!esVacia(lista)){
    tposicion p;
    int i =0;

    for (p = lista; p != NULL; p = p->sig){

        ui->motrar_tableWidget->setRowCount(longitud(lista));
        ui->motrar_tableWidget->setColumnCount(7);

        QString dia = QString("%1").arg(p->elemento.fecha.dia);
        QString mes = QString("%1").arg(p->elemento.fecha.mes);
        QString anio = QString("%1").arg(p->elemento.fecha.anio);
        QTime t(p->elemento.hora.hora, p->elemento.hora.minuto);

        //QString hora = convHoraMinutoMostrar(AgendaUEM.tarea[i].hora.hora, AgendaUEM.tarea[i].hora.minuto); // <- Natalia
        QString hora = t.toString("hh:mm");

        //QString minuto = QString("%1").arg(AgendaUEM.tarea[i].hora.minuto);

        QString descripcion = QString("%1").arg(p->elemento.descripcion);
        QString prioridad = QString("%1").arg(p->elemento.prioritario);

        QString check = QString("%1").arg(p->elemento.eliminar);

        QTableWidgetItem* item = new QTableWidgetItem(dia);
        QTableWidgetItem* item1 = new QTableWidgetItem(mes);
        QTableWidgetItem* item2 = new QTableWidgetItem(anio);

        QTableWidgetItem* item3 = new QTableWidgetItem(hora);
        //QTableWidgetItem* item4 = new QTableWidgetItem(minuto);

        QTableWidgetItem* item5 = new QTableWidgetItem(descripcion);
        QTableWidgetItem* item6 = new QTableWidgetItem(prioridad);

        //Chequea el contenido de la variable check, creando un recuadro de checkbox, con tic o sin tic.
        QTableWidgetItem* item7 = new QTableWidgetItem(); // <- Natalia

        if (check == 0){
            item7->setCheckState(Qt::Checked);
        } else
            item7->setCheckState(Qt::Unchecked);

        ui->motrar_tableWidget->setItem(i,0,item);
        ui->motrar_tableWidget->setItem(i,1,item1);
        ui->motrar_tableWidget->setItem(i,2,item2);

        ui->motrar_tableWidget->setItem(i,3,item3);
        //ui->motrar_tableWidget->setItem(i,4,item4);

        ui->motrar_tableWidget->setItem(i,4,item5);
        ui->motrar_tableWidget->setItem(i,5,item6);

        ui->motrar_tableWidget->setItem(i,6,item7);
        i++;
    }
    } else {

        QMessageBox msgBox;
        msgBox.setText("No existen tareas actualmente.");
        msgBox.exec();
    }

}

/*!
 * \brief mostrar::convHoraMinutoMostrar -> funcion que devuelve un string en formato HH::MM. Queremos mostrar las horas y minutos con 2 digitos, por lo que si es menor que 10, agregamos un 0 alante.
 * \param hora como parámetro de entrada.
 * \param minuto como parámetro de entrada.
 * \return devuelve un string
 */

QString mostrar::convHoraMinutoMostrar(int hora, int minuto){  // <- Natalia

    QString stringHora;
    QString stringMinuto;

    if (hora<10) //es menor que 10 porque tiene un solo digito, a partir del numero 10 hay dos!! bobada!;)
        stringHora=QString("0%1").arg(hora);
    else
        stringHora=QString("%1").arg(hora);

    if (minuto<10)
        stringMinuto=QString("0%1").arg(minuto);
    else
        stringMinuto=QString("%1").arg(minuto);
    return QString("%1:%2").arg(stringHora).arg(stringMinuto);

}

/*!
 * \brief mostrar::getdia -> recogen la posición de la tarea y devuelve su dato.
 * \param posicion como parámetro de entrada.
 * \return el entero dia, como parámetro de salida.
 */

int mostrar::getdia(int posicion){
    return ui->motrar_tableWidget->item(posicion,0)->text().toInt();
}

/*!
 * \brief mostrar::getmes -> devuelve el mes en la posición del array en la que se encuentra.
 * \param posicion como parámetro de entrada.
 * \return el entero mes, como parámetro de salida.
 */

int mostrar::getmes(int posicion){
    return ui->motrar_tableWidget->item(posicion,1)->text().toInt();
}

/*!
 * \brief mostrar::getanio -> devuelve el año en la posición del array en la que se encuentra.
 * \param posicion como parámetro de entrada.
 * \return el entero año, como parámetro de salida.
 */

int mostrar::getanio(int posicion){
    return ui->motrar_tableWidget->item(posicion,2)->text().toInt();
}

/*!
 * \brief mostrar::gethora -> devuelve el hora en la posición del array en la que se encuentra.
 * \param posicion como parámetro de entrada.
 * \return el entero hora, como parámetro de salida.
 */

int mostrar::gethora(int posicion){

    QStringList qsl = ui->motrar_tableWidget->item(posicion,3)->text().split(":");
    return qsl[0].toInt();
}

/*!
 * \brief mostrar::getminuto -> devuelve el minuto en la posición del array en la que se encuentra.
 * \param posicion como parámetro de entrada.
 * \return el entero minuto, como parámetro de salida.
 */

int mostrar::getminuto(int posicion){
    QStringList qsl = ui->motrar_tableWidget->item(posicion,3)->text().split(":");
    return qsl[1].toInt();
}

/*!
 * \brief mostrar::getdescripcion -> devuelve la descripción en la posición del array en la que se encuentra.
 * \param posicion como parámetro de entrada.
 * \return el string descripcion, como parámetro de salida.
 */

QString mostrar::getdescripcion(int posicion){
    return ui->motrar_tableWidget->item(posicion,4)->text().toStdString().c_str();
}

/*!
 * \brief mostrar::getprioridad -> devuelve la prioridad en la posición del array en la que se encuentra.
 * \param posicion como parámetro de entrada.
 * \return el entero prioridad, como parámetro de salida.
 */

int mostrar::getprioridad(int posicion){
    return ui->motrar_tableWidget->item(posicion,5)->text().toInt();
}

/*!
 * \brief mostrar::geteliminar -> devuelve la prioridad en la posición del array en la que se encuentra.
 * \param posicion  devuelve que es 1, y si no 0; y segun eso, lo borra o no.
 * \return devuelve el check.
 */
int mostrar::geteliminar(int posicion){

    int r;

    if(ui->motrar_tableWidget->item(posicion,6)->checkState() == Qt::Checked)
        r = 1;
    else
        r = 0;

    return r;
}


