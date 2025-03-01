#include "BasicShaders.h"


void BasicShader::m_ParseFile(const std::string& filePath, std::string& resultHolder)
{
    std::ifstream file(filePath);
    std::string line;
    std::stringstream ss;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            ss << line << '\n';
        }

        resultHolder = ss.str();
    }
}

unsigned int BasicShader::m_CompileShader(GLenum shaderType)
{
    std::string* source = nullptr;

    switch (shaderType)
    {
    case GL_VERTEX_SHADER:
        source = &m_VertexParsedString;
        break;
    case GL_FRAGMENT_SHADER:
        source = &m_FragmentParsedString;
        break;
    default:
        std::cout << "INVALID SHADER TYPE CALLING COMPILE SHADER" << std::endl;
        assert(1 == 2);
        return 0;
        break;
    }
    if (source == nullptr)
    {
        assert(1 == 2);
        return 0;
    }
    const char* src = source->c_str();

    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    //error checking
    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;

        std::cout << "Source:\n" << src << std::endl;
    }

    return shader;
}

BasicShader::BasicShader(std::string& vertexShaderFilePath, std::string& fragmentShaderFilePath)
    :vertexShaderPath(vertexShaderFilePath)
    ,fragmentShaderPath(fragmentShaderFilePath)
    ,shaderID(glCreateProgram())
{
    RecompileShaders();
}

BasicShader::BasicShader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
    :vertexShaderPath(vertexShaderFilePath)
    , fragmentShaderPath(fragmentShaderFilePath)
    , shaderID(glCreateProgram())
{
    RecompileShaders();
}

BasicShader::~BasicShader()
{
    glDeleteProgram(shaderID);
}

int BasicShader::GetUniformLocation(const std::string& name)
{
    auto it = m_LocationCache.find(name);
    if (it != m_LocationCache.end())
    {
        return it->second;
    }
    const int location = glGetUniformLocation(shaderID, name.c_str());
    if (location != -1)
    {
        m_LocationCache[name] = location;
    }
    else
    {
        std::cout << "UNIFORM '" << name << "' DOES NOT EXIST" << std::endl;
        return -1;
    }
    return location;
}

int BasicShader::GetUniformLocation(const char* name)
{
    auto it = m_LocationCache.find(name);
    if (it != m_LocationCache.end())
    {
        return it->second;
    }
    const int location = glGetUniformLocation(shaderID, name);
    if (location != -1)
    {
        m_LocationCache[name] = location;
    }
    else
    {
        std::cout << "UNIFORM '" << name << "' DOES NOT EXIST" << std::endl;
        return -1;
    }
    return location;
}

void BasicShader::RecompileShaders()
{
    m_ParseFile(vertexShaderPath, m_VertexParsedString);
    m_ParseFile(fragmentShaderPath, m_FragmentParsedString);
    unsigned int vertexShader = m_CompileShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = m_CompileShader(GL_FRAGMENT_SHADER);

    glAttachShader(shaderID, vertexShader);
    glAttachShader(shaderID, fragmentShader);
    glLinkProgram(shaderID);

    //error checking
    int successProgram;
    char infoLogProgram[512];
    glGetProgramiv(shaderID, GL_LINK_STATUS, &successProgram);

    if (!successProgram) {
        glGetProgramInfoLog(shaderID, 512, NULL, infoLogProgram);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLogProgram << std::endl;

        std::cout << "Vertex Source:\n" << m_VertexParsedString << std::endl;

        std::cout << "Fragment Source:\n" << m_FragmentParsedString << std::endl;
    }
    //cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
