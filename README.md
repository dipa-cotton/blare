<img width="800" height="592" alt="Screenshot 2026-08-04 at 5 14 55 PM" src="https://github.com/user-attachments/assets/64e34e26-11cd-41a9-8bab-d1cdbff04bab" />


# blare
my annoying alarm clock :)

## purpose
i wanted to make this alarm clock to familiarize myself with C++ and the arduino IDE. i really enjoyed playing around with the pcb as well, it was a fun mini project!

## goals
i want to submit this to blare to hopefully get the pillowcase :) I'll sleep better knowing orpheus is watching over me... or i guess under me

## components
the main files are my PCB and Schematic made in kicad, and I have directories of my arduino code and my case's stl file as well :)

no ai was used in this project :))))))

## pictures

<img width="1082" height="823" alt="Screenshot 2026-08-03 at 8 34 41 PM" src="https://github.com/user-attachments/assets/b98381d6-c43e-43de-81bf-751480dc5d04" />
<img width="868" height="666" alt="Screenshot 2026-08-04 at 5 19 33 PM" src="https://github.com/user-attachments/assets/72d8d75d-0131-482c-b313-6880b96282c1" />
<img width="868" height="666" alt="Screenshot 2026-08-04 at 5 16 09 PM" src="https://github.com/user-attachments/assets/93ca13b1-0655-4d17-9ce5-a28064bfafbc" />
<img width="868" height="666" alt="Screenshot 2026-08-04 at 5 15 20 PM" src="https://github.com/user-attachments/assets/95fb4db9-bcc2-4c4c-9f61-cf7c5864e913" />

## BOM
- 6 Cherry MX Switches
- 1 LCD Display
- 1 Lolin C3 Mini
- 1 Buzzer
- 6 Diodes
- 3 Capacitors (already owned)
a more detailed list can be found in BOM.csv :)

## Journal
### Day 1: PCB
#### Hours Spent: 3
##### What did you do?:
Today, I used KiCAD to build the schematic for my alarm as well as routed the PCB. This took quite a bit of effort, and took me a couple of hours due to fixing ERC and DRC issues.

##### Why did you do it?:
I did this to create the PCB for my project, so it can be easily manufactured and used to make an alarm clock that is compact for its size :)

##### What problems did you face?:
I faced issues with ERC (electric rules checker), mostly unused pins lol. In the end though, with google by my side, I was able to figure out that the unused pins must have an x symbol at the end of them to prevent KiCAD from getting angered. In the images above, you can see the specific wiring of the components, as well as the final PCB. The PCB was the easy part, as routing was quite simple.

<img width="1276" height="702" alt="Screenshot 2026-08-03 at 8 13 27 PM" src="https://github.com/user-attachments/assets/99cda37d-8ca1-40a8-9902-17ab17de2efa" />

<img width="1315" height="823" alt="Screenshot 2026-08-03 at 8 33 25 PM" src="https://github.com/user-attachments/assets/dcd2672a-e4e1-46ab-9e18-b41c03d04cc5" />

### Day 2: Code
#### Hours Spent: 4
##### What did you do?:
Today, I used the Arduino IDE to fully code the alarm clock. In my code, there are if statements that correspond each switch to a certain command, which displays what it does on the LCD as well. There are multiple commands, such as one that displays an undertale doggo, one that shows the weather, one that allows you to set an alarm time, one that shows the current time, and others as well. This code, once uploaded should hopefully turn the alarm clock into a working device, not just an alarm clock :)

##### Why did you do it?:
I did this with the goal of making something more complex than a simple alarm clock, but a device within itself that can be used for multiple purposes, sort of like a nightstand hub that tells you everything you need to know!

##### What problems did you face?:
I faced syntax issues with C++ as always, and I also didn't know how to display an image of the undertale doggo on the screen, but with guidance from google and a website that turned the image into a format that the c3 can understand, I was able to successfully use it to display an image when a certain button is pressed. In the future, I may try to add motion, or a lil gif of the guy jumping!
<img width="554" height="280" alt="Screenshot 2026-08-04 at 12 12 19 AM" src="https://github.com/user-attachments/assets/c6d9b3c5-8b7b-41c9-9bcc-d5ffde4254e1" />

### Day 3: CAD
#### Hours Spent: 1
##### What did you do?:
Today, I used Fusion 360 to create a case for my alarm clock. I exported a step file of the pcb from KiCAD, imported it into Fusion as a mesh file, and created a case around it. This process made sure that everything is correctly spaced, and looks nice.

##### Why did you do it?:
I did this so the alarm clock isn't just a PCB with no case. It has a heart too, yknow? In the future, I'll make it look nicer, but once my PCB arrives, I'll make sure everything fits and make it look nicer.

##### What problems did you face?:
I didn't really face any issues, cuz I know Fusion 360 pretty well, but text always acts funny on my Mac so I just had to struggle with that for a minute or 2.
<img width="1858" height="1324" alt="image" src="https://github.com/user-attachments/assets/18c14671-d128-409c-a902-72af7864753f" />



