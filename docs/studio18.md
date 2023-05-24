# Studio 18
1.) Dylan Alfonso, Stacey Acheampong, Nina Latimore

2) We discussed about the factory method, which basically allows  other class
	(subclasses) to decide which objects to create.Instead of modyfing the createfile method
	it might be better to create a new abstract class overrrides the creatfile to create new files.

3) Some advantages of the abstract factory pattern is that it allows for much more flexible code.
	A new class should be created when a new "family" of calsses needs to be created. So a class not supported by the 
	already existing factory classes. Maybe modifying the existing factory classes to support the new file type. Yes the
	same factory can be used to create files for two file system implementations that manage the same type of files. No,
	the same concrete factory implementation cannot be used to create files for two file system implementations that manage 
	different types of files.

4) Made 2 files, one being an image and one being a text file. I wrote different contents to their respective files, and then
	added those files to the filesystem. I then printed the output of the reading of those files, which returned the address.
	Then I read the contents of the files, which printed out the contents!

5) It only depends on the AbstractFile interface!