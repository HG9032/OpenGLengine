#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
private:
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 rotation = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);

public:
    void translate(glm::vec3 offset);
    void setPosition(glm::vec3 newPosition);

    void rotate(glm::vec3 angles);
    void setRotation(glm::vec3 newRotation);

    void setScale(glm::vec3 newScale);

    glm::mat4 getMatrix() const;
};