#pragma once
#include "Model.h"
#include <glm/gtc/type_ptr.hpp>

class Render {
public:
	void clear();
	void draw(const Model& model);
};