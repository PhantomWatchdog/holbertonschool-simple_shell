![PNG](https://camo.githubusercontent.com/e0f37f261a871cddc208e0643210660d47ae767f47097291bc55c80120160636/68747470733a2f2f696d616765732e73717561726573706163652d63646e2e636f6d2f636f6e74656e742f76312f3561346266653862663039636134323238636563613362372f313533393133393139393539382d414e4834353449485a49314f4b574f4e4b5258592f6c6f676f2e6a70673f666f726d61743d3235303077)

# Project Simple Shell:hammer_and_wrench:

As our own version of a shell program, it allow the user execute the shell, this one awaiting a command to execute.
It was writed in C language.
This project is the last low-level programming part of the first trimester at Holberton School.

## Dependencies :couple:

The shell program was coded on an Ubuntu 20.04 LTS machine with `gcc` version 11.4.0.

## Usage :running:

To execute it, need to compile all `.c` files in the repository and include the header `main.h`.

Compilation:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Example:
```
#Guantanamo$ /bin/ls
file1.c file2.c file3.c
```
# How Shell works 

* What is a Shell?

```
This project is a simple implementation of a Shell in the C language. 
A Shell is a command interpreter that allows the user to interact with 
an operating system using a command-line interface. This shell offers 
basic functionality such as command execution, directory management 
and I/O redirection.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Schema_Shell.png)

# Displaying a command prompt:

```
After Shell execution, a command prompt is displayed, waiting for 
a command. A command prompt displays information about the user, 
the current directory, etc.
```
```
#Ken/Research$
```
# Reading user input:

```
When the Shell receives a command written by the user followed 
by the Enter key, it reads the input using functions 
like fgets and stores the value in a buffer.
```

# Order analysis:

```
User input is parsed, enabling the Shell to understand the 
command and arguments. The input is divided into tokens, 
each representing a part of the command: command name, arguments, 
options, etc. This phase enables the Shell to understand the structure 
of the command. This phase enables the structure of the command 
to be understood.
```

# Order search:

```
Once a command and its arguments have been parsed, Shell searches 
for the executable file of the corresponding command. 
Command executables are located in the directories specified by 
the PATH environment variable.
```

# Creating a child process:

```
When an executable function is found, the Shell creates a child 
process using a system call like fork. A child process is a separate 
instance of the Shell in which the command is executed.
```

# Executing a command:

```
To execute a command, the child process uses system calls such 
as exec to replace its own program with the program to be executed. 
The new program takes over execution of the child process, and the 
command is executed in that process.
```

# Waiting for order execution to finish:

```
The parent process waits for the child process to finish, using functions
 such as wait or waitpid. This ensures that the Shell does not display 
 the next prompt until the command has been completed.
```

# Output display:

```
If an executed command returns output (text, data), Shell displays the 
output in the terminal.
```

# Back to command prompt:

```
When a command has been completed, the Shell returns to its initial state, 
awaiting another command from the user.
```

# Shell output:

```
The user can exit the Shell by entering a specific command or by 
pressing a Ctrl-D key combination.
```
* Features

```
Execute external commands.
Support for built-in commands (cd, exit).
Error handling.
I/O redirection (simple redirects and pipes not supported).
Display a command prompt.
```

![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Prompt.png)

* Dependencies

```
This project requires no external dependencies other than 
standard C libraries.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Read_input.png)

* Parsing a Command

```
The user input are parsed permitting to Shell to understand the 
command and arguments.
The input is splited into tokens, each one represents a part of 
the command : Command name, arguments, options ...
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
When a command and its arguments are parsed, the shell search 
the exe file of the correspondant command.
The commands exe are in directories specified by the PATH 
environment variable.
```

* Create Child Process
```
When function executable is found, the Shell create child 
process using a system call like `fork`.
A Child process is an `instance` separated of Shell in 
which the command is executed.
```
* Execute Command
```
For execute a command, the Child process use system call like `exec` 
to replace his own program with the program to be executed.
The new program takes over the Child process execution, and the command 
run in this process.
```
* Wait for Command Completion

```
The parent process wait for Child precess completion, with functions 
like wait or waitpid.
Ensuring that Shell don't display the next prompt until the command's end. 
```
* Display Output

```
If a executed command return a output(text, data), the Shell 
display the output in terminal.
```
* Return the Prompt

```
When a command is complete, the Shell return to his inital state.
Waiting another user command.
```
* Exit the Shell

```
The user can exit the shell by entering a specific command or 
pressing a key combination `Ctrl-D`.
```

## PID / PPID :hammer_and_wrench:

![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/ProcessCreation.jpg)

* What's a process ?

```
A process refers to an independently executing unit of a program.
That's a process in instance of a running program, with its own 
memory space and system resources.
A process has its own unique memory ID. (PID)
```
* New or created

```
The process is being created or initialized by the operating system. 
It's in the process of being set up for execution.
```
* Ready

```
The process is ready to be executed by the CPU (Central Processing Unit). 
It's in a queue waiting for its turn.
```

* Running

```
The process is actively being executed by the CPU.
```

* Waiting

```
The process is waiting for a particular event or resource before 
it can proceed. For example, it might be waiting for user input 
or the completion of I/O operations.
```

* Complete

```
The process has completed his execution. It might be waiting 
for the operating system to clean up its resources before being 
fully removed from the system.
```

* Zombie or defunct

```
A process that has completed its execution but hasn't yet been 
fully removed from the system.
Stay in this state briefly until the operating system cleans up 
its resources.
It can happen if the parent process hasn't yet acknowledged 
the termination of its child process.
```

* Suspended

```
The process is temporarily suspended and isn't executing. It can be either voluntarily suspended (e.g., by user request) or involuntarily suspended 
(e.g., due to resource constraints).
```

* Swapped

```
The process's memory contents have been temporarily moved out 
of main memory and onto disk to make space for other processes. 
This is a state that's used in systems with limited memory.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/ProcessSwitch.jpg)

## How manipulate the environment of the current process :hammer_and_wrench:

* What is the environment of the current process ?

```
Process environment manipulation allows you to access and modify 
the environment variables of a running program.
```

* How to handle it ?

```
To access and manipulate environment variables within the current process, 
the user can use the `getenv()` and `setenv()` functions provided by `stdlib.h`.
`getenv()` allow to the user retrieve the value of a specific environment.
`setenv()` allow to the user set or update value of an environment.
```

## execve :hammer_and_wrench:

* What is a execve ?

```
execve() is a system function that replaces the memory image of 
the current process with that of a new program to be executed, enabling 
the user to run a different program while keeping the same process.
```
* How do to an execve ?
```
To use execve() in the C language, need to include the unistd.h library. 
Next, provide the path to the program to be executed, an array of arguments 
for this program, and possibly an environment array. 
When execve() is called, the current process is replaced by the new program. 
If execve() succeeds, the following code will not be executed. 
If it fails, it will return -1.
```

## How to suspend a process execution :hammer_and_wrench:

* Wait

```
The wait() system call is used by a parent process to wait for 
the completion of his child process(es).
This mechanism is essential for process management, allow the parent 
process to ensure that child processes have completed their execution 
before the parent itself continue or terminate.
```

## EOF :hammer_and_wrench:

* What is a EOF

```
In the context of file input/output operations in C, EOF (End of file) 
is a special constant used to indicate the end of a file.
```
* How do to an EOF ?
```
To detect the end of a file in C, use a read loop with a condition based 
on the return value of the file read function. EOF is returned by functions 
such as fgetc() when the end of the file is reached.
```

## MIT License :lock:

```
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.
```

## Authors :black_nib:

* <[Nour Chaouch](https://github.com/NChaouch)>
* <[Nicolas Fouquet](https://github.com/PhantomWatchdog)># Shell in language C:

## Acknowledgements :pray:

This program was written as part of the curriculum for Holberton School.
Holberton School is a campus-based full-stack software engineering program
that prepares students for careers in the tech industry using project-based
peer learning. For more information, visit [this link](https://www.holbertonschool.com/).

:traffic_light: :boom: :police_car: :roller_coaster: :skull:

* What is a Shell?

```
This project is a simple implementation of a Shell in the C language. 
A Shell is a command interpreter that allows the user to interact with 
an operating system using a command-line interface. This shell offers 
basic functionality such as command execution, directory management 
and I/O redirection.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Schema_Shell.png)

# Displaying a command prompt:

```
After Shell execution, a command prompt is displayed, waiting for 
a command. A command prompt displays information about the user, 
the current directory, etc.
```
```
#Ken/Research$
```
# Reading user input:

```
When the Shell receives a command written by the user followed 
by the Enter key, it reads the input using functions 
like fgets and stores the value in a buffer.
```

# Order analysis:

```
User input is parsed, enabling the Shell to understand the 
command and arguments. The input is divided into tokens, 
each representing a part of the command: command name, arguments, 
options, etc. This phase enables the Shell to understand the structure 
of the command. This phase enables the structure of the command 
to be understood.
```

# Order search:

```
Once a command and its arguments have been parsed, Shell searches 
for the executable file of the corresponding command. 
Command executables are located in the directories specified by 
the PATH environment variable.
```

# Creating a child process:

```
When an executable function is found, the Shell creates a child 
process using a system call like fork. A child process is a separate 
instance of the Shell in which the command is executed.
```

# Executing a command:

```
To execute a command, the child process uses system calls such 
as exec to replace its own program with the program to be executed. 
The new program takes over execution of the child process, and the 
command is executed in that process.
```

# Waiting for order execution to finish:

```
The parent process waits for the child process to finish, using functions
 such as wait or waitpid. This ensures that the Shell does not display 
 the next prompt until the command has been completed.
```

# Output display:

```
If an executed command returns output (text, data), Shell displays the 
output in the terminal.
```

# Back to command prompt:

```
When a command has been completed, the Shell returns to its initial state, 
awaiting another command from the user.
```

# Shell output:

```
The user can exit the Shell by entering a specific command or by 
pressing a Ctrl-D key combination.
```
* Features

```
Execute external commands.
Support for built-in commands (cd, exit).
Error handling.
I/O redirection (simple redirects and pipes not supported).
Display a command prompt.
```

![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Prompt.png)

* Dependencies

```
This project requires no external dependencies other than 
standard C libraries.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/Read_input.png)

* Parsing a Command

```
The user input are parsed permitting to Shell to understand the 
command and arguments.
The input is splited into tokens, each one represents a part of 
the command : Command name, arguments, options ...
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
When a command and its arguments are parsed, the shell search 
the exe file of the correspondant command.
The commands exe are in directories specified by the PATH 
environment variable.
```

* Create Child Process
```
When function executable is found, the Shell create child 
process using a system call like `fork`.
A Child process is an `instance` separated of Shell in 
which the command is executed.
```
* Execute Command
```
For execute a command, the Child process use system call like `exec` 
to replace his own program with the program to be executed.
The new program takes over the Child process execution, and the command 
run in this process.
```
* Wait for Command Completion

```
The parent process wait for Child precess completion, with functions 
like wait or waitpid.
Ensuring that Shell don't display the next prompt until the command's end. 
```
* Display Output

```
If a executed command return a output(text, data), the Shell 
display the output in terminal.
```
* Return the Prompt

```
When a command is complete, the Shell return to his inital state.
Waiting another user command.
```
* Exit the Shell

```
The user can exit the shell by entering a specific command or 
pressing a key combination `Ctrl-D`.
```

## PID / PPID :hammer_and_wrench:

![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/ProcessCreation.jpg)

* What's a process ?

```
A process refers to an independently executing unit of a program.
That's a process in instance of a running program, with its own 
memory space and system resources.
A process has its own unique memory ID. (PID)
```
* New or created

```
The process is being created or initialized by the operating system. 
It's in the process of being set up for execution.
```
* Ready

```
The process is ready to be executed by the CPU (Central Processing Unit). 
It's in a queue waiting for its turn.
```

* Running

```
The process is actively being executed by the CPU.
```

* Waiting

```
The process is waiting for a particular event or resource before 
it can proceed. For example, it might be waiting for user input 
or the completion of I/O operations.
```

* Complete

```
The process has completed his execution. It might be waiting 
for the operating system to clean up its resources before being 
fully removed from the system.
```

* Zombie or defunct

```
A process that has completed its execution but hasn't yet been 
fully removed from the system.
Stay in this state briefly until the operating system cleans up 
its resources.
It can happen if the parent process hasn't yet acknowledged 
the termination of its child process.
```

* Suspended

```
The process is temporarily suspended and isn't executing. It can be either voluntarily suspended (e.g., by user request) or involuntarily suspended 
(e.g., due to resource constraints).
```

* Swapped

```
The process's memory contents have been temporarily moved out 
of main memory and onto disk to make space for other processes. 
This is a state that's used in systems with limited memory.
```
![Scheme](https://github.com/PhantomWatchdog/holbertonschool-simple_shell/blob/main/Images/ProcessSwitch.jpg)

## How manipulate the environment of the current process :hammer_and_wrench:

* What is the environment of the current process ?

```
Process environment manipulation allows you to access and modify 
the environment variables of a running program.
```

* How to handle it ?

```
To access and manipulate environment variables within the current process, 
the user can use the `getenv()` and `setenv()` functions provided by `stdlib.h`.
`getenv()` allow to the user retrieve the value of a specific environment.
`setenv()` allow to the user set or update value of an environment.
```

## execve :hammer_and_wrench:

* What is a execve ?

```
execve() is a system function that replaces the memory image of 
the current process with that of a new program to be executed, enabling 
the user to run a different program while keeping the same process.
```
* How do to an execve ?
```
To use execve() in the C language, need to include the unistd.h library. 
Next, provide the path to the program to be executed, an array of arguments 
for this program, and possibly an environment array. 
When execve() is called, the current process is replaced by the new program. 
If execve() succeeds, the following code will not be executed. 
If it fails, it will return -1.
```

## How to suspend a process execution :hammer_and_wrench:

* Wait

```
The wait() system call is used by a parent process to wait for 
the completion of his child process(es).
This mechanism is essential for process management, allow the parent 
process to ensure that child processes have completed their execution 
before the parent itself continue or terminate.
```

## EOF :hammer_and_wrench:

* What is a EOF

```
In the context of file input/output operations in C, EOF (End of file) 
is a special constant used to indicate the end of a file.
```
* How do to an EOF ?
```
To detect the end of a file in C, use a read loop with a condition based 
on the return value of the file read function. EOF is returned by functions 
such as fgetc() when the end of the file is reached.
```

## MIT License:

```
This project is licensed under the MIT License - see the LICENSE file for details.
```

## Authors:

* <[Nour Chaouch](https://github.com/NChaouch)>
* <[Nicolas Fouquet](https://github.com/PhantomWatchdog)>
