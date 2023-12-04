#include <iostream>
#include <string>
#include "C:\Users\jogam\Documents\School Stuff\Computer Graphics\Machine Learning and Soft Computing project\Machine Learning and Soft Computing project\CImg.h"
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <conio.h>


#include <C:\Users\jogam\Documents\School Stuff\Computer Graphics\CG A2\CG A2\glm\glm.hpp>
#include <C:\Users\jogam\Documents\School Stuff\Computer Graphics\CG A2\CG A2\glm/gtc/matrix_transform.hpp>
#include <C:\Users\jogam\Documents\School Stuff\Computer Graphics\CG A2\CG A2\glm/gtc/type_ptr.hpp>




using namespace cimg_library;
using namespace std;
using namespace glm;


class Sphere { //sphere class
public:
    vec3 center;
    float radius = 1;
    vec3 color;

    Sphere(double xin, double yin, double zin, float radin) {//initialization of sphere
        center = vec3(xin, yin, zin);
        radius = radin;
        color = vec3(0.0f, 0.0f, 1.0f);
    }

    float signedDistance(const vec3& origin) const {
        return length(origin - center) - radius;
    }
    
};

int main(int argc, const char* argv) {

    fstream sceneFile;
    sceneFile.open("SceneDescription.txt", ios::in);
    string line;
    
    vector<Sphere> spheres;
    int x, y;
    int maxWidth;
    int maxHeight;
    vec3 eye, viewOrigin, viewUp, viewRight;
    float maxDistance = 100.0f;
    int maxIterations = 100;
    float delta = 0.001f;
    

    
    while (getline(sceneFile, line)) { //read data from file object and put it into string.
        string type;
        stringstream ssl(line);
        getline(ssl, type, ' '); //reads in the first word of the line and sets that as the type

        if (type == "image") { //all of these are if statements that initalize variables based on what the type of data input is
            string a, b;
            getline(ssl, a, ' ');
            maxWidth = stod(a);
            getline(ssl, b, ' ');
            maxHeight = stod(b);
        }
        else if (type == "viewport") {
            string a, b, c, d, e, f, g, h, i;

            getline(ssl, a, ' ');
            viewOrigin.x = stof(a);
            getline(ssl, b, ' ');
            viewOrigin.y = stof(b);
            getline(ssl, c, ' ');
            viewOrigin.z = stof(c);
            getline(ssl, d, ' ');
            viewRight.x = stof(d);
            getline(ssl, e, ' ');
            viewRight.y = stof(e);
            getline(ssl, f, ' ');
            viewRight.z = stof(f);
            getline(ssl, g, ' ');
            viewUp.x = stof(g);
            getline(ssl, h, ' ');
            viewUp.y = stof(h);
            getline(ssl, i, ' ');
            viewUp.z = stof(i);
        }
        else if (type == "eye") {
            string a, b, c;

            getline(ssl, a, ' ');
            eye.x = stof(a);
            getline(ssl, b, ' ');
            eye.y = stof(b);
            getline(ssl, c, ' ');
            eye.z = stof(c);
        }
        else if (type == "sphere") {
            string a, b, c, d;
            float x, y, z, rad;

            getline(ssl, a, ' ');
            x = stod(a);
            getline(ssl, b, ' ');
            y = stod(b);
            getline(ssl, c, ' ');
            z = stod(c);
            getline(ssl, d, ' ');
            rad = stof(d);

            Sphere sphereN(x, y, z, rad);
            spheres.push_back(sphereN);

        }
    }
    sceneFile.close(); //close scene file


    CImg<unsigned char> image(maxWidth, maxHeight, 1, 3, 0);

    for (y = 0; y < maxHeight; y += 1) {
        for (x = 0; x < maxWidth; x += 1) {
            vec3 pixel = vec3(x, y, viewOrigin.z);
            vec3 currentCoords = pixel;
            vec3 pixelColor(0, 0, 0);
            vec3 dir = normalize(pixel - eye);

            float traveledDistance = 0.0f;
            int iteration = 0;
            
            float smallestSignedDist = numeric_limits<float>::infinity();
            bool collisionFound = false;

            while (traveledDistance < maxDistance && iteration < maxIterations && !collisionFound) {
                for (const auto& sphere : spheres) {
                    float t = sphere.signedDistance(currentCoords);
                    if (t < delta) {
                        pixelColor = sphere.color;
                        collisionFound = true;
                    }
                    else if (t <= smallestSignedDist) {
                        smallestSignedDist = t;
                    }
                }
                traveledDistance += smallestSignedDist;
                iteration += 1;
              
                vec3 currentCoords = pixel + traveledDistance * dir;
            }
            image(x, y, 0) = static_cast<unsigned char>(pixelColor.x * 255);
            image(x, y, 1) = static_cast<unsigned char>(pixelColor.y * 255);
            image(x, y, 2) = static_cast<unsigned char>(pixelColor.z * 255); 
        }
    }

    image.display("resultImage.png");
    return 0;
}