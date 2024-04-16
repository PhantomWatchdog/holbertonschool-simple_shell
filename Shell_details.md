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

## How to suspend a process execution :hammer_and_wrench:

## EOF :hammer_and_wrench:

