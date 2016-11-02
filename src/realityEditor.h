#pragma once

//#include "ofMain.h"
//#include "ofxiOS.h"
//#include "ofxiOSExtras.h"

#include "ofxVuforia.h"
#include "ofxJSON.h"
#include "ofxNetwork.h"
#include "ofxXmlSettings.h"

//#include "ofxWKWebViewInterfaceJavaScript.h"
//#include "ofxUIWebViewInterfaceJavaScript.h"

#include "ofxWebViewInterface.h"

class realityEditor : public ofxVuforia_App, ofxWebViewDelegateCpp /*ofxWKWebViewDelegateCpp, ofxUIWebViewDelegateCpp*/ {
    
public:
    void setup();
    
    void update();
    
    void draw();
    
    void deviceOrientationChanged(int newOrientation);
    
    void exit();
    
    void renderJavascript();
    
    void downloadTargets();
    
    void cons();
    
    void urlResponse(ofHttpResponse &response);
    
    ofFile files_;
    ofxUDPManager udpConnection, udpConnection2;
    // HeartbeatListener* heartbeatListener;
    vector<vector<string> > nameCount;
    vector<vector<string> > targetsList;
    
    //    ofxWKWebViewInterfaceJavaScript interface;
    //    ofxUIWebViewInterfaceJavaScript interface;
    
    ofxWebViewInterfaceJavaScript interface;
    
    void handleCustomRequest(NSString *request);
    
    ofxJSONElement json;
    bool waitUntil;
    bool onlyOnce;
    bool waitGUI;
    char udpMessage[256];
    bool nameExists = false;
    bool targetExists = false;
    int numbersToMuch;
    
    string arrayList[3] = {"dat", "xml", "jpg"};
    
    int datasetHolder = 100000;
    
    ofxXmlSettings XML;
    ofxXmlSettings XMLTargets;
    
    int interfaceCounter = 0;
    string xmlStructure;
    
    ofHttpResponse ofSaveURLTo(string url, string path);
    
    ofBuffer dataBuffer;
    
    ofMatrix4x4 tempMatrix;
    vector<ofMatrix4x4> matrixTemp;
    vector<string> nameTemp;
    
    vector<Vuforia::DataSet *>  datasetList;
    
    float matrixOld = 0.0;
    
    int foundMarker;
    bool reloader = false;
    bool freeze = false;
    bool extendedTracking = false;
    bool frozeCameraImage = false;
    float cameraRatio = 1;
    
    ofFbo fbo;
    ofFbo fbo2;
    
    bool updateSwitch =true;
    
    ofImage cameraImage;
    
    ofImage imgInterface, imgObject;
    // NSMutableString *stringforTransform;
    
    //vector<ofxVuforia_Marker>tempMarker;
    bool projectionMatrixSend = false;
    
    NSString *pMatrix;
    
    NSMutableString *stringforTransform = [NSMutableString stringWithCapacity:2000];
    
    ofAppiOSWindow thisWindow =  *ofxiPhoneGetOFWindow();
    int screenScale = 1;
    
    int haveChangedUIwithURL = 0;
    bool changedURLOk = false;
    
    
    int developerState = 0;
    int extTrackingState = 0;
    int clearSkyState = 0;
    string externalState = "";
    
    bool sendAccelerationData = false;
    
    ofVec3f accel;
    ofVec2f orientation;
    bool inSync = false;
    
    bool everySecond = false;
    
    string lastTracker;
    
    int32_t crc32(const void* data, size_t length);
    long bitNumber (bool bits[21]);
    string itob62( long i );
    uint32_t crc = 0xffffffff;
    void crc32reset();
    
    ofFile file;
    ofBuffer buff;
    
    /* void touchDown(ofTouchEventArgs & touch);
     void touchMoved(ofTouchEventArgs & touch);
     void touchUp(ofTouchEventArgs & touch);
     void touchDoubleTap(ofTouchEventArgs & touch);
     void touchCancelled(ofTouchEventArgs & touch);*/
    
    /*  void lostFocus();
     void gotFocus();
     void gotMemoryWarning();
     void deviceOrientationChanged(int newOrientation);*/
    
    
};


