<h3>Toy Robot Code Challenge</h3>

<b>Projects</b>

“ToyRobotApp” – the Toy Robot console application<br>
“ToyRobotCore” – the core logic shared between “ToyRobotApp” and “ToyRobotTest” <br>
“ToyRobotTest” - the Toy Robot test application

<b>Prerequisite</b>
Visual Studio 2019 installed with enabling the workload "Desktop development with C++"


<b>Installation</b>
1) Unzip the attachment “TRApplication.zip”

2) To open the project on Visual Studio by double clicking the solution file TRApplication.sln
3) Click on the solution folder and perform “Clean” and “Rebuild”


<b>How to run “ToyRobotApp”</b>
1) Set “ToyRobotApp” as start up project

2) Open AppSettings.h and update your preferred input file path and file name which feed the commands to the “ToyRobotApp”

3) Open the input file and update the below commands. ( Commands should be in Capital)

PLACE 2,3,NORTH</br>
LEFT </br>
MOVE </br>
RIGHT </br>
REPORT </br>

4) Run the “ToyRobotApp” application by Ctrl+F5



<b>How to run “ToyRobotTest”</b>

1) Set the project “ToyRobotTest” as start up project
2) Run the “ToyRobotTest” application by Ctrl+F5
3) Each test cases will be executed, displaying the list of commands executed and the status of test case will be printed on command prompt.

TestCases.cpp - List of core test cases ToyRobot
Test.cpp - Calls the test cases with input data

(Screenshots are captured below)
