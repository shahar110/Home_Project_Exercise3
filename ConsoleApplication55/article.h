#ifndef __ARTICLE_H
#define __ARTICLE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "date.h"
#include <fstream>
#include "ArticleException.h"
using namespace std;

const int NAME_LENGTH = 20;
class Article
{
private:
	string articleName;
	string magazineName;
	Date publishDate;

public:
	Article(string articleName, string magazineName, const Date& date);
	Article(ifstream& in);
	bool setArticleName(string articleName);
	bool setMagazineName(string magazineName);
	bool setDate(const Date& newDate);

	const string& getArticleName() const { return articleName; }
	const string& getMagazineName() const { return magazineName; }
	Date getDate() const;

	void print() const;

};

#endif // !1