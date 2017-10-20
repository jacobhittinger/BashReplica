---------------------------------------------------------------------------------------------------------------

## Bash Replica

Eastern Washington University, CSCD 340 - Operating Systems, 2016

---------------------------------------------------------------------------------------------------------------

This is a replica of the well known Unix shell: Bash.

---------------------------------------------------------------------------------------------------------------

### Requirements:

This software must be run in a Linux environment.

---------------------------------------------------------------------------------------------------------------

### Configuration:

**.myshrc** : /BashReplica/myshrc/.myshrc
+ You will need this file in order to permanently add to $PATH or change default settings for history stuff.
+ See 'myshrcExampleFile.txt' for an example '.myshrc' file.
+ If you choose to supply this file, it must match exact formatting.
+ Not having the '.myshrc' file will simply cause the program to use default values.

**.mysh_history** : /BashReplica/myshrc/.mysh_history
+ This file contains entries representing the history of executed commands.
+ See 'mysh_historyExampleFile.txt' for an example '.mysh_history' file.
+ If you choose to supply this file, it must match exact formatting.
+ Not having the '.mysh_history' file will simply cause the program to create one for you.

---------------------------------------------------------------------------------------------------------------

### Functionality:

**Changing Directories**
+ The current directory can be changed using the 'cd' command.

**Background Execution**
+ Commands can be ran in the background using an '&'.

**Pipes**
+ Standard piping can be achieved using '||'.
+ Capable of handling two pipes.

**PATH Handling and Extension**
+ The PATH can be handled, and displayed.
+ Adding to the path is possible, and can be made permanent by adding it to the .myshrc file.

**History**
+ A history of executed commands is maintained.
+ This can be viewed using the 'history' command.

**Programs via execvp()**
+ By utilizing execvp(), other programs within the environment can be run.
+ E.g. 'ls', 'cp', 'rm'.

---------------------------------------------------------------------------------------------------------------