# Getting Started with Amazon FreeRTOS using Keil MDK
## Target: STMicroelectronics STM32L4 Discovery kit IoT node

The following section explains how to get started with Amazon Web Services (AWS) using Amazon FreeRTOS and Keil MDK from Arm as software development environment. Follow these steps to connect your device to AWS.

1. The page [Getting Started with Amazon FreeRTOS](https://docs.aws.amazon.com/freertos/latest/userguide/freertos-getting-started.html) contains some basic information. Follow steps under **Create Your AWS IoT Credentials** to prepare the AWS account for your IoT device.
2. Download [Amazon FreeRTOS Device Software](https://github.com/MDK-Packs/amazon-freertos) and extract it to folder. This folder is referred as *BASE_FOLDER* in the following.
3. Open &#181;Vision project **aws_demos.uvprojx** located in folder *<BASE_FOLDER>*\demos\st\stm32l475_discovery\mdk\
4. The page [Getting Started with the STMicroelectronics (ST) STM32L4 Discovery Kit IoT node](https://docs.aws.amazon.com/freertos/latest/userguide/getting_started_st.html) contains the section **Configure Your Project**. Follow this instructions to:
   - **Configure Your Wi-Fi Credentials**
   - **Configure Your AWS IoT Endpoint**
   - **Configure Your AWS IoT Credentials**
   - **Run the FreeRTOS Samples**, only first 4 steps are relevant
5. Connect your development PC with an USB cable to STM32 IoT Discovery Boardu using the **USB STLINK** micro USB port
6. Use **Flash-Download** to program the project to the Flash memory of the STM32 microcontroller
7. **Press RESET button** on the STM32 IoT Discovery kit to start the application
8. The **debug messages** are printed by default via a UART communication. To show these messages, you may connect a Terminal Applicaiton using a Virtual COM Port with settings 115200 Bauds, Parity None, 8 Data Bits, 1 Stop Bit. 
9. Using **MQTT client** in AWS IoT, you should see the MQTT messages sent by your device

<br/>

## Benefits of MDK

Keil MDK offers several benefits compared to open source development tools. For example you can see the thread activity of the RTOS kernel using the Event Recorder. 

Another major benefit is the commericial compiler that offers significant memory savings and performance improvements.

**Memory Size Comparision**

The table table shows a comparison of resource requirements depending on Compiler used for generating the application program.

| Compiler            | Optimization        | ROM [Bytes] | RAM [Bytes] |
|:------------------- |:-------------------:|:-----------:|:-----------:|
| ARM Compiler v6.9   | -Oz (image size)    | 136468      | 120640      |
| GCC v6.3.1 20170620 | -Os (image size)    | 175928      | 121820      |

