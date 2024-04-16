# How Shell works :hammer_and_wrench:

* What's the Shell ?

```
A Shell is a program receiving different kind of inputs written from users.
These inputs are send to the computer for execute them.
It can be considered as an interface allowing use of list of services.
Two types exist : `Command line interface` or `Graphical interface`.
This interface will be a gateaway between users and OS.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Schema_Shell.png)

* Display a Prompt

```
Following the execution of Shell, a Prompt is displayed and is awaiting for command.
A Prompt display an information about `user`,`current directory`...
```

```
#Ken/Research$
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Prompt.png)

* Read User Input

```
When Shell receive a command written by user followed by the `Enter` key.
The Shell read the input with the use of functions like `fgets` and store the value in a buffer.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Read_input.png)

* Parsing a Command

* Search a Command
 
## PID / PPID :hammer_and_wrench:
* Create a Child Process
* Execute a Command
* Wait the Complete Exe of a Command
* Display Output
* Come back to Prompt
* Exit the Shell

## How manipulate the environment of the current process :hammer_and_wrench:

## Three prototypes for main function ? :hammer_and_wrench:

## execve :hammer_and_wrench:

* What's an execve ?

```
An execve is a function that allows you to execute a program by completely replacing the code of the current process. 
This is known as a "system call", because by calling this function, 
you can replace the code of the current process with another, while retaining the same process ID. 
Arguments and environment variables can be passed.

```

* How to do an execve ?

```
For example, in a simple C program that calls execve to execute the "ls" program (which lists the files in a directory). 
When execve is called, the "ls" program will be executed instead of our program, with the options we've specified 
(such as "-l" to display file details) and the environment variables we've defined. 
Once the "ls" program ends, control does not revert to our original program, as it has been replaced.

```

## Suspend a process execution :hammer_and_wrench:

* What's a suspend a process execution ?

```
On Linux, suspending a process means temporarily pausing the execution of a running program or process. 
This frees up system resources or temporarily interrupts program execution without closing the program completely.

```

* How to suspend a process execution ?

```
To suspend a process on Linux, simply use the Ctrl + Z key combination. This will pause the process. 
Then, to resume the process, use the bg command to bring it into the background, or fg to bring it back into the foreground. 
If you need to suspend a process from another terminal or session, use the kill -SIGSTOP <PID> command, and to resume it, 
kill -SIGCONT <PID>.

```

## EOF :hammer_and_wrench:

* What's an EOF ?

```
An EOF (End of file) in shell means to mark the end of a file when reading from standard input.

```

* How to do an EOF ?

```
In shell, Ctrl-D is used to indicate the end of a file when reading from standard input, which corresponds to EOF. 
When Ctrl-D is pressed, it signals to the program that the input is finished, and it stops reading.
Ctrl-C, on the other hand, sends a SIGINT signal to the running process, which is often used to interrupt the execution 
of a running program. This can be useful for stopping a program that seems to be stuck, or for cancelling an operation in progress.

```
