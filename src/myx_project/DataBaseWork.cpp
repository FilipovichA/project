/*
 *  @file    DataBaseWork.cpp
 *  @brief   TODO
 *  @details TODO
 */
#include "DataBaseWork.hpp"
/*
 *  @fn DataBaseWork::DataBaseWork
 *  @param name TODO
 *  @param host TODO
 *  @param dbname TODO
 *  @param password TODO
 *  @return TODO
 *  @details TODO
 */DataBaseWork::DataBaseWork( const QString& name, const QString& host, const QString& dbname, const QString& password )
{
	db = QSqlDatabase::addDatabase( "QPSQL" );
	db.setUserName( name );
	db.setHostName( host );
	db.setDatabaseName( dbname );
	db.setPassword( password );
}


/*
 *  @fn DataBaseWork::connect
 *  @return TODO
 *  @details TODO
 */bool DataBaseWork::connect()
{
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
 *  @fn DataBaseWork::insert
 *  @param id TODO
 *  @param col1 TODO
 *  @param col2 TODO
 *  @return TODO
 *  @details TODO
 */bool DataBaseWork::insert( const QString& id, const QString& col1, const QString& col2 )
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
 *  @fn DataBaseWork::select
 *  @return TODO
 *  @details TODO
 */QString DataBaseWork::select()
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


// EOF DataBaseWork.cpp
