#include "ofApp.h"
#include "ofxInkSim.h"
#include "ofxMoodMachine.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ResetTime = 0;
    
    //title at top of screen
    ofSetWindowTitle("Project1_GenerativeArt");
    
    //background
    //ofBackground(0, 0, 0);
    
    //ink drawing setup
    inkSim.setup();
    moodmachine.setSpeed(2.0);
    
    BaseX = ofGetWidth()/2;
    BaseY = ofGetHeight()/2;
    NoiseY = 0.025;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    inkSim.update();
    
    // calc position within the window
    //PosX = ofNoise(NoiseX) * ofGetWidth();
    //PosY = ofNoise(NoiseY) * ofGetHeight();
    
    //random noise instead of calculation
    PosX = ofRandom(ofGetWidth());
    PosY = ofRandom(ofGetHeight());
    
    
    NoiseX = NoiseX + 0.0005; // how much to move each frame
    NoiseY = NoiseY + 0.0002;
    
    if (ofGetElapsedTimeMillis() - ResetTime > 10000) {
        inkSim.clear();
        ResetTime = ofGetElapsedTimeMillis();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //start Ink Simulation
    inkSim.draw();
    
    //set color, start drawing according to noise generation
    ofColor c = moodmachine;
    inkSim.stroke(&brush, PosX, PosY, getInkColor(c.getHueAngle(), 255, 10));
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == '1')
    {
        inkSim.setDrawMode(ofxInkSim::INKFIX);
    }
    else if (key == '2')
    {
        inkSim.setDrawMode(ofxInkSim::INKSURF);
    }
    else if (key == '3')
    {
        inkSim.setDrawMode(ofxInkSim::INKFLOW);
    }
    else if (key == '4')
    {
        inkSim.setDrawMode(ofxInkSim::WATERFLOW);
    }
    else if (key == 'd')
    {
        inkSim.toggleDebug();
    }
    else if (key == 'c')
    {
        inkSim.clear();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    //ofColor c = moodmachine;
    //inkSim.stroke(&brush, x, y, getInkColor(c.getHueAngle(), 255, 10));
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    inkSim.stopStroke(&brush);
    
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
