#ifndef PATOCLIENT_GLOBAL_H
#define PATOCLIENT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PATOCLIENT_LIBRARY)
#  define PATOCLIENTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATOCLIENTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PATOCLIENT_GLOBAL_H
