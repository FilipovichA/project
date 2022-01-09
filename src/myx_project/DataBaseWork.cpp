#include "DataBaseWork.hpp"
DataBaseWork::DataBaseWork( const QString& name, const QString& host, const QString& dbname, const QString password )
{
	db = QSqlDatabase::addDatabase( "QPSQL" );
	db.setUserName( name );
	db.setHostName( host );
	db.setDatabaseName( dbname );
	db.setPassword( password );
}


bool DataBaseWork::connect()
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


bool DataBaseWork::insert( QString id, QString col1, QString col2 )
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


QString DataBaseWork::select()
{
	QSqlQuery query;
	query.prepare( "select id,col1,col2 from tabl;" );
	if ( !query.exec() )
	{
		qDebug() << "failed";
		return( 0 );
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
