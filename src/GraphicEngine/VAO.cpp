#include "include/GraphicEngine/VAO.h"

VAO VAOManagement::generateVAO(vector<pair<PositionVec3, NormalVec3>> vertexData) {
	VAO myVAO;
	GLuint vbo;
	GLuint ebo;
	vector<int> index;
	for (int i = 0; i < vertexData.size(); ++i) index.push_back(i);

	glGenVertexArrays(1, &myVAO.vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(myVAO.vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(vertexData[0]), &vertexData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertexData[0]), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertexData[0]), (GLvoid*)sizeof(PositionVec3));
	
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	myVAO.count = vertexData.size();

	return myVAO;
}

void VAOManagement::drawVAO(vector<VAO> vao) {
	for (int i = 0; i < vao.size(); ++i) {
		glBindVertexArray(vao[i].vao);
		glDrawArrays(GL_TRIANGLES, 0, vao[i].count);
		glBindVertexArray(0);
	}
}