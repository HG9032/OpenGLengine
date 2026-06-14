#include "Transform.h"

void Transform::translate(glm::vec3 offset){
    position += offset;
}

void Transform::setPosition(glm::vec3 newPosition){
    position = newPosition;
}

void Transform::rotate(glm::vec3 angles){
    rotation += angles;
}

void Transform::setRotation(glm::vec3 newRotation){
    rotation = newRotation;
}

void Transform::setScale(glm::vec3 newScale){
    scale = newScale;
}

glm::mat4 Transform::getMatrix() const
{
    glm::mat4 model(1.0f);

    model = glm::translate(model, position);

    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    model = glm::scale(model, scale);

    return model;
}