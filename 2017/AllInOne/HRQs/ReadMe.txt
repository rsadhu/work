#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<vector>
#include <limits> // for numeric_limits
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
using namespace std;


struct Person
{
	string Name = "Unknown";

	typedef pair<string, string> Trait;
	vector<Trait> Traits;
};


vector<string>split(string s, char tok)
{

	std::istringstream ss1(s);
	std::string token;

	vector<string> d1;
	while (getline(ss1, token, tok)) {
		d1.push_back(token);
	}
	return d1;
}

Person ConvertRawInputToPerson(string rawInput)
{
	Person person;
	vector<string> traits = split(rawInput, ' ');
	for (string trait : traits)
	{
		vector<string> keyValuePair = split(trait, '=');
		if (keyValuePair.size() == 2)
		{

			string key = keyValuePair[0];
			string value = keyValuePair[1];

			if (key == "Name") { person.Name = value; }
			else { person.Traits.push_back(make_pair(key, value)); }
		}
		else
		{
			throw exception();
		}
	}
	return person;
}

bool StringEquals(string left, string right)
{
	//if (left.size() == right.size())
	{
		for (int i = 0; i < left.length(); ++i)
		{
			if (left[i] != right[i]) { return false; }
		}
		return true;
	}//return false;
}

bool HasTrait(vector<Person::Trait> & traits, Person::Trait & soughtTrait)
{
	return find_if(traits.begin(), traits.end(),
		[soughtTrait](Person::Trait & trait)
	{
		return StringEquals(soughtTrait.first, trait.first) && StringEquals(soughtTrait.second, trait.second);
	})
		!= traits.end();
}

class Registry
{
	std::vector<Person> mPersons;

public:
	void Add(Person person)
	{
		mPersons.push_back(person);
	}

	Person FindMatchingPersonByRawTraits(string rawTraits)
	{
		Person soughtPerson;;

		vector<string> traits = split(rawTraits, ' ');
		for (string trait : traits)
		{
			vector<string> keyValuePair = split(trait, '=');

			string key = keyValuePair[0];
			string value = keyValuePair[1];

			soughtPerson.Traits.push_back(make_pair(key, value));
		}


		for (Person & person : mPersons)
		{
			bool ret = false;

			for (auto & soughtTrait : soughtPerson.Traits)
			{
				if (soughtTrait.first == "Name")
				{
					if (soughtTrait.second == person.Name)
					{
						return person;
					}
				}
				else
				{
					if (HasTrait(person.Traits, soughtTrait))
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<vector>
#include <limits> // for numeric_limits
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
						using namespace std;


					struct Person
					{
						string Name = "Unknown";

						typedef pair<string, string> Trait;
						vector<Trait> Traits;
					};


					vector<string>split(string s, char tok)
					{

						std::istringstream ss1(s);
						std::string token;

						vector<string> d1;
						while (getline(ss1, token, tok)) {
							d1.push_back(token);
						}
						return d1;
					}

					Person ConvertRawInputToPerson(string rawInput)
					{
						Person person;
						vector<string> traits = split(rawInput, ' ');
						for (string trait : traits)
						{
							vector<string> keyValuePair = split(trait, '=');
							if (keyValuePair.size() == 2)
							{

								string key = keyValuePair[0];
								string value = keyValuePair[1];

								if (key == "Name") { person.Name = value; }
								else { person.Traits.push_back(make_pair(key, value)); }
							}
							else
							{
								throw exception();
							}
						}
						return person;
					}

					bool StringEquals(string left, string right)
					{
						//if (left.size() == right.size())
						{
							for (int i = 0; i < left.length(); ++i)
							{
								if (left[i] != right[i]) { return false; }
							}
							return true;
						}//return false;
					}




					7
A,B,1
A,D,3
A,E,2
B,C,1
B,E,2
C,E,2
C,F,3
D,E,1
D,F,7
D,G,5
E,F,4
F,G,9