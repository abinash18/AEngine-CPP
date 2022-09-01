#include "aepch.h"
#include "Camera.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace AEngine {

    Camera::Camera(float _fov, float _aspect_ratio, float _z_near, float _z_far) {
        projection     = glm::perspective(_fov, _aspect_ratio, _z_near, _z_far);
        view           = glm::mat4(1.0f);
        viewProjection = projection * view;
    }

    Camera::Camera(float _left, float _right, float _bottom, float _top, float _z_near, float _z_far) {
        projection     = glm::ortho(_left, _right, _bottom, _top, _z_near, _z_far);
        view           = glm::mat4(1.0f);
        viewProjection = projection * view;
    }

    Camera::~Camera() {}

    void Camera::recalculateViewMatrix() {

        glm::mat4 transform = translate(glm::mat4(1.0f), position) *
                              rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));

        view           = inverse(transform);
        viewProjection = projection * view;

    }

    void Camera::update(float _delta) { }

    void Camera::render() {}

    void Camera::input(float _delta) {}

}
