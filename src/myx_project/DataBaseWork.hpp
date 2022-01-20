/*
 * @file DataBaseWork.hpp
 * @brief TODO
 * @details TODO
 */
#ifndef DataBaseWork_HPP
#define DataBaseWork_HPP
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
/*
 * @class DataBaseWork
 * @brief TODO
 * @details TODO
 */
class DataBaseWork
{
	//объявление методов класса DataBaseWork
public:
	bool connect( const QString& name, const QString& host, const QString& dbname, const QString& password );
	bool insert( const QString& id, const QString& col1, const QString& col2 );
	QString select();
private:
	QSqlDatabase db;
};
#endif // ifndef DataBaseWork_HPP
// DataBaseWork_HPP
// EOF DataBaseWork.hpp
