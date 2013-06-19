#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMessageBox>
#include <QPainter>
#include <fstream>
#include <QTextCharFormat>

#include "tlista.h"
#include "aniadir.h"
#include "mostrar.h"
#include "ayuda.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
        tlista lista = NULL;
        telemento elemento;
        tposicion p;
        int primeravez;
    
private slots:

        void on_principal_btn_aniadir_clicked();

        void on_btn_mostrar_principal_clicked();

        void on_btn_guardar_principal_clicked();

        void mostrarTareasTablaMain();

        void leer_fich(tlista &);

        void escribirArchivo (tlista);

        void pintarCeldas();

        void abrirAyuda();

        void on_calendarWidget_main_clicked(const QDate &date);

        void on_pushButton_clicked();

        void on_btn_salir_principal_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
