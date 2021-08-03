#include "testqtqml.h"

TestQtQml::TestQtQml()
{

    connect(this, &TestQtQml::changeAddress, &m_kvr, &KVR::changeAddress);
}


KVR::KVR(QObject *parent):QObject(parent)
{
    connect(this, &KVR::changeAddress, this , &KVR::onAddressChanged);
}

void KVR::onAddressChanged(QString address)
{
    m_addr = address;
}
