/*
 *  @file    dbconnect.hpp
 *  @brief   TODO
 *  @details TODO
 */
#ifndef DBCONNECT_HPP
#define DBCONNECT_HPP

#include <QWidget>
#include "QMessageBox"

namespace Ui {

class DbConnect;

} // namespace Ui
/*
 *  @class   DbConnect
 *  @brief   TODO
 *  @details TODO
 */
class DbConnect : public QWidget
{
	Q_OBJECT

public:
	explicit DbConnect( QWidget* parent = nullptr );
	~DbConnect();
	//объявление слотов класса DbConnect
private slots:
	void connectDb2();

private:
	Ui::DbConnect* ui;
};

#endif // ifndef DBCONNECT_HPP
// DBCONNECT_HPP
// EOF dbconnect.hpp
