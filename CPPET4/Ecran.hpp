#ifndef ECRAN_H 
#define ECRAN_H 

#include <iostream>
#include "Pos.hpp"
#include "Pixel.hpp"
#include "RGB.hpp"

class Ecran
{
	Pos gh,dh,gb;
	int resolution;
	Pixel** pixel;

	public :
	Ecran(){};
	Ecran(Pos gh1, Pos dh1, Pos gb1, int res): gh(gh1),dh(dh1), gb(gb1), resolution(res) 
	{ 
		pixel = new Pixel*[resolution];
		for(int i=0; i<resolution;i++)
		{
			pixel[i] = new Pixel[resolution];
		}
	}
	void afficher(std::ostream &flux) const;
	void initColorEcran(RGB backgroundColor);
	Pixel** getPixel() {return pixel;}
	int getResolution(){return resolution;}
};

void Ecran::initColorEcran(RGB backgroundColor)
{
	for(int i=0; i<resolution;i++)
	{
		for(int j=0; j<resolution;j++)
		{
			pixel[i][j].setColor(backgroundColor);
		}
	}
}
void Ecran::afficher(std::ostream &flux) const
{
    flux << "Ecran : DH :" << dh << " GH :" << gh << " GB :" << gb << " Resolution : [" << resolution << "]";
}

std::ostream &operator<<(std::ostream &flux, Ecran const& e)
{
    e.afficher(flux);
    return flux;
}


#endif