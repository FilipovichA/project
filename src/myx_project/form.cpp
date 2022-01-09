#include "form.hpp"
#include "ui_form.h"


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
DataBaseWork databaseWork("sasha","localhost","bd","2882");
void Form::on_pushButton_clicked()
{
    databaseWork.connect();
    QFile input_file(ui->lineEdit->text()); /*"/home/sasha/myx_project/src/test_project_myx/table1.csv"*/
    if (!input_file.open(QFile::ReadOnly))
    {
        qDebug()<<"error";
    }
    else
    {
        while(!input_file.atEnd())
        {QString line= input_file.readLine();
            QStringList list;
            list=line.split(",");
            databaseWork.insert(list.at(0),list.at(1),list.at(2));
        }
    }
    input_file.close();
}

void Form::on_pushButton_2_clicked()
{databaseWork.connect();
    QFile output_file1(ui->lineEdit_2->text()); /*"/home/sasha/myx_project/src/test_project_myx/table2.csv"*/
    QString lines;
    if(!output_file1.open(QFile::WriteOnly))
    {
        qDebug()<<"error";

    }
    QTextStream stream(&output_file1);
    lines= databaseWork.select();
    stream<<lines;
    output_file1.close();

}
