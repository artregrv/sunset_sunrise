#include "database_manager.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);

    QQmlApplicationEngine engine("qrc:main.qml");

    DatabaseManager databaseManager;

    return application.exec();
}
