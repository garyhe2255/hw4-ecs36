#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "json.hpp"

#include "AVL.h"

using namespace std;

void readJson(string fileName, AVL &avl) {
	int key;
	int numOps;
	string operation;
	ifstream inputFile(fileName);
	nlohmann::json inputJson;

	inputFile >> inputJson;

	//reads metadata numOps
	numOps = inputJson["metadata"]["numOps"];

	for (int i = 1; i <= numOps; i++) {
		//converts operation number to string
		string num = to_string(i);
		key = inputJson[num]["key"];
		operation = inputJson[num]["operation"];

		if (operation == "Insert") {
			avl.insert(key);
		} else {
			cout << "Nonexistent operation" << endl;
		}

	}

	inputFile.close();
}

int main(int argc, char* argv[]) {
	AVL avl;

	readJson(argv[1], avl);

	return 0;
}
