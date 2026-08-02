

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
<img width="848" height="682" alt="Screenshot 2026-07-20 at 7 49 32 PM" src="https://github.com/user-attachments/assets/da54956a-2a7c-4308-a1c8-741d8b7642bb" />
<img width="848" height="682" alt="Screenshot 2026-07-20 at 7 50 00 PM" src="https://github.com/user-attachments/assets/af6569d8-7f9a-4175-86dd-233c998ccc74" />
<img width="696" height="586" alt="Screenshot 2026-07-20 at 7 50 36 PM" src="https://github.com/user-attachments/assets/7e9f44f5-f9dc-486d-810e-393899269bae" />
<img width="688" height="586" alt="Screenshot 2026-08-02 at 7 16 50 PM" src="https://github.com/user-attachments/assets/f6e20af3-55e8-4551-a485-5333b0a23248" />

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

### Day 2: Code
#### Hours Spent: 4
##### What did you do?:
Today, I used the Arduino IDE to fully code the alarm clock. In my code, there are if statements that correspond each switch to a certain command, which displays what it does on the LCD as well. There are multiple commands, such as one that displays an undertale doggo, one that shows the weather, one that allows you to set an alarm time, one that shows the current time, and others as well. This code, once uploaded should hopefully turn the alarm clock into a working device, not just an alarm clock :)

##### Why did you do it?:
I did this with the goal of making something more complex than a simple alarm clock, but a device within itself that can be used for multiple purposes, sort of like a nightstand hub that tells you everything you need to know!

##### What problems did you face?:
I faced syntax issues with C++ as always, and I also didn't know how to display an image of the undertale doggo on the screen, but with guidance from google and a website that turned the image into a format that the c3 can understand, I was able to successfully use it to display an image when a certain button is pressed. In the future, I may try to add motion, or a lil gif of the guy jumping!
