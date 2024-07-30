# include "sun.h";


//***************************************************************
//						 CONSTRUCTORS
//***************************************************************

Sun::Sun() {

}

Sun::Sun(float radius, float resolution, glm::vec3 position) {
	this->radius = radius;
	this->resolution = resolution;
	this->position = position;
	this->topColor = ofColor::white;
	this->bottomColor = ofColor::white;
	this->lightCount = 5;
	this->setup();
}

//***************************************************************
//						PUBLIC MEMBERS
//***************************************************************

void Sun::setup() {
	this->createMesh();
	this->addPointLights();
}

void Sun::update() {

}

void Sun::draw() {
	ofPushMatrix();
	ofTranslate(this->position);
	mesh.draw();
	ofPopMatrix();
}

void Sun::drawWireframe()
{
	ofPushMatrix();
	ofTranslate(this->position);
	ofSetColor(this->topColor);
	mesh.drawWireframe();
	ofPopMatrix();
}


void Sun::enable() {
	for (ofLight pointLight : this->pointLights) {
		pointLight.enable();
	}
}

void Sun::disable() {
	for (ofLight pointLight : this->pointLights) {
		pointLight.disable();
	}
}

void Sun::setPosition(glm::vec3 position){
	this->position = position;
}

void Sun::setLightCount(int lightCount){
	this->lightCount = lightCount;
}

void Sun::setLightDiffuseColor(ofColor diffuseColor) {
	for (ofLight pointLight : this->pointLights) {
		pointLight.setDiffuseColor(diffuseColor);
	}
}

void Sun::setLightSpecularColor(ofColor specularColor) {
	for (ofLight pointLight : this->pointLights) {
		pointLight.setDiffuseColor(specularColor);
	}
}

void Sun::setTopColor(ofColor topColor) {
	this->topColor = topColor;
	this->updateColors();
}

void Sun::setBottomColor(ofColor bottomColor) {
	this->bottomColor = bottomColor;
	this->updateColors();
}

//***************************************************************
//						PRIVATE MEMBERS
//***************************************************************

void Sun::createMesh() {
	this->mesh = ofMesh::sphere(this->radius, this->resolution, OF_PRIMITIVE_TRIANGLES);
	this->updateColors();
}

void Sun::addPointLights() {
	std::vector<glm::vec3> vertices = this->mesh.getVertices();
	int lightDensity = glm::round(vertices.size() / this->lightCount);
	for (int i = 0; i < vertices.size(); i++) {
		if (i % lightDensity == 0) {
			ofLight pointLight;
			pointLight.setPointLight();
			pointLight.setPosition(this->position + vertices[i] * 1.2);
			pointLight.setDiffuseColor(ofColor::white);
			this->pointLights.push_back(pointLight);
		}
	}
}


void Sun::updateColors() {
	std::vector<glm::vec3> vertices = this->mesh.getVertices();
	std::vector<ofFloatColor> colors(vertices.size());

	for (size_t i = 0; i < vertices.size(); ++i) {
		float heightFactor = (vertices[i].y + this->radius) / (2 * this->radius);
		colors[i] = this->bottomColor.getLerped(this->topColor, heightFactor);
	}

	this->mesh.clearColors();
	for (const auto& color : colors) {
		this->mesh.addColor(color);
	}
}

