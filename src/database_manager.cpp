#include "database_manager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTime>
#include <QDate>

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

    // QSqlQuery query;
    // query.prepare("INSERT INTO day (date, sunrise_time, sunset_time) "
    //               "VALUES (:date, :sunrise_time, :sunset_time)");
    // query.bindValue(":date", "2024.02.02");
    // query.bindValue(":sunrise_time", "00:00:01");
    // query.bindValue(":sunset_time", "00:00:02");
    // qDebug() << "exec:" << query.exec();

    qDebug() << database.isOpen() << database.tables();

    // QString currentDate = "2024.02.02";
    QDate currentDate = QDate::currentDate();

    QSqlQuery dayQuery;
    dayQuery.prepare("SELECT * FROM day WHERE date = :date");
    dayQuery.bindValue(":date", currentDate.toString(Qt::ISODate));
    qDebug() << "exec:" << dayQuery.exec();

    QSqlRecord record = dayQuery.record();
    qDebug() << "columns number:" << record.count();

    dayQuery.next();

    int sunriseTimeIndex = record.indexOf("sunrise_time");
    qDebug() << "sunrise time at" << currentDate.toString(Qt::ISODate) << "is" << dayQuery.value(sunriseTimeIndex).toTime();
    int sunsetTimeIndex = record.indexOf("sunset_time");
    qDebug() << "sunset time at" << currentDate.toString(Qt::ISODate) << "is" << dayQuery.value(sunsetTimeIndex).toTime();
}

