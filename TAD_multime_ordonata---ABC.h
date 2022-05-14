#pragma once
#include "ABCNode.h"
#include <vector>
using namespace std;

template<class TElem>
class TADMultimeOrdonata {
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
	TADMultimeOrdonata();
	~TADMultimeOrdonata() = default;

	void add(TElem elem);
	int remove(TElem elem);
	int modify(TElem e_vechi, TElem e_nou);
	int searchPos(TElem elem);
	bool exists(TElem elem);
	int size();

	TElem operator[](int poz);
	TADMultimeOrdonata<TElem> operator=(TADMultimeOrdonata<TElem>& other);
	bool operator==(TADMultimeOrdonata<TElem>& other);
};

template<class TElem>
inline void TADMultimeOrdonata<TElem>::add(ABCNode<TElem>* node, TElem elem)
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
inline ABCNode<TElem>* TADMultimeOrdonata<TElem>::search(ABCNode<TElem>* node, TElem elem)
{
	if (elem == node->info) return node;
	else if (elem < node->info)
	{
		if (node->left == nullptr) return nullptr;
		search(node->left, elem);
	}
	else if (elem > node->info)
	{
		if (node->right == nullptr) return nullptr;
		search(node->right, elem);
	}
}

template<class TElem>
inline void TADMultimeOrdonata<TElem>::remove(ABCNode<TElem>*& node, TElem elem)
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
inline void TADMultimeOrdonata<TElem>::getAll(ABCNode<TElem>* node, vector<TElem>& all)
{
	if (node != nullptr)
	{
		getAll(node->left, all);
		all.push_back(node->info);
		getAll(node->right, all);
	}
}

template<class TElem>
inline void TADMultimeOrdonata<TElem>::stergAux(ABCNode<TElem>*& p, ABCNode<TElem>*& R)
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
inline TADMultimeOrdonata<TElem>::TADMultimeOrdonata()
{
	this->root = nullptr;
}

template<class TElem>
inline void TADMultimeOrdonata<TElem>::add(TElem elem)
{
	if (this->root == nullptr) this->root = new ABCNode<TElem>(elem, nullptr, nullptr);
	else add(this->root, elem);
}

template<class TElem>
inline int TADMultimeOrdonata<TElem>::remove(TElem elem)
{
	if (search(elem) == nullptr)
		return 0;
	remove(this->root, elem);
	return 1;
}

template<class TElem>
inline int TADMultimeOrdonata<TElem>::modify(TElem e_vechi, TElem e_nou)
{
	if (!exists(e_vechi)) return 0;
	remove(e_vechi);
	add(e_nou);
	return 1;
}

template<class TElem>
inline int TADMultimeOrdonata<TElem>::searchPos(TElem elem)
{
	if (!exists(elem)) return -1;
	vector<TElem> all = getAll();
	for (int i = 0; i < all.size(); i++)
		if (all[i] == elem) return i;
}

template<class TElem>
inline bool TADMultimeOrdonata<TElem>::exists(TElem elem)
{
	if (search(elem) == nullptr) return false;
	return true;
}

template<class TElem>
inline ABCNode<TElem>* TADMultimeOrdonata<TElem>::search(TElem elem)
{
	if (this->root == nullptr)
		return nullptr;
	return search(this->root, elem);
}

template<class TElem>
inline vector<TElem> TADMultimeOrdonata<TElem>::getAll()
{
	vector<TElem> all;
	getAll(this->root, all);
	return all;
}

template<class TElem>
inline int TADMultimeOrdonata<TElem>::size()
{
	return getAll().size();
}

template<class TElem>
inline TElem TADMultimeOrdonata<TElem>::operator[](int poz)
{
	if (poz >= 0 && poz < this->size()) return getAll()[poz];
	return {};
}

template<class TElem>
inline TADMultimeOrdonata<TElem> TADMultimeOrdonata<TElem>::operator=(TADMultimeOrdonata<TElem>& other)
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
inline bool TADMultimeOrdonata<TElem>::operator==(TADMultimeOrdonata<TElem>& other)
{
	vector<TElem> all_this = this->getAll();
	vector<TElem> all_other = other.getAll();
	if (all_this.size() != all_other.size()) return false;
	for (int i = 0; i < all_this.size(); i++)
		if (!(all_this[i] == all_other[i])) return false;
	return true;
}
