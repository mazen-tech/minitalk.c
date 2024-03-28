<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banners/piscine_and_common_core/github_piscine_and_common_core_banner_minitalk.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/evaluated-06%20%2F%2001%20%2F%202023-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/score-125%20%2F%20100-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/jotavare/minitalk?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/jotavare/minitalk?color=%2312bab9&style=flat-square" />
	<a href='https://www.linkedin.com/in/joaoptoliveira' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
	<a href='https://profile.intra.42.fr/users/jotavare' target="_blank"><img alt='42' src='https://img.shields.io/badge/Porto-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#mandatory">Mandatory</a> •
	<a href="#bonus">Bonus</a> •
	<a href="#norminette">Norminette</a> •
	<a href="#license">License</a>
</p>

## ABOUT
This is a server/client system that uses UNIX signals for communication. The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

- [Subject](https://github.com/jotavare/minitalk/blob/master/subject/en_subject_minitalk.pdf) `PDF`
- [References](https://github.com/jotavare/42-resources#02-minitalk) `GitHub`

## Stuff that you need to know
#### getpid(void) --> is a system call in Unix-like operating systems that retrieves the process ID (PID) of the calling process and it doesn't accept any arrgument.
```bash
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("My PID is: %d\n", getpid());
    return 0;
}
```

#### getppid(void) --> is a system call in Unix-like operating systems that retrieves the parent process ID (PPID) of the calling process and it also doesnot accept any argument at getpid.
```bash
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("My parent's PID is: %d\n", getppid());
    return 0;
}
```

#### kill(pid, signal) --> is a system call used to send a signal to a process or a group of processes.
#### It can be used to terminate or send other signals to a process based on the signal number provided

```bash
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    kill(pid, SIGTERM); // Terminates the current process
    return 0;
}
```
#### sleep("number of seconds") --> is a function that causes the current thread to sleep for a specified number of seconds.

```bash 
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Sleeping for 5 seconds...\n");
    sleep(5); // Sleeps for 5 seconds
    printf("Woke up after sleeping.\n");
    return 0;
}
```
#### fork() --> is a system call that creates a new process by duplicating the calling process.
#### After a successful fork(), two identical processes are created: the parent process and the child process.

``` bash
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process\n");
    } else if (pid > 0) {
        printf("Parent process\n");
    } else {
        fprintf(stderr, "Error in forking\n");
    }
    return 0;
}
```
#### exit() is a library function used to terminate the calling process
```bash
#include <stdlib.h>

int main() {
    // Some program logic...

    if (/* Some condition for error */) {
        // Error occurred, terminate program with non-zero status
        exit(1);
    }

    // Otherwise, exit program normally with zero status
    exit(0);
}
```

#### signal() function is used to establish signal handlers for specific signals.

```bash
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Received SIGINT signal\n");
    // Perform any necessary actions in response to the signal
}

int main() {
    // Registering SIGINT handler
    signal(SIGINT, sigint_handler);

    // Your program logic goes here
    // ...

    return 0;
}
```

#### sigemptyset():
##### This function initializes an empty signal set.
##### It clears all signals from the given signal set.
##### It takes a pointer to a sigset_t data structure, which represents the set of signals.
```baah
#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t set;
    // Initialize an empty signal set
    sigemptyset(&set);

    // Now 'set' represents an empty signal set
    // You can add signals to it using sigaddset() if needed

    return 0;
}
```

#### sigaddset():
##### This function adds a specified signal to the given signal set.
##### It allows you to specify which signals you want to include in the signal set.
##### It takes two arguments: a pointer to a sigset_t data structure representing the signal set, and the signal number you want to add to the set
```bash
#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t set;
    // Initialize an empty signal set
    sigemptyset(&set);

    // Add SIGINT and SIGTERM to the signal set
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGTERM);

    // Now 'set' contains SIGINT and SIGTERM signals
    // You can use sigismember() to check if a signal is in the set

    return 0;
}
```

#### sigaction():
##### This function is used to change the action taken by a process upon receipt of a specific signal.
##### It allows you to specify a new signal handler function for a given signal.
```bash
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function for SIGINT
void sigint_handler(int signum) {
    printf("Received SIGINT signal\n");
    // Perform any necessary cleanup actions
    // Terminate the program
    exit(EXIT_SUCCESS);
}

int main() {
    // Set up signal handler for SIGINT using sigaction
    struct sigaction sa;
    sa.sa_handler = sigint_handler; // Specify the handler function
    sigemptyset(&sa.sa_mask);       // Clear the signal mask during handling
    sa.sa_flags = 0;                // No special flags

    // Register the handler for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Main program loop
    while (1) {
        // Your program logic goes here
        // In this example, we just sleep indefinitely
        sleep(1);
    }

    return 0;
}
```

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone https://github.com/mazen-tech/minitalk.git
```

#### 2º - Enter the project folder and run `make`
```bash
cd minitalk/minitalk
make
```

#### 3º - Run server or server_bonus and copy its PID
```bash
./server
./server_bonus
```

#### 4º - Open another terminal, run client or client_bonus, paste the PID and write a message
```bash
./client [SERVER PID] [MESSAGE]
./client_bonus [SERVER PID] [MESSAGE] [EMOTE]
```

#### MAKEFILE RULES

`make` - Compile minitalk **mandatory** files.

`make bonus` - Compile minitalk **bonus** files.

`make all` - Compile **mandatory** + **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
- [x] Produce server and client executables.
- [x] The Client must communicate a string passed as a parameter to the server (referenced by its process ID) and display it.
- [x] Use `SIGUSR1` and `SIGUSR2` signals only.

## BONUS
- [x] Add reception acknowledgement system.
- [x] Support Unicode characters.
