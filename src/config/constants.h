#pragma once

#include "ofMain.h"

namespace Constants {


	// Window Values
	constexpr int WINDOW_WIDTH = 1200;
	constexpr int WINDOW_HEIGHT = 1000;
	const string WINDOW_TITLE = "Generative Landscape";

	// Graphic Settings
	constexpr int FRAMERATE = 60;

	// Colors
	const ofColor BACKGROUND_COLOR = ofColor(0, 0, 0);
	const ofColor SUN_TOP_COLOR = ofColor(255, 0, 0);
	const ofColor SUN_BOTTOM_COLOR = ofColor(229, 118, 0);
	const ofColor PLANE_COLOR = ofColor(37, 0, 63);
	const ofColor PLANE_WIREFRAME_COLOR = ofColor(45, 85, 173);

	// Scene variables
	constexpr glm::vec3 SCENE_CENTER = glm::vec3(0, 0, 0);
	constexpr int PLANE_SCALE = 30;
	constexpr int PLANE_WIDTH = 1000;
	constexpr int PLANE_HEIGHT = 800;
	constexpr int PLANE_AMPLITUDE = 100;
	constexpr int SUN_RESOLUTION = 32;
	constexpr int SUN_RADIUS = 250;
	constexpr float FLYING_SPEED = 0.01;
	
}