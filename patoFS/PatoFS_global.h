#ifndef PATOFS_GLOBAL_H
#define PATOFS_GLOBAL_H

#include <QtCore/qglobal.h>

#include porcaria.h

#if defined(PATOFS_LIBRARY)
#  define PATOFSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATOFSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PATOFS_GLOBAL_H
