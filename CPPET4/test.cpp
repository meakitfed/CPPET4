#include <iostream>
#include <cstdlib>
#include <string>
#include "Pos.hpp"
#include "RGB.hpp"
#include "Intersection.hpp"
#include "Segment.hpp"
#include "Objets.hpp"
#include "Visible.hpp"
#include "Sphere.hpp"
/*#include "InputFileControlleur.hpp"
#include "OutputFileControlleur.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Source.hpp"
*/

using namespace std;

int main()
{
	/*Scene* s = new Scene();
	InputFileControlleur f(s,"fichier");
	f.parseInputFile();
	OutputFileControlleur o(s,"hey");
	o.writeInOutputFile();*/

	RGB c(1,2,3);
	RGB co(3,2,1);
	RGB cou(6,6,6);
	RGB couy = 2*(c+co+cou);

	cout << couy << endl;

	return 0;
}