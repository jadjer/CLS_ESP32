// Copyright 2022 Pavel Suprunov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Created by jadjer on 23.09.22.
//

#pragma once

#include <esp_err.h>
#include <thread>

enum PumpState {
  ERROR,
  DISABLE,
  ENABLE
};

/**
 * @brief
 */
class Pump {
 public:
  explicit Pump(int controlPin, int feedbackPin);
  ~Pump();

 public:
  /**
   * @brief
   */
  void enable(int delay);

  /**
   * @brief
   */
  void disable();

 public:
  /**
   * @brief
   * @return
   */
  [[nodiscard]] PumpState getState() const;

 public:
  /**
   * @brief
   */
  void spinOnce();

 protected:
  int m_delay;
  int m_controlPin;
  int m_feedbackPin;
  PumpState m_state;
  unsigned long m_startTime;
};
