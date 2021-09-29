#pragma once
#include <math.h>
static std::string toStandardString(System::String^ myString);
static String^ toSystemString(std::string myString);

std::vector<char> muveletiJelek = { '+','-','*','/','(',')','.','^' };
std::vector<std::string> fuggvenyWhitelist = { "sqrt", "sin", "cos", "tan" };

class Token {
public:
	char kind; // fvnév: f, műveleti jel, zárójel: önmaga, szám: n
	double value; //számhoz és fv indexhez

	Token(char ch, double val) : kind(ch), value(val) {}//számhoz
	Token(char ch) : kind(ch) {}//műveleti jelhez, zárójelhez
};

bool benneVanE(std::vector<char>charVect, char myChar)//megnézi hogy az adott karakter benne van-e az adott tömbben
{
	for (char currentChar : charVect)
	{
		if (myChar == currentChar) return true;
	}
	return false;
}

bool kindBenneVanE(std::vector<Token>tokenVect, char myChar)//megnézi hogy az adott karakter benne van-e az adott tömbben
{
	for (Token currentToken : tokenVect)
	{
		if (currentToken.kind == myChar) return true;
	}
	return false;
}

bool allowedChar(char myChar)//ha számjegy vagy műveleti jel az adott karakter akkor megengedett
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
		if (inputCharVect[i] != '.' && !isdigit(inputCharVect[i]) && (i - 1) >= 0 && isdigit(inputCharVect[i - 1]))//elértük a szám végét, ez már nem számjegy de még az előző létezik és az volt
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
				if (beforeDot) retval = retval * 10.0 + (inputCharVect[i] - 48); //pont előtt, csúnya ascii hack, nem volt jó sehogy sem, így most műxik
				else
				{
					retval = retval + (inputCharVect[i] - 48) * pow(0.1, dotCounter);//pont után
					dotCounter++;
				}
			}
		}

		//ha műveleti jel
		else if (benneVanE(muveletiJelek, inputCharVect[i])) tokenisedInput.push_back(Token(inputCharVect[i]));

		//ha bármi más, megnézzük, hogy függvény-e
		else
		{
			bool megvan = false;
			for (int fuggvenyekIndex = 0; fuggvenyekIndex < fuggvenyWhitelist.size() && !megvan; fuggvenyekIndex++) //megnézünk minden fv-t
			{
				bool mindjo = true;//eddig minden karakter egyezik-e
				for (int fuggKarIndex = 0; fuggKarIndex < fuggvenyWhitelist[fuggvenyekIndex].size() && (i + fuggKarIndex) < inputCharVect.size(); fuggKarIndex++) //karakterenként
				{
					if (inputCharVect[i + fuggKarIndex] != fuggvenyWhitelist[fuggvenyekIndex][fuggKarIndex]) mindjo = false;
					if (fuggvenyWhitelist[fuggvenyekIndex].size() == fuggKarIndex + 1 && mindjo) {
						tokenisedInput.push_back(Token('f', fuggvenyekIndex));
						i = i + fuggKarIndex;
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

void dumpKinds(std::vector<Token> tokenisedInput)
{
	std::vector<char> errKinds;
	for (Token currToken : tokenisedInput)
	{
		errKinds.push_back(currToken.kind);
	}
	throw(errKinds);
}


double calc(std::vector<Token> tokenisedInput) {
	if (!zarojelekJokE(tokenisedInput)) throw("Nem jók a zárójelek báttya");
	while (kindBenneVanE(tokenisedInput, 'f'))//először függvények belseje feldolgozása
	{
		bool megvan = false;
		for (int fuggvenyPos = 0; fuggvenyPos < tokenisedInput.size() && !megvan; fuggvenyPos++)//megkeressük az első fv-t
		{
			if (tokenisedInput[fuggvenyPos].kind == 'f')//megtalálom akkor is
			{
				if (tokenisedInput.size() < (fuggvenyPos + 2) || tokenisedInput[fuggvenyPos + 1].kind != '(') throw("A függvény után zárójel kötelező!");
				int nyitott = 1;
				for (int csukoZPos = fuggvenyPos + 2; csukoZPos < tokenisedInput.size() && !megvan; csukoZPos++)//megkeresem a csukózárójel indexét is
				{
					if (tokenisedInput[csukoZPos].kind == '(') nyitott++;
					if (tokenisedInput[csukoZPos].kind == ')') nyitott--;

					if (tokenisedInput[csukoZPos].kind == ')' && nyitott == 0)//megvan!
					{
						if (fuggvenyPos + 2 == csukoZPos) throw("Üres a függvény!");
						megvan = true;
						std::vector<Token> tempTokenvect;//ezt fogjuk kiszámolni rekurzívan
						for (int i = fuggvenyPos + 2; i < csukoZPos; i++)
						{
							tempTokenvect.push_back(tokenisedInput[i]);//beletesszük a zárójelen belüli részt
						}
						int fuggTipus = tokenisedInput[fuggvenyPos].value;//ez kell mert töröljök az eredeti adatot
						tokenisedInput.erase(tokenisedInput.begin() + fuggvenyPos, tokenisedInput.begin() + csukoZPos + 1);
						double belsoErtek = calc(tempTokenvect);
						switch (fuggTipus) {//{ "sqrt", "sin", "cos", "tan" };
						case 0://sqrt
							belsoErtek = sqrt(belsoErtek);
							break;
						case 1://sin
							belsoErtek = sin(belsoErtek);
							break;
						case 2://cos
							belsoErtek = cos(belsoErtek);
							break;
						case 3://tan
							belsoErtek = tan(belsoErtek);
							break;
						default:
							throw("Nem ismert függvény!");
						}
						tokenisedInput.insert(tokenisedInput.begin() + fuggvenyPos, Token('n', belsoErtek));

					}
				}
			}
		}
	}

	while (kindBenneVanE(tokenisedInput, '('))//zárójelek feldolgozása elég a ( karakter mert megnéztük hogy jók-e korábban
	{
		bool megvan = false;
		for (int nyitoPos = 0; nyitoPos < tokenisedInput.size() && !megvan; nyitoPos++)
		{
			if (tokenisedInput[nyitoPos].kind == '(')
			{

				int nyitott = 1;
				for (int zaroPos = nyitoPos + 1; zaroPos < tokenisedInput.size() && !megvan; zaroPos++)
				{
					if (tokenisedInput[zaroPos].kind == '(') nyitott++;
					if (tokenisedInput[zaroPos].kind == ')') nyitott--;
					if (tokenisedInput[zaroPos].kind == ')' && nyitott == 0)
					{
						megvan = true;
						if (nyitoPos + 1 == zaroPos) throw("Üres a zárójel");//üres a zárójel
						/*{
							tokenisedInput.erase(tokenisedInput.begin() + nyitoPos, tokenisedInput.begin() + zaroPos + 1);//üres a zárójel akk töröljük
							if (tokenisedInput.size() == 0) tokenisedInput.push_back(Token('n', 0)); //ha csak egy üres zárójel van és nincs más
						}*/
						std::vector<Token> tempTokenvect;//ezt fogjuk kiszámolni rekurzívan
						for (int i = nyitoPos + 1; i < zaroPos; i++)
						{
							tempTokenvect.push_back(tokenisedInput[i]);//beletesszük a zárójelen belüli részt
						}
						tokenisedInput.erase(tokenisedInput.begin() + nyitoPos, tokenisedInput.begin() + (zaroPos + 1));
						tokenisedInput.insert(tokenisedInput.begin() + nyitoPos, Token('n', calc(tempTokenvect)));

					}
				}
			}
		}
	}
	//{ '+', '-', '*', '/', '(', ')', '.', '^' };

	while (kindBenneVanE(tokenisedInput, '^'))
	{
		bool megvan = false;
		for (int jelHelye = 0; jelHelye < tokenisedInput.size() && !megvan; jelHelye++)
		{
			if (tokenisedInput[jelHelye].kind == '^')
			{
				megvan = true;
				if (jelHelye == 0 || tokenisedInput[jelHelye - 1].kind != 'n' || jelHelye + 1 > tokenisedInput.size() - 1 || tokenisedInput[jelHelye + 1].kind != 'n')
					throw("A műveleti jel két oldala nem szám");
				double tempCalcVal = pow(tokenisedInput[jelHelye - 1].value, tokenisedInput[jelHelye + 1].value);
				tokenisedInput.erase(tokenisedInput.begin() + (jelHelye - 1), tokenisedInput.begin() + (jelHelye + 2));
				tokenisedInput.insert(tokenisedInput.begin() + (jelHelye - 1), Token('n', tempCalcVal));
			}
		}
	}

	while (kindBenneVanE(tokenisedInput, '*') || kindBenneVanE(tokenisedInput, '/'))
	{
		bool megvan = false;
		for (int jelHelye = 0; jelHelye < tokenisedInput.size() && !megvan; jelHelye++)
		{
			if (tokenisedInput[jelHelye].kind == '*' || tokenisedInput[jelHelye].kind == '/')
			{
				megvan = true;
				if (jelHelye == 0 || tokenisedInput[jelHelye - 1].kind != 'n' || jelHelye + 1 > tokenisedInput.size() - 1 || tokenisedInput[jelHelye + 1].kind != 'n')
					throw("A műveleti jel két oldala nem szám");
				double tempCalcVal;
				switch (tokenisedInput[jelHelye].kind) {//{"*", "/" };
				case '*':
					tempCalcVal = tokenisedInput[jelHelye - 1].value * tokenisedInput[jelHelye + 1].value;
					break;
				case '/':
					tempCalcVal = tokenisedInput[jelHelye - 1].value / tokenisedInput[jelHelye + 1].value;
					break;
				default:
					throw("Nem ismert művelet!");
				}
				tokenisedInput.erase(tokenisedInput.begin() + (jelHelye - 1), tokenisedInput.begin() + (jelHelye + 2));
				tokenisedInput.insert(tokenisedInput.begin() + (jelHelye - 1), Token('n', tempCalcVal));
			}
		}
	}

	while (kindBenneVanE(tokenisedInput, '+') || kindBenneVanE(tokenisedInput, '-'))
	{
		bool megvan = false;
		for (int jelHelye = 0; jelHelye < tokenisedInput.size() && !megvan; jelHelye++)
		{
			if (tokenisedInput[jelHelye].kind == '+' || tokenisedInput[jelHelye].kind == '-')
			{
				megvan = true;
				if (jelHelye == 0 || tokenisedInput[jelHelye - 1].kind != 'n' || jelHelye + 1 > tokenisedInput.size() - 1 || tokenisedInput[jelHelye + 1].kind != 'n')
					throw("A műveleti jel két oldala nem szám");
				double tempCalcVal;
				switch (tokenisedInput[jelHelye].kind) {//{ "+", "-"};
				case '+':
					tempCalcVal = tokenisedInput[jelHelye - 1].value + tokenisedInput[jelHelye + 1].value;
					break;
				case '-':
					tempCalcVal = tokenisedInput[jelHelye - 1].value - tokenisedInput[jelHelye + 1].value;
					break;
				default:
					throw("Nem ismert művelet!");
				}
				tokenisedInput.erase(tokenisedInput.begin() + (jelHelye - 1), tokenisedInput.begin() + (jelHelye + 2));
				tokenisedInput.insert(tokenisedInput.begin() + (jelHelye - 1), Token('n', tempCalcVal));
			}
		}

	}

	if (tokenisedInput.size() == 1 && tokenisedInput[0].kind == 'n') return tokenisedInput[0].value; //ha szám a végeredmény
	else if (tokenisedInput.size() > 1 && tokenisedInput[0].kind == 'n' && tokenisedInput[1].kind == 'n') throw("Két érték közül hiányzik művelet!");

	//else throw("elbacta a \"proGramozó\""); //a végeredmény nem egy darab szám ¯\_(ツ)_/¯
	else dumpKinds(tokenisedInput);//dump token kinds from the current vector
}

double calculate(std::vector<char> inputCharVect) {//ez hívódik meg
	return calc(tokenise(inputCharVect));//azért itt alakítjuk át, hogy utána a másik fv-t már tudjuk rekurzívan hívni a zárójelekre
}