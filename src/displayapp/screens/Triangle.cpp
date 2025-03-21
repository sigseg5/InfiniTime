#include "Triangle.h"

#include <date/date.h>
#include <lvgl/lvgl.h>
#include <cstdio>
#include "BatteryIcon.h"
#include "BleIcon.h"
#include "NotificationIcon.h"
#include "Symbols.h"
#include "components/battery/BatteryController.h"
#include "components/ble/BleController.h"
#include "components/ble/NotificationManager.h"
#include "components/heartrate/HeartRateController.h"
#include "components/motion/MotionController.h"
#include "components/settings/Settings.h"
#include "../DisplayApp.h"

using namespace Pinetime::Applications::Screens;

Triangle::Triangle(DisplayApp* app,
               Controllers::Settings& settingsController,
               Controllers::Battery& batteryController)
  : Screen(app),
    settingsController {settingsController},
    batteryController {batteryController} {
      settingsController.SetClockFace(3);

      batteryIcon = lv_label_create(lv_scr_act(), nullptr);
      lv_label_set_text(batteryIcon, Symbols::batteryFull);
      lv_obj_align(batteryIcon, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, -5, 2);

}

Triangle::~Triangle() {
  lv_obj_clean(lv_scr_act());
}

bool Triangle::Refresh() {
//  batteryPercentRemaining = batteryController.PercentRemaining();
//  if (batteryPercentRemaining.IsUpdated()) {
//    auto batteryPercent = batteryPercentRemaining.Get();
//    lv_label_set_text(batteryIcon, BatteryIcon::GetBatteryIcon(batteryPercent));
//    auto isCharging = batteryController.IsCharging() || batteryController.IsPowerPresent();
//    lv_label_set_text(batteryPlug, BatteryIcon::GetPlugIcon(isCharging));
//  }
//
//  bleState = bleController.IsConnected();
//  if (bleState.IsUpdated()) {
//    if (bleState.Get() == true) {
//      lv_label_set_text(bleIcon, BleIcon::GetIcon(true));
//    } else {
//      lv_label_set_text(bleIcon, BleIcon::GetIcon(false));
//    }
//  }
//  lv_obj_align(batteryIcon, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, -5, 5);
//  lv_obj_align(batteryPlug, batteryIcon, LV_ALIGN_OUT_LEFT_MID, -5, 0);
//  lv_obj_align(bleIcon, batteryPlug, LV_ALIGN_OUT_LEFT_MID, -5, 0);
//
//  notificationState = notificatioManager.AreNewNotificationsAvailable();
//  if (notificationState.IsUpdated()) {
//    if (notificationState.Get() == true)
//      lv_label_set_text(notificationIcon, NotificationIcon::GetIcon(true));
//    else
//      lv_label_set_text(notificationIcon, NotificationIcon::GetIcon(false));
//  }
//
//  currentDateTime = dateTimeController.CurrentDateTime();
//
//  if (currentDateTime.IsUpdated()) {
//    auto newDateTime = currentDateTime.Get();
//
//    auto dp = date::floor<date::days>(newDateTime);
//    auto time = date::make_time(newDateTime - dp);
//    auto yearMonthDay = date::year_month_day(dp);
//
//    auto year = (int) yearMonthDay.year();
//    auto month = static_cast<Pinetime::Controllers::DateTime::Months>((unsigned) yearMonthDay.month());
//    auto day = (unsigned) yearMonthDay.day();
//    auto dayOfWeek = static_cast<Pinetime::Controllers::DateTime::Days>(date::weekday(yearMonthDay).iso_encoding());
//
//    int hour = time.hours().count();
//    auto minute = time.minutes().count();
//
//    char minutesChar[3];
//    sprintf(minutesChar, "%02d", static_cast<int>(minute));
//
//    char hoursChar[3];
//    char ampmChar[3];
//    if (settingsController.GetClockType() == Controllers::Settings::ClockType::H24) {
//      sprintf(hoursChar, "%02d", hour);
//    } else {
//      if (hour == 0 && hour != 12) {
//        hour = 12;
//        sprintf(ampmChar, "AM");
//      } else if (hour == 12 && hour != 0) {
//        hour = 12;
//        sprintf(ampmChar, "PM");
//      } else if (hour < 12 && hour != 0) {
//        sprintf(ampmChar, "AM");
//      } else if (hour > 12 && hour != 0) {
//        hour = hour - 12;
//        sprintf(ampmChar, "PM");
//      }
//      sprintf(hoursChar, "%02d", hour);
//    }
//
//    if (hoursChar[0] != displayedChar[0] || hoursChar[1] != displayedChar[1] || minutesChar[0] != displayedChar[2] ||
//        minutesChar[1] != displayedChar[3]) {
//      displayedChar[0] = hoursChar[0];
//      displayedChar[1] = hoursChar[1];
//      displayedChar[2] = minutesChar[0];
//      displayedChar[3] = minutesChar[1];
//
//      char timeStr[6];
//
//      if (settingsController.GetClockType() == Controllers::Settings::ClockType::H12) {
//        lv_label_set_text(label_time_ampm, ampmChar);
//        if (hoursChar[0] == '0') {
//          hoursChar[0] = ' ';
//        }
//      }
//
//      sprintf(timeStr, "%c%c:%c%c", hoursChar[0], hoursChar[1], minutesChar[0], minutesChar[1]);
//      lv_label_set_text(label_time, timeStr);
//
//      if (settingsController.GetClockType() == Controllers::Settings::ClockType::H12) {
//        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, 0, 0);
//      } else {
//        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
//      }
//    }
//
//    if ((year != currentYear) || (month != currentMonth) || (dayOfWeek != currentDayOfWeek) || (day != currentDay)) {
//      char dateStr[22];
//      if (settingsController.GetClockType() == Controllers::Settings::ClockType::H24) {
//        sprintf(dateStr, "%s %d %s %d", dateTimeController.DayOfWeekShortToString(), day, dateTimeController.MonthShortToString(), year);
//      } else {
//        sprintf(dateStr, "%s %s %d %d", dateTimeController.DayOfWeekShortToString(), dateTimeController.MonthShortToString(), day, year);
//      }
//      lv_label_set_text(label_date, dateStr);
//      lv_obj_align(label_date, lv_scr_act(), LV_ALIGN_CENTER, 0, 60);
//
//      currentYear = year;
//      currentMonth = month;
//      currentDayOfWeek = dayOfWeek;
//      currentDay = day;
//    }
//  }
//
//  heartbeat = heartRateController.HeartRate();
//  heartbeatRunning = heartRateController.State() != Controllers::HeartRateController::States::Stopped;
//  if (heartbeat.IsUpdated() || heartbeatRunning.IsUpdated()) {
//    if (heartbeatRunning.Get()) {
//      lv_obj_set_style_local_text_color(heartbeatIcon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xCE1B1B));
//      lv_label_set_text_fmt(heartbeatValue, "%d", heartbeat.Get());
//    } else {
//      lv_obj_set_style_local_text_color(heartbeatIcon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x1B1B1B));
//      lv_label_set_text_static(heartbeatValue, "");
//    }
//
//    lv_obj_align(heartbeatIcon, lv_scr_act(), LV_ALIGN_IN_BOTTOM_LEFT, 5, -2);
//    lv_obj_align(heartbeatValue, heartbeatIcon, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
//  }
//
//  stepCount = motionController.NbSteps();
//  motionSensorOk = motionController.IsSensorOk();
//  if (stepCount.IsUpdated() || motionSensorOk.IsUpdated()) {
//    lv_label_set_text_fmt(stepValue, "%lu", stepCount.Get());
//    lv_obj_align(stepValue, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, -5, -2);
//    lv_obj_align(stepIcon, stepValue, LV_ALIGN_OUT_LEFT_MID, -5, 0);
//  }

  return running;
}
