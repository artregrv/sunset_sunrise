#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QSqlDatabase>

#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);

    QQmlApplicationEngine engine("/home/artregrv/repos/qt_sql/main.qml");

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    // database.setHostName("localhost");
    database.setDatabaseName("/home/artregrv/test.db");

    qDebug() << database.open() << "is open";

    // database.setUserName("root");
    // database.setPassword("vasntkp");

    qDebug() << database.tables();

    return application.exec();
}
