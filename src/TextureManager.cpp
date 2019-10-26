#include "TextureManager.hpp"

std::map<std::string, Texture2D> TextureManager::textures = std::map<std::string, Texture2D>();

void TextureManager::loadTexture(std::string textureName, std::string texturePath)
{
	Texture2D texture = LoadTexture(texturePath.c_str());
	textures[textureName] = texture;
}

Texture& TextureManager::getTexture(std::string textureName)
{
	return textures[textureName];
}
