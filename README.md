## ccRTOS - cross compiler real time operating system
This is me experimenting with creating a real time operating system and using test driven developement (TDD) techniques to get there. The rtos will support a full suit of test showing functionality and demonstrating usefulness. The goal is to make it easy for the user to understand what is going on without having to interogate functions that are 50+ lines. I am going to be starting simply by adding just the most basic features. Until I have a working system.


## goals
#### Short term
* ~Priority Queue~
* Timer
* Task
* Scheduler
  * readyQueue
  * waitingQueue
  * activeTask

#### Long Term
* Isolates Stacks
* Stack size management
* Semephores
* Mutex
* Queues
* Use macros to auto add all tasks to scheduler


