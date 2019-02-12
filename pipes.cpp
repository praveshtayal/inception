#include <iostream>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h> // For pipe
#define BUFSIZE 1024
using namespace std;

int main()
{
    int fileDesc[2];
    char buf[BUFSIZE] = "This is the text I am writing to the pipe";
    int err=pipe(fileDesc); // Opens a pipe
    int readFD = fileDesc[0], writeFD=fileDesc[1];
    cout << err << endl;
    cout << fileDesc[0] << endl;
    cout << fileDesc[1] << endl;


    int pid=fork();
    if(pid==0)
    {
        cout << "In child process\n";
        ssize_t readSize = read(readFD, buf, BUFSIZE);
        if(readSize>0)
            cout << buf << endl;
        return 0;
    }
    else if(pid==-1)
    {
        cout << "Cant fork new process\n";
        return 0;
    }
    cout << "In parent process writing to the buffer\n";
    char c, *ptr=buf;
    cin.get(c);
    while(c != '$'){
        *ptr++ = c;
        cin.get(c);
    }
    *ptr++ = '\0';
    cout << "The process ID is " << pid << endl;
    ssize_t writeSize = write(writeFD, buf, BUFSIZE);
    cout << "In parent process wrote " << writeSize << " bytes\n";

}
