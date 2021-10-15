//#include "utility.h"
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>

struct ques
{ char q[50],o[50],corr;
};

void createEasy() {
	ofstream f("easy.dat",ios::binary);
	if(!f) cout<<"error";
	ques ob[10];
	strcpy(ob[0].q,"The weight of diamonds is measured in?");
	strcpy(ob[0].o,"A. Tola\nB. Carat\nC. Maund\nD. Troy\n");
	ob[0].corr='B';
	strcpy(ob[1].q,"Which state of India has the shortest coastline?");
	strcpy(ob[1].o,"A. Goa\nB. Maharashtra\nC. Odisha\nD. West Bengal\n");
	ob[1].corr='A';
	strcpy(ob[2].q,"Which country is not part of the UK?");
	strcpy(ob[2].o,"A. England\nB. Wales\nC. Ireland\nD. Scotland\n");
	ob[2].corr='C';
	strcpy(ob[3].q,"Which planet is not named after a god?");
	strcpy(ob[3].o,"A. Venus\nB. Uranus\nC. Earth\nD. Mars\n");
	ob[3].corr='C';
	strcpy(ob[4].q,"Ruble is the currency of which country?");
	strcpy(ob[4].o,"A. Ukraine\nB. Siberia\nC. Czech Rep\nD. Russia\n");
	ob[4].corr='D';
	//strcpy(ob[5].q,"What is the name of element 118?");
	//strcpy(ob[5].o,"A. Tennessine\nB. Moscovium\nC. Nihonium\nD. Oganeson\n");
	//ob[5].corr='D';
	strcpy(ob[5].q,"From what language is the word 'ketchup' derived?");
	strcpy(ob[5].o,"A. Italian\nB. Chinese\nC. German\nD. Tagalog\n");
	ob[5].corr='B';
	strcpy(ob[6].q,"What is the longest river on Earth?");
	strcpy(ob[6].o,"A. Amazon\nB. Hwang Ho\nC. Nile\nD. Mississippi\n");
	ob[6].corr='C';
	//strcpy(ob[8].q,"What colour is the world's most expensive diamond?");
	//strcpy(ob[8].o,"A. Blue\nB. Colourless\nC. Yellow\nD. Red\n");
	//ob[8].corr='A';
	//strcpy(ob[8].q,"Which is the hottest country?");
	//strcpy(ob[8].o,"A. Senegal\nB. Chad\nC. Nigeria\nD. Ethiopia\n");
	//ob[9].corr='D';
	for(int i=0;i<7;++i)
	      f.write((char*)&ob[i],sizeof(ob[i]));
	f.close();
}

void createMedium() {
	ofstream f("medium.dat",ios::binary);
	if(!f) cout<<"error";
	ques ob[10];
	strcpy(ob[0].q,"Which virus is from a place in Malaysia?");
	strcpy(ob[0].o,"A. Nipah\nB. Ebola\nC. Influenza\nD. HIV");
	ob[0].corr='A';
	strcpy(ob[1].q,"Which is the smallest country?");
	strcpy(ob[1].o,"A. Portugal\nB. Turkey\nC. Vatican City\nD. Sweden\n");
	ob[1].corr='C';
	strcpy(ob[2].q,"Which African country was never colonized?");
	strcpy(ob[2].o,"A. Egypt \nB. South Africa\nC. Ethiopia\nD. Libya\n");
	ob[2].corr='C';
	strcpy(ob[3].q,"Which of the following is not a German car?");
	strcpy(ob[3].o,"A. BMW \nB. Ferrari\nC. Audi\nD. Benz\n");
	ob[3].corr='B';
	//strcpy(ob[4].q,"Which of the foll isn't a left hand drive country?");
	//strcpy(ob[4].o,"A. Malta \nB. Cyprus\n C. Australia\nD. Brazil\n");
	//ob[4].corr='D';
	strcpy(ob[4].q,"What is the Hardy-Ramanujam number?");
	strcpy(ob[4].o,"A. 1728\nB. 1729\nC. 1730\nD. 1731\n");
	ob[4].corr='B';
	strcpy(ob[5].q,"How many pairs of chromosomes does a human have?");
	strcpy(ob[5].o,"A. 23\nB. 22\nC. 21\nD. 20\n");
	ob[5].corr='A';
	//strcpy(ob[7].q,"A century year is  divisible by which number to be a leap year?");
	//strcpy(ob[7].o,"A. 4\nB. 20\nC. 200\nD. 400\n");
	//ob[7].corr='D';
	strcpy(ob[6].q,"Which planet rotates in retrograde?");
	strcpy(ob[6].o,"A. Saturn\nB. Neptune C. Venus\nD. Uranus\n");
	ob[6].corr='C';
	//strcpy(ob[7].q,"How many in a baker's dozen?");
	//strcpy(ob[7].o,"A. 12\nB. 13\nC. 14\nD. 15\n");
	//ob[7].corr='B';
	for(int i=0;i<7;++i)
	      f.write((char*)&ob[i],sizeof(ob[i]));
	f.close();
}

void createHard() {
	ofstream f("hard.dat",ios::binary);
	if(!f) cout<<"error";
	ques ob[10];
	strcpy(ob[0].q,"What mammal lays eggs?");
	strcpy(ob[0].o,"A. Lizard\nB. Platypus\nC. Eagle\nD. Bear\n");
	ob[0].corr='B';
	strcpy(ob[1].q,"Last name of Japan's president?");
	strcpy(ob[1].o,"A. Abe\nB. Ace\nC. Ade\nD. Age\n");
	ob[1].corr='A';
	strcpy(ob[2].q,"Country code of Germany?");
	strcpy(ob[2].o,"A. GER\nB. GEM\nC. DEU\nD. DEM\n");
	ob[2].corr='C';
	strcpy(ob[3].q,"Which is not a prime number");
	strcpy(ob[3].o,"A. 2\nB. 3\nC. 4\nD. 5\n");
	ob[3].corr='C';
	strcpy(ob[4].q,"Symbol of Nitric Oxide?");
	strcpy(ob[4].o,"A. NO2\nB. N2O\nC. NO\nD. N2O2\n");
	ob[4].corr='C';
	strcpy(ob[5].q,"When is Boxing Sunday in Australia?");
	strcpy(ob[5].o,"A. 24/12\nB. 25/12\nC. 26/12\nD. 27/12\n");
	ob[5].corr='C';
	strcpy(ob[6].q,"Which is not a programming lang?");
	strcpy(ob[6].o,"A. C\nB. C++\nC. C+\nD. C#\n");
	ob[6].corr='C';

	for(int i=0;i<7;++i)
	      f.write((char*)&ob[i],sizeof(ob[i]));
	f.close();
}