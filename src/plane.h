#pragma once
#include "ofMain.h"

class Plane
{
public:
	Plane();
	Plane(int width, int height, int scale, ofColor color);

	void setup();
	void update();
	void draw();
	void drawWireframe();
	void clear();


	void setWidth(int width);
	int getWidth() const;
	void setHeight(int height);
	int getHeight() const;
	void setScale(int scale);
	int getScale() const;
	void setHeightAmplitude(float heightAmplitude);
	int getHeightAmplitude() const;
	void setFlyingSpeed(float flyingSpeed);
	int getFlyingSpeed() const;
	void setColor(ofColor color);
	ofColor getColor() const;
	void setWireframeColor(ofColor wireframeColor);
	ofColor getWireframeColor() const;

private:
	int width;
	int height;
	int scale;
	int rows;
	int columns;
	float flyingPosition;
	float flyingSpeed;
	float heightAmplitude;
	glm::vec3 position;
	ofVboMesh mesh;
	ofColor color;
	ofColor wireframeColor;
	std::vector<std::vector<float>> heightMap;

	void createMesh();
	void updateHeightMap();
	void updateMesh();
	void updateColors(ofFloatColor color);

};
