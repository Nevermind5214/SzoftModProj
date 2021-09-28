#pragma once
#include <math.h>
static std::string toStandardString(System::String^ myString);
static String^ toSystemString(std::string myString);

std::vector<char> muveletiJelek = { '+','-','*','/','(',')','.','^' };
std::vector<std::string> fuggvenyWhitelist = { "sqrt", "sin", "cos", "tan" };

class Token {
public:
	char kind; // fvnév: f, mûveleti jel, zárójel: önmaga, szám: n
	double value; //számhoz
	std::string name; //függvénynévhez
	//Token() : kind(0) {}

	Token(char ch, double val) : kind(ch), value(val) {}//számhoz
	Token(char ch) : kind(ch) {}//mûveleti jelhez, zárójelhez
	Token(char ch, std::string n) : kind(ch), name(n) {}//függvénynévhez
};

bool benneVanE(std::vector<char>charVect, char myChar)//megnézi hogy az adott karakter benne van-e az adott tömbben
{
	for (char currentChar : charVect)
	{
		if (myChar == currentChar) return true;
	}
	return false;
}

bool allowedChar(char myChar)//ha számjegy vagy mûveleti jel az adott karakter akkor megengedett
{
	return (isdigit(myChar) || benneVanE(muveletiJelek, myChar));
}

bool zarojelekJokE(std::vector<Token> inputTokenVect) {//DONE
	int nyitott = 0;
	for (Token currentToken : inputTokenVect)
	{
		if (currentToken.kind == '(') nyitott++;
		if (currentToken.kind == ')') nyitott--;
		if (nyitott < 0) return false;
	}
	if (nyitott == 0) return true;
	else return false;
}

std::vector<Token> tokenise(std::vector<char> inputCharVect) { //DONE
	std::vector<Token> tokenisedInput;
	double retval = 0;
	int dotCounter = 1;
	bool beforeDot = true;

	for (int i = 0; i < inputCharVect.size(); i++)//végignézzük a tömböt karakterenként
	{
		if (inputCharVect[i]!= '.' && !isdigit(inputCharVect[i]) && (i - 1) >= 0 && isdigit(inputCharVect[i - 1]))//elértük a szám végét, ez már nem számjegy de még az elõzõ létezik és az volt
		{
			tokenisedInput.push_back(Token('n', retval)); //szám vége, reseteljük a segédváltozókat és beletesszük
			retval = 0;
			dotCounter = 1;
			beforeDot = true;
		}

		//ha számjegy
		if (isdigit(inputCharVect[i]) || inputCharVect[i] == '.')//számjegy vagy pont (a .012  stb. is elfogadott
		{
			if (inputCharVect[i] == '.')
			{
				beforeDot = false;
				if ((i == inputCharVect.size() - 1) || !isdigit(inputCharVect[i + 1])) throw("A pont után számjegynek kell állnia!");
			}
			else
			{
				if (beforeDot) retval = retval * 10.0 + (inputCharVect[i] - 48); //pont elõtt, csúnya ascii hack, nem volt jó sehogy sem, így most mûxik
				else
				{
					retval = retval + (inputCharVect[i] - 48) * pow(0.1, dotCounter);//pont után
					dotCounter++;
				}
			}
		}

		//ha mûveleti jel
		else if (benneVanE(muveletiJelek, inputCharVect[i])) tokenisedInput.push_back(Token(inputCharVect[i]));

		//ha bármi más, megnézzük, hogy függvény-e
		else
		{
			bool megvan = false;
			for (int fuggvenyekIndex = 0; fuggvenyekIndex < fuggvenyWhitelist.size() && !megvan; fuggvenyekIndex++) //megnézünk minden fv-t
			{
				bool mindjo = true;//eddig minden karakter egyezik-e
				std::string currentFuggvenynev = "";
				for (int fuggKarIndex = 0; fuggKarIndex < fuggvenyWhitelist[fuggvenyekIndex].size() && (i + fuggKarIndex) < inputCharVect.size(); fuggKarIndex++) //karakterenként
				{
					if (inputCharVect[i + fuggKarIndex] == fuggvenyWhitelist[fuggvenyekIndex][fuggKarIndex]) {
						currentFuggvenynev = currentFuggvenynev + inputCharVect[i + fuggKarIndex];
					}
					else mindjo = false;
					if (fuggvenyWhitelist[fuggvenyekIndex].size() == currentFuggvenynev.size() && mindjo) {
						tokenisedInput.push_back(Token('f', currentFuggvenynev));
						i = i + currentFuggvenynev.size() - 1;
						megvan = true;
					}
				}
			}
			if (!megvan)
			{
				std::string dotnetegyfos(1, inputCharVect[i]);
				throw("Ismeretlen karakter: '" + toSystemString(dotnetegyfos) + "'");
			}
		}

		//elértünk a karakterek végére és az utsó jegy szám volt akkor bele kell tenni mert már nem lesz több a for-ban
		if ((i == inputCharVect.size() - 1) && (isdigit(inputCharVect[i]))) tokenisedInput.push_back(Token('n', retval));
	}

	return tokenisedInput;
}

double calculate(std::vector<char> inputCharVect) {
	std::vector<Token> tokenisedInput = tokenise(inputCharVect);

	/*
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

		*/
	if (tokenisedInput.size() > 0 && tokenisedInput[0].kind == 'n') return tokenisedInput[0].value;
	if (tokenisedInput.size() > 0 && tokenisedInput[0].kind == 'f') throw(tokenisedInput[0].name);
	else return 0;
	//}
	//else throw("nemjók a zárójelek báttya");
}
