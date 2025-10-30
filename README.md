# software-systems-projects
Projects I've made for a software systems class at McGill University (Fall 2024)

# Assignment 1 - Learning CLI

* Using linux terminal, learned how to traverse through directories and edit files with `Vim`.
* Cloned lecture notes via `Git` and practiced git commands like `add` and `commit`.
* Set up file transfer to/from remote linux server (`rsync/SSH`) and documented the workflow.

# Assignment 2 - Automating Developer Tasks

* Practiced scripting with `Bash` (shebangs, status-code checks, redirection, positional parameters):
    1. Automated backing up assignments into a tar, including a save timestamp `backups/assignments-YYYY-MM-DDTHH:MM:SS.tar.gz` via `backup-hmk`.
    2. Automated the download of assignment repos with `git clone` into this repo via `get-assignment`.
* Learned `tar` basics and documented usage in `using-tar.txt`.

# Assignment 3 - CSV Analysis

* Created script to analyze CSV data using bash features like `grep`, `cut`, and `pipelining` for correct data collection and dissection.
* Emphasized function efficiency and reusability for operations (i.e. count, total, rows-for, sum).
* Validated inputs and handled edge cases to avoid error.
* Produced `all-averages` to make a sorted list of countries with average city population using points mentioned above.

# Assignment 4 - Bash Practice

* Parsed real web server logs (`jerrington.me.log`) with `./analyze`, creating many subcommands for analysis (i.e. unique IP requests per day, most popular posts, etc.).
* Learned to filter noisy/hostile requests, focusing on status codes and paths instead.
* Gained experience dealing with recursion, text processing, and CLI UX.

# Assignment 5 - Calculator in C

* Built a calculator with operations like squareroot, find gcd, and anagram, with strict input validation and error handling.
* Gained experience dealing with `stderr`, `stdout`, and exit codes.
* Created a `build` script that automates test cases and compiles with flags like `-Wall` and `-lm`.

# Assignment 6 - Improved Calculator

* Improved testing by creating a new test suite, `run-tests`, using the `it` function, capturing: name, expected exit code, expected stdout/stderr, and inputs.
* Implemented a `Makefile` with proper dependencies and a PHONY `test` target that builds `minicalc` if needed and runs `run-tests` (instead of the build script from A5).
* Built a dynamic string builder in C (`stringbuilder.c/.h`), which taught me how to work with dynamic memory and resource management, resizing, and custom string operations (build, copy, delete).

# Assignment 7 - Chat Application

* Engineered a multi-client `TCP` chat server in C that broadcasts messages in real time, using `socket/bind/listen/accept` with effective error handling.
* Implemented nonblocking I/O with `fcntl(O_NONBLOCK)` and an event-driven polling loop, eliminating blocking on accept() and reads.
* Added capacity controls (room-full handshake + close) and defensive parsing to mitigate malformed input.
* Built a repeatable test harness and scripts to simulate concurrent users.

# Assignment 8 - Information Security

* Completed a crypto theory module, detailing the CIA triad analyses, Diffie-Hellman key exchange, RSA authentication, and MAC design.
* Undertook hacking challenges (both CTF style):
    1. Performed an `injection` attack on a vulnerable calculator webpage with arbritrary commands.
    2. Performed a `reverse-engineer / buffer-overflow` attack on a C login program with `GDB` and designed an overflow input to give me admin privileges.
* Learned how to write post-exploitation writeups (root cause, impact, and mitigations).

# Bonus Project - News Scraper

* Practiced real-world webscraping skills with Bash by scraping Hacker News front page(s) with using `curl` and targeted `regex`.
*  Created tool-ready CSV with proper quoting (commas/quotes/newlines) for clean import into Excel/pandas/etc.
* Handled `HTML` quirks by using its stable page structure and writing regex with guards.