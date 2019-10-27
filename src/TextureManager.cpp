#include "TextureManager.hpp"

void TextureManager::loadTexture(std::string textureName, std::string texturePath)
{
	Texture2D texture = LoadTexture(texturePath.c_str());
	textures[textureName] = texture;
}

Texture& TextureManager::getTextureRef(std::string textureName)
{
	return textures[textureName];
}

Texture TextureManager::getTexture(std::string textureName)
{
	return textures[textureName];
}
