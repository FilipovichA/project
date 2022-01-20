/*
 * @file DataBaseWork.cpp
 * @brief TODO
 * @details TODO
 */
#include "DataBaseWork.hpp"
/*
 * @fn DataBaseWork::connect
 * @return TODO
 * @details TODO
 */
//поключение к базе данных
bool DataBaseWork::connect( const QString& name, const QString& host, const QString& dbname, const QString& password )
{
	db = QSqlDatabase::addDatabase( "QPSQL" );
	db.setUserName( name );
	db.setHostName( host );
	db.setDatabaseName( dbname );
	db.setPassword( password );
	if ( !db.open() )
	{
		qDebug() << "bd not open";
		return( false );
	}
	else
	{
		qDebug() << "bd is open";
		return( true );
	}
}


/*
 * @fn DataBaseWork::insert
 * @param id TODO
 * @param col1 TODO
 * @param col2 TODO
 * @return TODO
 * @details TODO
 */
//реализация запроса insert в базе данных
bool DataBaseWork::insert( const QString& id, const QString& col1, const QString& col2 )
{
	QSqlQuery query;
	query.prepare( "INSERT INTO tabl (id,col1,col2)"
	               " VALUES (" + id + "," + col1 + "," + col2 + ")" );
	if ( !query.exec() )
	{
		qDebug() << "failed";
		return( false );
	}
	else
	{
		qDebug() << "Successfully";
		return( true );
	}
}


/*
 * @fn DataBaseWork::select
 * @return TODO
 * @details TODO
 */
//реализация запроса select в базе данных
QString DataBaseWork::select()
{
	QSqlQuery query;
	query.prepare( "select id,col1,col2 from tabl;" );
	if ( !query.exec() )
	{
		qDebug() << "failed";
		return( nullptr );
	}
	else
	{
		QString line;
		//запись данных из базы в QString построчно, разделяя их ";"
		while ( query.next() )
		{
			line = line + query.value( "id" ).toString() + ";";
			line = line + query.value( "col1" ).toString() + ";";
			line = line + query.value( "col2" ).toString() + ";";
			line = line + "\n";
		}
		return( line );
	}
} // DataBaseWork::select


// DataBaseWork::select
// EOF DataBaseWork.cpp
