#pragma once

#include <string>

#include <GL/glew.h>
#include <ImageMagick-6/Magick++.h>

class Texture
{
public:
	Texture(GLenum TextureTarget, const std::string& Filename);
	//Load the image
	bool Load();
	//Bind to OpenGL Rendering Pipeline
	void Bind(GLenum TextureUnit);

private:
	std::string m_filename;
	GLenum m_textureTarget;
	GLuint m_textureObj;
	//Information about the image
	Magick::Image m_image;
	//Image data (actual pixel information)
	Magick::Blob m_blob;
};