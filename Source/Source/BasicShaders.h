#ifndef BASICSHADERS_H
#define BASICSHADERS_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <stdio.h>
#include <assert.h>

class BasicShader
{
private:
	enum ShaderMode
	{
		VERTEX,
		FRAGMENT
	};
	std::string m_VertexParsedString;
	std::string m_FragmentParsedString;

	std::unordered_map<std::string, int> m_LocationCache;

	void m_ParseFile(const std::string& filePath, std::string& resultHolder);
	unsigned int m_CompileShader(GLenum shaderType);
public:
	int shaderID;

	std::string vertexShaderPath;
	std::string fragmentShaderPath;

	BasicShader(std::string& vertexShaderFilePath, std::string& fragmentShaderFilePath);
	BasicShader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);
	~BasicShader();

	inline void Bind() const { glUseProgram(shaderID); };
	inline void Unbind() const { glUseProgram(0); };

	int GetUniformLocation(const std::string& name);
	int GetUniformLocation(const char* name);

	void RecompileShaders();
};

#endif BASICSHADERS_H