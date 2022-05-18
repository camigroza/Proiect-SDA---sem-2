#pragma once
#include "ABCNode.h"
#include <vector>
using namespace std;

template<class TElem>
class MultimeOrdonata {
private:
	ABCNode<TElem>* root;
	void add(ABCNode<TElem>* node, TElem elem);
	ABCNode<TElem>* search(TElem elem);
	ABCNode<TElem>* search(ABCNode<TElem>* node, TElem elem);
	void remove(ABCNode<TElem>*& node, TElem elem);
	void getAll(ABCNode<TElem>* node, vector<TElem>& all);
	void stergAux(ABCNode<TElem>*& p, ABCNode<TElem>*& R);
	vector<TElem> getAll();

public:
	//constructori si destructor
	MultimeOrdonata();
	~MultimeOrdonata() = default;

	/// <summary>
	/// Adauga un element in multime
	/// </summary>
	/// <param name="elem"> elementul de adaugat </param>
	void add(TElem elem);

	/// <summary>
	/// Sterge un element din multime
	/// </summary>
	/// <param name="elem"> elementul de sters </param>
	/// <returns> 0 daca elementul nu se afla in multime, 1 in caz contrar </returns>
	int remove(TElem elem);

	/// <summary>
	/// Modifica un element
	/// </summary>
	/// <param name="e_vechi"> elementul de modificat </param>
	/// <param name="e_nou"> elementul cu care se modifica </param>
	/// <returns>
	/// --> 0 daca nu exista elementul vechi de modificat sau daca exista deja in multime elementul nou cu care vrea sa se modifice
	/// --> 1 altfel
	/// </returns>
	int modify(TElem e_vechi, TElem e_nou);

	/// <summary>
	/// Indica pozitia pe care se afla un element
	/// </summary>
	/// <param name="elem"> elementul a carui pozitie o cautam </param>
	/// <returns> pozitia pe care se afla elementul in multimea ordonata daca acesta exista, -1 in caz contrar </returns>
	int searchPos(TElem elem);

	/// <summary>
	/// Indica daca exista un element in multime
	/// </summary>
	/// <param name="elem"> elementul dat </param>
	/// <returns> true, daca elementul se afla in multime, false in caz contrar </returns>
	bool exists(TElem elem);

	/// <summary>
	/// Indica dimensiunea multimii
	/// </summary>
	/// <returns> numerul de elemente din multime </returns>
	int size();

	//overload la operatori
	TElem operator[](int poz);
	MultimeOrdonata<TElem> operator=(MultimeOrdonata<TElem>& other);
	bool operator==(MultimeOrdonata<TElem>& other);
};

template<class TElem>
inline void MultimeOrdonata<TElem>::add(ABCNode<TElem>* node, TElem elem)
{
	if (elem < node->info)
	{
		if (node->left != nullptr)
			add(node->left, elem);
		else
			node->left = new ABCNode<TElem>(elem, nullptr, nullptr);
	}
	else if (elem > node->info)
	{
		if (node->right != nullptr)
			add(node->right, elem);
		else
			node->right = new ABCNode<TElem>(elem, nullptr, nullptr);
	}
}

template<class TElem>
inline ABCNode<TElem>* MultimeOrdonata<TElem>::search(ABCNode<TElem>* node, TElem elem)
{
	if (elem == node->info) return node;
	else if (elem < node->info)
	{
		if (node->left == nullptr) return nullptr;
		return search(node->left, elem);
	}
	else if (elem > node->info)
	{
		if (node->right == nullptr) return nullptr;
		return search(node->right, elem);
	}
}

template<class TElem>
inline void MultimeOrdonata<TElem>::remove(ABCNode<TElem>*& node, TElem elem)
{
	if (node->info == elem)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			ABCNode<TElem>* aux = new ABCNode<TElem>;
			aux = node;
			node = nullptr;
			delete aux;
		}
		else if (node->left == nullptr)
		{
			ABCNode<TElem>* aux = new ABCNode<TElem>;
			aux = node;
			node = node->right;
			delete aux;
		}
		else if (node->right == nullptr)
		{
			ABCNode<TElem>* aux = new ABCNode<TElem>;
			aux = node;
			node = node->left;
			delete aux;
		}
		else
			stergAux(node->left, node);
	}
	else if (elem < node->info)
		remove(node->left, elem);
	else
		remove(node->right, elem);
}

template<class TElem>
inline void MultimeOrdonata<TElem>::getAll(ABCNode<TElem>* node, vector<TElem>& all)
{
	if (node != nullptr)
	{
		getAll(node->left, all);
		all.push_back(node->info);
		getAll(node->right, all);
	}
}

template<class TElem>
inline void MultimeOrdonata<TElem>::stergAux(ABCNode<TElem>*& p, ABCNode<TElem>*& R)
{
	// p - pointerul cu care identificam nodul cel mai din dreapta
	// R - nodul care trebuie sters

	if (p->right != nullptr)
		stergAux(p->right, R);
	else
	{
		R->info = p->info;
		ABCNode<TElem>* aux = new ABCNode<TElem>;
		aux = p;
		p = p->left;
		delete aux;
	}
}

template<class TElem>
inline MultimeOrdonata<TElem>::MultimeOrdonata()
{
	this->root = nullptr;
}

template<class TElem>
inline void MultimeOrdonata<TElem>::add(TElem elem)
{
	if (this->root == nullptr) this->root = new ABCNode<TElem>(elem, nullptr, nullptr);
	else add(this->root, elem);
}

template<class TElem>
inline int MultimeOrdonata<TElem>::remove(TElem elem)
{
	if (search(elem) == nullptr)
		return 0;
	remove(this->root, elem);
	return 1;
}

template<class TElem>
inline int MultimeOrdonata<TElem>::modify(TElem e_vechi, TElem e_nou)
{
	if (!exists(e_vechi)) return 0;
	if (exists(e_nou)) return 0;
	remove(e_vechi);
	add(e_nou);
	return 1;
}

template<class TElem>
inline int MultimeOrdonata<TElem>::searchPos(TElem elem)
{
	if (!exists(elem)) return -1;
	vector<TElem> all = getAll();
	for (int i = 0; i < all.size(); i++)
		if (all[i] == elem) return i;
}

template<class TElem>
inline bool MultimeOrdonata<TElem>::exists(TElem elem)
{
	if (search(elem) == nullptr) return false;
	return true;
}

template<class TElem>
inline ABCNode<TElem>* MultimeOrdonata<TElem>::search(TElem elem)
{
	if (this->root == nullptr)
		return nullptr;
	return search(this->root, elem);
}

template<class TElem>
inline vector<TElem> MultimeOrdonata<TElem>::getAll()
{
	vector<TElem> all;
	getAll(this->root, all);
	return all;
}

template<class TElem>
inline int MultimeOrdonata<TElem>::size()
{
	return getAll().size();
}

template<class TElem>
inline TElem MultimeOrdonata<TElem>::operator[](int poz)
{
	if (poz >= 0 && poz < this->size()) return getAll()[poz];
	return {};
}

template<class TElem>
inline MultimeOrdonata<TElem> MultimeOrdonata<TElem>::operator=(MultimeOrdonata<TElem>& other)
{
	if (this != &other)
	{
		vector<TElem> all = other.getAll();
		for (int i = 0; i < all.size();i++)
			this->add(all[i]);
	}
	return *this;
}

template<class TElem>
inline bool MultimeOrdonata<TElem>::operator==(MultimeOrdonata<TElem>& other)
{
	vector<TElem> all_this = this->getAll();
	vector<TElem> all_other = other.getAll();
	if (all_this.size() != all_other.size()) return false;
	for (int i = 0; i < all_this.size(); i++)
		if (!(all_this[i] == all_other[i])) return false;
	return true;
}
