#pragma once
#include "ofMain.h"

class Sun {
	public:
		Sun();
		Sun(float radius, float resolution, glm::vec3 position);

		void setup();
		void update();
		void draw();
		void drawWireframe();

		void enable();
		void disable();

		void setPosition(glm::vec3);
		void setLightCount(int lightCount); // Max = 8;
		void setLightDiffuseColor(ofColor diffuseColor);
		void setLightSpecularColor(ofColor specularColor);
		void setTopColor(ofColor topColor);
		void setBottomColor(ofColor bottomColor);

	private:
		// Sun Variables
		float radius;
		float resolution;
		glm::vec3 position;
		ofColor topColor;				// Different colors for gradient effect
		ofColor bottomColor;
		int lightCount;

		// Construction Variables
		ofVboMesh mesh;
		std::vector<ofLight> pointLights;

		// Construction Methods
		void createMesh();
		void addPointLights();
		void updateColors();

};