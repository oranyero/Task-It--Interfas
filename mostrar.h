#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <QDialog>
#include <QTime>
#include <QTableView>
#include <QMessageBox>
#include "tlista.h"

namespace Ui {
class mostrar;
}

class mostrar : public QDialog
{
    Q_OBJECT
    
public:
    explicit mostrar(QWidget *parent = 0);
    ~mostrar();

public slots:
    void setParametros(tlista);

    QString convHoraMinutoMostrar(int hora, int minuto);
    int getdia(int posicion);
    int getmes(int posicion);
    int getanio(int posicion);
    int gethora(int posicion);
    int getminuto(int posicion);
    QString getdescripcion(int posicion);
    int getprioridad(int posicion);
    int geteliminar(int posicion);
    
private:
    Ui::mostrar *ui;
};

#endif // MOSTRAR_H
