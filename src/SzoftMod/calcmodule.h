#pragma once
static std::string toStandardString(System::String^ myString);

bool allowedChar(char myChar) {
	bool allowed = false;
	std::vector<char> whitelist = { '0','1','2','3','4','5','6','7','8','9','+','-','*','/','(',')','.' };
	for (int i = 0; i < whitelist.size(); i++)
	{
		if (myChar == whitelist[i]) allowed = true;
	}
	return allowed;
}

std::vector<char> sanitazeInput(std::vector<char> inputCharVect) {
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

bool zarojelekJokE(std::vector<char> inputCharVect) {
	int nyitott = 0;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '(') nyitott++;
		if (inputCharVect[i] == ')') nyitott--;
		if (nyitott < 0) return false;
	}
	if (nyitott == 0) return true;
	else return false;
}

bool vanBenneNyitoZarojel(std::vector<char> inputCharVect) {
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '(') van = true;
	}
	return van;
}

bool vanBenneSzorzasOsztas(std::vector<char> inputCharVect) {
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '*' || inputCharVect[i] == '/') van = true;
	}
	return van;
}

bool vanBenneOsszeadasKivonas(std::vector<char> inputCharVect) {
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '+' || inputCharVect[i] == '-') van = true;
	}
	return van;
}

double calculate(std::vector<char> inputCharVect) {

	inputCharVect = sanitazeInput(inputCharVect);
	double eredmeny = 0;

	if (zarojelekJokE(inputCharVect)) {
		while (vanBenneNyitoZarojel(inputCharVect))
		{
			bool kellEMegSzamolni = true;
			for (int nyitoIndex = 0; nyitoIndex < inputCharVect.size() && kellEMegSzamolni; nyitoIndex++)
			{
				if (inputCharVect[nyitoIndex] == '(' && inputCharVect[nyitoIndex + 1] != '(') {
					for (int zaroIndex = nyitoIndex; zaroIndex < inputCharVect.size() && kellEMegSzamolni; zaroIndex++)
					{
						if (inputCharVect[zaroIndex] == ')') {
							std::vector<char> tempZarojelVect;
							for (int i = nyitoIndex+1; i < zaroIndex-1; i++)
							{
								tempZarojelVect.push_back(inputCharVect[i]);
							}

							inputCharVect.erase(inputCharVect.begin() + nyitoIndex, inputCharVect.begin() + zaroIndex);

							std::string tempCalcString = toStandardString(calculate(tempZarojelVect).ToString());

							for (int i = 0; i < tempCalcString.size(); i++)
							{
								inputCharVect.insert(inputCharVect.begin() + nyitoIndex + i, tempCalcString[i]);
							}
							kellEMegSzamolni = false;
						}
					}
				}
			}
		}

		while (vanBenneSzorzasOsztas(inputCharVect))
		{
			bool kellEMegSzamolni = true;
			for (int szorzasHelye = 0; szorzasHelye < inputCharVect.size() && kellEMegSzamolni; szorzasHelye++)
			{
				if (inputCharVect[szorzasHelye] == '*')
				{
					if (szorzasHelye == 0) throw("Nincs balérték báttya");
					

					int balertekIndex = szorzasHelye - 1;
					while (balertekIndex>0 && isdigit(inputCharVect[balertekIndex-1]))
					{
						balertekIndex--;
					}

					int jobbertekIndex = szorzasHelye + 1;
					while (jobbertekIndex < inputCharVect.size() && isdigit(inputCharVect[balertekIndex + 1]))
					{
						balertekIndex++;
					}

					double 

					kellEMegSzamolni = false;
				}
			}
		}

		while (vanBenneOsszeadasKivonas(inputCharVect))
		{

		}

		for (int i = 0; i < inputCharVect.size(); i++)
		{
			//ide jön csúnya számjegyenkénti konverzó, de most mára elegem van
			char currentChar = inputCharVect[i];
			eredmeny = eredmeny * 10 + inputCharVect[i];
		}
		return eredmeny;
	}
	else throw("nemjók a zárójelek báttya");
}
