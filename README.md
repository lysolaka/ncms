# NCMS

Secret No-Compromise Minesweeper project (shhhhh)

# Compiling
Run:
```
$ make <option=value> ...
```

# Makefile options
These features control only the compilation process and do not configure the source (for now at least)
1. DISPLAY
- cli - Compile only the CLIDisplay into the binary
- cli_debug - Compile only the CLIDebugDisplay
- cli_both - Compile both CLI displays (recommended)

2. CONTROLLER
- cli - Compile only the CLIController

3. COLOR
- true - Enable coloured CLI output
- false - Disable colour output
