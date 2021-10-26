# Introduction To Robotics

<h3> Author:&nbsp;&nbsp;Ristea Mihai Cristian
<h3> Contact: mihai.ristea@s.unibuc.ro
<h3>&nbsp;&nbsp;&nbsp;&nbsp;This repository contains the summary of homeworks and projects done as part of the "Introduction To Robotics" laboratory.
<h2> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Homework #0:
<h3>https://github.com/JustMike13/IntroductionToRobotics/
<h2> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Homework #1:
<h3>Technical Task: Use a separate potentiometer in controlling each of the color of the RGB led (Red,Green andBlue). The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led).
<h3>Components: RBG led (1 minimum), potentiometers (3 minimum), resistors and wires (per logic).
  
  
  <img src="https://user-images.githubusercontent.com/62668963/138786478-a48b513e-ea3c-4019-9595-05f6d988422f.jpg" width = "1000"> <br />
Wires: <br />
  &nbsp;&nbsp;White for 5V <br />
  &nbsp;&nbsp;Black for Ground <br />
  &nbsp;&nbsp;Yellow for each of the potentiometers <br />
  &nbsp;&nbsp;Red for PWM signal to the red diode of the RGB LED <br />
  &nbsp;&nbsp;Green for PWM signal to the green diode of the RGB LED <br />
  &nbsp;&nbsp;Blue for PWM signal to the blue diode of the RGB LED <br /> <br />
  <img src="https://user-images.githubusercontent.com/62668963/138786837-7fe70716-dea9-4c4f-b469-f6c04a707232.jpg" width = "1000"> <br />
Wires (for each potentiometer): <br />
  &nbsp;&nbsp;Black for Ground from the shared Ground line of the breadboard <br />
  &nbsp;&nbsp;Yellow for the signal <br />
  &nbsp;&nbsp;White for 5V from the shared 5V line of the breadboard <br /> <br />
  <img src="https://user-images.githubusercontent.com/62668963/138787001-837d6834-a976-491e-87c1-fa7504fc801e.jpg" width = "1000"> <br />
Wires: <br />
  &nbsp;&nbsp;Black for Ground from the Arduino board to the shared Ground line <br />
  &nbsp;&nbsp;White for 5V from the Arduino board to the shared 5V line <br />
  &nbsp;&nbsp;Resistor for Ground from shared line to LED <br />
  &nbsp;&nbsp;Red, Green and Blue for each color's digital signal from the Arduino board <br />
