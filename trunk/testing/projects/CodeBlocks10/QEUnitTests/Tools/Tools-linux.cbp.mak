#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.137                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC =  -I$(MAKEPATH)trunk/headers -I$(MAKEPATH)trunk/3rdparty/Boost/include -I$(MAKEPATH)trunk/testing/tests/unit
CFLAGS =  -Wshadow -Wredundant-decls -Wcast-align -Winline -Wmissing-include-dirs -Wswitch-default -Wall -DQE_ASSERT_THROWS_EXCEPTION
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUGLINUX32SHAREDRTSTATIC =  $(INC)
CFLAGS_DEBUGLINUX32SHAREDRTSTATIC =  $(CFLAGS) -g -m32 -D_DEBUG
RESINC_DEBUGLINUX32SHAREDRTSTATIC =  $(RESINC)
RCFLAGS_DEBUGLINUX32SHAREDRTSTATIC =  $(RCFLAGS)
LIBDIR_DEBUGLINUX32SHAREDRTSTATIC =  $(LIBDIR) -L$(MAKEPATH)trunk/testing/bin/CodeBlocks10/DebugLinux32SharedrtStatic
LIB_DEBUGLINUX32SHAREDRTSTATIC = $(LIB) $(MAKEPATH)trunk/bin/CodeBlocks10/DebugLinux32SharedrtStatic/QuimeraEngineTools.a $(MAKEPATH)trunk/bin/CodeBlocks10/DebugLinux32SharedrtStatic/QuimeraEngineSystem.a $(MAKEPATH)trunk/bin/CodeBlocks10/DebugLinux32SharedrtStatic/QuimeraEngineCore.a $(MAKEPATH)trunk/3rdparty/Boost/bin/Linux32/DebugSharedrtStatic/libboost_unit_test_framework.a
LDFLAGS_DEBUGLINUX32SHAREDRTSTATIC =  $(LDFLAGS) -m32
OBJDIR_DEBUGLINUX32SHAREDRTSTATIC = $(MAKEPATH)trunk/testing/garbage/CodeBlocks10/DebugLinux32SharedrtStatic
DEP_DEBUGLINUX32SHAREDRTSTATIC = 
OUT_DEBUGLINUX32SHAREDRTSTATIC = $(MAKEPATH)trunk/testing/bin/CodeBlocks10/DebugLinux32SharedrtStatic/Unit_TestModule_Tools

OBJ_DEBUGLINUX32SHAREDRTSTATIC = $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTransformationMatrix_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTranslationMatrix_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector2_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQAngle_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQFloat_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQVF32_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/TestModule_Tools.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/EQTestType.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/QCommonTestConfig.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/QSimpleConfigLoader.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix3x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix2x2_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix3x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix3x4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix4x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix4x4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseQuaternion_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector2_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QDualQuaternion_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix2x2_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseDualQuaternion_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix3x4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix4x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix4x4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QQuaternion_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QRotationMatrix3x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QScalingMatrix3x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QSpaceConversionMatrix_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTransformationMatrix3x3_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/EQEnumeration_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQPoint_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBasePlane_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseRay_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseRay_QVector4_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseTriangle_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseLineSegment_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseHexahedron_Test.o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseOrb_Test.o

all: debuglinux32sharedrtstatic

clean: clean_debuglinux32sharedrtstatic

before_debuglinux32sharedrtstatic: 
	test -d $(MAKEPATH)trunk/testing/bin/CodeBlocks10/DebugLinux32SharedrtStatic || mkdir -p $(MAKEPATH)trunk/testing/bin/CodeBlocks10/DebugLinux32SharedrtStatic
	test -d $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools || mkdir -p $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools
	test -d $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_core || mkdir -p $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_core
	test -d $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem || mkdir -p $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem

after_debuglinux32sharedrtstatic: 
	cp "$(MAKEPATH)trunk/testing/bin/TestConfig.txt" "$(MAKEPATH)trunk/testing/bin/CodeBlocks10/DebugLinux32SharedrtStatic"

debuglinux32sharedrtstatic: before_debuglinux32sharedrtstatic out_debuglinux32sharedrtstatic after_debuglinux32sharedrtstatic

out_debuglinux32sharedrtstatic: $(OBJ_DEBUGLINUX32SHAREDRTSTATIC) $(DEP_DEBUGLINUX32SHAREDRTSTATIC)
	$(LD) $(LDFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(LIBDIR_DEBUGLINUX32SHAREDRTSTATIC) $(OBJ_DEBUGLINUX32SHAREDRTSTATIC) $(LIB_DEBUGLINUX32SHAREDRTSTATIC) -o $(OUT_DEBUGLINUX32SHAREDRTSTATIC)

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTransformationMatrix_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QTransformationMatrix_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QTransformationMatrix_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTransformationMatrix_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTranslationMatrix_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QTranslationMatrix_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QTranslationMatrix_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTranslationMatrix_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector2_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QVector2_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QVector2_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector2_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QVector3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QVector3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QVector4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QVector4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QVector4_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQAngle_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQAngle_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQAngle_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQAngle_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQFloat_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQFloat_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQFloat_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQFloat_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQVF32_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQVF32_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQVF32_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQVF32_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/TestModule_Tools.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/TestModule_Tools.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/TestModule_Tools.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/TestModule_Tools.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/EQTestType.o: $(MAKEPATH)trunk/testing/testsystem/EQTestType.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/testsystem/EQTestType.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/EQTestType.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/QCommonTestConfig.o: $(MAKEPATH)trunk/testing/testsystem/QCommonTestConfig.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/testsystem/QCommonTestConfig.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/QCommonTestConfig.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/QSimpleConfigLoader.o: $(MAKEPATH)trunk/testing/testsystem/QSimpleConfigLoader.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/testsystem/QSimpleConfigLoader.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/testsystem/QSimpleConfigLoader.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix3x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix3x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix3x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix3x3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix2x2_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix2x2_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix2x2_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix2x2_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix3x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix3x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix3x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix3x3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix3x4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix3x4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix3x4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix3x4_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix4x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix4x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix4x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix4x3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix4x4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix4x4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseMatrix4x4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseMatrix4x4_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseQuaternion_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseQuaternion_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseQuaternion_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseQuaternion_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector2_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseVector2_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseVector2_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector2_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseVector3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseVector3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseVector4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseVector4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseVector4_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QDualQuaternion_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QDualQuaternion_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QDualQuaternion_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QDualQuaternion_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix2x2_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix2x2_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix2x2_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix2x2_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseDualQuaternion_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseDualQuaternion_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseDualQuaternion_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseDualQuaternion_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix3x4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix3x4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix3x4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix3x4_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix4x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix4x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix4x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix4x3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix4x4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix4x4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QMatrix4x4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QMatrix4x4_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QQuaternion_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QQuaternion_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QQuaternion_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QQuaternion_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QRotationMatrix3x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QRotationMatrix3x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QRotationMatrix3x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QRotationMatrix3x3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QScalingMatrix3x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QScalingMatrix3x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QScalingMatrix3x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QScalingMatrix3x3_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QSpaceConversionMatrix_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QSpaceConversionMatrix_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QSpaceConversionMatrix_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QSpaceConversionMatrix_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTransformationMatrix3x3_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QTransformationMatrix3x3_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QTransformationMatrix3x3_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QTransformationMatrix3x3_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_core/EQEnumeration_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_core/EQEnumeration_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_core/EQEnumeration_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_core/EQEnumeration_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQPoint_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQPoint_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/SQPoint_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/SQPoint_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBasePlane_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBasePlane_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBasePlane_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBasePlane_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseRay_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseRay_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseRay_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseRay_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseRay_QVector4_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseRay_QVector4_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseRay_QVector4_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseRay_QVector4_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseTriangle_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseTriangle_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseTriangle_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseTriangle_Test.o
	
$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseLineSegment_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseLineSegment_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseLineSegment_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseLineSegment_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseHexahedron_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseHexahedron_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseHexahedron_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseHexahedron_Test.o

$(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseOrb_Test.o: $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseOrb_Test.cpp
	$(CXX) $(CFLAGS_DEBUGLINUX32SHAREDRTSTATIC) $(INC_DEBUGLINUX32SHAREDRTSTATIC) -c $(MAKEPATH)trunk/testing/tests/unit/testmodule_tools/QBaseOrb_Test.cpp -o $(OBJDIR_DEBUGLINUX32SHAREDRTSTATIC)/__/__/__/__/tests/unit/testmodule_tools/QBaseOrb_Test.o

clean_debuglinux32sharedrtstatic: 
	rm -f $(OBJ_DEBUGLINUX32SHAREDRTSTATIC) $(OUT_DEBUGLINUX32SHAREDRTSTATIC)

.PHONY: before_debuglinux32sharedrtstatic after_debuglinux32sharedrtstatic clean_debuglinux32sharedrtstatic

