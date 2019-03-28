#pragma once

#include <iostream>
#include<string>



class Sprite
{
private:
	BIB_Image * image;

public:
	Sprite(std::string filnamn);
	Sprite(const Sprite&);
	const Sprite& operator=(const Sprite& other);


	~Sprite();
};

struct BIB_Image {
	int count;
	char* pixels;

};