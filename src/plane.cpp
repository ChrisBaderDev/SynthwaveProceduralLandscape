#include "plane.h"

//***************************************************************
//						 CONSTRUCTORS
//***************************************************************

Plane::Plane()
{
}

Plane::Plane(const int width, const int height, const int scale, const ofColor color)
{
	this->width = width;
	this->height = height;
	this->scale = scale;
	this->color = color;
	this->setup();
}


//***************************************************************
//					   PUBLIC FUNCTIONS
//***************************************************************

void Plane::setup()
{
	this->rows = std::round(this->height / this->scale);
	this->columns = std::round(this->width / this->scale);
	this->flyingPosition = 1;
	this->flyingSpeed = 0.01;
	this->mesh.setMode(OF_PRIMITIVE_TRIANGLES);
	this->heightMap.resize(columns, std::vector<float>(rows, 0.0f));
	this->createMesh();
}

void Plane::update()
{
	this->updateHeightMap();
	this->updateMesh();
}

void Plane::clear()
{
	this->mesh.clear();
}

void Plane::draw()
{
	this->updateColors(this->color);
	this->mesh.draw();
}

void Plane::drawWireframe()
{
	this->updateColors(this->wireframeColor);
	this->mesh.drawWireframe();
}

void Plane::setWidth(const int width)
{
	this->width = width;
}

int Plane::getWidth() const
{
	return this->width;
}

void Plane::setHeight(int height)
{
	this->height = height;
}

int Plane::getHeight() const
{
	return this->height;
}

void Plane::setScale(int scale)
{
	this->scale = scale;
}

int Plane::getScale() const
{
	return this->scale;
}

void Plane::setHeightAmplitude(float heightAmplitude)
{
	this->heightAmplitude = heightAmplitude;
}

int Plane::getHeightAmplitude() const
{
	return this->heightAmplitude;
}

void Plane::setFlyingSpeed(float flyingSpeed)
{
	this->flyingSpeed = flyingSpeed;
}

int Plane::getFlyingSpeed() const
{
	return this->flyingSpeed;
}

void Plane::setColor(ofColor color)
{
	this->color = color;
}

ofColor Plane::getColor() const
{
	return this->color;
}

void Plane::setWireframeColor(ofColor wireframeColor)
{
	this->wireframeColor = wireframeColor;
}

ofColor Plane::getWireframeColor() const
{
	return this->wireframeColor;
}


//***************************************************************
//					   PRIVATE FUNCTIONS
//***************************************************************

void Plane::createMesh()
{
	// Add Vertices to the Mesh
	for (int y = 0; y < this->rows; y++)
	{
		for (int x = 0; x < this->columns; x++)
		{
			this->mesh.addVertex(glm::vec3(x * this->scale, y * this->scale, this->heightMap[x][y]));
			this->mesh.addColor(ofColor(50, 11, 66));
		}
	}

	// Assign indices to the mesh for triangles
	for (int y = 0; y < this->rows - 1; y++)
	{
		for (int x = 0; x < this->columns - 1; x++)
		{
			int topLeft = x + y * this->columns;
			int topRight = (x + 1) + y * this->columns;
			int bottomLeft = x + (y + 1) * this->columns;
			int bottomRight = (x + 1) + (y + 1) * this->columns;

			// First triangle (top left, bottom left, top right) - counter-clockwise order
			this->mesh.addIndex(topLeft);
			this->mesh.addIndex(bottomLeft);
			this->mesh.addIndex(topRight);

			// Second triangle (top right, bottom left, bottom right) - counter-clockwise order
			this->mesh.addIndex(topRight);
			this->mesh.addIndex(bottomLeft);
			this->mesh.addIndex(bottomRight);
		}
	}
}

void Plane::updateHeightMap()
{
	this->flyingPosition += this->flyingSpeed;
	float yOff = this->flyingPosition;
	for (int y = 0; y < this->rows - 1; y++)
	{
		float xOff = 0;
		for (int x = 0; x < this->columns - 1; x++)
		{
			float noiseValue = ofNoise(xOff, yOff);
			noiseValue = std::pow(noiseValue, 5);
			this->heightMap[x][y] = ofMap(noiseValue, 0, 1, 0, this->heightAmplitude);
			xOff += 0.08;
		}
		yOff += 0.12;
	}
}

void Plane::updateMesh()
{
	std::vector<glm::vec3> vertices = this->mesh.getVertices();
	for (int y = 0; y < this->rows; y++)
	{
		for (int x = 0; x < this->columns; x++)
		{
			vertices[x + y * this->columns].z = this->heightMap[x][y];
		}
	}
	this->mesh.getVbo().updateVertexData(vertices.data(), vertices.size());
}


void Plane::updateColors(ofFloatColor color)
{
	std::vector<ofFloatColor> colors = this->mesh.getColors();
	for (int y = 0; y < this->rows; y++)
	{
		for (int x = 0; x < this->columns; x++)
		{
			colors[x + y * this->columns] = color;
		}
	}
	this->mesh.getVbo().updateColorData(colors.data(), colors.size());
}
