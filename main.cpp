
	/**
	Barchelor's dergee thesis "Creating safe distributed database"
	main.cpp
	Purpose: Creating main window of program

	@author Natalia Glazkina
	@version 1.0 10.04.2016
	*/
#include <QApplication>
#include "basesWidget.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	BasesWidget baseWidget;
	baseWidget.show();

	return app.exec();
}
