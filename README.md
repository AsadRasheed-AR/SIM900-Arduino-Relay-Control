# SIM900-Arduino-Relay-Control
This project uses GSM Module (SIM900) with Arduino to switch Relay state by SMS OR CALL. 
![alt text](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2017/08/GSM-feature-image.png?fit=1280%2C416&quality=100&strip=all&ssl=1)

# Step 1 (Connect SIM900 With Arduino)
### Use picture as a reference for connecting SIM900 to Arduino.

![alt text](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2017/10/GSM-Arduino-circuit.jpg?resize=828%2C509&quality=100&strip=all&ssl=1)

# Step 2 (Connect Relay with Arduino)
```
Connections are given Below : 

Arduino           Relay Module
+5V                 VCC
GND                 GND
PIN2                Signal
```

![alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTLNzMklM-UMQDHovuOIuYrjHav37NRg-NfYQ&usqp=CAU)

# Step 3 (Upload Sketch to Arduino)
Download "sms_call_gate.ino" Sketch from the repository and Upload it to Arduino.
NOTE : Make sure to replace your number in code at line number 71. The number must be in international format.

# Step 4
After uploading the code open the serial monitor , set the baudrate to 9600. It will help you to see the response of module on sms and call.

# Step 5
Make a call on SIM (inserted in SIM900), The relay should switch its state from OFF TO ON for 1 second and then again turn off.

# Step 6
send SMS on SIM (inserted in SIM900), The relay should switch its state from OFF TO ON for 1 second and then again turn off. 

