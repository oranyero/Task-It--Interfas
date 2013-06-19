#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leer_fich(lista);

    primeravez = 0; //Eliminar cuando no este en demostracion.

    if(primeravez != 1){
        abrirAyuda();
        primeravez = 1;
    }

    pintarCeldas();

    //selecciona la fecha del dia de hoy
    ui->main_info_dia->setPlainText(ui->calendarWidget_main->selectedDate().toString("dd"));
    ui->main_info_mes->setPlainText(ui->calendarWidget_main->selectedDate().toString("MMMM"));
    ui->main_info_anio->setPlainText(ui->calendarWidget_main->selectedDate().toString("yyyy"));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_principal_btn_aniadir_clicked()
{
    aniadir *d1 = new aniadir();
    d1->setDate(ui->calendarWidget_main->selectedDate());
    if(d1->exec()==QDialog::Accepted){

        telemento e;
        e.fecha.dia = d1->getdia();
        e.fecha.mes = d1->getmes();
        e.fecha.anio = d1->getanio();

        e.hora.hora = d1->gethora();
        e.hora.minuto = d1->getminuto();

        strcpy(e.descripcion, d1->getdescripcion().toStdString().c_str());
        e.prioritario = d1->getprioridad();
        e.eliminar = 0;

        insertarOrdenado(lista, e);

        pintarCeldas();

    } else {

        QMessageBox msgBox;
        msgBox.setText("No se guardo la tarea.");
        msgBox.exec();

    }

}



void MainWindow::on_btn_mostrar_principal_clicked(){

    mostrar *d2 = new mostrar();

    d2->setParametros(lista);

    if(d2->exec()==QDialog::Accepted){

        if(!esVacia(lista)){

            int i = 0;
            for (p = lista; p != NULL; p = p->sig){

                p->elemento.fecha.dia = d2->getdia(i);
                p->elemento.fecha.mes = d2->getmes(i);
                p->elemento.fecha.anio = d2->getanio(i);

                p->elemento.hora.hora = d2->gethora(i);
                p->elemento.hora.minuto = d2->getminuto(i);

                strcpy(p->elemento.descripcion, d2->getdescripcion(i).toStdString().c_str());
                p->elemento.prioritario = d2->getprioridad(i);
                p->elemento.eliminar = d2->geteliminar(i);
                i++;
            }

            for (p = lista; p != NULL; p = p->sig){

                if(p->elemento.eliminar == 1){
                    borrar(lista, p);
                }

            }

            pintarCeldas();
        }
    }
}

void MainWindow::abrirAyuda(){

    ayuda *a1 = new ayuda();
    a1->exec();

}

void MainWindow::on_btn_guardar_principal_clicked(){

    escribirArchivo(lista);

}

void MainWindow::on_calendarWidget_main_clicked(const QDate &date){

    mostrarTareasTablaMain();
}


void MainWindow::mostrarTareasTablaMain(){

    // marca la fecha seleccionada
    ui->main_info_dia->setPlainText(ui->calendarWidget_main->selectedDate().toString("dd"));
    ui->main_info_mes->setPlainText(ui->calendarWidget_main->selectedDate().toString("MMMM"));
    ui->main_info_anio->setPlainText(ui->calendarWidget_main->selectedDate().toString("yyyy"));

    int c=1;
    if(!esVacia(lista)){
    //limpia la tabla
    for(int i=0; i < longitud(lista); i++){
       ui->main_info_tareas_dia->removeRow(i);

    }

    //Crea la informacion hora, minuto, tarea, prioridad de la tabla.
            ui->main_info_tareas_dia->setRowCount(5);
            ui->main_info_tareas_dia->setColumnCount(4);

            QTableWidgetItem* hora = new QTableWidgetItem("Hora");
            QTableWidgetItem* minuto = new QTableWidgetItem("Minuto");

            QTableWidgetItem* tarea = new QTableWidgetItem("Tarea");
            QTableWidgetItem* prioridad = new QTableWidgetItem("Prioridad");

            ui->main_info_tareas_dia->setItem(0,0,tarea);

            ui->main_info_tareas_dia->setItem(0,1,hora);
            ui->main_info_tareas_dia->setItem(0,2,minuto);

            ui->main_info_tareas_dia->setItem(0,3,prioridad);

        //Muestra las tareas para el dia seleccionado
        for (p = lista; p != NULL; p = p->sig){

            if(ui->calendarWidget_main->selectedDate().day() == p->elemento.fecha.dia && ui->calendarWidget_main->selectedDate().month() == p->elemento.fecha.mes && ui->calendarWidget_main->selectedDate().year() == p->elemento.fecha.anio){

                QString dia = QString("%1").arg(p->elemento.fecha.dia);
                QString mes = QString("%1").arg(p->elemento.fecha.mes);
                QString anio = QString("%1").arg(p->elemento.fecha.anio);

                QString hora = QString("%1").arg(p->elemento.hora.hora);
                QString minuto = QString("%1").arg(p->elemento.hora.minuto);

                QString descripcion = QString("%1").arg(p->elemento.descripcion);
                QString prioridad = QString("%1").arg(p->elemento.prioritario);

                QTableWidgetItem* hh = new QTableWidgetItem(hora);
                QTableWidgetItem* min = new QTableWidgetItem(minuto);

                QTableWidgetItem* des = new QTableWidgetItem(descripcion);
                QTableWidgetItem* pri = new QTableWidgetItem(prioridad);

                ui->main_info_tareas_dia->setItem(c,0,des);

                ui->main_info_tareas_dia->setItem(c,1,hh);
                ui->main_info_tareas_dia->setItem(c,2,min);

                ui->main_info_tareas_dia->setItem(c,3,pri);
                c++;
            }

        }

       }

}


void MainWindow::leer_fich(tlista &l){


    fstream AuxArchivo;

    AuxArchivo.open("/Applications/Qt/Proyectos/TaskItFinal/TaskItFinal/bd.txt", ios::in);

    if(!AuxArchivo){

        QMessageBox msgBox;
        msgBox.setText("Error en la carga del archivo.");
        msgBox.exec();

    } else {

        telemento e;
        int lng;

        AuxArchivo >> lng;
        AuxArchivo >> primeravez;

        for(int i = 0; i < lng; i++){

            AuxArchivo >> e.hora.hora;
            AuxArchivo >> e.hora.minuto;

            AuxArchivo >> e.fecha.dia;
            AuxArchivo >> e.fecha.mes;
            AuxArchivo >> e.fecha.anio;

            AuxArchivo >> e.prioritario;
            AuxArchivo.getline(e.descripcion, 50);

            insertarFinal(l, e);

        }

    }

    AuxArchivo.close();

}

void MainWindow::escribirArchivo (tlista l){

    tposicion p;
    fstream archivo;

    archivo.open("/Applications/Qt/Proyectos/TaskItFinal/TaskItFinal/bd.txt", ios::out);

    if (!archivo)

        cout << "\nError al escribir en el archivo.\n";

    else{

        archivo << longitud(l) << " ";
        archivo << primeravez << endl;

        p = l;

        while (p != NULL) {

            archivo << p->elemento.hora.hora << " ";
            archivo << p->elemento.hora.minuto << " ";

            archivo << p->elemento.fecha.dia << " ";
            archivo << p->elemento.fecha.mes << " ";
            archivo << p->elemento.fecha.anio << " ";

            archivo << p->elemento.prioritario << " ";
            archivo << p->elemento.descripcion << endl;

            p = p->sig;

        }

        QMessageBox msgBox;
        msgBox.setText("Se ha guardado el archivo.");
        msgBox.exec();


    }
}

void MainWindow::pintarCeldas(){

    if(!esVacia(lista)){
    //definición de variables
    QBrush brushpri1,brushpri2,brushpri3;
    QDate date;

    //colores
    brushpri1.setColor(QColor(255,214,214)); //rojo
    brushpri2.setColor(QColor(255,253,227)); //amarillo
    brushpri3.setColor(QColor(225,237,255)); //azul

    //pintarlas
    for (p = lista; p != NULL; p = p->sig){

     date.setDate(p->elemento.fecha.anio, p->elemento.fecha.mes, p->elemento.fecha.dia);
     QTextCharFormat cf = ui->calendarWidget_main->dateTextFormat(date);

     switch(p->elemento.prioritario){
        case 1:
            cf.setBackground( brushpri1 );
            break;

        case 2:
            cf.setBackground( brushpri2 );
            break;

        case 3:
            cf.setBackground( brushpri3 );
            break;
        }

     ui->calendarWidget_main->setDateTextFormat( date, cf );

    }

    }

}

void MainWindow::on_pushButton_clicked()
{
    escribirArchivo(lista);
}

void MainWindow::on_btn_salir_principal_clicked(){

    close();

}
