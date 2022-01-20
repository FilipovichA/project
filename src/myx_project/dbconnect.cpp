/*
 *  @file    dbconnect.cpp
 *  @brief   TODO
 *  @details TODO
 */
#include "dbconnect.hpp"
#include "ui_dbconnect.h"
#include "DataBaseWork.hpp"

/*
 *  @fn DbConnect::DbConnect
 *  @param parent TODO
 *  @return TODO
 *  @details TODO
 */
DbConnect::DbConnect( QWidget* parent ) :
	QWidget( parent ),
	ui     ( new Ui::DbConnect )
{
	ui->setupUi( this );
	//скрытие пароля при вводе в форме
	ui->lineEdit_4->setEchoMode( QLineEdit::Password );
	//подключение к кнопке индивидуального слота
	connect( ui->pushButton, &QPushButton::clicked, this, &DbConnect::connectDb2 );
}


/*
 *  @fn $(fclass)::~DbConnect
 *  @return TODO
 *  @details TODO
 */
DbConnect::~DbConnect()
{
	delete ui;
}


/*
 *  @fn DbConnect::on_pushButton_clicked
 *  @return TODO
 *  @details TODO
 */
//ввод в слот исполняемой функции
void DbConnect::connectDb2()
{ //создание объекста класса DataBaseWork
	DataBaseWork databaseWork;
	//вызов метода класса DataBaseWork
	databaseWork.connect( ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text() );
}


// EOF dbconnect.cpp
