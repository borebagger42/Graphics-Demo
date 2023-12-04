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
    //initialize radius, color, and center variables

    Sphere(double xin, double yin, double zin, float radin) {//initialization of sphere
        //class initialization
    }

    float signedDistance(const vec3& origin) const {
        //calculate the distance from a given point (origin) to it's closest point on the sphere, retaining it's sign
    }
    
};

int main(int argc, const char* argv) {

    // a bunch of variable declarations
    

    
    while (getline(sceneFile, line)) { //read data from file object and put it into a string.
        //read in the scene file

        if (type == "image") { //all of these are if statements that initialize variables based on what the type of data input is
            //initialize proper variables if the first line of the scene file is an image
        }
        else if (type == "viewport") {
            //same thing but with viewport
        }
        else if (type == "eye") {
            //same thing but with eye
        }
        else if (type == "sphere") {
            //same thing but with sphere

        }
    }
    sceneFile.close(); //close scene file


    //create the image

    //iterate through each pixel{
                                    {    
            //calculate the coordinate of the pixel in global space

            //initialize some variables

            //loop while you haven't hit either of your maximums or an object {
                //loop through all the objects in the scene {
                    //calculate the signed distance;
                    //if there is a collision{
                        //break the loop and set the pixel color to blue
                    }
                    //if the calculated smallest signed distance is smaller than the last {
                        //update the smallest signed distance
                    }
                }
                //iterate the travel distance, and number of iterations, and move to the next spot on the ray according to the smallest signed distance
            }
            //update the image pixels
        }
    }

    //display the image
    return 0;
}
