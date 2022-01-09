#include "DataBaseWork.hpp"
#include "form.hpp"
//#include "form.hpp"

#include <QApplication>
#include <QIcon>
#include <QTranslator>

int main( int argc, char** argv )
{
	QApplication app( argc, argv );
	auto* w = new Form();
	w->show();
	return( QApplication::exec() );
}
