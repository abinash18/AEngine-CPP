#pragma once
#include <glm/glm.hpp>

#include "SceneComponent.h"

namespace AEngine {
    class Camera : public SceneComponent {
        public:
            Camera(float _fov, float _aspect_ratio, float _z_near, float _z_far);
            Camera(float _left, float _right, float _bottom, float _top, float _z_near, float _z_far);

            ~Camera();

            void recalculateViewMatrix();

            virtual void update(float _delta) override;
            virtual void render() override;
            virtual void input(float _delta) override;
        private:
            glm::mat4 projection;
            glm::mat4 view;
            glm::mat4 viewProjection;

            glm::vec3 position = { 0.0f, 0.0f, 0.0f };

            float rotation = 0.0f;
    };
}
