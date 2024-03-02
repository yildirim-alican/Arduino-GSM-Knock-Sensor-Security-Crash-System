# Arduino GSM Knock Sensor Security & Crash System

This Arduino project implements a GSM-based knock sensor alarm system. The system is designed to detect physical impacts or knocks using a knock sensor and send alerts via SMS and phone call to a predefined phone number through a GSM module.

## Features

- **Knock Detection**: Utilizes a knock sensor to detect physical impacts or knocks.
- **GSM Communication**: Sends SMS alerts and initiates phone calls to a specified number using a GSM module.
- **Threshold Setting**: Adjustable threshold value for customizing the sensitivity of the knock sensor.
- **LED Indicator**: Visual feedback through an LED indicator when a knock is detected and the system is active.
- **Consecutive Reading Verification**: Reduces false positives by verifying consecutive knock readings.
- **Initialization Routine**: Ensures proper system startup with an initialization routine.

## Usage

1. **Setup Hardware:**
   - Connect the Arduino board with the necessary components, including the knock sensor, LED indicator, and GSM module.
   - Ensure all connections are correct and secure.

2. **Configure Phone Number:**
   - Set the desired phone number (`PhoneNumber`) to receive alerts in the Arduino sketch.

3. **Adjust Threshold:**
   - Customize the sensitivity by adjusting the threshold value (`threshold`) in the Arduino sketch.

4. **Upload Sketch:**
   - Upload the provided Arduino sketch to the Arduino board.

5. **Initialize GSM Module:**
   - Ensure the GSM module is properly initialized and connected to the network.

6. **Monitor Alerts:**
   - Upon detecting a knock, the system will send an SMS alert and initiate a phone call to the configured number.

## Contributing

Feel free to contribute to the project by opening issues, proposing enhancements, or submitting pull requests. Please follow the [contribution guidelines](CONTRIBUTING.md).

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

- Thanks to [RobonioGSM Library](https://github.com/RobonioDev/Robonio-GSM-shield-library) for GSM communication support.

## Author

[Alican YILDIRIM]
