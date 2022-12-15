#ifndef Option_H
#define Option_H

#include <iostream>
#include <string>

using namespace std;

class Option
{
	friend ostream& operator<<(ostream& s,const Option&);
	friend istream& operator>>(istream& s,Option&);

	private:
		string code;
		string intitule;
		float prix;
	public:
		Option();
		Option(string,string,float);
		Option(const Option&);
		~Option();

		void setCode(string);
		void setIntitule(string);
		void setPrix(float);

		string getCode()const;
		string getIntitule()const;
		float getPrix()const;

		void Affiche()const;
		Option operator--();
		Option operator--(int);
};

#endif 