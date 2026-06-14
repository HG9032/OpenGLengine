#pragma once
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transform.h"
#include "Mesh.h"

class Model {
private:
    std::vector<float> vert = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    std::vector<unsigned int> indices = { 0, 1, 2 };

    Mesh* mesh;
    
    glm::vec3 color = glm::vec3(1.0f);

public:
    Transform transform;
    const Shader& shader;

    Model(const Shader& shader, glm::vec3 position);
    ~Model();

    Mesh& getMesh() const;
    const Shader& getShader() const;
    void setMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

    void setColor(const glm::vec3& color);
    glm::vec3 getColor() const;
};