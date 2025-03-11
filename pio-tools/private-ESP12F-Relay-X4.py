Import("env")
import os

# Liste der Environments, die gebaut werden sollen
environments_to_build = [
                         "tasmota-ESP12F-Relay-X4-private",
                         "tasmota-ESP12F-Relay-X4-Display-private",
                         "tasmota-ESP12F-Relay-X4-Display-Sensors-private",
                         "tasmota-ESP12F-Relay-X4-SSD1306-private",
                         "tasmota-ESP12F-Relay-X4-SSD1306-Sensors-private",
                         "tasmota-ESP12F-Relay-X4-SH1106-private",
                         "tasmota-ESP12F-Relay-X4-SH1106-Sensors-private",
                         "tasmota-ESP12F-Relay-X4-DE-private",
                         "tasmota-ESP12F-Relay-X4-Display-DE-private",
                         "tasmota-ESP12F-Relay-X4-Display-Sensors-DE-private",
                         "tasmota-ESP12F-Relay-X4-SSD1306-DE-private",
                         "tasmota-ESP12F-Relay-X4-SSD1306-Sensors-DE-private",
                         "tasmota-ESP12F-Relay-X4-SH1106-DE-private",
                         "tasmota-ESP12F-Relay-X4-SH1106-Sensors-DE-private"
                        ]

for target_env in environments_to_build:
    env.Execute(f"pio run -e {target_env}")
