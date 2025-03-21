#pragma once

#include <lvgl/src/lv_core/lv_obj.h>
#include <chrono>
#include <cstdint>
#include <memory>
#include "Screen.h"
#include "ScreenList.h"
#include "components/datetime/DateTimeController.h"

namespace Pinetime {
  namespace Controllers {
    class Settings;
    class Battery;
  }

  namespace Applications {
    namespace Screens {

      class Triangle: public Screen {
      public:
        Triangle(DisplayApp* app,
               Controllers::Settings& settingsController,
               Controllers::Battery& batteryController);
        ~Triangle() override;
        bool Refresh() override;

//        void OnObjectEvent(lv_obj_t* pObj, lv_event_t i);

      private:
        Controllers::Settings& settingsController;
        Controllers::Battery& batteryController;
        lv_obj_t* batteryIcon;
      };
    }
  }
}
