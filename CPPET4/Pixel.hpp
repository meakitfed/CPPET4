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
	void drawPixel(Pos posCam, std::vector<Visible*>* obj, Source src);

/*
	//peutetre transformer des trucs en pointeurs
	RGB calculCouleurPrim(Segment s, RGB src, Intersection inter, Lobjets){
		Segment source(inter, source.pos);
		if (testObstacle(source) == null)
		{
			RGB couleurCalculee;
			Segment intersrc(inter, src.getPosition());
			couleurCalculee = inter.getNormale().calculCos(intersrc)*inter.color*src.color;
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

void Pixel::drawPixel(Pos posCam, std::vector<Visible*>* obj, Source src){
	float distanceAvecPixel=-1;
			Intersection inter;

			//creation du segment qui part de cam vers le pixel
			Segment s(posCam,this->getPosition());

			//pour tout les objets visibles
			for(std::vector<Visible*>::iterator o = obj->begin() ; o != obj->end(); ++o)
			{
				Intersection* interTemp = (*o)->estTraverse(s);

				//si intersection trouvee
				//on met à jour la distance si nécessaire
				if(interTemp != NULL)
				{
					float d = s.getOrigine().distanceAvecPoint(interTemp->getOrigine());
					if(distanceAvecPixel > d || distanceAvecPixel == 1)
					{
						inter = *interTemp;
						distanceAvecPixel = d;
					}
				}
				delete interTemp;
			}
			
			if(distanceAvecPixel!=-1)
			{
				//rajouter calcul d'obsacle entre inter et src
				//RGB couleurCalculee;
				//Segment intersrc(inter.getOrigine(), src.getPosition());
				//couleurCalculee = inter.getNormale().calculeCos(intersrc.getVecteur())*inter.getColor()*src.getColor();
				this->setColor(inter.getColor());
			}
}

#endif