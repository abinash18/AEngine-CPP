# TODO

- There is a issue with MOUSE_MOVED in Event.h where there is a similar macro defined in Windows.h and i had to rename the enum to MouseMoved which dose not fit the enum code style. 
- Write Events with a buffer and non blocking.

## Important
- Let the user have full control over the main function of the program, make a secondary entry point to the engine, maybe some functions like 
    ```C++
    start()
    
    stop()
    
    
    ```