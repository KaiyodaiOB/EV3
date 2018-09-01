#include "app.h"
#include <Port.h>

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
bool isTestEnable = true;

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
Utility::Speaker gSpeaker;

//------------------------------
//  EV3システム生成
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

static void setupRun()
{
	gTailController.setTailMotorDriver(&gTailMotorDriver);
	gTailController.setPID(&gTailPID);
}

static void user_system_create()
{
	setupInformation();
	setupMeasurement();
	setupRun();
	setupTest();

	//  タッチセンサの初期化に2msのdelayがあるため、ここで待つ
	tslp_tsk(2);

	//  システム生成完了通知
	ev3_led_set_color(LED_GREEN);
	tslp_tsk(500);
	ev3_led_set_color(LED_OFF);
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
		while(true)
		{
			//
			//  ボタン操作から動作モード（キャリブレーションor）を決定
			//
			{
				ev3_sta_cyc(EV3_CYC_TRACER);    //  周期ハンドラ開始
				slp_tsk();                      //  バックボタンが押されるまで待つ
				ev3_stp_cyc(EV3_CYC_TRACER);    //  周期ハンドラ停止
			}
		}
	}
}

//------------------------------
//  EV3システム破棄
static void user_system_destroy()
{
	//teardownXXX();
}

//------------------------------
//  メインタスク
void main_task(intptr_t unused)
{
	user_system_create();
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
	}
	ext_tsk();
}
