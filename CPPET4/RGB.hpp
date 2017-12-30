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
    RGB add(RGB const& b) const;
    RGB mult1(float const& a) const;
    RGB mult2(RGB const& b) const;

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

RGB RGB::add(RGB const& b) const{
    RGB rst(this->R+b.R,this->G+b.G, this->B+b.B);
    return rst;
}

//Esperons que ce soit transitif
RGB operator+(RGB const& a, RGB const& b)
{
    RGB rst;
    rst = a.add(b);
    return rst;

    // Calcul des valeurs des attributs de resultat

}


RGB RGB::mult1(float const& a) const{
    RGB rst(a*this->R, a*this->G, a*this->B);
    return rst;
}

RGB operator*(float const& a, RGB const& b)
{

    RGB rst;
    rst = b.mult1(a);
    // Calcul des valeurs des attributs de resultat

    return rst;
}

RGB RGB::mult2(RGB const& b) const{
    RGB rst(this->R*b.R, this->G*b.G, this->B*b.B);
    return rst;
}

RGB operator*(RGB const& a, RGB const& b)
{

    RGB rst;
    rst = a.mult2(b);
    // Calcul des valeurs des attributs de resultat

    return rst;
}


#endif