#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    // Creando los colores de la tercera barra
    QColor cRellenoBarra0(93, 70, 146);
    QColor cBordeBarra0(72, 0, 239);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra0);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra0);


    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    //obtener datos para la primera barra
    int nota1 = ui->inNota1->value();
    int altoN1 = this->getAlto(nota1);
    int incYN1 = this->incY(altoN1);


    // Dibujar primera barra
    painter.drawRect(x+75, y+50+incYN1,100,altoN1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(255, 120, 0);
    // Crear otro objeto color para el borde
    QColor colorBorde(255, 86, 42);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    //obtener datos para la segunda barra
    int nota2 = ui->inNota2->value();
    int altoN2 = this->getAlto(nota2);
    int incYN2 = this->incY(altoN2);

    // Dibujar segunda barra
    painter.drawRect(x+200, y+50+incYN2, 100, altoN2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(43, 116, 108);
    QColor cBordeBarra3(0, 197, 176);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //obtener datos para la tercera barra
    int nota3 = ui->inNota3->value();
    int altoN3 = this->getAlto(nota3);
    int incYN3 = this->incY(altoN3);

    // Dibujar tercera barra
    painter.drawRect(x+315,y+50+incYN3,100,altoN3);

    //dibuujar promedio

    int promedio = (nota1 + nota2 + nota3) / 3;
    int altoN4 = this->getAlto(promedio);
    int incYN4 = this->incY(altoN4);

    painter.drawLine(x+50,y+50+incYN4,x+450,y+50+incYN4);
    QColor cRellenoBarra4(155, 250, 0);
    QColor cBordeBarra4(121, 143, 12);

//Plano cartesiano
    //linea en y
    painter.drawLine(x+50,y+50,x+50,y+475);
    //linea en x
    painter.drawLine(x+25,y+450,x+475,y+450);

}

int Principal::getAlto(int valor)
{
    return  4 * valor;
}

int Principal::incY(int alto)
{
    return 400 - alto;
}




void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}



void Principal::on_pushButton_clicked(bool checked)
{

}



void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}
