/*
 *  @file    form.hpp
 *  @brief   TODO
 *  @details TODO
 */
#ifndef FORM_HPP
#define FORM_HPP

#include <QWidget>
#include "DataBaseWork.hpp"

namespace Ui {

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

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();


private:
	Ui::Form* ui;
}; // class Form

#endif // FORM_HPP
// EOF form.hpp
