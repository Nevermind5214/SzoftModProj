#pragma once
#include <math.h>
static std::string toStandardString(System::String^ myString);


std::vector<char> whitelist = { '0','1','2','3','4','5','6','7','8','9','+','-','*','/','(',')','.','^' };
std::vector<std::string> fuggvenyWhitelist = { "sqrt", "sin", "cos", "tan"};

bool allowedChar(char myChar) {//DONE
	bool allowed = false;
	for (int i = 0; i < whitelist.size(); i++)
	{
		if (myChar == whitelist[i]) allowed = true;
	}
	return allowed;
}


std::vector<char> sanitazeInput(std::vector<char> inputCharVect) { //DONE
	std::vector<char> tempCharVect;
	//remove shit
	for (int karakterPozicio = 0; karakterPozicio < inputCharVect.size(); karakterPozicio++)
	{
		if (allowedChar(inputCharVect[karakterPozicio])) {
			tempCharVect.push_back(inputCharVect[karakterPozicio]);
		}

		else
		{
			bool megvan = false;
			for (int fuggvenyekIndex = 0; fuggvenyekIndex < fuggvenyWhitelist.size() && !megvan; fuggvenyekIndex++) //megnézünk minden fv-t
			{
				bool mindjo = true;
				std::vector<char> tempCharVectFunct;
				for (int fuggKarIndex = 0; fuggKarIndex < fuggvenyWhitelist[fuggvenyekIndex].size() && (karakterPozicio + fuggKarIndex) < inputCharVect.size(); fuggKarIndex++) //karakterenként
				{
					if (inputCharVect[karakterPozicio + fuggKarIndex] == fuggvenyWhitelist[fuggvenyekIndex][fuggKarIndex]) {
						tempCharVectFunct.push_back(inputCharVect[karakterPozicio + fuggKarIndex]);
					}
					else mindjo = false;
					if (fuggvenyWhitelist[fuggvenyekIndex].size() == tempCharVectFunct.size() && mindjo) {
						for (int i = 0; i < tempCharVectFunct.size(); i++)
						{
							tempCharVect.push_back(tempCharVectFunct[i]);
						}
						karakterPozicio = karakterPozicio + tempCharVectFunct.size() - 1;
						megvan = true;
					}
				}
			}
			if (!megvan) throw("nem találtam ilyen fvt"); // ha nem volt közte
		}

	}
	return tempCharVect;
}

bool zarojelekJokE(std::vector<char> inputCharVect) {//DONE
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

bool vanBenneFuggveny(std::vector<char> inputCharVect) {//DONE
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (!allowedChar(inputCharVect[i])) van = true;
	}
	return van;
}

bool vanBenneNyitoZarojel(std::vector<char> inputCharVect) {//DONE
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '(') van = true;
	}
	return van;
}

bool vanBenneSzorzasOsztas(std::vector<char> inputCharVect) {//DONE
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '*' || inputCharVect[i] == '/') van = true;
	}
	return van;
}

bool vanBenneOsszeadasKivonas(std::vector<char> inputCharVect) {//DONE
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '+' || inputCharVect[i] == '-') van = true;
	}
	return van;
}

bool vanBenneHatvanyozas(std::vector<char> inputCharVect) {//DONE
	bool van = false;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (inputCharVect[i] == '^') van = true;
	}
	return van;
}

double toDouble(std::vector<char> inputCharVect) { //DONE
	double retval = 0;
	int dotCounter = 1;
	bool beforeDot = true;
	for (int i = 0; i < inputCharVect.size(); i++)
	{
		if (isdigit(inputCharVect[i]) || inputCharVect[i] == '.') {
			if (inputCharVect[i] == '.') beforeDot = false;
			else {
				if (beforeDot) retval = retval * 10.0 + (inputCharVect[i]-48); //csúnya ascii hack, nem volt jó sehogy sem, így most mûxik
				else {
					retval = retval + (inputCharVect[i] - 48) * pow(0.1, dotCounter);
					dotCounter++;
				}
			}
		}
		//else throw("double conversion error");
		else throw(inputCharVect);
	}
	return retval;
}

double calculate(std::vector<char> inputCharVect) {

	inputCharVect = sanitazeInput(inputCharVect);

	if (zarojelekJokE(inputCharVect)) {

		while (vanBenneFuggveny(inputCharVect)) {//DONE
			bool megvan = false;
			for (int karakterPozicio = 0; karakterPozicio < inputCharVect.size() && !megvan; karakterPozicio++)
			{
				for (int fuggvenyekIndex = 0; fuggvenyekIndex < fuggvenyWhitelist.size() && !megvan; fuggvenyekIndex++) //megnézünk minden fv-t
				{
					bool mindjo = true;
					for (int fuggKarIndex = 0; fuggKarIndex < fuggvenyWhitelist[fuggvenyekIndex].size() && (karakterPozicio + fuggKarIndex) < inputCharVect.size(); fuggKarIndex++) //karakterenként
					{
						if (inputCharVect[karakterPozicio + fuggKarIndex] != fuggvenyWhitelist[fuggvenyekIndex][fuggKarIndex]) mindjo = false;
						if (fuggvenyWhitelist[fuggvenyekIndex].size() == fuggKarIndex + 1 && mindjo) {
							megvan = true;
							double csereErtek=0;
							int kovizarojelHelye = 0;
							for (int i = karakterPozicio + 2; i < inputCharVect.size() && kovizarojelHelye == 0; i++)
							{
								if (inputCharVect[i] == ')') kovizarojelHelye = i;
							}
							std::vector<char> tempCsereErtekVektor;
							for (int i = karakterPozicio + fuggvenyWhitelist[fuggvenyekIndex].size()+1; i < kovizarojelHelye; i++)
							{
								tempCsereErtekVektor.push_back(inputCharVect[i]);
							}
							if (karakterPozicio + fuggvenyWhitelist[fuggvenyekIndex].size() + 1 == kovizarojelHelye) throw("Üres a függvény");
							csereErtek = calculate(tempCsereErtekVektor);
							switch (fuggvenyekIndex) // "sqrt", "sin", "cos", "tan",
							{
							case 0://sqrt
								csereErtek = sqrt(csereErtek);
								break;
							case 1://sin
								csereErtek = sin(csereErtek);
								break;
							case 2://cos
								csereErtek = cos(csereErtek);
								break;
							case 3://tan
								csereErtek = tan(csereErtek);
								break;
							default:
								throw("valamiért nem találta a fvt a switchben");
								break;
							}


							inputCharVect.erase(inputCharVect.begin() + karakterPozicio, inputCharVect.begin() + kovizarojelHelye+1);
							std::string temporaryMystring = std::to_string(csereErtek);
							for (int i = 0; i < temporaryMystring.size(); i++)
							{
								inputCharVect.insert(inputCharVect.begin() + karakterPozicio + i, temporaryMystring[i]);
							}

						}
					}
				}
			}
			break;
		}

		while (vanBenneNyitoZarojel(inputCharVect))//DONE
		{
			bool kellEMegSzamolni = true;
			for (int nyitoIndex = 0; nyitoIndex < inputCharVect.size() && kellEMegSzamolni; nyitoIndex++)
			{
				if (inputCharVect[nyitoIndex] == '(' && inputCharVect[nyitoIndex + 1] != '(') {
					for (int zaroIndex = nyitoIndex+1; zaroIndex < inputCharVect.size() && kellEMegSzamolni; zaroIndex++)
					{
						if (inputCharVect[zaroIndex] == ')') {
							std::vector<char> tempZarojelVect;
							for (int i = nyitoIndex + 1; i <= zaroIndex - 1; i++)
							{
								tempZarojelVect.push_back(inputCharVect[i]);
							}

							inputCharVect.erase(inputCharVect.begin() + nyitoIndex, inputCharVect.begin() + zaroIndex+1);

							std::string tempCalcString = std::to_string(calculate(tempZarojelVect));

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


		
		while (vanBenneHatvanyozas(inputCharVect))
		{
			break;
		}

		while (vanBenneSzorzasOsztas(inputCharVect))
		{

			// "balszám*jobbszám" cuccot felülírni az eredményével erase insert-el
			break; //debug
			bool kellEMegSzamolni = true;
			for (int szorzasHelye = 0; szorzasHelye < inputCharVect.size() && kellEMegSzamolni; szorzasHelye++)
			{
				if (inputCharVect[szorzasHelye] == '*')
				{
					if (szorzasHelye == 0) throw("Nincs balérték báttya");


					int balertekIndex = szorzasHelye - 1;
					while (balertekIndex > 0 && isdigit(inputCharVect[balertekIndex - 1]))
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

			// "balszám+jobbszám" cuccot felülírni az eredményével  erase insert-el
			break; //debug
		}


		return toDouble(inputCharVect);
	}
	else throw("nemjók a zárójelek báttya");
}
