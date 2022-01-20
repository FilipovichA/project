/*
 * @file form.cpp
 * @brief TODO
 * @details TODO
 */
#include "form.hpp"
#include "ui_form.h"
/*
 * @fn Form::Form
 * @param parent TODO
 * @return TODO
 * @details TODO
 */
Form::Form( QWidget* parent ) :
	QWidget( parent ),
	ui     ( new Ui::Form )
{
	ui->setupUi( this );
	//подключение к кнопкам индивидуальных слотов
	connect( ui->pushButton_3, &QPushButton::clicked, this, &Form::connectDb );
	connect( ui->pushButton, &QPushButton::clicked, this, &Form::import );
	connect( ui->pushButton_2, &QPushButton::clicked, this, &Form::exportt );
	connect( ui->pushButton_4, &QPushButton::clicked, this, &Form::save );
	connect( ui->pushButton_5, &QPushButton::clicked, this, &Form::show_table );
}


/*
 * @fn $(fclass)::~Form
 * @return TODO
 * @details TODO
 */
Form::~Form()
{
	delete ui;
}


/*
 * @fn Form::on_pushButton_clicked
 * @return TODO
 * @details TODO
 */
//слоты для обработки нажатия кнопок
//чтение данных из файла и запись в базу данных
void Form::import()
{
	DataBaseWork database_work;
	//открытие и чтение нужного файла
	QFile inputFile( ui->lineEdit->text() );
	if ( !inputFile.open( QFile::ReadOnly ) )
	{
		qDebug() << "error";
	}
	else
	{
		while ( !inputFile.atEnd() )
		{ //запись данных из файла в QString построчно
			QString line = inputFile.readLine();
			QStringList list;
			//запись данных в QStringList, разделяя их по столбцам запятыми
			list = line.split( "," );
			//запись данных в базу данных в нужные столбцы
			database_work.insert( list.at( 0 ), list.at( 1 ), list.at( 2 ) );
		}
	}
	inputFile.close();
} // Form::import


/*
 * @fn Form::on_pushButton_2_clicked
 * @return TODO
 * @details TODO
 */
//чтение данных из базы данных и запись в файл
void Form::exportt()
{
	DataBaseWork database_work;
	//окрытие файла для записи данных
	QFile outputFile1( ui->lineEdit_2->text() );
	QString lines;
	if ( !outputFile1.open( QFile::WriteOnly ) )
	{
		qDebug() << "error";
	}
	//создание QTextStream, ссылающийся на открытый файл для записи данных
	QTextStream stream( &outputFile1 );
	//запись данных построчно из базы в QString
	lines = database_work.select();
	//запись данных из QString в файл
	stream << lines;
	outputFile1.close();
}


// EOF form.cpp
//открытие новой формы с полями для подключения к бд
void Form::connectDb()
{
	dbconnect = new DbConnect;
	dbconnect->show();
}


/*
 *  @fn Form::on_pushButton_5_clicked
 *  @return TODO
 *  @details TODO
 */
//вывод таблицы в tableView
void Form::show_table()
{
	model = new QSqlTableModel();
	//указание названия таблицы для вывода
	model->setTable( ui->lineEdit_3->text() );
	model->select();
	ui->tableView->setModel( model );
	ui->tableView->resizeColumnsToContents();
	ui->tableView->show();
}


/*
 *  @fn Form::on_pushButton_4_clicked
 *  @return TODO
 *  @details TODO
 */
//сохранение всех измененийв базе
void Form::save()
{
	model->submitAll();
}


// EOF form.cpp
