#ifndef PATOALGORITHMS_GLOBAL_H
#define PATOALGORITHMS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PATOALGORITHMS_LIBRARY)
#  define PATOALGORITHMSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATOALGORITHMSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PATOALGORITHMS_GLOBAL_H
