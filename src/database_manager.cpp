#include "database_manager.h"

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDebug>

DatabaseManager::DatabaseManager()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL3");
    // QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    // database.setDatabaseName("/home/artregrv/test.db");
    database.setHostName("localhost");
    database.setDatabaseName("sunset_sunrise");
    database.setUserName("user");
    database.setPassword("123");
    database.open();

    // qDebug() << QSqlDatabase::drivers();

    QSqlQuery query;
    query.prepare("INSERT INTO day (date, sunrise_time, sunset_time) "
                  "VALUES (:date, :sunrise_time, :sunset_time)");
    query.bindValue(":date", "2024.02.02");
    query.bindValue(":sunrise_time", "00:00:01");
    query.bindValue(":sunset_time", "00:00:02");
    qDebug() << "exec:" << query.exec();

    qDebug() << database.isOpen() << database.tables();
}

