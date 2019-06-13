#include "researcher.h"

Researcher::Researcher(const string& name) : StaffMember(name) 
{
}
Researcher::Researcher(ifstream& in) : StaffMember(in)
{

}

bool Researcher::operator<(const Researcher & r) const
{
	if (this->getNumOfArticles() < r.getNumOfArticles())
		return true;
	else
		return false;
}

bool Researcher::operator>(const Researcher & r) const
{
	if (this->getNumOfArticles() > r.getNumOfArticles())
		return true;
	else
		return false;
}

bool Researcher::operator==(const Researcher & r) const
{
	if (this->getNumOfArticles() == r.getNumOfArticles())
		return true;
	else
		return false;
}

bool Researcher::operator!=(const Researcher & r) const
{
	if (this->getNumOfArticles() != r.getNumOfArticles())
		return true;
	else
		return false;
}

bool Researcher::operator>=(const Researcher & r) const
{
	if (this->getNumOfArticles() > r.getNumOfArticles() || this->getNumOfArticles() == r.getNumOfArticles())
		return true;
	else
		return false;
}

bool Researcher::operator<=(const Researcher & r) const
{
	if (this->getNumOfArticles() < r.getNumOfArticles() || this->getNumOfArticles() == r.getNumOfArticles())
		return true;
	else
		return false;
}

bool Researcher::addArticle(const string& articleName, const string& magazineName, const Date& date)
{
	try
	{
		Article r(articleName, magazineName, date);
		articleArr.push_back(r);
		return true;
	}
	catch (ArticleNameException& e)
	{
		e.show();
	}
	catch (ArticleMagazineException& e)
	{
		e.show();
	}
}

int Researcher::getNumOfArticles() const
{
	return articleArr.size();
}

void Researcher::printDetails() const
{
	cout << "Researcher Name: " << name << "    , ID: " << employeeNum;
}

void Researcher::printArticleList() const
{
	cout << name << " - Displaying list of articles(" << articleArr.size() << "):" << endl;
	for (int i = 0; i < articleArr.size(); i++)
	{
		articleArr[i].print();
		cout << endl;
	}
}