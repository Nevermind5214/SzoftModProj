#pragma once


bool allowedChar(char myChar) {
	bool allowed = false;
	std::vector<char> whitelist = { '0','1','2','3','4','5','6','7','8','9','+','-','*','/','(',')' };
	for (int i = 0; i < whitelist.size(); i++)
	{
		if (myChar == whitelist[i]) allowed = true;
	}
	return allowed;
}

std::vector<char> sanitazeInput(std::vector<char> inputCharVect){
	std::vector<char> tempCharVect;
	//remove shit
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (allowedChar(inputCharVect[i])) {
			tempCharVect.push_back(inputCharVect[i]);
		}
	}
	return tempCharVect;
}

double calculate(std::vector<char> inputCharVect) {
	
	inputCharVect = sanitazeInput(inputCharVect);

	for (int inputPtr = 0; inputPtr < inputCharVect.size(); inputPtr++)
	{
		//itt jön a számolás, logika stb


	}
	return 1337;
}