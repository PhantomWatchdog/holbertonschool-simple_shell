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

```
The user input are parsed permitting to Shell to understand the command and arguments.
The input is splited into tokens, each one represents a part of the command :
Command name, arguments, options ...).
This phase permit the understanding of the command structure.
```
```
DELIMITER
"String test version"
String
test
version

PARSING
```

* Search a Command
 
```
When a command and its arguments are parsed, the shell search the exe file of the correspondant command.
The commands exe are in directories specified by the PATH environment variable.
```

* Create Child Process
```
When function executable is found, the Shell create child process using a system call like `fork`.
A Child process is an `instance` separated of Shell in which the command is executed.
```
* Execute Command
```
For execute a command, the Child process use system call like `exec` to replace his own program with the program to be executed.
The new program takes over the Child process execution, and the command run in this process.
```
* Wait for Command Completion

```
The parent process wait for Child precess completion, with functions like wait or waitpid.
Ensuring that Shell don't display the next prompt until the command's end. 
```
* Display Output

```
If a executed command return a output(text, data), the Shell display the output in terminal.
```
* Return the Prompt

```
When a command is complete, the Shell return to his inital state.
Waiting another user command.
```
* Exit the Shell

```
The user can exit the shell by entering a specific command or pressing a key combination `Ctrl-D`.
```

## PID / PPID :hammer_and_wrench:

![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/ProcessCreation.jpg)

* What's a process ?

```
A process refers to an independently executing unit of a program.
That's a process in instance of a running program, with its own memory space and system resources.
A process has its own unique memory ID. (PID)
```
* New or created

```
The process is being created or initialized by the operating system. It's in the process of being set up for execution.
```
* Ready

```
The process is ready to be executed by the CPU. It's in a queue waiting for its turn.
```

* Running

```
The process is actively being executed by the CPU.
```

* Waiting

```
The process is waiting for a particular event or resource before it can proceed. For example, it might be waiting for user input or the completion of I/O operations.
```

* Complete

```
The process has completed his execution. It might be waiting for the operating system to clean up its resources before being fully removed from the system.
```

* Zombie or defunct

```
A process that has completed its execution but hasn't yet been fully removed from the system.
Stay in this state briefly until the operating system cleans up its resources.
It can happen if the parent process hasn't yet acknowledged the termination of its child process.
```

* Suspended

```
The process is temporarily suspended and isn't executing. It can be either voluntarily suspended (e.g., by user request) or involuntarily suspended (e.g., due to resource constraints).
```

* Swapped

```
The process's memory contents have been temporarily moved out of main memory and onto disk to make space for other processes. This is a state that's used in systems with limited memory.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/ProcessSwitch.jpg)

## How manipulate the environment of the current process :hammer_and_wrench:

```
To access and manipulate environment variables within the current process, you can use the `getenv()` and `setenv()` functions provided by `stdlib.h`.
`getenv()` allow you to retrieve the value of a specific environment.
`setenv()` allow you to set or update value of an environment.
```

## execve :hammer_and_wrench:

<<<<<<< HEAD
```
The execve() system call is used to replace the current process memory image with a new program. It's the primary way to execute a different program with the same process.
The new program can be an executable file or a script, and it become the running process, inheriting the same process ID (PID).
```

## How to suspend a process execution :hammer_and_wrench:
=======
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
>>>>>>> Nour

* Wait

```
The wait() system call is used by a parent process to wait for the completion of his child process(es).
This mechanism is essential for process management, allow the parent process to ensure that child processes have completed their execution before the parent itself continue or terminate.
```

## EOF :hammer_and_wrench:

<<<<<<< HEAD
```
In the context of file input/output operations in C, EOF is a special constant used to indicate the end of a file.
=======
* What's an EOF ?

```
An EOF (End of file) in shell means to mark the end of a file when reading from standard input.

```

* How to do an EOF ?

```
In shell, Ctrl-D is used to indicate the end of a file when reading from standard input, which corresponds to EOF. 
When Ctrl-D is pressed, it signals to the program that the input is finished, and it stops reading.
Ctrl-C, on the other hand, sends a SIGINT signal to the running process, which is often used to interrupt the execution 
of a running program. This can be useful for stopping a program that seems to be stuck, or for cancelling an operation 
in progress.

>>>>>>> Nour
```
