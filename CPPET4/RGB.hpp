#ifndef RGB_H
#define RGB_H 

#include <iostream>

class RGB 
{
	private :
	int R;
	int G;
	int B;

	public :
	void afficher(std::ostream &flux) const;
	RGB(){};
	RGB(int R1, int G1, int B1) : R(R1), G(G1), B(B1){};
};

void RGB::afficher(std::ostream &flux) const
{
    flux << R << " " << G << " " << B << " " ;
}

std::ostream &operator<<(std::ostream &flux, RGB const& rgb)
{
    rgb.afficher(flux) ;
    return flux;
}

#endif