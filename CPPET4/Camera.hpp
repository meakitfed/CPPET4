#ifndef CAMERA_H 
#define CAMERA_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include "Objets.hpp"

class Camera : public Objets
{
	public :
	Camera() : Objets(){};
	void afficher(std::ostream &flux) const;
};

void Camera::afficher(std::ostream &flux) const
{
    flux << "Position Camera :" << position;
}

std::ostream &operator<<(std::ostream &flux, Camera const& cam)
{
    cam.afficher(flux) ;
    return flux;
}
#endif