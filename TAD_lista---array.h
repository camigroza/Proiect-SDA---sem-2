#pragma once


template<class TElem>
class TADLista {
private:
	TElem* elems;
	int capacitate;
	int nr_elems;
	void resize();

public:
	TADLista();
	TADLista(const TADLista<TElem>& other);
	~TADLista() = default;

	void add(TElem e);
	int remove(TElem e);
	int modify(TElem e_vechi, TElem e_nou);
	int searchPos(TElem e);
	bool exists(TElem e);
	int size();

	TElem operator[](int poz);
	TADLista<TElem> operator=(const TADLista<TElem>& other);
	bool operator==(const TADLista<TElem>& other);
};

template<class TElem>
inline void TADLista<TElem>::resize()
{
	TElem* x = new TElem[capacitate * 2];
	for (int i = 0; i < nr_elems; i++)
		x[i] = elems[i];
	capacitate *= 2;
	delete[] elems;
	elems = x;
}

template<class TElem>
inline TADLista<TElem>::TADLista()
{
	this->capacitate = 10;
	this->elems = new TElem[capacitate];
	this->nr_elems = 0;
}

template<class TElem>
inline TADLista<TElem>::TADLista(const TADLista<TElem>& other)
{
	this->capacitate = other.capacitate;
	this->nr_elems = other.nr_elems;
	this->elems = new TElem[capacitate];
	for (int i = 0; i < this->nr_elems; i++)
		this->elems[i] = other.elems[i];
}

template<class TElem>
inline void TADLista<TElem>::add(TElem e)
{
	if (this->nr_elems == this->capacitate) resize();
	this->elems[this->nr_elems++] = e;
}

template<class TElem>
inline int TADLista<TElem>::remove(TElem e)
{
	if (!exists(e)) return 0;
	int poz = searchPos(e);
	for (int i = poz; i < this->nr_elems - 1; i++)
		elems[i] = elems[i + 1];
	this->nr_elems--;
	return 1;
}

template<class TElem>
inline int TADLista<TElem>::modify(TElem e_vechi, TElem e_nou)
{
	if (!exists(e_vechi)) return 0;
	int poz = searchPos(e_vechi);
	elems[poz] = e_nou;
	return 1;
}

template<class TElem>
inline int TADLista<TElem>::searchPos(TElem e)
{
	for (int i = 0; i < this->nr_elems; i++)
		if (elems[i] == e) return i;
	return -1;
}

template<class TElem>
inline bool TADLista<TElem>::exists(TElem e)
{
	for (int i = 0; i < this->nr_elems; i++)
		if (elems[i] == e) return true;
	return false;
}

template<class TElem>
inline int TADLista<TElem>::size()
{
	return this->nr_elems;
}

template<class TElem>
inline TElem TADLista<TElem>::operator[](int poz)
{
	if (poz >= 0 && poz < this->nr_elems) return elems[poz];
	return {};
}

template<class TElem>
inline TADLista<TElem> TADLista<TElem>::operator=(const TADLista<TElem>& other)
{
	if (this != &other)
	{
		this->capacitate = other.capacitate;
		this->nr_elems = other.nr_elems;
		this->elems = new TElem[capacitate];
		for (int i = 0; i < this->nr_elems; i++)
			this->elems[i] = other.elems[i];
	}
	return *this;
}

template<class TElem>
inline bool TADLista<TElem>::operator==(const TADLista<TElem>& other)
{
	if (this->capacitate != other.capacitate) return false;
	if (this->nr_elems != other.nr_elems) return false;
	for (int i = 0; i < other.nr_elems; i++)
		if (!(elems[i] == other.elems[i])) return false;
	return true;
}
