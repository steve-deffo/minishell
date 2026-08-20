# Minishell

A Unix shell written in C as part of the 42 curriculum. It reproduces a practical subset of Bash while focusing on processes, file descriptors, parsing, signals, and memory safety.

## Features

- Interactive prompt and PATH resolution
- Built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Pipes and process chaining
- Input and output redirections
- Here-documents
- Environment-variable expansion
- Quote handling
- Exit-status propagation
- Interactive signal handling

## Build

```bash
git clone https://github.com/steve-deffo/minishell.git
cd minishell
make
./minishell
```

## Memory checks

```bash
valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
```

## Structure

- `srcs/` — shell implementation
- `includes/` — headers
- `libft/` — supporting C library
- `readline.supp` — Valgrind suppressions

This project develops a practical understanding of processes, inter-process communication, file descriptors, signals, parsing, and resource management.
