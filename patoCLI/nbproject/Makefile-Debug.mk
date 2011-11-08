#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/684244108/patochangeset.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/checkinCLI.o \
	${OBJECTDIR}/_ext/684244108/patobase.o \
	${OBJECTDIR}/checkoutCLI.o \
	${OBJECTDIR}/_ext/764798604/PatoClientException.o \
	${OBJECTDIR}/statusCLI.o \
	${OBJECTDIR}/_ext/684244108/patofilestatus.o \
	${OBJECTDIR}/updateCLI.o \
	${OBJECTDIR}/cliReader.o \
	${OBJECTDIR}/utils.o \
	${OBJECTDIR}/addCLI.o \
	${OBJECTDIR}/_ext/764798604/patoclientapi.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../QtSDK/Desktop/Qt/474/gcc/lib -L../../../QtSDK/Simulator/Qt/gcc/include/QtCore -lQtCore

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/684244108/patochangeset.o: ../patoBase/patochangeset.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/684244108
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/684244108/patochangeset.o ../patoBase/patochangeset.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/checkinCLI.o: checkinCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/checkinCLI.o checkinCLI.cpp

${OBJECTDIR}/_ext/684244108/patobase.o: ../patoBase/patobase.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/684244108
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/684244108/patobase.o ../patoBase/patobase.cpp

${OBJECTDIR}/checkoutCLI.o: checkoutCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/checkoutCLI.o checkoutCLI.cpp

${OBJECTDIR}/_ext/764798604/PatoClientException.o: ../patoClientAPI/PatoClientException.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/764798604
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/764798604/PatoClientException.o ../patoClientAPI/PatoClientException.cpp

${OBJECTDIR}/statusCLI.o: statusCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/statusCLI.o statusCLI.cpp

${OBJECTDIR}/_ext/684244108/patofilestatus.o: ../patoBase/patofilestatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/684244108
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/684244108/patofilestatus.o ../patoBase/patofilestatus.cpp

${OBJECTDIR}/updateCLI.o: updateCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/updateCLI.o updateCLI.cpp

${OBJECTDIR}/cliReader.o: cliReader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/cliReader.o cliReader.cpp

${OBJECTDIR}/utils.o: utils.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/utils.o utils.cpp

${OBJECTDIR}/addCLI.o: addCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/addCLI.o addCLI.cpp

${OBJECTDIR}/_ext/764798604/patoclientapi.o: ../patoClientAPI/patoclientapi.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/764798604
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -I../../../QtSDK/Desktop/Qt/474/gcc/bin -I../../../QtSDK/Simulator/Qt/gcc/include/QtCore -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/764798604/patoclientapi.o ../patoClientAPI/patoclientapi.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
