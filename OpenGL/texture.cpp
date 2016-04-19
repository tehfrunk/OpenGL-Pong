#include <iostream>
#include "texture.h"

Texture::Texture(GLenum TextureTarget, const std::string& Filename)
{
	m_textureTarget = TextureTarget;
	m_filename = Filename;
}

bool Texture::Load()
{
	try
	{
		m_image.read(m_filename);
		m_image.write(&m_blob, "RGBA");
	}
	catch (Magick::Error& Error)
	{
		std::cout << "Error loading texture '" << m_filename << "': " << Error.what() << std::endl;
		return false;
	}

	//Generate texture
	glGenTextures(1, &m_textureObj);
	//Bind texture to rendering pipeline for transfer to GPU
	glBindTexture(m_textureTarget, m_textureObj);
	//Create texture from ImageMagick blob (image bytes)
	glTexImage2D(m_textureTarget, 0, GL_RGBA, m_image.columns(), m_image.rows(), 0, GL_RGBA,
		GL_UNSIGNED_BYTE, m_blob.data());
	//Tell OpenGL how to handle minification and magnification
	glTexParameterf(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Unbind the texture from pipeline
	glBindTexture(m_textureTarget, 0);
	
	return true;
}

void Texture::Bind(GLenum TextureUnit)
{
	glActiveTexture(TextureUnit);
	glBindTexture(m_textureTarget, m_textureObj);
}