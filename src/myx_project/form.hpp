/*
 * @file form.hpp
 * @brief TODO
 * @details TODO
 */
#ifndef FORM_HPP
#define FORM_HPP

#include <QWidget>
#include "DataBaseWork.hpp"
#include "dbconnect.hpp"
#include "QSqlTableModel"


namespace Ui {

/*
 * @class Form
 * @brief TODO
 * @details TODO
 */
class Form;

} // namespace Ui
/*
 *  @class   Form
 *  @brief   TODO
 *  @details TODO
 */
class Form : public QWidget
{
	Q_OBJECT

public:
	explicit Form( QWidget* parent = nullptr );
	~Form();
	//объявление слотов класса Form
private slots:
	void import();
	void exportt();
	void connectDb();
	void save();
	void show_table();
private:
	Ui::Form*       ui;
	DbConnect*      dbconnect;
	QSqlTableModel* model;
}; // class Form

#endif // FORM_HPP
// EOF form.hpp
