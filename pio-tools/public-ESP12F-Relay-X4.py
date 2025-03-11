Import("env")
import os

# Liste der Environments, die gebaut werden sollen
environments_to_build = ["tasmota-minimal",
                         "tasmota-ESP12F-Relay-X4",
                         "tasmota-ESP12F-Relay-X4-Display",
                         "tasmota-ESP12F-Relay-X4-Display-Sensors",
                         "tasmota-ESP12F-Relay-X4-SSD1306",
                         "tasmota-ESP12F-Relay-X4-SSD1306-Sensors",
                         "tasmota-ESP12F-Relay-X4-SH1106",
                         "tasmota-ESP12F-Relay-X4-SH1106-Sensors",
                         "tasmota-minimal-DE",
                         "tasmota-ESP12F-Relay-X4-DE",
                         "tasmota-ESP12F-Relay-X4-Display-DE",
                         "tasmota-ESP12F-Relay-X4-Display-Sensors-DE",
                         "tasmota-ESP12F-Relay-X4-SSD1306-DE",
                         "tasmota-ESP12F-Relay-X4-SSD1306-Sensors-DE",
                         "tasmota-ESP12F-Relay-X4-SH1106-DE",
                         "tasmota-ESP12F-Relay-X4-SH1106-Sensors-DE"
                        ]

for target_env in environments_to_build:
    env.Execute(f"pio run -e {target_env}")
