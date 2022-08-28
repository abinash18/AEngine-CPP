# Render Graph
---

::: mermaid
flowchart TD
    RenderEngine[Render Engine] -->|Contains| RenderAPI[Current Rendering API]
    RenderEngine[Render Engine] -->|Contains| RenderCommand[Current Render Commands]

    WindowRender[Window Render] -->|Calls| RenderEngine[Render Engine Render]

:::

The user can extend the render engine to their desire. That means the render engine will contain the render function and the user can call the render commands in it. therefore there is no need for seperate render engines for each api.

This will allow for the render and update to be seperated and performed on different threads.