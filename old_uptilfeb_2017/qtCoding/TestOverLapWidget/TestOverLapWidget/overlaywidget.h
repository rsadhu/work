#ifndef OVERLAYWIDGET_H
#define OVERLAYWIDGET_H
#include <QWidget>

namespace OverLay
{
	class OverLayWidget : public QWidget
	{
		Q_OBJECT

	public:
		OverLayWidget(QWidget *parent = 0);
		~OverLayWidget();	
	protected:
		void paintEvent(QPaintEvent  *event);
		void resizeEvent(QResizeEvent *event);
	};
};

#endif // OVERLAYWIDGET_H
