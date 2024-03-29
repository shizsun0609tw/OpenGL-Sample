#include "include/GraphicEngine/Shader.h"

Shader::Shader() {

}

Shader::Shader(string VertexShaderPath, string FragmentShaderPath) {
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLint isCompiled = 0;
	ifstream vertexShaderFile, fragmentShaderFile;
	string vertexShaderCode, fragmentShaderCode;
	char ch;

	shaderProgram = glCreateProgram();

	vertexShaderFile.open(VertexShaderPath);
	fragmentShaderFile.open(FragmentShaderPath);
	if (!vertexShaderFile) cout << VertexShaderPath << " open failed!" << endl;
	else {
		cout << "Start to Compile Vertex Shader" << endl;

		while (!vertexShaderFile.eof()) {
			vertexShaderFile.get(ch);
			vertexShaderCode += ch;
		}
		GLchar* vertexContext[] = { &vertexShaderCode[0] };
		glShaderSource(vertexShader, 1, vertexContext, NULL);
		glCompileShader(vertexShader);
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);
			vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &errorLog[0]);
			for (int i = 0; i < errorLog.size(); i++) cout << errorLog[i];
			glDeleteShader(vertexShader);
			return;
		}
		else {
			cout << VertexShaderPath << " compiled success!" << endl;
		}

		glAttachShader(shaderProgram, vertexShader);
	}
	if (!fragmentShaderFile) cout << FragmentShaderPath << " open failed!" << endl;
	else {
		cout << "Start to Compile Fragment Shader" << endl;
		while (!fragmentShaderFile.eof()) {
			fragmentShaderFile.get(ch);
			fragmentShaderCode += ch;
		}
		GLchar* fragmentContext[] = { &fragmentShaderCode[0] };
		glShaderSource(fragmentShader, 1, fragmentContext, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
			vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &errorLog[0]);
			for (int i = 0; i < errorLog.size(); i++) cout << errorLog[i];
			glDeleteShader(fragmentShader);
			return;
		}
		else {
			cout << FragmentShaderPath << " compiled success!" << endl;
		}
		glAttachShader(shaderProgram, fragmentShader);
	}
	glLinkProgram(shaderProgram);

	vertexShaderFile.close();
	fragmentShaderFile.close();
}

Shader::~Shader() {

}

