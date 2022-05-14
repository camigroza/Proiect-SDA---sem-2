#pragma once

template<typename T>
class TADMultimeOrdonata;

template<class TElem>
class ABCNode {
private:
	TElem info;
	ABCNode<TElem>* left;
	ABCNode<TElem>* right;

public:
	ABCNode();
	ABCNode(TElem info_);
	ABCNode(TElem info_, ABCNode<TElem>* left_, ABCNode<TElem>* right_);
	~ABCNode() = default;

	ABCNode<TElem>& operator=(const ABCNode<TElem>& other);
	bool operator==(const ABCNode<TElem>& other);

	friend class TADMultimeOrdonata<TElem>;
};

template<class TElem>
inline ABCNode<TElem>::ABCNode()
{
	this->info = {};
	this->left = nullptr;
	this->right = nullptr;
}

template<class TElem>
inline ABCNode<TElem>::ABCNode(TElem info_)
{
	this->info = info_;
	this->left = nullptr;
	this->right = nullptr;
}

template<class TElem>
inline ABCNode<TElem>::ABCNode(TElem info_, ABCNode<TElem>* left_, ABCNode<TElem>* right_)
{
	this->info = info_;
	this->left = left_;
	this->right = right_;
}

template<class TElem>
inline ABCNode<TElem>& ABCNode<TElem>::operator=(const ABCNode<TElem>& other)
{
	if (this != &other)
	{
		this->info = other.info;
		if (this->left)
		{
			delete this->left;
			this->left = nullptr;
		}
		if (this->right)
		{
			delete this->right;
			this->right = nullptr;
		}
		this->left = other.left;
		this->right = other.right;
	}
	return *this;
}

template<class TElem>
inline bool ABCNode<TElem>::operator==(const ABCNode<TElem>& other)
{
	return this->info == other.info && this->left == other.left && this->right == other.right;
}
