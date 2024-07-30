#pragma once

#include "ofMain.h"
#include "config/constants.h"
#include "sun.h"
#include "plane.h"

class ofApp : public ofBaseApp{

	public:
		// OF Functions
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		std::vector<std::vector<float>> heightMap;
		ofEasyCam cam;
		ofMesh mesh;
		float flying = 0;

		// Lighting
		Sun sun;
		Plane plane;
};
