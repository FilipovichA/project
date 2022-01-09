#include "form.hpp"
#include "ui_form.h"


Form::Form( QWidget* parent ) :
	QWidget( parent ),
	ui     ( new Ui::Form )
{
	ui->setupUi( this );
}


Form::~Form()
{
	delete ui;
}


DataBaseWork database_work( "sasha", "localhost", "bd", "2882" );
void Form::on_pushButton_clicked()
{
	database_work.connect();
	QFile inputFile( ui->lineEdit->text() );     //"/home/sasha/myx_project/src/test_project_myx/table1.csv"
	if ( !inputFile.open( QFile::ReadOnly ) )
	{
		qDebug() << "error";
	}
	else
	{
		while ( !inputFile.atEnd() )
		{
			QString line = inputFile.readLine();
			QStringList list;
			list = line.split( "," );
			database_work.insert( list.at( 0 ), list.at( 1 ), list.at( 2 ) );
		}
	}
	inputFile.close();
}


void Form::on_pushButton_2_clicked()
{
	database_work.connect();
	QFile outputFile1( ui->lineEdit_2->text() ); //"/home/sasha/myx_project/src/test_project_myx/table2.csv"
	QString lines;
	if ( !outputFile1.open( QFile::WriteOnly ) )
	{
		qDebug() << "error";
	}
	QTextStream stream( &outputFile1 );
	lines = database_work.select();
	stream << lines;
	outputFile1.close();
}
