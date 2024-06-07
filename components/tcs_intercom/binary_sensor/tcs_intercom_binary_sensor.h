#pragma once
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "../tcs_intercom.h"
#include "esphome/components/binary_sensor/binary_sensor.h"

namespace esphome
{
    namespace tcs_intercom
    {
        class TCSIntercomBinarySensor : public binary_sensor::BinarySensor, public TCSIntercomListener
        {
            public:
                void set_command_template(std::function<uint32_t()> command_template) { command_template_ = command_template; }
                void turn_on(uint32_t *timer, uint16_t auto_off) override;
                void turn_off(uint32_t *timer) override;
                std::function<uint32_t()> command_template_;

            protected:
                binary_sensor::BinarySensor *incoming_command_sensor_{nullptr};
                uint32_t command_;
                uint32_t command_value_{0};
        };

    }  // namespace tcs_intercom
}  // namespace esphome