#include <string>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
		std::string FragementShader_Blinn{"char #version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec3 aNormal;\n"
			"layout (location = 2) in vec2 aTexCoords;\n"
			"\n"
			"// declare an interface block; see 'Advanced GLSL' for what these are.\n"
			"out VS_OUT {\n"
				"vec3 FragPos;\n"
				"vec3 Normal;\n"
				"vec2 TexCoords;\n"
			"} vs_out;\n"
			"\n"
			"uniform mat4 projection;\n"
			"uniform mat4 view;\n"
			"\n"
			"void main()\n"
			"{\n"
				"vs_out.FragPos = aPos;\n"
				"vs_out.Normal = aNormal;\n"
				"vs_out.TexCoords = aTexCoords;\n"
				"gl_Position = projection * view * vec4(aPos, 1.0);\n"
			"}\n"
		};

	std::cout << FragementShader_Blinn << std::endl;
	
}