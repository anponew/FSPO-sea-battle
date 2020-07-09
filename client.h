#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>

class Client : public QObject
{
    Q_OBJECT
public:
    bool isConnected = false;
    QString userName;
    QString address;
    QTcpSocket* socketClient;
    QJsonObject jo;

    explicit Client(QObject *parent = nullptr);

    void readUserName();

    void readAddress();

    void readSocket();

    void writeToSocket(bool state);

    void connectToServer();

    void pack(QString key, QJsonValue data);
signals:

    void enemySpotted(QString mes);

    void cannotConnect();
};

#endif // CLIENT_H
