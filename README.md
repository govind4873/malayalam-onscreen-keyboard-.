# malayalam-virtual-keyboard-.
This project aims to develop an onscreen keyboard for disabled in Malayalam language for Linux platforms  using GTK libraries .
I am learning the basics of Gnome application development from https://developer.gnome.org/gtk3/3.22/ 
step by step development of an onscreen keyboard . 
 
the present status of the project , the keyboard can input UNICODE characters of malayalam in the terminal window .
gcc `pkg-config --cflags gtk+-3.0` -o example-3 example-3.c `pkg-config --libs gtk+-3.0`
 
Scope of improvement 
1. finding a method to input the malayalam text to the input stream and not from the terminal 
2. code optimization of the keyboard, instead of individual intialisation of objects 
3. function to return the unicode from the button label instead of triggering individual functions to return the unicode.

by Goind GS, Btech student,Sree Chitra Thirunal College of Engineering 

