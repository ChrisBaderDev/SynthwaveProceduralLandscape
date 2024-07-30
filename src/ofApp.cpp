#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
	ofSetWindowTitle(Constants::WINDOW_TITLE);
	ofBackground(Constants::BACKGROUND_COLOR);
	ofSetFrameRate(Constants::FRAMERATE);
	ofEnableDepthTest();

	// Setup Camera
	this->cam.setPosition(glm::vec3(0, 0, Constants::PLANE_WIDTH * 0.4));
	this->cam.lookAt(Constants::SCENE_CENTER);

	// Setup Light
	this->sun = Sun(Constants::SUN_RADIUS, Constants::SUN_RESOLUTION, Constants::SCENE_CENTER);
	this->sun.setLightCount(8);
	this->sun.setTopColor(Constants::SUN_TOP_COLOR);
	this->sun.setBottomColor(Constants::SUN_BOTTOM_COLOR);
	this->sun.setLightDiffuseColor(ofColor::white);
	this->sun.setLightSpecularColor(ofColor::white);

	// Setup Landscape
	this->plane = Plane(Constants::PLANE_WIDTH, Constants::PLANE_HEIGHT, Constants::PLANE_SCALE, ofColor(50, 10, 66));
	this->plane.setHeightAmplitude(Constants::PLANE_AMPLITUDE);
	this->plane.setFlyingSpeed(Constants::FLYING_SPEED);
	this->plane.setColor(Constants::PLANE_COLOR);
	this->plane.setWireframeColor(Constants::PLANE_WIREFRAME_COLOR);
}
//--------------------------------------------------------------
void ofApp::update(){
	this->plane.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();
	this->sun.enable();
	ofDrawAxis(50);
	ofBackground(Constants::BACKGROUND_COLOR);
	ofSetLineWidth(1);
	ofFill();

	ofPushMatrix();
	ofRotateXDeg(280);
	ofTranslate(-Constants::PLANE_WIDTH / 2, -Constants::PLANE_HEIGHT / 2, 0);
	this->plane.draw();
	this->plane.drawWireframe();
	ofPopMatrix();

	ofPushMatrix();
	ofTranslate(glm::vec3(0, Constants::SUN_RADIUS, (- Constants::PLANE_WIDTH / 2) - Constants::SUN_RADIUS));
	this->sun.draw();
	ofPopMatrix();

	this->sun.disable();
	this->cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}