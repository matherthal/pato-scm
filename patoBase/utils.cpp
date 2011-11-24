#include "utils.h"
#include <QDataStream>
#include <QDebug>

Utils::Utils()
{
}

std::map< std::string, std::string> Utils::toMapStringString( QByteArray&  BArray)
{
    std::map< std::string, std::string> ret;

    QDataStream stream(&BArray, QIODevice::ReadOnly);

    qint32 size;
    stream >> size;

    QString s1;
    QString s2;
    for (int i=0; i < size; i++)
    {
        stream >> s1;
        stream >> s2;

        ret.insert( std::map< std::string, std::string>::value_type( s1.toStdString(), s2.toStdString()) );
    }

    return ret;
}

QByteArray Utils::toByteArray( const std::map< std::string, std::string>& mapStringString)
{
    QByteArray bArray;

    QDataStream stream(&bArray, QIODevice::ReadWrite);

    qint32 size = mapStringString.size();
    stream << size;

    std::map< std::string, std::string>::const_iterator it;
    for ( it = mapStringString.begin(); it != mapStringString.end(); it++)
    {
        stream << QString().fromStdString( it->first );
        stream << QString().fromStdString( it->second );
    }

    return bArray;
}
