#pragma once


enum SUCCESSANDERRORS {
    //cat errors
    SUCCESS,
    NULLFILE,
    //display
    FILENOTFOUND,
    //Copy
    FILEDNE,
    EXTENSION,
    CLONEFAIL,
    //Macro
    PARSENOTSET,
    DIFFERENTSIZES,
    //Commandprompt
    FAILEDINSERTION,
    USERQUITS,
    //Imagefile
    APPENDNOTSUPPORTED,
    SIZENOTEQUAL,
    INCORRECTPIXEL,
    //touchcommand
    FAILTOCREATEFILE,
    //password done
    INCORRECTPASSWORD,
    //Simplefilesystem 
    FILEDOESNOTEXIST,
    FILEEXISTS,
    ABSTRACTFILENULL,
    FILENOTOPEN,
    ABSTRACTFILENOTOPEN,
    OPEN,
    //remove
    FILENOTREMOVED
};




