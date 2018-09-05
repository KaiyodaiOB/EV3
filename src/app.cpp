#include <stdio.h>

#include <Port.h>
#include "app.h"

#include "Decision/Decision.h"
#include "Decision/DecisionSet.h"

#include "Driver/ColorSensorDriver.h"
#include "Driver/GyroSensorDriver.h"
#include "Driver/MotorDriver.h"
#include "Driver/SonarSensorDriver.h"
#include "Driver/TouchSensorDriver.h"

#include "Execute/Section.h"
#include "Execute/SectionExecutor.h"

#include "Information/CourseInformation.h"
#include "Information/DeviceInformation.h"
#include "Information/EV3BodyInformation.h"
#include "Information/RunCorrectionInformation.h"
#include "Information/RunInformation.h"
#include "Information/TailAngleInformation.h"

#include "Measurement/DeviceInformationUpdater.h"
#include "Measurement/DirectionMeter.h"
#include "Measurement/DistanceMeter.h"
#include "Measurement/GrayMeter.h"
#include "Measurement/iManualMeter.h"
#include "Measurement/Measurement.h"
#include "Measurement/RunInformationUpdater.h"
#include "Measurement/VelocityMeter.h"

#include "Run/InvertedPendulumBalancer.h"
#include "Run/PID.h"
#include "Run/Run.h"
#include "Run/TailController.h"

#include "Test/Test.h"

#include "Utility/LCDController.h"
#include "Utility/Speaker.h"

//------------------------------
//  テスト有効/無効指定
bool isTestEnable = false;

//------------------------------
//  デストラクタ問題の回避
//  https://github.com/ETrobocon/etroboEV3/wiki/problem_and_coping
void *__dso_handle=0;

//------------------------------
//  オブジェクト宣言/定義
Decision::Decision gDecision;

Driver::ColorSensorDriver gColorSensorDriver(PORT_3);
Driver::GyroSensorDriver  gGyroSensorDriver( PORT_4);
Driver::MotorDriver       gRightMotorDriver( PORT_B);
Driver::MotorDriver       gLeftMotorDriver(  PORT_C);
Driver::MotorDriver       gTailMotorDriver(  PORT_A);
Driver::SonarSensorDriver gSonarSensorDriver(PORT_2);
Driver::TouchSensorDriver gTouchSensorDriver(PORT_1);

Execute::SectionExecutor gSectionExecutor;

Information::CourseInformation        gCourseInformation;
Information::DeviceInformation        gCurrentDeviceInformation;
Information::DeviceInformation        gPreviousDeviceInformation;
Information::EV3BodyInformation       gEV3BodyInformation;
Information::RunCorrectionInformation gRunCorrectionInformation;
Information::RunInformation           gRunInformation;
Information::TailAngleInformation     gTailAngleInformation;

Measurement::DeviceInformationUpdater gDeviceInformationUpdater;
Measurement::DirectionMeter           gDirectionMeter;
Measurement::DistanceMeter            gDistanceMeter;
Measurement::GrayMeter                gGrayMeter;
Measurement::Measurement              gMeasurement;
Measurement::VelocityMeter            gVelocityMeter;
Measurement::RunInformationUpdater    gRunInformationUpdater;

Run::InvertedPendulumBalancer gInvertedPendulumBalancer;
Run::PID                      gTailPID;
Run::Run                      gRun;
Run::TailController           gTailController;

Test::Test gTest;

Utility::LCDController gLCDController;
Utility::Speaker       gSpeaker;

//------------------------------
//  EV3システム生成
static void setupDecision()
{
	gDecision.setCurrentDeviceInformation(&gCurrentDeviceInformation);
	gDecision.setRunInformation(          &gRunInformation);
	
}

static void setupInformation()
{
	int gyroOffset = 0;
	gCurrentDeviceInformation.setGyroOffset(gyroOffset);
}

static void setupMeasurement()
{
	gDeviceInformationUpdater.setColorSensorDriver(&gColorSensorDriver);
	gDeviceInformationUpdater.setGyroSensorDriver( &gGyroSensorDriver);
	gDeviceInformationUpdater.setRightMotorDriver( &gRightMotorDriver);
	gDeviceInformationUpdater.setLeftMotorDriver(  &gLeftMotorDriver);
	gDeviceInformationUpdater.setTailMotorDriver(  &gTailMotorDriver);
	gDeviceInformationUpdater.setSonarSensorDriver(&gSonarSensorDriver);
	gDeviceInformationUpdater.setTouchSensorDriver(&gTouchSensorDriver);
	gDeviceInformationUpdater.setCurrentDeviceInformation( &gCurrentDeviceInformation);
	gDeviceInformationUpdater.setPreviousDeviceInformation(&gPreviousDeviceInformation);

	gDirectionMeter.setCurrentDeviceInformation( &gCurrentDeviceInformation);
	gDirectionMeter.setPreviousDeviceInformation(&gPreviousDeviceInformation);
	gDirectionMeter.setEV3BodyInformation(       &gEV3BodyInformation);
	gDirectionMeter.setRunInformation(           &gRunInformation);

	gDistanceMeter.setCurrentDeviceInformation( &gCurrentDeviceInformation);
	gDistanceMeter.setPreviousDeviceInformation(&gPreviousDeviceInformation);
	gDistanceMeter.setEV3BodyInformation(       &gEV3BodyInformation);
	gDistanceMeter.setRunInformation(           &gRunInformation);

	gGrayMeter.setAcceptRange(             10);
	gGrayMeter.setLeastAcceptCount(        10);
	gGrayMeter.setCourseInformation(       &gCourseInformation);
	gGrayMeter.setCurrentDeviceInformation(&gCurrentDeviceInformation);
	gGrayMeter.setRunInformation(          &gRunInformation);

	gVelocityMeter.setCurrentDeviceInformation( &gCurrentDeviceInformation);
	gVelocityMeter.setPreviousDeviceInformation(&gPreviousDeviceInformation);
	gVelocityMeter.setEV3BodyInformation(       &gEV3BodyInformation);
	gVelocityMeter.setRunInformation(           &gRunInformation);
	
	gRunInformationUpdater.setRunInformation(&gRunInformation);
	gRunInformationUpdater.addManualMeter(&gDirectionMeter);
	gRunInformationUpdater.addManualMeter(&gDistanceMeter);
	gRunInformationUpdater.addManualMeter(&gGrayMeter);
	gRunInformationUpdater.addManualMeter(&gVelocityMeter);
	
	gMeasurement.setRunInformationUpdater(   &gRunInformationUpdater);
	gMeasurement.setDeviceInformationUpdater(&gDeviceInformationUpdater);
}

static void setupRun()
{
	gTailController.setTailMotorDriver(&gTailMotorDriver);
	gTailController.setPID(&gTailPID);
	
	gRun.setInvertedPendulumBalancer(&gInvertedPendulumBalancer);
	gRun.setTailController(          &gTailController);
	gRun.setRightMotorDriver(        &gRightMotorDriver);
	gRun.setLeftMotorDriver(         &gLeftMotorDriver);
	gRun.setCourseInformation(       &gCourseInformation);
	gRun.setCurrentDeviceInformation(&gCurrentDeviceInformation);
	gRun.setRunCorrectionInformation(&gRunCorrectionInformation);
	gRun.setTailAngleInformation(    &gTailAngleInformation);
}

static void setupTest()
{
	gTest.setColorSensorDriver(&gColorSensorDriver);
	gTest.setGyroSensorDriver( &gGyroSensorDriver);
	gTest.setRightMotorDriver( &gRightMotorDriver);
	gTest.setLeftMotorDriver(  &gLeftMotorDriver);
	gTest.setTailMotorDriver(  &gTailMotorDriver);
	gTest.setSonarSensorDriver(&gSonarSensorDriver);
	gTest.setTouchSensorDriver(&gTouchSensorDriver);

	gTest.setLCDController(&gLCDController);
	gTest.setSpeaker(      &gSpeaker);
}

static void setup(FILE*& file)
{
	static const int VALUE_ENABLE  = 1;
	double kp, ki, kd, tailKp, tailKi, tailKd;
	int forward, turnSelectionType, turn, brightnessOffset, formingCondition, numDecisionSet;
	int isInvertedPendulumControlEnable, isStraigitCorrectionEnable, isTailControlEnable, tailAngleType;
	while(fscanf(file, "%d, %lf,%lf,%lf, %d,%d,%d,%d, %d, %d,%d, %lf,%lf,%lf, %d, %d,",
				 &isInvertedPendulumControlEnable, &kp,&ki,&kd, &forward,&turnSelectionType,&turn,&brightnessOffset,
				 &isStraigitCorrectionEnable, &isTailControlEnable,&tailAngleType,
				 &tailKp,&tailKi,&tailKd, &formingCondition, &numDecisionSet) != EOF)
	{
		Execute::Section* section = new Execute::Section();
		section->setMeasurement(&gMeasurement);
		section->setDecision(&gDecision);
		section->setFormingCondition(static_cast<Decision::EFormingCondition>(formingCondition));
		for(int i = 0; i < numDecisionSet; i++)
		{
			int decisionTarget, comparisonMode;
			double threshold1, threshold2;
			fscanf(file, "%d, %d, %lf, %lf,", &decisionTarget, &comparisonMode, &threshold1, &threshold2);
			Decision::DecisionSet* decisionSet = new Decision::DecisionSet();
			decisionSet->setDecisionTarget(static_cast<Decision::EDecisionTarget>(decisionTarget));
			decisionSet->setComparisonMode(static_cast<Decision::EComparisonMode>(comparisonMode));
			decisionSet->setThreshold1(threshold1);
			decisionSet->setThreshold2(threshold2);
			section->addDecisionSet(decisionSet);
		}
		section->setRun(&gRun);
		Run::RunSet* runSet = new Run::RunSet();
		{
			runSet->setTailAngleType(static_cast<Information::ETailAngleType>(tailAngleType));
			runSet->setTurnSelectionType(static_cast<Run::ETurnSelectionType>(turnSelectionType));
			runSet->setIsInvertedPendulumControlEnable(isInvertedPendulumControlEnable == VALUE_ENABLE);
			runSet->setIsStraightCorrectionEnable(isStraigitCorrectionEnable == VALUE_ENABLE);
			runSet->setIsTailControlEnable(isTailControlEnable == VALUE_ENABLE);
			runSet->setForward(forward);
			runSet->setTurn(turn);
			runSet->setTargetColorOffset(brightnessOffset);
		}
		section->setRunSet(runSet);
		section->setPID(new Run::PID(kp, ki, kd));
		gSectionExecutor.addSection(section);
	}
}

static void setup(const char* filename)
{
	FILE* source = fopen(filename, "r");
	if(source == NULL) { return; }
	setup(source);
	fclose(source);
}

static void setup()
{
	setup("speed.csv");
	setup("bonus.csv");
}

//------------------------------
//  EV3システム構築
static void user_system_create()
{
	//  タッチセンサの初期化に2msのdelayがあるため、ここで待つ
	tslp_tsk(2);
	
	setupDecision();
	setupInformation();
	setupMeasurement();
	setupRun();
	setupTest();
	setup();

	//  システム生成完了通知
	ev3_led_set_color(LED_GREEN);
	tslp_tsk(500);
	ev3_led_set_color(LED_OFF);
}

static void initializeDriver()
{
	gRightMotorDriver.reset();
	gLeftMotorDriver.reset();
	gTailMotorDriver.reset();
}

static void initializeRun()
{
	gInvertedPendulumBalancer.init();
}

//------------------------------
//  EV3システム初期化
static void user_system_initialize()
{
	initializeDriver();
	initializeRun();
}

//------------------------------
//  EV3システム実行
static void user_system_execute()
{
	if(isTestEnable)
	{
		gTest.execute();
	}
	else
	{
		ev3_sta_cyc(EV3_CYC_TRACER);    //  周期ハンドラ開始
		slp_tsk();                      //  バックボタンが押されるまで待つ
		ev3_stp_cyc(EV3_CYC_TRACER);    //  周期ハンドラ停止
	}
}



//------------------------------
//  EV3システム破棄
static void user_system_destroy()
{
	//  define and call teardownXXX(); if need.
}

//------------------------------
//  メインタスク
void main_task(intptr_t unused)
{
	user_system_create();
	user_system_initialize();
	user_system_execute();
	user_system_destroy();
	ext_tsk();
}

void ev3_cyc_tracer(intptr_t exinf)
{
	act_tsk(TRACER_TASK);
}

void tracer_task(intptr_t exinf)
{
	if (ev3_button_is_pressed(BACK_BUTTON))
	{
		wup_tsk(MAIN_TASK);
	}
	else
	{
		gSectionExecutor.execute();
	}
	ext_tsk();
}
