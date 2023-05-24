# Lab 5
Team: Dylan Alfonso, Stacey Acheampong, Nina Latimore
Work Distribution:
- LSCommand - Dylan / Stacey
- RemoveCommand - Stacey / Dylan
- Modifying TouchCommand - Dylan
- CatCommand - Dylan
- DisplayCommand - Dylan / Stacey
- CopyCommand - Dylan
- MacroCommands - Stacey
- Rename Command - Dylan / Stacey
- Additional MacroCommand - Stacey
- Updating main and testing - Dylan
- Readme - Dylan / Stacey

1.) First error we're running into is that "-a" is not being recognized by the code, it's automatically trying to write everytime.
	Found the error by debugging, the input is only accepting the characters before the space, anything after the space is not being recognized
	
	Fix: edited the extraction in run() to extract via getline() instead of iss.

2.) Next error, in copy command, I couldn't figure out how to get the extension or how to create a brand new copy

	Fix: Created function in abstract file and all of the files associated, also manually got the extension.

3.) Error: Cannot figure out how to put on the meta data in LSCommand
	
	Fix: 

4.) Error: Failed catCommand.executeTextFileNAppendSaving
	
	Fix: A lot of the catCommand I was adding an uneccessary '\n', so I fixed when I added it.

5.) Error: DSCommand image formatted isn't printing properly

	Fix: Started using basicdisplayvisitor and fixed that code, now it prints formatted properly

6.) Error: Invalid format test for rename not working properly.

	Fix: In Macrocommand, it wasn't exiting whenever the return was failing, changed that and now it passes.

7.) Error: copy.validcopy is failing, the getName() of the file isn't changing when it should,
	Fix: In the clone function, I was just returning a direct copy without changing the private fileName, fixed by using temp variable.

8.) Error: copypasswordprotected failing
	Fix: PasswordProxy's copy function wasn't creating a whole new file, fixed that.



ALL TESTS PASSING :)!!!!

Manually testing in main, here's how it looks, I left comments and tested every function.:


C:\Users\dylan\cse332 repo\lab 5 final\out\build\x64-Debug\src>lab5.exe
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch hey.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TRYING NO EXTENSION
$ touch hi 
Failure to create new file
Command Failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch hi.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch image.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING ls
$ ls
hey.txt             hi.txt
image.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls -m
hey.txt             text                0
hi.txt              text                0
image.img           image               0

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING cat
$ cat hi.txt
 hi.txt
Enter text to write to the file. Enter :wq to save and quit or :q to quit without saving:
hi
there
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING ds
$ ds hi.txt
hi
there

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING OVERWRITNG WITH cat
$ cat hi.txt
 hi.txt
Enter text to write to the file. Enter :wq to save and quit or :q to quit without saving:
nope
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds hi.txt
nope

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING APPENDING WITH cat
$ cat hi.txt -a
 hi.txt -a
nope
Enter text to append to the file. Enter :wq to save and quit or :q to quit without saving:
hi
:wq

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//CAT AND DS WITH IMAGE TESTING
$ cat image.img
 image.img
Enter text to write to the file. Enter :wq to save and quit or :q to quit without saving:
X X X X X3
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds image.img
X X
 X
X X

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds image.img -d
X X X X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING ls -m
$ ls -m
hey.txt             text                0
hi.txt              text                6
image.img           image               9

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
hey.txt             hi.txt
image.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING remove
$ remove image.img
Remove success
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls -m
hey.txt             text                0
hi.txt              text                6

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING cp
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cp hi.txt hello
cloning file
succesfully copied!
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls -m
hello.txt           text                6
hey.txt             text                0
hi.txt              text                6

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//MAKING SURE THEY ARE 2 SEPERATE FILES
$ cat hello.txt
 hello.txt
Enter text to write to the file. Enter :wq to save and quit or :q to quit without saving:
change
occured
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls -m
hello.txt           text                14
hey.txt             text                0
hi.txt              text                6

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds hello.txt
change
occured

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds hi.txt
nopehi

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
// TESTING rn
$ rn hi.txt changehi
cloning file
succesfully copied!
Remove success
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
changehi.txt        hello.txt
hey.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING CDS
$ cds hey.txt
 hey.txt
Enter text to write to the file. Enter :wq to save and quit or :q to quit without saving:
written
:wq
written

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
//TESTING help
$ help
cat
cds
cp
ds
ls
remove
rn
touch
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ help rn
Rename renames a file
Usage: rn <existing_file> <new_name>
CatDS is a combination of Cat and DS, after concatenating or writing to the file a formatted file will return to you
Usage: cds <filename> [-a]
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ q
DONE!!!