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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/checkinCLI.o \
	${OBJECTDIR}/checkoutCLI.o \
	${OBJECTDIR}/statusCLI.o \
	${OBJECTDIR}/updateCLI.o \
	${OBJECTDIR}/cliReader.o \
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
LDLIBSOPTIONS=-L../../../QtSDK/Desktop/Qt/474/gcc/lib -lQtCore

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/patocli ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/checkinCLI.o: checkinCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/checkinCLI.o checkinCLI.cpp

${OBJECTDIR}/checkoutCLI.o: checkoutCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/checkoutCLI.o checkoutCLI.cpp

${OBJECTDIR}/statusCLI.o: statusCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/statusCLI.o statusCLI.cpp

${OBJECTDIR}/updateCLI.o: updateCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/updateCLI.o updateCLI.cpp

${OBJECTDIR}/cliReader.o: cliReader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/cliReader.o cliReader.cpp

${OBJECTDIR}/addCLI.o: addCLI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/addCLI.o addCLI.cpp

${OBJECTDIR}/_ext/764798604/patoclientapi.o: ../patoClientAPI/patoclientapi.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/764798604
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../QtSDK/Desktop/Qt/474/gcc/include -I../../../QtSDK/Madde/targets/harmattan-nokia-meego-api/bin -I../../../QtSDK/Simulator/Qt/gcc/bin -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/764798604/patoclientapi.o ../patoClientAPI/patoclientapi.cpp

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
