#include "bleremote.h"

namespace BleRemote {

  class MyCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
        // Do something with the found device ...

        Serial.printf("Scan Result - n:%s a:%s\r\n", 
            advertisedDevice.getName().c_str(), 
            advertisedDevice.getAddress().toString().c_str()
          );

        //Serial.println(advertisedDevice.getPayload());
    }
  };


  void startScan() {

    BLEDevice::init("t-watch");
    BLEScan* pMyScan = BLEDevice::getScan();
    pMyScan->setActiveScan(true); //active scan uses more power, but get results faster
    pMyScan->clearResults();
    pMyScan->setInterval(100);
    pMyScan->setWindow(99);  // less or equal setInterval value
    pMyScan->setAdvertisedDeviceCallbacks(new MyCallbacks(), true);
    pMyScan->start(10, false);

  }



}