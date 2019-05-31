#ifndef __ARTICLE_EXCEPTION_H
#define __ARTICLE_EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

class ArticleException
{
public:
	virtual void show() const
	{
		cout << "Failed to create Article object!" << endl;
	}
};


class ArticleNameException : public ArticleException
{
private:
	string value;

public:
	ArticleNameException(const string& name) : value(name) {}

	virtual void show() const override
	{
		ArticleException::show();
		cout << "Invalid article name value \"" << value << "\" entered!" << endl;
	}
};


class ArticleMagazineException : public ArticleException
{
private:
	string value;

public:
	ArticleMagazineException(const string& magazine) : value(magazine) {}

	virtual void show() const override
	{
		ArticleException::show();
		cout << "Invalid magazine value \"" << value << "\" entered!" << endl;
	}
};

#endif