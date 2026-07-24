#  Simple Text Editor using Stack (C#)

A simple console-based text editor built with **C#** to demonstrate the use of the **Stack** data structure.

## Features

- Add new text
- Undo the last action
- Redo the last undone action
- Delete the last word
- Display the current text
- Menu-driven console interface

## 🛠 Technologies

- C#
- .NET Console Application
- Stack<T>

##  Data Structure

The project uses two stacks:

- **Undo Stack**: Stores previous text states.
- **Redo Stack**: Stores undone states to allow redo operations.

##  How It Works

1. Every time the text changes, the current state is pushed into the **Undo Stack**.
2. Performing **Undo** moves the current state to the **Redo Stack** and restores the previous state.
3. Performing **Redo** restores the latest undone state.
4. Adding new text clears the **Redo Stack**, just like real text editors.
5. Deleting the last word also supports Undo and Redo.

##  Example

```text
Current Text:
Hello World

1. Add Text
2. Undo
3. Redo
4. Delete Last Word
5. Exit
```

##  Learning Objectives

This project demonstrates:

- Stack operations (Push, Pop, Peek)
- Managing application states
- Implementing Undo/Redo functionality
- Console application development in C#
