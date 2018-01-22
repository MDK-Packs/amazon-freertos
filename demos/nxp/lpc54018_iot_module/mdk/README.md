# Getting Started with Amazon FreeRTOS using Keil MDK
## Target: NXP LPC54018 IoT Module

The following section explains how to get started with Amazon Web Services (AWS) using Amazon FreeRTOS and Keil MDK from Arm as software development environment. Follow these steps to connect your device to AWS.

1. The page [Getting Started with Amazon FreeRTOS](https://docs.aws.amazon.com/freertos/latest/userguide/freertos-getting-started.html) contains some basic information. Follow steps under **Create Your AWS IoT Credentials** to prepare the AWS account for your IoT device.
2. Download [Amazon FreeRTOS Device Software](https://github.com/MDK-Packs/amazon-freertos) and extract it to folder. This folder is referred as *BASE_FOLDER* in the following.
3. Open &#181;Vision project **aws_demos.uvprojx** located in folder *<BASE_FOLDER>*\demos\nxp\lpc54018_iot_module\mdk\
4. The page [Getting Started with the NXP LPC54018 IoT Module](https://docs.aws.amazon.com/freertos/latest/userguide/getting_started_nxp.html) contains the section **Configure Your Project**. Follow this instructions to:
   - **Configure Your Wi-Fi Credentials**
   - **Configure Your AWS IoT Endpoint**
   - **Configure Your AWS IoT Credentials**
   - **Run the FreeRTOS Samples**, only first 4 steps are relevant
5. Connect your development PC with an USB cable to NXP LPC54018 IoT Module High-speed USB port
6. Connect ULINK2 Debugger probe to NXP LPC54018 IoT Module 10-pin SWD Debug header
7. Use **Start Debug Session** and **Run** to start the application
8. The **debug messages** are printed by default via a Virtual COM Port (installation file: fsl_ucwxp.inf). To show these messages, you may connect a Terminal Application using a Virtual COM Port with settings 115200 Bauds, Parity None, 8 Data Bits, 1 Stop Bit. 
9. Using **MQTT client** in AWS IoT, you should see the MQTT messages sent by your device
