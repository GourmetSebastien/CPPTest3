#include "Option.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/

Option::Option()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de Option"<<endl;
	#endif
	
	setCode("Pas de code");
	setIntitule("Pas d'intitulé");
	prix=0;
}
Option::Option(string c,string i,float p)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de Option"<<endl;
	#endif

	setCode(c);
	setIntitule(i);
	setPrix(p);
}
Option::Option(const Option &source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie d'option"<<endl;
	#endif

	setCode(source.getCode());
	setIntitule(source.getIntitule());
	setPrix(source.getPrix());
}
Option::~Option()
{
	#ifdef DEBUG
		cout<<"Destructeur d'Option"<<endl;
	#endif

}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
string Option::getCode()const
{
	return code;
}
string Option::getIntitule()const
{
	return intitule;
}
float Option::getPrix()const
{
	return prix;
}
void Option::setCode(string c)
{
	code = c;
}
void Option::setIntitule(string i)
{
	intitule=i;
}
void Option::setPrix(float p)
{
	if(p>=0)
		prix=p;
}

/*********************************************/
/************Modeles publiques****************/
/*********************************************/

void Option::Affiche()const
{
	cout<<"Code: "<<code<<endl<<"Intitulé: "<<intitule<<endl<<"Prix :"<<prix<<endl;
}
/*********************************************/
/*************Surchage opérateur**************/
/*********************************************/
ostream& operator<<(ostream& s,const Option& source)
{
	s<<"Code: "<<source.getCode()<<endl<<"Intitulé: "<<source.getIntitule()<<endl<<"Prix :"<<source.getPrix()<<endl;
	return s;
}
istream& operator>>(istream& s,Option& source)
{
	string code,intitule;
	float prix;

	cout<<"Code:";
	getline(cin,code);
	cout<<endl;

	cout<<"intitule:";
	getline(cin,intitule);
	cout<<endl;

	cout<<"Prix:";
	cin>>prix;
	cout<<endl;

	source.setCode(code);
	source.setIntitule(intitule);
	source.setPrix(prix);

	return s;
}
Option Option::operator--()
{
	setPrix(getPrix()-50);

	return (*this);
}
Option Option::operator--(int n)
{
	Option tmp(*this);
	(*this).setPrix(((*this).getPrix()-50));

	return tmp;
}