#include "include/Reader/Reader.h"

vector<VAO> Reader::readObj(string path) {
	vector<VAO> vao;
	fstream file;
	
	file.open(path, ios::in);
	
	if (!file) {
		cout << path << " open failed" << endl;
	}
	else {
		string s;
		vector<glm::vec3> position;
		vector<glm::vec3> normal;
		vector<pair<glm::uvec3, glm::uvec3>> index;
		do {
			float inFloat;
			int inInt1, inInt2;
			glm::vec3 inV1, inV2;

			file >> s;

			if (s == "v") {
				for (int i = 0; i < 3; ++i) {
					file >> inFloat;
					inV1[i] = inFloat;
				}
				position.push_back(inV1);
			}
			else if (s == "vn") {
				for (int i = 0; i < 3; ++i) {
					file >> inFloat;
					inV1[i] = inFloat;
				}
				normal.push_back(inV1);
			}
			else if (s == "o" || file.eof()) {
				file >> s;
				if (index.size() == 0) continue;
				vector<pair<PositionVec3, NormalVec3>> data = preProcess(position, normal, index);

				vao.push_back(VAOManagement::generateVAO(data));
				
				index.clear();
			}
			else if (s == "f") {
				for (int i = 0; i < 3; ++i) {
					file >> inInt1;
					file.get();
					file.get();
					file >> inInt2;

					inV1[i] = inInt1;
					inV2[i] = inInt2;
				}
				index.push_back(pair<glm::uvec3, glm::uvec3>(inV1, inV2));
			}
		} while (!file.eof());

		cout << path << " open success!" << endl;
	}

	file.close();

	return vao;
}

vector<pair<PositionVec3, NormalVec3>> Reader::preProcess(vector<glm::vec3> position, vector<glm::vec3> normal, vector<pair<glm::uvec3, glm::uvec3>> index) {
	vector<pair<PositionVec3, NormalVec3>> rev;
	PositionVec3 p;
	NormalVec3 n;
	/*
		rev data 
				Vertex 0		    V1		
		(Vx, Vy, Vz, Nx, Ny, Nz), (...), ...
	*/

	for (int i = 0; i < index.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				p[k] = position[index[i].first[j] - 1][k];
			}
			for (int k = 0; k < 3; ++k) {
				n[k] = normal[index[i].second[j] - 1][k];
			}
			rev.push_back(pair<PositionVec3, NormalVec3>(p, n));
		}
	}

	return rev;
}