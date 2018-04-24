For this assignment, you will be making a command line text editor. When you run the program, you 
will be provided with a menu that will give you the option to read, edit or exit. It will also 
show the number of characters that have been read.

When you edit the file, you will enter data line by line and when done, you will enter ‘/’ or 
Ctrl + X to exit.

Once done, it will wait for 3 seconds and then reopen the main menu.

For reading a file, it will ask for the file name and then display its contents. If the number of 
lines is more than 24, it will ask the user if it should continue reading.

Once reading is done, the menu will show the total number of characters read in this session. This 
means that if you open 3 files and read 50 characters each, then the count should be 150.

The program should check if the user has entered a proper command. In case the user does not, it 
should tell the user of his/her mistake.

If the user chooses to edit the file, then the user can enter “edit”, “Edit”, “eDIt”, or any other 
combination of edit and the program should work. The same thing should happen for all other menu 
commands.