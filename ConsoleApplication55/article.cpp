#include "article.h"


Article::Article(string articleName, string magazineName, const Date& date) : publishDate(date)
{
	setArticleName(articleName);
	setMagazineName(magazineName);
}

bool Article::setArticleName(string tmpArtName) throw (ArticleNameException)
{
	if (tmpArtName.length() > 100 || tmpArtName.empty())
		throw ArticleNameException(tmpArtName);

	this->articleName = tmpArtName;
	return true;
}

bool Article::setMagazineName(string tmpMagName) throw (ArticleMagazineException)
{
	if (tmpMagName.length() > 100 || tmpMagName.empty())
		throw ArticleMagazineException(tmpMagName);

	magazineName = tmpMagName;
	return true;
}

bool Article::setDate(const Date& newDate)
{
	publishDate = newDate;
	return true;
}


Date Article::getDate() const
{
	return publishDate;
}

void Article::print() const
{
	cout << "Article name: " << articleName << "    , published by magazie: : " << magazineName
		<< "    , at ";
	publishDate.printDate();
}



Article::Article(ifstream& in) : publishDate(in)
{
	int nameLengt, magazineLength;
	//input article name
	in.read((char*)&nameLengt, sizeof(nameLengt));
	in.read((char*)&articleName, nameLengt);

	//input magazine name
	in.read((char*)&magazineLength, sizeof(magazineLength));
	in.read((char*)&magazineName, magazineLength);
}