# task
A task is a program that runs inside of the RTOS. The task runs inside of a dedicated stack.

## Features
* Creates a node for the scheduler
* Stores a priority
* Creates the right size stack
* Stores it's own state so when stopped it can be stopped
* Can be resumed externally

## Test list
* Creates a node with a pointer to itself
* Stores priority
