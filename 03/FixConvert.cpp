#include <unordered_map>
#include "FixConvert.h"

FixConvert::FixConvert() : expression{""} {}

FixConvert::FixConvert(string exp) 
	: expression{exp} 
{
	priorityTable.insert({{"+", Priority::THIRD}, {"-", Priority::THIRD}, {"*", Priority::SECOND}, {"/", Priority::SECOND}, {"(", Priority::FIRST}, {")", Priority::FIRST}});
	convert();
}

void FixConvert::convert()
{
	if (expression.empty()) 
	{
		expressionInPostFix = "";
		return;
	}

	stringstream rawExpression{expression};
	string word;
	while (rawExpression >> word)
	{
		unordered_map<string, Priority>::iterator iter = priorityTable->find(word);
		if (iter == priorityTable.end())
			expressionInPostFix += word;
		else
		{
			switch(iter->second)
			{
				case Priority::FIRST:
					hang.push(word);	
					break;
				case Priority::SECOND:
					while (hang.top()->second == Priority::FIRST)
					{
						expressionInPostFix += hang.top();
						hang.pop();
					}
					break;
				case Priority::THIRD:
					break;
				default:
					break;
			}
		}	
						
					
	}
}

FixConvert::~FixConvert() {}



