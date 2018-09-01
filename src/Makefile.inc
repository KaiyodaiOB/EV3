mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += balancer.o balancer_param.o

APPL_CXXOBJS += \
	Decision.o DecisionSet.o \
	ColorSensorDriver.o GyroSensorDriver.o MotorDriver.o TouchSensorDriver.o SonarSensorDriver.o \
	Section.o SectionExecutor.o \
	CourseInformation.o DeviceInformation.o EV3BodyInformation.o RunCorrectionInformation.o RunInformation.o TailAngleInformation.o \
	DeviceInformationUpdater.o DirectionMeter.o DistanceMeter.o GrayMeter.o iManualMeter.o Measurement.o RunInformationUpdater.o VelocityMeter.o \
	InvertedPendulumBalancer.o PID.o Run.o RunSet.o TailController.o \
	Test.o \
	LCDController.o Speaker.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
	$(mkfile_path)Decision \
	$(mkfile_path)Driver \
	$(mkfile_path)Execute \
	$(mkfile_path)Information \
	$(mkfile_path)Measurement \
	$(mkfile_path)Run \
	$(mkfile_path)Test \
	$(mkfile_path)Utility

INCLUDES += \
	-I$(mkfile_path)Decision \
	-I$(mkfile_path)Driver \
	-I$(mkfile_path)Execute \
	-I$(mkfile_path)Information \
	-I$(mkfile_path)Measurement \
	-I$(mkfile_path)Run \
	-I$(mkfile_path)Test \
	-I$(mkfile_path)Utility
