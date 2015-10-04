#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

class Network: public QObject
{
    //Q_OBJECT
public:
    Network(QObject* parent);
    ~Network();
public slots:
    void updateData();
};

#endif // NETWORK_H
