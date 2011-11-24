#ifndef UTILS_H
#define UTILS_H

#include <QByteArray>
#include <string>
#include <map>
#include <vector>

class Utils
{
public:
    Utils();

    static std::map< std::string, std::string> toMapStringString( QByteArray&  );
    static QByteArray toByteArray( const std::map< std::string, std::string>& );
};

#endif // UTILS_H
