#ifndef PATOWORKSPACE_GLOBAL_H
#define PATOWORKSPACE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PATOWORKSPACE_LIBRARY)
#  define PATOWORKSPACESHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATOWORKSPACESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PATOWORKSPACE_GLOBAL_H
