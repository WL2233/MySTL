//T:<<26.11>>13m51s

#ifndef MYDEQUE_H
#define MYDEQUE_H


#ifndef SAFE_DELETE
#define SAFE_DELETE(p){if(p){delete;p=nullptr;}}
#endif // !SAFE_DELETE
#ifndef SAFE_DELARR
#define SAFE_DELARR(p){if(p){delete[]p;p=nullptr;}}
#endif // !SAFE_DELARR

template<class T>
class mydeque
{
public:
	mydeque()
	{
		 _pleftdata = nullptr;
		 _leftcapacity = 0;
		 _leftsize = 0;

		 _prightdata = nullptr;
		 _rightcapacity = 0;
		 _rightsize = 0;
	
	}

	mydeque(size_t count)
	{
		if (count > 0)
		{
		
			_leftcapacity = count/2;
			_leftsize = _leftcapacity;
			_rightcapacity = count - _leftcapacity;
			_rightsize = _rightcapacity;

			if (_leftcapacity > 0)
			{
				_pleftdata = new T[_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			_prightdata = new T[_rightcapacity];

			for (int i = (int)_leftsize - 1; i >= 0; --i)
			{
				_pleftdata[i] = T();
			}

			for (size_t i = 0; i < _rightsize; ++i)
			{
				_prightdata[i] = T();
			}
			
		}
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}
	}

	mydeque(size_t count, T const& val)
	{
		if (count > 0)
		{

			_leftcapacity = count / 2;
			_leftsize = _leftcapacity;
			_rightcapacity = count - _leftcapacity;
			_rightsize = _rightcapacity;
			if (_leftcapacity > 0)
			{
				_pleftdata = new T[_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			_prightdata = new T[_rightcapacity];

			for (int i = (int)_leftsize - 1; i >= 0; --i)
			{
				_pleftdata[i] = val;
			}

			for (size_t i = 0; i < _rightsize; ++i)
			{
				_prightdata[i] = val;
			}

		}
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}
	}
	//拷贝构造
	mydeque(mydeque const& other)
	{
	
		size_t othersize = other._leftsize + other._rightsize;

		if(othersize >0)
		{ 
			this->_leftcapacity = othersize / 2;
			this->_rightcapacity = othersize - this->_leftcapacity;
			this->_leftsize = this->_leftcapacity;
			this->_rightsize = this->_rightcapacity;

			if (this->_leftcapacity > 0)
			{
				this->_pleftdata = new T[this->_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			this->_prightdata = new T[this->_rightcapacity];

			bool thisinleft = (this->_leftsize > 0) ? true : false;
			bool otherinleft = (other._leftsize > 0) ? true : false;

			size_t thisrearindex;
			size_t otherrearindex;

			if (thisinleft)
			{
				thisrearindex = this->_leftsize - 1;
			}
			else
			{
				thisrearindex = 0;
			}

			if (otherinleft)
			{
				otherrearindex = other._leftsize - 1;
			}
			else
			{
				otherrearindex = 0;
			}

			for (size_t i = 0; i < othersize; ++i)
			{
				if (thisinleft)
				{
					if (otherinleft)
					{
						this->_pleftdata[thisrearindex] = other._pleftdata[otherrearindex];
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						this->_pleftdata[thisrearindex] = other._prightdata[otherrearindex];
						++otherrearindex;
					}
					if (thisrearindex > 0)
					{
						--thisrearindex;
					}
					else
					{
						thisrearindex = 0;
						thisinleft = false;
					}
				}
				else
				{
					if (otherinleft)
					{
						this->_prightdata[thisrearindex] = other._pleftdata[otherrearindex];
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						this->_prightdata[thisrearindex] = other._prightdata[otherrearindex];
						++otherrearindex;
					}
					++thisrearindex;
				}
			}
		}	
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}
	}

	
	template<class InputIterator, class = typename enable_if<_Is_iterator<InputIterator>::value, void>::type>
	mydeque(InputIterator first, InputIterator last)
	{
		size_t count = last - first;

		if(count>0)
		{
			InputIterator pt = first;
			_leftcapacity = count / 2;
			_leftsize = _leftcapacity;
			_rightcapacity = count - _leftcapacity;
			_rightsize = _rightcapacity;
			if (_leftcapacity > 0)
			{
				_pleftdata = new T[_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			_prightdata = new T[_rightcapacity];

			for (int i = _leftsize - 1; i >= 0; --i)
			{
				_pleftdata[i] = *(pt++);
			}

			for (size_t i = 0; i < _rightsize; ++i)
			{
				_prightdata[i] = *(pt++);
			}

		}
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}
	}

	//赋值运算
	mydeque& operator=(mydeque const& other)
	{
		SAFE_DELARR(_pleftdata);
		/*_leftcapacity = 0;
		_leftsize = 0;*/

		SAFE_DELARR(_prightdata);
	/*	_rightcapacity = 0;
		_rightsize = 0;*/
		size_t othersize = other._leftsize + other._rightsize;

		if (othersize > 0)
		{
			this->_leftcapacity = othersize / 2;
			this->_rightcapacity = othersize - this->_leftcapacity;
			this->_leftsize = this->_leftcapacity;
			this->_rightsize = this->_rightcapacity;

			if (this->_leftcapacity > 0)
			{
				this->_pleftdata = new T[this->_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			this->_prightdata = new T[this->_rightcapacity];

			bool thisinleft = (this->_leftsize > 0) ? true : false;
			bool otherinleft = (other._leftsize > 0) ? true : false;

			size_t thisrearindex;
			size_t otherrearindex;

			if (thisinleft)
			{
				thisrearindex = this->_leftsize - 1;
			}
			else
			{
				thisrearindex = 0;
			}

			if (otherinleft)
			{
				otherrearindex = other._leftsize - 1;
			}
			else
			{
				otherrearindex = 0;
			}

			for (size_t i = 0; i < othersize; ++i)
			{
				if (thisinleft)
				{
					if (otherinleft)
					{
						this->_pleftdata[thisrearindex] = other._pleftdata[otherrearindex];
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						this->_pleftdata[thisrearindex] = other._prightdata[otherrearindex];
						++otherrearindex;
					}
					if (thisrearindex > 0)
					{
						--thisrearindex;
					}
					else
					{
						thisrearindex = 0;
						thisinleft = false;
					}
				}
				else
				{
					if (otherinleft)
					{
						this->_prightdata[thisrearindex] = other._pleftdata[otherrearindex];
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						this->_prightdata[thisrearindex] = other._prightdata[otherrearindex];
						++otherrearindex;
					}
					++thisrearindex;
				}
			}
		}
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}

		return *this;
	
	}

	~mydeque()
	{
		SAFE_DELARR(_prightdata);
		SAFE_DELARR(_pleftdata);
		//可不写
		/*_leftcapacity = 0;
		_leftsize = 0;
		_rightcapacity = 0;
		_rightsize = 0;*/
	}

public:
	bool operator==(mydeque const& other)
	{
		size_t thissize = this->_leftsize + this->_rightsize;
		size_t othersize = other._leftsize + other._rightsize;
		if (thissize != othersize)
		{
			return false;
		}
		else
		{
			bool thisinleft = (this->_leftsize > 0) ? true : false;
			bool otherinleft = (other._leftsize > 0) ? true : false;
			size_t thisrearindex;
			size_t otherrearindex;

			if (thisinleft)
			{
				thisrearindex = this->_leftsize - 1;
			}
			else
			{
				thisrearindex = 0;
			}

			if (otherinleft)
			{
				otherrearindex = other._leftsize - 1;
			}
			else
			{
				otherrearindex = 0;
			}

			size_t thissizeindex = 0;
			size_t othersizeindex = 0;


			while (thissizeindex < thissize && othersizeindex < othersize)
			{
				if (thisinleft)
				{
					if (otherinleft)
					{
						if (this->_pleftdata[thisrearindex] != other._pleftdata[otherrearindex])
						{
							return false;
						}
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						if (this->_pleftdata[thisrearindex] != other._prightdata[otherrearindex])
						{
							return false;
						}
						++otherrearindex;
					}
					if (thisrearindex > 0)
					{
						--thisrearindex;
					}
					else
					{
						thisrearindex = 0;
						thisinleft = false;
					}
				}
				else
				{
					if (otherinleft)
					{
						if (this->_prightdata[thisrearindex] != other._pleftdata[otherrearindex])
						{
							return false;
						}
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						if (this->_prightdata[thisrearindex] != other._prightdata[otherrearindex])
						{
							return false;
						}
						++otherrearindex;
					}
					++thisrearindex;
				}

				++thissizeindex;
				++othersizeindex;
			}

			return true;
		}		
	}

	bool operator!=(mydeque const& other)
	{
		size_t thissize = this->_leftsize + this->_rightsize;
		size_t othersize = other._leftsize + other._rightsize;

		if (thissize != othersize)
		{
			return true;
		}
		else
		{
			bool thisinleft = (this->_leftsize > 0) ? true : false;
			bool otherinleft = (other._leftsize > 0) ? true : false;
			size_t thisrearindex;
			size_t otherrearindex;

			if (thisinleft)
			{
				thisrearindex = this->_leftsize - 1;
			}
			else
			{
				thisrearindex = 0;
			}

			if (otherinleft)
			{
				otherrearindex = other._leftsize - 1;
			}
			else
			{
				otherrearindex = 0;
			}

			size_t thissizeindex = 0;
			size_t othersizeindex = 0;


			while (thissizeindex < thissize && othersizeindex < othersize)
			{
				if (thisinleft)
				{
					if (otherinleft)
					{
						if (this->_pleftdata[thisrearindex] != other._pleftdata[otherrearindex])
						{
							return true;
						}
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						if (this->_pleftdata[thisrearindex] != other._prightdata[otherrearindex])
						{
							return true;
						}
						++otherrearindex;
					}
					if (thisrearindex > 0)
					{
						--thisrearindex;
					}
					else
					{
						thisrearindex = 0;
						thisinleft = false;
					}
				}
				else
				{
					if (otherinleft)
					{
						if (this->_prightdata[thisrearindex] != other._pleftdata[otherrearindex])
						{
							return true;
						}
						if (otherrearindex > 0)
						{
							--otherrearindex;
						}
						else
						{
							otherrearindex = 0;
							otherinleft = false;
						}
					}
					else
					{
						if (this->_prightdata[thisrearindex] != other._prightdata[otherrearindex])
						{
							return true;
						}
						++otherrearindex;
					}
					++thisrearindex;
				}
				++thissizeindex;
				++othersizeindex;
			}
			return false;
		}
	}

	bool operator>(mydeque const& other)
	{
		bool thisinleft = (this->_leftsize > 0) ? true : false;
		bool otherinleft = (other._leftsize > 0) ? true : false;
		size_t thisrearindex;
		size_t otherrearindex;

		if (thisinleft)
		{
			thisrearindex = this->_leftsize - 1;
		}
		else
		{
			thisrearindex = 0;
		}

		if (otherinleft)
		{
			otherrearindex = other._leftsize - 1;
		}
		else
		{
			otherrearindex = 0;
		}

		size_t thissizeindex = 0;
		size_t othersizeindex = 0;
		size_t thissize = this->_leftsize + this->_rightsize;
		size_t othersize = other._leftsize + other._rightsize;

		while (thissizeindex < thissize && othersizeindex < othersize)
		{
			if (thisinleft)
			{
				if (otherinleft)
				{
					if (this->_pleftdata[thisrearindex] > other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_pleftdata[thisrearindex] < other._pleftdata[otherrearindex]
							{
								return false;
							}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_pleftdata[thisrearindex] > other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{

						if (this->_pleftdata[thisrearindex] < other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				if (thisrearindex > 0)
				{
					--thisrearindex;
				}
				else
				{
					thisrearindex = 0;
					thisinleft = false;
				}
			}
			else
			{
				if (otherinleft)
				{
					if (this->_prightdata[thisrearindex]> other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] < other._pleftdata[otherrearindex])
						{
							return false;
						}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_prightdata[thisrearindex] > other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] < other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				++thisrearindex;
			}

			++thissizeindex;
			++othersizeindex;
		}

		if (thissize > othersize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(mydeque const& other)
	{
		bool thisinleft = (this->_leftsize > 0) ? true : false;
		bool otherinleft = (other._leftsize > 0) ? true : false;
		size_t thisrearindex;
		size_t otherrearindex;

		if (thisinleft)
		{
			thisrearindex = this->_leftsize - 1;
		}
		else
		{
			thisrearindex = 0;
		}

		if (otherinleft)
		{
			otherrearindex = other._leftsize - 1;
		}
		else
		{
			otherrearindex = 0;
		}

		size_t thissizeindex = 0;
		size_t othersizeindex = 0;
		size_t thissize = this->_leftsize + this->_rightsize;
		size_t othersize = other._leftsize + other._rightsize;

		while (thissizeindex < thissize && othersizeindex < othersize)
		{
			if (thisinleft)
			{
				if (otherinleft)
				{
					if (this->_pleftdata[thisrearindex] < other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_pleftdata[thisrearindex] > other._pleftdata[otherrearindex]
							{
								return false;
							}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_pleftdata[thisrearindex] < other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{

						if (this->_pleftdata[thisrearindex] > other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				if (thisrearindex > 0)
				{
					--thisrearindex;
				}
				else
				{
					thisrearindex = 0;
					thisinleft = false;
				}
			}
			else
			{
				if (otherinleft)
				{
					if (this->_prightdata[thisrearindex] < other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] > other._pleftdata[otherrearindex])
						{
							return false;
						}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_prightdata[thisrearindex] < other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] > other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				++thisrearindex;
			}

			++thissizeindex;
			++othersizeindex;
		}

		if (thissize < othersize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(mydeque const& other)

	{
		bool thisinleft = (this->_leftsize > 0) ? true : false;
		bool otherinleft = (other._leftsize > 0) ? true : false;
		size_t thisrearindex;
		size_t otherrearindex;

		if (thisinleft)
		{
			thisrearindex = this->_leftsize - 1;
		}
		else
		{
			thisrearindex = 0;
		}

		if (otherinleft)
		{
			otherrearindex = other._leftsize - 1;
		}
		else
		{
			otherrearindex = 0;
		}

		size_t thissizeindex = 0;
		size_t othersizeindex = 0;
		size_t thissize = this->_leftsize + this->_rightsize;
		size_t othersize = other._leftsize + other._rightsize;

		while (thissizeindex < thissize && othersizeindex < othersize)
		{
			if (thisinleft)
			{
				if (otherinleft)
				{
					if (this->_pleftdata[thisrearindex] > other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_pleftdata[thisrearindex] < other._pleftdata[otherrearindex]
							{
								return false;
							}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_pleftdata[thisrearindex] > other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{

						if (this->_pleftdata[thisrearindex] < other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				if (thisrearindex > 0)
				{
					--thisrearindex;
				}
				else
				{
					thisrearindex = 0;
					thisinleft = false;
				}
			}
			else
			{
				if (otherinleft)
				{
					if (this->_prightdata[thisrearindex] > other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] < other._pleftdata[otherrearindex])
						{
							return false;
						}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_prightdata[thisrearindex] > other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] < other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				++thisrearindex;
			}

			++thissizeindex;
			++othersizeindex;
		}

		if (thissize >= othersize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(mydeque const& other)

	{
		bool thisinleft = (this->_leftsize > 0) ? true : false;
		bool otherinleft = (other._leftsize > 0) ? true : false;
		size_t thisrearindex;
		size_t otherrearindex;

		if (thisinleft)
		{
			thisrearindex = this->_leftsize - 1;
		}
		else
		{
			thisrearindex = 0;
		}

		if (otherinleft)
		{
			otherrearindex = other._leftsize - 1;
		}
		else
		{
			otherrearindex = 0;
		}

		size_t thissizeindex = 0;
		size_t othersizeindex = 0;
		size_t thissize = this->_leftsize + this->_rightsize;
		size_t othersize = other._leftsize + other._rightsize;

		while (thissizeindex < thissize && othersizeindex < othersize)
		{
			if (thisinleft)
			{
				if (otherinleft)
				{
					if (this->_pleftdata[thisrearindex] < other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_pleftdata[thisrearindex] > other._pleftdata[otherrearindex]
							{
								return false;
							}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_pleftdata[thisrearindex] < other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{

						if (this->_pleftdata[thisrearindex] > other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				if (thisrearindex > 0)
				{
					--thisrearindex;
				}
				else
				{
					thisrearindex = 0;
					thisinleft = false;
				}
			}
			else
			{
				if (otherinleft)
				{
					if (this->_prightdata[thisrearindex] < other._pleftdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] > other._pleftdata[otherrearindex])
						{
							return false;
						}
					}
					if (otherrearindex > 0)
					{
						--otherrearindex;
					}
					else
					{
						otherrearindex = 0;
						otherinleft = false;
					}
				}
				else
				{
					if (this->_prightdata[thisrearindex] < other._prightdata[otherrearindex])
					{
						return true;
					}
					else
					{
						if (this->_prightdata[thisrearindex] > other._prightdata[otherrearindex])
						{
							return false;
						}
					}
					++otherrearindex;
				}
				++thisrearindex;
			}

			++thissizeindex;
			++othersizeindex;
		}

		if (thissize <= othersize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	//assign() 是用于将一个范围内的元素赋值给容器的成员函数。
	//需要注意的是，调用 assign() 函数会清空容器原有的元素，并用新的元素替换它们。
	void assign(size_t count, const T& val)
	{
		SAFE_DELARR(_prightdata);
		SAFE_DELARR(_pleftdata);
		
		/*_leftcapacity = 0;
		_leftsize = 0;
		_rightcapacity = 0;
		_rightsize = 0;*/

		if (count > 0)
		{

			_leftcapacity = count / 2;
			_leftsize = _leftcapacity;
			_rightcapacity = count - _leftcapacity;
			_rightsize = _rightcapacity;
			if (_leftcapacity > 0)
			{
				_pleftdata = new T[_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			_prightdata = new T[_rightcapacity];

			for (int i = (int)_leftsize - 1; i >= 0; --i)
			{
				_pleftdata[i] = val;
			}

			for (size_t i = 0; i < _rightsize; ++i)
			{
				_prightdata[i] = val;
			}

		}
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}
	}
	template<class InputIterator,
		class = typename enable_if<_Is_iterator<InputIterator>::value, void>::type>
	void assign(InputIterator first, InputIterator last) 
	{
		SAFE_DELARR(_prightdata);
		SAFE_DELARR(_pleftdata);

		/*_leftcapacity = 0;
		_leftsize = 0;
		_rightcapacity = 0;
		_rightsize = 0;*/

		size_t count = last - first;

		if (count > 0)
		{
			InputIterator pt = first;
			_leftcapacity = count / 2;
			_leftsize = _leftcapacity;
			_rightcapacity = count - _leftcapacity;
			_rightsize = _rightcapacity;
			if (_leftcapacity > 0)
			{
				_pleftdata = new T[_leftcapacity];
			}
			else
			{
				_pleftdata = nullptr;
			}
			_prightdata = new T[_rightcapacity];

			for (int i = _leftsize - 1; i >= 0; --i)
			{
				_pleftdata[i] = *(pt++);
			}

			for (size_t i = 0; i < _rightsize; ++i)
			{
				_prightdata[i] = *(pt++);
			}

		}
		else
		{
			_pleftdata = nullptr;
			_leftcapacity = 0;
			_leftsize = 0;

			_prightdata = nullptr;
			_rightcapacity = 0;
			_rightsize = 0;
		}
	}
	
	T& at(size_t pos)
	{
		if (pos >= _leftsize + _rightsize)
		{
			throw "incalid indes";
		}
	}

	T const& at(size_t pos) const


	//T& operator[](size_t pos)
	//{
	//	if (pos > _size)
	//	{
	//		throw "incalid indes";
	//	}
	//	return _pdata[pos];
	//}
	//T const& operator[](size_t pos) const
	//{
	//	if (pos > _size)
	//	{
	//		throw "incalid indes";
	//	}
	//	return _pdata[pos];
	//}
protected:
	T* _pleftdata;                  
	size_t _leftcapacity;		
	size_t _leftsize;	

	T* _prightdata;                   
	size_t _rightcapacity;		
	size_t _rightsize;			

};












#endif // !MYDEQUE_H

