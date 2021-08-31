#include <unordered_map>
#include "FixConvert.h"

FixConvert::FixConvert() : expression{""} {}

FixConvert::FixConvert(string exp) 
	: expression{exp}, expressionInPostFix{""} 
{
	priorityTable.insert({{"+", Priority::THIRD}, {"-", Priority::THIRD}, {"*", Priority::SECOND}, {"/", Priority::SECOND}, {"(", Priority::ZERO}, {")", Priority::FIRST}});
	convert();
}

void FixConvert::convert()
{
	if (expression.empty()) 
	{
		expressionInPostFix = "";
		return;
	}
	
	// cout << "expression" << expression << endl;

	stringstream rawExpression{expression};
	string word;
	while (rawExpression >> word)
	{
		// cout << "word: " << word << endl;
		unordered_map<string, Priority>::iterator iter = priorityTable.find(word);
		if (iter == priorityTable.end())
			expressionInPostFix += word;
		else if (hang.empty())
			hang.push(word);
		else
		{
			switch(iter->second)
			{
				case Priority::THIRD:
					while (!hang.empty() && priorityTable.find(hang.top())->second != Priority::ZERO)
					{
						expressionInPostFix += hang.top();
						hang.pop();
					}
					hang.push(word);
					break;
				case Priority::SECOND:
					while (!hang.empty() && priorityTable.find(hang.top())->second == Priority::SECOND)
					{
						expressionInPostFix += hang.top();
						hang.pop();
					}
					hang.push(word);
					break;
				case Priority::FIRST:
					while (!hang.empty() && priorityTable.find(hang.top())->second != Priority::ZERO)
					{
						expressionInPostFix += hang.top();
						hang.pop();
					}
					hang.pop();
					break;
				default:
					hang.push(word);
					break;
			}
		}	
	}

	while (!hang.empty())
	{
		expressionInPostFix += hang.top();
		hang.pop();
	}
}

FixConvert::~FixConvert() {}

string FixConvert::getPostFixExpression()
{
	return expressionInPostFix;
}

