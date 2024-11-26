# PIPEX
| 42 Project| Description |
| ----------- | ----------- |
| <a href=""> <img src="https://github.com/0bvim/42-project-badges/blob/main/badges/pipexe.png?raw=true" /></a> | This project implements the working of a well-known UNIX mechanism: the pipe. A pipe allows connecting the output of one command directly to the input of another, allowing data to flow between them without the need for intermediate storage. This facilitates the chaining of commands to perform complex processes efficiently. It is a key tool for online data processing, optimizing tasks such as filtering and manipulation for example.|

## Mandatory implementation
Your program should be executed as follows: ``./pipex file1 command1 command2 file2``


Running the pipex program should do the same as the following command: ``< file1 command1 | command2 > file2``

## Bonus implementation
Your program should be executed as follows: ``./pipex file1 command1 command2 ... commandn file2``


Running the pipex program should do the same as the following command: ``< file1 command1 | command2 | ... | commandn > file2``
