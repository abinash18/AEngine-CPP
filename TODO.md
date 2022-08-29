# TODO

- There is a issue with MOUSE_MOVED in Event.h where there is a similar macro defined in Windows.h and i had to rename the enum to MouseMoved which dose not fit the enum code style.
- Write Events with a buffer and non blocking.

## Important

- Let the user have full control over the main function of the program, make a secondary entry point to the engine, maybe some functions like
```C++
start();
stop();
```
- Create a engine wide interface to implement these methods:

```cpp
class Renderable { /* Idk what to call it.*/
    public:
        virtual void update(float _delta) = 0;
        virtual void render() = 0;
        virtual void input(float _delta) = 0;
}
```

- Create a interface for components with a transform matrix.

```cpp
class TransformableComponent {
    public: 
        glm::mat4& getTransform() {
            // Idk if i want this to be able to change the transform.
            return transform;
        } 
    private: 
        Transform transform;
}
```

- Alias `glm::` with AEngine types. like 
```cpp
using Matrix4f = glm::mat4;
// or
using mat4 = glm::mat4;
```
