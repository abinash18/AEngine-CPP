<h1 align="center"> Code Style for AEngine-CPP </h1> 

---
#### Includes:
Header files should use this as a template to includes.
```cpp
#include <...> // The system's included headers should be placed at the top.

#include "..." // Whatever the user needs to include should be done after.
```
---
### Headers:
When writing for the engine all header files should enclose all definitions in the AEngine namespace.
```cpp
namespace AEngine {
    // ...
}
```
---

### Classes
Seperate class definitions and method implementations in headers and source files.

#### Class in Header:
```cpp
// Includes
namespace AEngine {
    class <...> {
        public:
            // Constructor
            // Then Destructor
            // Public variables should be described first.

            // Then public methods.

            // Getters and Setters should be defined in header if only one line and at the bottom of public or private feilds.
        private:
            // Private variables should be defined first

            // Then private methods.
    }
}
```
---
```cpp
#pragma once
#include "AEngine/render/api/Buffer.h"

namespace AEngine {
    class BufferOGL : public Buffer {
        public:
            virtual      ~BufferOGL() override = default;
            virtual void bind() const override;
            virtual void unBind() const override;
            void         destroy() override;
        protected:
            uint32_t id;
            uint32_t type;
    };
}
```

```cpp
#include <aepch.h>
#include "BufferOGL.h"

#include "glad/glad.h"

namespace AEngine {
    void BufferOGL::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }

    void BufferOGL::unBind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    //TODO: idk
    void BufferOGL::destroy() {

    }
}

```