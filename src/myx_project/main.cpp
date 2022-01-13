/*
 *  @file    main.cpp
 *  @brief   TODO
 *  @details TODO
 */
#include "DataBaseWork.hpp"
#include "form.hpp"
//#include "form.hpp"

#include <QApplication>
#include <QIcon>
#include <QTranslator>

/*
 *  @fn $(fclass)::main
 *  @param argc TODO
 *  @param argv TODO
 *  @return TODO
 *  @details TODO
 */int main( int argc, char** argv )
{
	QApplication app( argc, argv );
	auto* w = new Form();
	w->show();
	return( QApplication::exec() );
}


// EOF main.cpp
