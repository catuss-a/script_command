script_command by axel catusse
==============

recode of the script command on Linux.

script : make typescript of terminal session


Description
=============

Script makes a typescript of everything printed on your terminal. It is useful for students who need a hardcopy record of an interactive session as proof of an assignment, as the typescript file can be printed out later with lpr(1).

If the argument file is given, script saves all dialogue in file. If no file name is given, the typescript is saved in the file typescript.

Options:
=============
    -a'        Append the output to file or typescript, retaining the priorcontents.

    -c COMMAND
    Run the COMMAND rather than an interactive shell. This makes it easy for a script to capture the output of a program that behaves differently when its stdout is not a tty.

    -f' Flush output after each write. This is nice for telecooperation: One person does 'mkfifo foo; script -f foo' and another can supervise real-time what is being done using 'cat foo'.

    -q' Be quiet.

    -t' Output timing data to standard error. This data contains two fields, separated by a space. The first field indicates how much time elapsed since the previous output. The second field indicates how many characters were output this time. This information can be used to replay typescripts with realistic typing and output delays.