📨 minitalk - 42 School Project

🧩 About the Project
minitalk is a project where you implement a simple client-server communication system using UNIX signals.

The goal is to send messages from a client program to a server program, one bit at a time, using only:

✔ SIGUSR1 — represents binary 1.
✔ SIGUSR2 — represents binary 0.

The project is a great introduction to:

UNIX signals and process communication.

Bitwise operations and data encoding.

Handling asynchronous communication in C.

⚒️ What You Have to Build
✅ A server that prints the received message.
✅ A client that sends a string to the server, character by character, bit by bit.
✅ Bonus (optional): Support for more complex features like sending acknowledgments or Unicode characters.

🎯 Learning Focus
Signal handling with signal() or sigaction().

Sending and receiving information via UNIX signals.

Bit manipulation and understanding data transmission at the binary level.

Working with getpid() to target specific processes.
