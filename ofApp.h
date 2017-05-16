#pragma once

#include "ofMain.h"
#include "ofxInkSim.h"
#include "SampleBrush.h"
#include "ofxGui.h"
#include "ofxMoodMachine.h"

class ofApp : public ofBaseApp{
    
public:
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
    
    
    void ofxGuiSetFont(const string & fontPath,int fontsize, bool _bAntiAliased=true, bool _bFullCharacterSet=false, int        dpi=0);
    void ofxGuiSetBitmapFont();
    
    void ofxGuiSetHeaderColor(const ofColor & color);
    void ofxGuiSetBackgroundColor(const ofColor & color);
    void ofxGuiSetBorderColor(const ofColor & color);
    void ofxGuiSetTextColor(const ofColor & color);
    void ofxGuiSetFillColor(const ofColor & color);
    
    void ofxGuiSetTextPadding(int padding);
    void ofxGuiSetDefaultWidth(int width);
    void ofxGuiSetDefaultHeight(int height);
    
    float PosX, PosY; //position
    float BaseX, BaseY; //base position
    float NoiseX, NoiseY; // noise position animation variable
    float OffsetX; //how much +/- to move the pos
    long ResetTime; //keeps track of time re-set, milaseconds
    
    
private:
    
    ofxMoodMachine moodmachine;
    
    ofxInkSim inkSim;
    SampleBrush brush;
    
};
