# Studio 19
1.) Dylan Alfonso, Stacey Acheampong, Nina Latimore

2.) The test we ran in main:
    vector<char> contents = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
    vector<char> overWriteTest = { 'o' };
    AbstractFile* hi = new ImageFile("hi");
    //cout << hi->getName() << endl;
    hi->write(contents);
    hi->write(contents);
    hi->append(contents);
    hi->read();
    hi->write(overWriteTest);
    hi->read();
    cout << hi->getSize() << endl;

3.) Communication:
	the object to be visited implemts an accept() method which takes a reference to some visitor object. When the visitor wants to visit an object it calls the object's accept method.
	Then the object's accept method calls the appropriate visit method by passing a reference to itself as an argument. The visit method in the visitor object will perform some operation on the visited object.

4.) Delegation on a basic level allows an object to assign some of its responsibility to another object. The object can forward request to the delegated objects which can perform tasks and send the result to the object. 
	The visitor pattern does this through the accpet method, where each class implements the accept method. The accpet method delegates the task of visiting an object to the visitor(by calling the visitor's visit()). 
	This allows the visitor to operate on objects without changing their interface.

5.) One disadvantage is that we would need to know the return type when designing. If we don't, we would have to go back and manually change all of them, which isn't convenient object oriented programming.

