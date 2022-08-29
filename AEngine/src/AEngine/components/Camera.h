#pragma once
#include "SceneComponent.h"

namespace AEngine {
    class Camera : public SceneComponent {
        virtual void update(float _delta) override;
        virtual void render() override;
        virtual void input(float _delta) override;
        private:
            
    };
}
