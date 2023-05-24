# Studio 21
1)Team: Stacey Acheampong, Dylan Alfonso and Nina Latimore

2.) It's important to declare a virtual destructor in the base class
	it helps to avoid memory leaks. The virtual destructor ensures that any derived class destructor
	is destroyed via a reference or a pointer of the base class.

3.) for command prompt using dependency injection make sis reusable and flexible because it allows for 
different implementations of the file factory and file system so that it can be 
easily swapped in and out without affecting the commnad prompt functionality. Tbe command 
prompt can be configured to use these instead of the simple file system
and its associated factory object.

4.) I won't copy the code to avoid redundency. However, in main we tested to make sure all the files would initialize
	properly, and then on the command prompt we tested asking for help, asking for help specifically on touch command,     
	and we executed the touch command. All performed as expected!