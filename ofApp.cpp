#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	for (int x = -150; x <= 150; x += 150) {

		for (int y = -150; y <= 150; y += 150) {

			this->drawNoiseBox(glm::vec3(x, y, 0), 80);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::drawNoiseBox(glm::vec3 location, int length) {

	ofPushMatrix();
	ofTranslate(location);

	int size = 20;
	for (int x = -length * 0.5; x <= length * 0.5; x += size) {

		for (int y = -length * 0.5; y <= length * 0.5; y += size) {

			for (int z = -length * 0.5; z <= length * 0.5; z += size) {

				auto box_location = glm::vec3(x, y, z);
				auto noise_value = ofNoise(location.x + x * 0.005, location.y + y * 0.005, location.z + z * 0.005, ofGetFrameNum() * 0.005);

				ofNoFill();
				ofSetColor(39);
				ofDrawBox(box_location, size * 0.9);

				if (noise_value > 0.5) {

					ofFill();
					ofSetColor(239);
					ofDrawBox(box_location, size * 0.88);
				}
			}
		}
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}