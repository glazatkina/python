	/**
	Barchelor's dergee thesis "Creating safe distributed database"
	basesWidget.cpp
	Purpose: realise class BasesWidget

	@author Natalia Glazkina
	@version 1.0 10.04.2016
	*/
#include "basesWidget.h"
#include <QtWidgets>
#include <QtSql>
#include <QCryptographicHash>
#include <QVBoxLayout>
#include <QFile>

BasesWidget::BasesWidget(QWidget* pwgt /*=0*/) : QMainWindow(pwgt), ui(new Ui::mainWindow) {
	//download ui component
	setupUi(this);
	//set tabWidget at first tab
	tabWidget->setCurrentIndex(0);

	//creating signalMapper that catching all buttons clicks and connect it with menu buttons
	signalMapper = new QSignalMapper();

	signalMapper->setMapping(btnOpenFolderDB1, "btnOpenFolderDB1");
	connect(btnOpenFolderDB1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(btnRefreshDB1, "btnRefreshDB1");
	connect(btnRefreshDB1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(btnDeleteAllDB1, "btnDeleteAllDB1");
	connect(btnDeleteAllDB1, SIGNAL(clicked()), signalMapper, SLOT(map()));

	signalMapper->setMapping(btnOpenFolderDB2, "btnOpenFolderDB2");
	connect(btnOpenFolderDB2, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(btnRefrechDB2, "btnRefreshDB2");
	connect(btnRefrechDB2, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(btnDeleteAllDB2, "btnDeleteAllDB2");
	connect(btnDeleteAllDB2, SIGNAL(clicked()), signalMapper, SLOT(map()));

	//trying to connect to administrator database
	if (connectDB()) {

		//connecting to table with files BUZ OO
		modelServerDB1 = new QSqlQueryModel;
		modelServerDB1->setQuery("SELECT files1.\"fileName\", files1.\"fileDate\", FALSE FROM public.files1;", db);
		modelServerDB1->setHeaderData(0, Qt::Horizontal, tr("Name"));
		modelServerDB1->setHeaderData(1, Qt::Horizontal, tr("Date"));
		modelServerDB1->setHeaderData(2, Qt::Horizontal, tr(""));
		tableViewServerDB1->setModel(modelServerDB1);
		//adding buttons "Save"
		for (int i = 0; i < modelServerDB1->rowCount(); i++) {
			QPushButton *btn = new QPushButton(tr("Save"), tableViewServerDB1);
			connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
			signalMapper->setMapping(btn, "B " + QString::number(i));
			tableViewServerDB1->setIndexWidget(modelServerDB1->index(i, 2), btn);
		}


		//connecting to table with files IBV
		modelServerDB2 = new QSqlQueryModel;
		modelServerDB2->setQuery("SELECT files2.\"fileName\", files2.\"fileDate\", FALSE FROM public.files2;", db);
		modelServerDB2->setHeaderData(0, Qt::Horizontal, tr("Name"));
		modelServerDB2->setHeaderData(1, Qt::Horizontal, tr("Date"));
		modelServerDB2->setHeaderData(2, Qt::Horizontal, tr(""));
		tableViewServerDB2->setModel(modelServerDB2);
		//adding buttons "Save"
		for (int i = 0; i < modelServerDB2->rowCount(); i++) {
			QPushButton *btn = new QPushButton(tr("Save"), tableViewServerDB2);
			connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
			signalMapper->setMapping(btn, "I " + QString::number(i));
			tableViewServerDB2->setIndexWidget(modelServerDB2->index(i, 2), btn);
		}

		//connecting to table with files BUZ OO
		modelLocalDB1 = new QSqlQueryModel;
		refresh("btnRefreshDB1");
		


		//connecting to table with files IBV
		modelLocalDB2 = new QSqlQueryModel;
		refresh("else");

	}
	else {
		int n = QMessageBox::critical(0, tr("Error"), tr("Error : ") + db.lastError().text(), QMessageBox::Ok);
	}	
	
	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(clicked(const QString &)));
}

BasesWidget::~BasesWidget() {
	delete ui;
	delete modelServerDB1;
	delete signalMapper;
}

bool BasesWidget::connectDB() {
	db = QSqlDatabase::addDatabase("QPSQL", "Admin");
	db.setHostName("localhost");
	db.setPort(5432);
	db.setDatabaseName("safetyAdmin");
	db.setUserName("postgres");
	db.setPassword("Roman9");


	db_loc = QSqlDatabase::addDatabase("QPSQL", "Operator");
	db_loc.setHostName("localhost");
	db_loc.setPort(5432);
	db_loc.setDatabaseName("safetyOperator");
	db_loc.setUserName("postgres");
	db_loc.setPassword("Roman9");
	if (db.open() && db_loc.open()) {
		statusbar->addWidget(new QLabel(tr("Database connection created.")));
		return true;
	}
	else {
		int n = QMessageBox::critical(0, tr("Error"), tr("Error : ") + db.lastError().text() + " " + db_loc.lastError().text(), QMessageBox::Ok);
		return false;
	}
}

void BasesWidget::clicked(const QString & text) {
	//buttons on bottom
	if (text[0] == 'b') {
		if (text[3] == 'D') {
			deleteAll(text);
		}
		else {
			if (text[3] == 'O') {
				openDir(text);
			}
			else {
				if (text[3] == 'R') {
					refresh(text);
				}
			}
		}
	}
	else {
		//buttons that save files from administrator database
		if (text[1] == ' ') {
			copy(text);
		}
		//bunntons that open files from local database
		else {
			open(text);
		}
	} 

	
}

bool BasesWidget::copy(const QString & text) {
	//QMessageBox::information(this, tr("Good"), "YOU WANT SAVE FIIILE WOOOW", QMessageBox::Ok);
	QStringList strLst = text.split(" ");
	int fileId = strLst[1].toInt();
	fileId++;
	QString fileName;
	QString fileDir;
	QDateTime fileDate;
	QString strQuery;
	QString tbl = (strLst[0] == "B") ? "files1" : "files2";
	if (strLst[0] == "B") { //this file from BUZ directory
		strQuery = QString("SELECT files1.\"fileName\", files1.\"fileDir\" FROM public.files1 WHERE files1.\"fileId\" = %1;").arg(fileId);
	}
	else { //this file from IBV directory
		strQuery = QString("SELECT files2.\"fileName\", files2.\"fileDir\" FROM public.files2 WHERE files2.\"fileId\" = %1;").arg(fileId);
	}
	QSqlQuery query(db);
	if (query.exec(strQuery)) {
		QSqlRecord rec = query.record();
		while (query.next()) {
			fileName = query.value(rec.indexOf("fileName")).toString();
			fileDir = query.value(rec.indexOf("fileDir")).toString();
			qDebug() << "fileName: " << fileName << "; fileDir: " << fileDir << "; fileDate: "<< fileDate << endl;
		}
		if (QFile(fileDir + "\\" + fileName).exists() && !(QFile("C:\\" + fileName).exists())) {
			QString newDir = "C:\\operatorDB\\";
			newDir += (tbl == "files1") ? "BUZ\\" : "IBV\\";
			newDir += QDateTime::currentDateTime().toString("yyyy.MM.dd.hh.mm") + "\\";
			QDir dir(newDir);
			if (!dir.exists()) {
				dir.mkdir(".");
			}

			bool ok = QFile::copy(fileDir + "\\" + fileName, newDir + fileName);
			if (!ok) {
				qDebug() << "Error: file copying failed.";
			}
			else {
				QSqlQuery queryRec(db_loc);
				strQuery = QString("INSERT INTO public.%1 (\"fileName\", \"fileDir\", \"fileSize\", \"fileDate\") VALUES (%2, %3, %4, %5);").arg("\"" + tbl + "\"").arg("'" + fileName + "'").arg("'" + newDir + "'").arg(QFileInfo(newDir + "\\" + fileName).size()).arg("'" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") + "'");
				qDebug() << strQuery;
				if (!queryRec.exec(strQuery)) {
					qDebug() << "Error: " << queryRec.lastError();
				}
				else {
					QMessageBox::information(this, tr("Good"), "File added to your computer. Press refresh button.", QMessageBox::Ok);
				}
			}
		}
		else {
			qDebug() << "Error: file not found";
		}
	}
	else {
		qDebug() << query.lastError();
	}
	return true;
}

bool BasesWidget::open(const QString & text) {
	QStringList strLst = text.split(" ");
	int fileId = strLst[1].toInt();
	QString dir;
	QSqlQuery qr(db_loc);
	if (text[0] == 'B') {
		QString query = QString("SELECT files1.\"fileName\", files1.\"fileDir\" FROM public.files1 WHERE files1.\"fileId\" = %1;").arg(fileId);
		if (!qr.exec(query))
			qDebug() << qr.lastError();
	}
	else {
		QString query = QString("SELECT files2.\"fileName\", files2.\"fileDir\" FROM public.files2 WHERE files2.\"fileId\" = %1;").arg(fileId);
		if (!qr.exec(query))
			qDebug() << qr.lastError();
	}
	QSqlRecord rec = qr.record();
	qr.next();
	dir = qr.value(rec.indexOf("fileDir")).toString();
	dir += qr.value(rec.indexOf("fileName")).toString();
	qDebug() << dir;
	QProcess::startDetached("cmd /c \"" + dir + "\"");
	return true;
}

bool BasesWidget::refresh(const QString & text) {
	//QMessageBox::critical(this, tr("Good"), "i loooove it", QMessageBox::Ok);
	if (text == "btnRefreshDB1") {
		QSqlQuery qr(db_loc);
		qr.exec("SELECT files1.\"fileId\" FROM public.files1;");
		QSqlRecord rec = qr.record();
		modelLocalDB1->setQuery("SELECT files1.\"fileName\", files1.\"fileDate\", FALSE FROM public.files1;", db_loc);
		modelLocalDB1->setHeaderData(0, Qt::Horizontal, tr("Name"));
		modelLocalDB1->setHeaderData(1, Qt::Horizontal, tr("Date"));
		modelLocalDB1->setHeaderData(2, Qt::Horizontal, tr(""));
		tableViewLocalDB1->setModel(modelLocalDB1);
		//adding buttons "Save"
		for (int i = 0; i < modelLocalDB1->rowCount(); i++) {
			qr.next();
			QPushButton *btn = new QPushButton(tr("Open"), tableViewLocalDB1);
			connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
			signalMapper->setMapping(btn, "BUZ " + qr.value(rec.indexOf("fileId")).toString());
			//qDebug() << qr.value(rec.indexOf("fileId")).toString() << endl;
			tableViewLocalDB1->setIndexWidget(modelLocalDB1->index(i, 2), btn);
		}
	}
	else {
		QSqlQuery qr(db_loc);
		qr.exec("SELECT files2.\"fileId\" FROM public.files2;");
		QSqlRecord rec = qr.record();
		modelLocalDB2->setQuery("SELECT files2.\"fileName\", files2.\"fileDate\", FALSE FROM public.files2;", db_loc);
		modelLocalDB2->setHeaderData(0, Qt::Horizontal, tr("Name"));
		modelLocalDB2->setHeaderData(1, Qt::Horizontal, tr("Date"));
		modelLocalDB2->setHeaderData(2, Qt::Horizontal, tr(""));
		tableViewLocalDB2->setModel(modelLocalDB2);
		//adding buttons "Save"
		for (int i = 0; i < modelLocalDB2->rowCount(); i++) {
			qr.next();
			QPushButton *btn = new QPushButton(tr("Open"), tableViewLocalDB2);
			connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
			signalMapper->setMapping(btn, "IBV " + qr.value(rec.indexOf("fileId")).toString());
			//qDebug() << qr.value(rec.indexOf("fileId")).toString() << endl;
			tableViewLocalDB2->setIndexWidget(modelLocalDB2->index(i, 2), btn);
		}
	}
	return true;
}

bool BasesWidget::openDir(const QString & text) {
	if (text[text.length() - 1] == '1')
		QProcess::startDetached("EXPLORER.EXE C:\\operatorDB\\BUZ");
	else 
		QProcess::startDetached("EXPLORER.EXE C:\\operatorDB\\IBV");
	return true;
}

bool BasesWidget::deleteAll(const QString & text) {
	QSqlQuery qr(db_loc);
	QDir dir;
	if (text[text.length() - 1] == '1') {
		dir.absoluteFilePath("C:\\operatorDB\\BUZ\\");
	}
	else {
		dir.absoluteFilePath("C:\\operatorDB\\IBV\\");
	}

	removeFolder(dir);
	return true;
}

int BasesWidget::removeFolder(QDir & dir)
{
	int res = 0;
	//Получаем список каталогов
	QStringList lstDirs = dir.entryList(QDir::Dirs | QDir::AllDirs | QDir::NoDotAndDotDot);
	//Получаем список файлов   
	QStringList lstFiles = dir.entryList(QDir::Files);

	//Удаляем файлы
	foreach(QString entry, lstFiles)
	{
		QString entryAbsPath = dir.absolutePath() + "\\" + entry;

		QFile::remove(entryAbsPath);
	}

	//Для папок делаем рекурсивный вызов    
	foreach(QString entry, lstDirs)
	{

		QString entryAbsPath = dir.absolutePath() + "\\" + entry;

		removeFolder(QDir(entryAbsPath));
	}

	if (!QDir().rmdir(dir.absolutePath()))
	{

		res = 1;
	}
	return res;
}