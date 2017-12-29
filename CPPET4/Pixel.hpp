#ifndef PIXEL_H
#define PIXEL_H

#include "RGB.hpp"
#include "Visible.hpp"
#include "Pos.hpp"
#include "Intersection.hpp"
#include "Segment.hpp"

class Pixel 
{
	Pos position;
	RGB couleur;

	public :
	Pixel() {};
	Pixel(Pos p, RGB c) : position(p), couleur(c) {};
	RGB getColor(){return couleur;}
	void setColor(RGB c){couleur=c;}
	Pos getPosition(){return position;}
	void setPosition(Pos p){position=p;}

/*
	//peutetre transformer des trucs en pointeurs
	RGB calculCouleurPrim(Segment s, RGB src, Intersection inter, Lobjets){
		Segment source(inter, source.pos);
		if (testObstacle(source) == null)
		{
			RGB couleurCalculee;
			couleurCalculee.R = Math.cos(s.calculAlpha(inter.normale))*inter.color.R*src.R;
			couleurCalculee.G = Math.cos(s.calculAlpha(inter.normale))*inter.color.G*src.G;
			couleurCalculee.B = Math.cos(s.calculAlpha(inter.normale))*inter.color.B*src.B;
			return couleurCalculee;
		}

		else
		{
			RGB couleurCalculee(0,0,0);
			return couleurCalculee;
		}
	}

	//moche d'avoir src en entrée, paske ça change jamais, src devrait être une var globale
	//et il faut rajouter le coeff de reflexion dans l'objet/intersection
	RGB calculCouleurFinal(RGB src, Segment incident){
		Intersection* inter = testObstacle(incident);
		if (inter = null)
		{
			RGB rst(80,80,100);
			return rst;
		}

		else
		{
			RGB rst = ((1-Reflexion)*calculCouleurPrim(incident, src, inter)) + (Reflexion*calculCouleurFinal(prolongeRayon(incident)));
		}


	}
*/

};

#endif