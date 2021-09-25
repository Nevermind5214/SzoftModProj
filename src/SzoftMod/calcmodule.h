#pragma once
static std::string toStandardString(System::String^ myString);


std::vector<char> whitelist = { '0','1','2','3','4','5','6','7','8','9','+','-','*','/','(',')','.' };
std::vector<std::string> fuggvenyWhitelist = { "sin", "cos", "tan", "ctg" };

bool allowedChar(char myChar) {//DONE
	bool allowed = false;
	for (int i = 0; i < whitelist.size(); i++)
	{
		if (myChar == whitelist[i]) allowed = true;
	}
	return allowed;
}


std::vector<char> sanitazeInput(std::vector<char> inputCharVect) {
	std::vector<char> tempCharVect;
	//remove shit
	for (int karakterPozicio = 0; karakterPozicio < inputCharVect.size(); karakterPozicio++)
	{
		if (allowedChar(inputCharVect[karakterPozicio])) {
			tempCharVect.push_back(inputCharVect[karakterPozicio]);
		}

		//ittt van valami hiba fos idk, nem nagyon j� a mintakeres�sem
		else
		{
			bool talatFuggvenyt = false;
			for (int talatFuggvenyIndex = 0; talatFuggvenyIndex < fuggvenyWhitelist.size() && !talatFuggvenyt; talatFuggvenyIndex++)
			{
				for (int fuggvenyKarakterIndex = 0; fuggvenyKarakterIndex < fuggvenyWhitelist[talatFuggvenyIndex].size(); fuggvenyKarakterIndex++)
				{
					if(karakterPozicio + fuggvenyKarakterIndex > inputCharVect.size()) throw("t�ll�g");

					if (fuggvenyWhitelist[talatFuggvenyIndex][fuggvenyKarakterIndex] == inputCharVect[karakterPozicio + fuggvenyKarakterIndex]) {
						talatFuggvenyt = true;
						tempCharVect.push_back(inputCharVect[karakterPozicio + fuggvenyKarakterIndex]);
					}
				}
				if (!talatFuggvenyt) throw("ismeretlen f�ghjgggv�ny");
			}

			if (!talatFuggvenyt) throw("ismeretlen f�GGv�ny");
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

double calculate(std::vector<char> inputCharVect) {

	inputCharVect = sanitazeInput(inputCharVect);
	double eredmeny = 0;

	if (zarojelekJokE(inputCharVect)) {

		while (vanBenneFuggveny(inputCharVect)) {
			break; //debug

			//egyes�vel math.f�ggv�ny(caluculate(a bleseje))  erase insert-el
		}

		while (vanBenneNyitoZarojel(inputCharVect))//DONE
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

			// "balsz�m*jobbsz�m" cuccot fel�l�rni az eredm�ny�vel erase insert-el
			break; //debug
			bool kellEMegSzamolni = true;
			for (int szorzasHelye = 0; szorzasHelye < inputCharVect.size() && kellEMegSzamolni; szorzasHelye++)
			{
				if (inputCharVect[szorzasHelye] == '*')
				{
					if (szorzasHelye == 0) throw("Nincs bal�rt�k b�ttya");
					

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

			// "balsz�m+jobbsz�m" cuccot fel�l�rni az eredm�ny�vel  erase insert-el
			break; //debug
		}

		for (int i = 0; i < inputCharVect.size(); i++)
		{
			//ide j�n cs�nya sz�mjegyenk�nti konverz�, de most m�ra elegem van
			char currentChar = inputCharVect[i];
			eredmeny = eredmeny * 10 + inputCharVect[i];
		}
		return eredmeny;
	}
	else throw("nemj�k a z�r�jelek b�ttya");
}
