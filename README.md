# NCMS

Secret No-Compromise Minesweeper project (shhhhh)

Not so secret anymore, I honestly hope people will know how to use it.

For compilation instructions look at the [Compiling](https://git.kcir.pwr.edu.pl/ssztuka/ncms#compiling) section.

## IMPORTANT! - Running the binary

Users should run the SFML versions with the present working directory `$PWD` set to the root of the project. This is because SFML is pointed to assets in the ./assets/ directory. If one chooses to run the binary from somewhere else, they should copy the assets directory so that it will be in the `$PWD` directory.

*Example: Running a binary from the project root directory*
```
$ ./bin/sfml_sweeper
```

## Instructions
- For CLI modes, the instructions are displayed, and accessible throughout the game.
```
Syntax: <command> [column] [row]
Commands:
r - Reveal field,
f - Toggle flag,
h - Display help,
q - Force quit.
```
- For GUI modes, the keybindings are intuitive, field selection is done by hovering the mouse over a field:
```
LMB - Reveal field,
RMB - Toggle flag,
Q - Force quit (reveal all mines and wait for the user to close the window).
```

# Compiling

- To build all targets run:
```
$ make
```
- To build a specific taget run:
```
$ make <target>
```
Available targets:
1. `cli` - CLI minesweeper game
2. `cli_debug` - CLI minesweeper game with debug view
3. `sfml` - GUI minesweeper game
4. `sfml_debug` - GUI minesweeper game with debug view

## Make options

Usage:
```
$ make [<target>] <options>
```

- When building CLI targets it is possible to enable colour support with:
```
COLOR=true
```
- When building any target it is possible to enable compiler optimisation with:
```
OPTIMISE=true
```
- When building any target it is possible to allow to choose the DEBUG difficulty with:
```
ALLOW_DEBUG_MODE=true
```
