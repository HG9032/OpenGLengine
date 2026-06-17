#include "Camera.h"

Camera::Camera()
{
}

void Camera::translate(glm::vec3 offset)
{
    position += offset;
}

void Camera::setPosition(glm::vec3 newPosition)
{
    position = newPosition;
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio) const
{
    return glm::perspective(
        glm::radians(fov),
        aspectRatio,
        nearPlane,
        farPlane
    );
}
void Camera::moveForward(float amount)
{
    glm::vec3 flatFront = glm::normalize(glm::vec3(front.x, 0.0f, front.z));
    position += flatFront * amount;
}

void Camera::moveBackward(float amount)
{
    glm::vec3 flatFront = glm::normalize(glm::vec3(front.x, 0.0f, front.z));
    position -= flatFront * amount;
}

void Camera::moveLeft(float amount)
{
    position -= right * amount;
}

void Camera::moveRight(float amount)
{
    position += right * amount;
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(
        position,
        position + front,
        up
    );
}

void Camera::rotate(float yawOffset, float pitchOffset)
{
    yaw += yawOffset;
    pitch += pitchOffset;

    if (pitch > 89.0f)
        pitch = 89.0f;

    if (pitch < -89.0f)
        pitch = -89.0f;

    updateVectors();
}

void Camera::updateVectors()
{
    glm::vec3 direction;

    direction.x =
        cos(glm::radians(yaw))
        * cos(glm::radians(pitch));

    direction.y =
        sin(glm::radians(pitch));

    direction.z =
        sin(glm::radians(yaw))
        * cos(glm::radians(pitch));

    front = glm::normalize(direction);

    right =
        glm::normalize(
            glm::cross(
                front,
                glm::vec3(0.0f, 1.0f, 0.0f)
            ));

    up =
        glm::normalize(
            glm::cross(
                right,
                front
            ));
}