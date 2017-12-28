#ifndef ECRAN_H 
#define ECRAN_H 

#include <iostream>
#include "Pos.hpp"
#include "Pixel.hpp"
#include "RGB.hpp"
#include "Visible.hpp"
#include "Segment.hpp"
#include <math.h>

class Ecran
{
	Pos gh,dh,gb;
	int resolution;
	Pixel** pixel;

	public :
	Ecran(){};
	Ecran(Pos gh1, Pos dh1, Pos gb1, int res): gh(gh1),dh(dh1), gb(gb1), resolution(res) 
	{ 
		RGB c;
		pixel = new Pixel*[resolution];
		for(int i=0; i<resolution;i++)
		{
			pixel[i] = new Pixel[resolution];
		}
	}
	void afficher(std::ostream &flux) const;
	void initEcran(RGB backgroundColor);
	void drawImage(Pos posCam, std::vector<Visible*>* obj);
	Pos getPosAt(int x, int y);
	Pixel** getPixel() {return pixel;}
	int getResolution(){return resolution;}
};

Pos Ecran::getPosAt(int x, int y)  
{
    float r = resolution;
 
    Pos p(gh.getX() + (x/r)*(dh.getX() - gh.getX())
                + (y/r)* (gb.getX() - gh.getX()),
            gh.getY() + (x/r)*(dh.getY() - gh.getY())
                + (y/r)* (gb.getY() - gh.getY()),
            gb.getZ() + (x/r)*(dh.getZ() - gb.getZ())
                + (y/r)* (gb.getZ() - gb.getZ()));
    return p;
}

void Ecran::initEcran(RGB backgroundColor)
{
	for(int i=0; i<resolution;i++)
	{
		for(int j=0; j<resolution;j++)
		{
			pixel[i][j].setColor(backgroundColor);
			pixel[i][j].setPosition(getPosAt(i,j));
		}
	}
}

void Ecran::drawImage(Pos posCam, std::vector<Visible*>* obj)
{
	for(int i=0; i<resolution;i++)
	{
		for(int j=0; j<resolution;j++)
		{
			int distanceAvecPixel=-1;
			Intersection inter;

			Segment s(posCam,pixel[i][j].getPosition());
			for(std::vector<Visible*>::iterator o = obj->begin() ; o != obj->end(); ++o)
			{
				Intersection* interTemp = (*o)->estTraverse(s);
				if(interTemp != NULL)
				{
					int d = s.getOrigine().distanceAvecPoint(interTemp->getOrigine());
					if(distanceAvecPixel > d)
					{
						inter = *interTemp;
						distanceAvecPixel = d;
					}
				}
				delete interTemp;
			}
			if(distanceAvecPixel!=-1)
			{
				pixel[i][j].setColor(inter.getColor());
			}
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