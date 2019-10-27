#pragma once
#include "raylib.h"
#include <map>
#include <string>

class TextureManager
{
public:
	void loadTexture(std::string textureName, std::string texturePath);
	Texture& getTextureRef(std::string textureName);
	Texture getTexture(std::string textureName);
private:
	std::map<std::string, Texture2D> textures;
};