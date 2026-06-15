#include "Model.h"
#include "Transform.h"

Model::Model(const Shader& shader, glm::vec3 position)
    : shader(shader), mesh(new Mesh(defaultVert, defaultIndices))
{
    transform.setPosition(position);
}

Model::~Model()
{
    delete mesh;
}

Mesh& Model::getMesh() const
{
    return *mesh;
}

const Shader& Model::getShader() const
{
    return shader;
}

void Model::setMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
{
    delete mesh;
    vert = vertices;
    this->indices = indices;
    mesh = new Mesh(vertices, indices);
}

void Model::setColor(const glm::vec3& newColor)
{
    color = newColor;
}

glm::vec3 Model::getColor() const
{
    return color;
}