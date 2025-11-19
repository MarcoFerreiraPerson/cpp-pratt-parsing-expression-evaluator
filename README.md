# cpp-pratt-parsing-expression-evaluator

A C++23 expression evaluator that uses Pratt parsing to evaluate mathematical expressions and variable assignments.

## Features

- Evaluates arithmetic expressions with proper operator precedence
- Supports basic operations: `+`, `-`, `*`, `/`
- Variable assignment and usage with the `=` operator
- Handles nested expressions with parentheses
- Built using Pratt parsing algorithm for efficient expression parsing

## How It Works

The evaluator processes expressions in three main stages:

1. **Lexing** - Tokenizes the input string into operators, numbers, and variables
2. **Parsing** - Uses Pratt parsing to build an expression tree respecting operator precedence
3. **Evaluation** - Traverses the expression tree (DFS) to compute the result

Variables are stored in a hash map and persist across multiple expression evaluations, allowing you to assign values and reuse them in subsequent expressions.

## Building and Running

### Build the project:
```bash
make
```

### Run the interactive REPL:
```bash
make run
```

### Clean build artifacts:
```bash
make clean
```

## Example Usage

The program launches an interactive REPL (Read-Eval-Print Loop) where you can enter expressions:

```
Expression Evaluator - Type 'exit' or 'quit' to end
Examples: a = 5, b = a * 2, 1 + 2 * 3
-------------------------------------------
>>> a = 2
= 2
>>> b = a * 67
= 134
>>> 1 + 2 * a + b
= 139
>>> exit
Goodbye!
```

### Supported Operations:
- **Assignment**: `x = 5`
- **Arithmetic**: `+`, `-`, `*`, `/`
- **Variables**: Use previously assigned variables in expressions
- **Parentheses**: `(2 + 3) * 4`
- **Exit**: Type `exit` or `quit` to close the REPL

## Requirements

- C++23 compatible compiler (clang++-20 or newer)
- libc++ standard library
- Make
