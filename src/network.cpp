#include "network.h"
#include "qmainwindow.h"
#include <qdebug.h>
#include <qobject.h>

Network::Network(QObject* parent) : QObject(parent)
{
}

Network::~Network()
{

}

void Network::updateData()
{
    qDebug("Updating data...\n");
}

