#ifndef ANIADIR_H
#define ANIADIR_H

#include <QDialog>
#include <QDate>

namespace Ui {
class aniadir;
}

class aniadir : public QDialog
{
    Q_OBJECT
    
public:
    explicit aniadir(QWidget *parent = 0);
    ~aniadir();
    
public slots:
    void setDate(QDate date);
    int getdia();
    int getmes();
    int getanio();
    int gethora();
    int getminuto();
    QString getdescripcion();
    int getprioridad();

private:
    Ui::aniadir *ui;
};

#endif // ANIADIR_H
