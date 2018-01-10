# Getting Started with Amazon FreeRTOS on STMicroelectronics STM32L4 Discovery kit IoT node with MDK-ARM

1. On [web page](https://docs.aws.amazon.com/freertos/latest/userguide/freertos-getting-started.html) follow steps under **Create Your AWS IoT Credentials** section
2. Download [Amazon FreeRTOS Device Software](https://github.com/MDK-Packs/amazon-freertos) and extract it to folder which will be referred as *BASE_FOLDER*
3. Open &#181;Vision project **aws_demos.uvprojx** located in folder *<BASE_FOLDER>*\demos\st\stm32l475_discovery\mdk\
4. On [web page](https://docs.aws.amazon.com/freertos/latest/userguide/getting_started_st.html) follow steps under **Configure Your Project** section:
   - **Configure Your Wi-Fi Credentials** sub-section
   - **Configure Your AWS IoT Endpoint** sub-section
   - **Configure Your AWS IoT Credentials** sub-section
   - **Run the FreeRTOS Samples** sub-section, only first 4 steps
5. Connect PC with USB cable to STM32 IoT Discovery Board **USB STLINK** micro USB port
6. **Download** executable to STM32 IoT Discovery Board microcontroller flash (**F8**)
7. **Press RESET button** on the STM32 IoT Discovery Board to start the application execution
8. To see **debug messages** you can open terminal application and connect to Virtual COM Port with settings 115200 Bauds, Parity None, 8 Data Bits, 1 Stop Bit
9. In the **MQTT client** in AWS IoT, you should see the MQTT messages sent by your device

<br/>

**Note**: below table shows a comparison of resource requirements depending on Compiler used

| Compiler            | Optimization        | Code [Bytes] | RAM [Bytes] |
|:------------------- |:-------------------:|:------------:|:-----------:|
| ARM Compiler v6.9   | -Oz image size      | 109636       | 120640      |
| GCC v6.3.1 20170620 | -O3 (optimize most) | 216376       | 121820      |

