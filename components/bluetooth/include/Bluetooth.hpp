//
// Created by jadjer on 29.08.22.
//

#pragma once

#include <BLECharacteristic.h>
#include <BLEClient.h>
#include <BLEServer.h>
#include <BLEService.h>
#include <string>

class Bluetooth {
 public:
  explicit Bluetooth(std::string const& name);
  ~Bluetooth();

 public:
  BLEService* createService(std::string const& serviceName, std::vector<std::string> const& characteristicsUUID);

 public:
  void start();
  void stop();
  void scan();
  void advertising();

 public:
  void setValueUInt16(std::string const& characteristicUuid, uint16_t value);
  void setValueFloat(std::string const& characteristicUuid, float value);
  void setValueString(std::string const& characteristicUuid, std::string const& value);

 private:
  BLEServer* m_server;
  BLEClient* m_client;
  BLEServiceMap m_bleServiceMap;
  BLECharacteristicMap m_bleCharacteristicMap;
};
