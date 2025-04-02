# Pipex

This project is about handling pipes.

## Features

### ✅ Basic Functionality
- The program is executed as follows:
  ```bash
  ./pipex file1 cmd1 cmd2 file2
- It takes 4 arguments:

    - file1 and file2 are file names.

    - cmd1 and cmd2 are shell commands with their parameters.

The program must behave exactly like the following shell command:
```bash
$> < file1 cmd1 | cmd2 > file2
```

### ✅ Multiple Pipes
- The program handles multiple pipes
```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
behaves like:
```bash
$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
### ✅ Here Document Support
- The program supports the here_doc functionality when the first parameter is "here_doc".

```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```
This should behave like:
```bash
$> cmd << LIMITER | cmd1 >> file
```
### Requirements
- Handle file redirection and piping as described.

- Ensure proper error handling for invalid arguments or commands.

- Implement functionality for handling the here_doc mechanism.

