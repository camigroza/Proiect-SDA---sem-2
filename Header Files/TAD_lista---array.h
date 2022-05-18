#pragma once


template<class TElem>
class Lista {
private:
	TElem* elems;
	int capacitate;
	int nr_elems;
	void resize();

public:
	//constructori si destructor
	Lista();
	Lista(const Lista<TElem>& other);
	~Lista() = default;

	/// <summary>
	/// Adauga un element in lista
	/// </summary>
	/// <param name="e"> elementul de adaugat </param>
	void add(TElem e);

	/// <summary>
	/// Sterge un element din lista
	/// </summary>
	/// <param name="e"> elementul de sters </param>
	/// <returns> 0 daca nu exista in lista elementul dat, 1 altfel </returns>
	int remove(TElem e);

	/// <summary>
	/// Modifica un element
	/// </summary>
	/// <param name="e_vechi"> elementul de modificat </param>
	/// <param name="e_nou"> elementul cu care se modifica </param>
	/// <returns> 0 daca nu exista elementul dat in lista, 1 altfel </returns>
	int modify(TElem e_vechi, TElem e_nou);

	/// <summary>
	/// Indica pozitia in lista a unui element
	/// </summary>
	/// <param name="e"> elementul dat </param>
	/// <returns> pozitia pe care se afla elementul in lista daca acesta exista, -1 in caz contrar </returns>
	int searchPos(TElem e);

	/// <summary>
	/// Indica daca un element se afla in lista
	/// </summary>
	/// <param name="e"> elementul dat </param>
	/// <returns> true, daca elementul se afla in lista, false in caz contrar </returns>
	bool exists(TElem e);

	/// <summary>
	/// Indica dimensiunea listei
	/// </summary>
	/// <returns> numarul de elemente din lista </returns>
	int size();

	//overload la operatori
	TElem operator[](int poz);
	Lista<TElem> operator=(const Lista<TElem>& other);
	bool operator==(const Lista<TElem>& other);
};

template<class TElem>
inline void Lista<TElem>::resize()
{
	TElem* x = new TElem[capacitate * 2];
	for (int i = 0; i < nr_elems; i++)
		x[i] = elems[i];
	capacitate *= 2;
	delete[] elems;
	elems = x;
}

template<class TElem>
inline Lista<TElem>::Lista()
{
	this->capacitate = 10;
	this->elems = new TElem[capacitate];
	this->nr_elems = 0;
}

template<class TElem>
inline Lista<TElem>::Lista(const Lista<TElem>& other)
{
	this->capacitate = other.capacitate;
	this->nr_elems = other.nr_elems;
	this->elems = new TElem[capacitate];
	for (int i = 0; i < this->nr_elems; i++)
		this->elems[i] = other.elems[i];
}

template<class TElem>
inline void Lista<TElem>::add(TElem e)
{
	if (this->nr_elems == this->capacitate) resize();
	this->elems[this->nr_elems++] = e;
}

template<class TElem>
inline int Lista<TElem>::remove(TElem e)
{
	if (!exists(e)) return 0;
	int poz = searchPos(e);
	for (int i = poz; i < this->nr_elems - 1; i++)
		elems[i] = elems[i + 1];
	this->nr_elems--;
	return 1;
}

template<class TElem>
inline int Lista<TElem>::modify(TElem e_vechi, TElem e_nou)
{
	if (!exists(e_vechi)) return 0;
	int poz = searchPos(e_vechi);
	elems[poz] = e_nou;
	return 1;
}

template<class TElem>
inline int Lista<TElem>::searchPos(TElem e)
{
	for (int i = 0; i < this->nr_elems; i++)
		if (elems[i] == e) return i;
	return -1;
}

template<class TElem>
inline bool Lista<TElem>::exists(TElem e)
{
	for (int i = 0; i < this->nr_elems; i++)
		if (elems[i] == e) return true;
	return false;
}

template<class TElem>
inline int Lista<TElem>::size()
{
	return this->nr_elems;
}

template<class TElem>
inline TElem Lista<TElem>::operator[](int poz)
{
	if (poz >= 0 && poz < this->nr_elems) return elems[poz];
	return {};
}

template<class TElem>
inline Lista<TElem> Lista<TElem>::operator=(const Lista<TElem>& other)
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
inline bool Lista<TElem>::operator==(const Lista<TElem>& other)
{
	if (this->capacitate != other.capacitate) return false;
	if (this->nr_elems != other.nr_elems) return false;
	for (int i = 0; i < other.nr_elems; i++)
		if (!(elems[i] == other.elems[i])) return false;
	return true;
}
