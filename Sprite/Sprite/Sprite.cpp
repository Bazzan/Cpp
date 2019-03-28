#include "Sprite.h"



Sprite::Sprite(std::string filnamn)
{
	image = new BIB_Image();
	image->pixels = BIB_loadPixels(filnamn);
	image->count = 1;
}


Sprite::~Sprite()
{

	image->count--;
	if (image->count == 0) {
		
		delete [] image->pixels;
		delete image;
	}

	
}


Sprite::Sprite(const Sprite&) {

		image->count++;
	
}


const Sprite& Sprite::operator=(const Sprite& other) {
	if (image != other.image) {
		Sprite::~Sprite();
	

	image = other.image;
	image->count++;
	}
	return *this;
}
