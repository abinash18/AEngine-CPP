#pragma once

namespace AEngine {
    class SceneComponent {
        virtual void update(float _delta) = 0;
        virtual void render() = 0;
        virtual void input(float _delta) = 0;
    };
}
