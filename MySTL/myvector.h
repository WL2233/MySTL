//myvector��vector�ڻ������������ϻ���һ�㣬��Ϊvector�ڻ������������ϻ�ʹ���ڴ濽�������Զ�������������myvector����Ч��

//��д��==���������ŵ����أ�

#ifndef MYVECTOR_H
#define MYVECTOR_H

#ifndef SAFE_DELETE
#define SAFE_DELETE(p){if(p){delete;p=nullptr;}}
#endif // !SAFE_DELETE
#ifndef SAFE_DELARR
#define SAFE_DELARR(p){if(p){delete[]p;p=nullptr;}}
#endif // !SAFE_DELARR



template<class T>
class myvector
{
protected:
	T* _pdata;                   //vector�Ƕ�̬���飬��������Ҫ��ָ��
	size_t _capacity;			//����
	size_t _size;				//��ЧԪ�ظ���
	bool _isbasetype;

public:
	//��������ģ���е�ģ��
	struct iterator   //��C++��ģ��ͽṹ�岻����������ʵ���ࡣĬ��������public���ࣻ
	{
		T* pt;
		iterator()
		{
			pt = nullptr;
		}
		iterator(iterator const& other)
		{
			this->pt = other.pt;
		}
		iterator& operator=(iterator const& other)
		{
			this->pt = other.pt;
			return *this;
		}
		iterator& operator++()//ǰ��++
		{
			++pt;
			return *this;
		}
		iterator operator++(int)
		{
			iterator ret = *this;
			++pt;
			return ret;
		}
		iterator& operator--()//ǰ��--
		{
			--pt;
			return *this;
		}
		iterator operator--(int)
		{
			iterator ret = *this;
			--pt;
			return ret;
		}
		T* operator->()
		{
			return pt;
		}
		T& operator*()
		{
			return *pt;
		}
		bool operator==(iterator const &other)
		{
			return this->pt == other.pt;
		}
		bool operator!=(iterator const& other)
		{
			return this->pt != other.pt;
		}
		//�Զ��幦�ܣ�ϵͳ��������û�еĹ���
		iterator operator+(int num)
		{
			iterator ret = *this;
			ret.pt += num;
			return ret;
		}
		iterator operator-(int num)
		{
			iterator ret = *this;
			ret.pt -= num;
			return ret;
		}
		int operator-(iterator const& other)
		{
			return this->pt - other.pt;
		}
		//!�Զ��幦��

		~iterator()
		{
			pt = nullptr;
		}
	};
	//����������
	struct const_iterator   //��C++��ģ��ͽṹ�岻����������ʵ���ࡣĬ��������public���ࣻ
	{
		T const * pt;
		const_iterator()
		{
			pt = nullptr;
		}
		const_iterator(iterator const& other)
		{
			this->pt = other.pt;
		}
		const_iterator(const_iterator const& other)
		{
			this->pt = other.pt;
		}
		const_iterator& operator=(const_iterator const& other)
		{
			this->pt = other.pt;
			return *this;
		}
		const_iterator& operator=(iterator const& other)
		{
			this->pt = other.pt;
			return *this;
		}
		const_iterator& operator++()//ǰ��++
		{
			++pt;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator ret = *this;
			++pt;
			return ret;
		}
		const_iterator& operator--()//ǰ��--
		{
			--pt;
			return *this;
		}
		const_iterator operator--(int)
		{
			const_iterator ret = *this;
			--pt;
			return ret;
		}
		T const * operator->()
		{
			return pt;
		}
		T const& operator*()
		{
			return *pt;
		}
		bool operator==(const_iterator const& other)
		{
			return this->pt == other.pt;
		}
		bool operator!=(const_iterator const& other)
		{
			return this->pt != other.pt;
		}
		//�Զ��幦�ܣ�ϵͳ��������û�еĹ���
		const_iterator operator+(int num)
		{
			const_iterator ret = *this;
			ret.pt += num;
			return ret;
		}
		const_iterator operator-(int num)
		{
			const_iterator ret = *this;
			ret.pt -= num;
			return ret;
		}
		int operator-(const_iterator const& other)
		{
			return this->pt - other.pt;
		}
		//!�Զ��幦��

		~const_iterator()
		{
			pt = nullptr;
		}
	};
	
	//���������
	struct reverse_iterator   //��C++��ģ��ͽṹ�岻����������ʵ���ࡣĬ��������public���ࣻ
	{
		T* pt;
		reverse_iterator()
		{
			pt = nullptr;
		}
		reverse_iterator(reverse_iterator const& other)
		{
			this->pt = other.pt;
		}
		reverse_iterator& operator=(reverse_iterator const& other)
		{
			this->pt = other.pt;
			return *this;
		}
		reverse_iterator& operator++()//ǰ��++
		{
			--pt;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator ret = *this;
			--pt;
			return ret;
		}
		reverse_iterator& operator--()//ǰ��--
		{
			++pt;
			return *this;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator ret = *this;
			++pt;
			return ret;
		}
		T* operator->()
		{
			return pt;
		}
		T& operator*()
		{
			return *pt;
		}
		bool operator==(reverse_iterator const& other)
		{
			return this->pt == other.pt;
		}
		bool operator!=(reverse_iterator const& other)
		{
			return this->pt != other.pt;
		}
		//�Զ��幦�ܣ�ϵͳ��������û�еĹ���
		reverse_iterator operator+(int num)
		{
			reverse_iterator ret = *this;
			ret.pt -= num;
			return ret;
		}
		reverse_iterator operator-(int num)
		{
			reverse_iterator ret = *this;
			ret.pt += num;
			return ret;
		}
		int operator-(reverse_iterator const& other)
		{
			return other.pt - this->pt;
		}
		//!�Զ��幦��

		~reverse_iterator()
		{
			pt = nullptr;
		}
	};
	//�������������
	struct const_reverse_iterator   //��C++��ģ��ͽṹ�岻����������ʵ���ࡣĬ��������public���ࣻ
	{
		T const * pt;
		const_reverse_iterator()
		{
			pt = nullptr;
		}
		const_reverse_iterator(reverse_iterator const& other)
		{
			this->pt = other.pt;
		}
		const_reverse_iterator(const_reverse_iterator const& other)
		{
			this->pt = other.pt;
		}
		const_reverse_iterator& operator=(const_reverse_iterator const& other)
		{
			this->pt = other.pt;
			return *this;
		}
		const_reverse_iterator& operator=(reverse_iterator const& other)
		{
			this->pt = other.pt;
			return *this;
		}
		const_reverse_iterator& operator++()//ǰ��++
		{
			--pt;
			return *this;
		}
		const_reverse_iterator operator++(int)
		{
			const_reverse_iterator ret = *this;
			--pt;
			return ret;
		}
		const_reverse_iterator& operator--()//ǰ��--
		{
			++pt;
			return *this;
		}
		const_reverse_iterator operator--(int)
		{
			const_reverse_iterator ret = *this;
			++pt;
			return ret;
		}
		T const* operator->()
		{
			return pt;
		}
		T const& operator*()
		{
			return *pt;
		}
		bool operator==(const_reverse_iterator const& other)
		{
			return this->pt == other.pt;
		}
		bool operator!=(const_reverse_iterator const& other)
		{
			return this->pt != other.pt;
		}
		//�Զ��幦�ܣ�ϵͳ��������û�еĹ���
		const_reverse_iterator operator+(int num)
		{
			const_reverse_iterator ret = *this;
			ret.pt -= num;
			return ret;
		}
		const_reverse_iterator operator-(int num)
		{
			const_reverse_iterator ret = *this;
			ret.pt += num;
			return ret;
		}
		int operator-(const_reverse_iterator const& other)
		{
			return other.pt - this->pt;
		}
		//!�Զ��幦��

		~const_reverse_iterator()
		{
			pt = nullptr;
		}
	};

public:
	myvector()
	{
		_pdata = nullptr;
		_capacity = 0;
		_size = 0;
	}

	myvector(size_t count)
	{
		if (count > 0)
		{
			_pdata = new T[count];
			_capacity = count;
			_size = count;
			for (size_t i = 0; i < count; ++i)
			{
				_pdata[i] = T();  //���������͵��޲ι���
			}
		}
		else
		{
			_pdata = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	myvector(size_t count, T const& val)
	{
		_pdata = new T[count];
		_capacity =count;
		_size = count;
		for (size_t i = 0; i < count; ++i)
		{
			_pdata[i] = val; 
		}
	}
	//��������
	myvector(myvector const& other)
	{
		if (other._size > 0)
		{
			this->_pdata = new T[other._size];
			this->_capacity = other._size;
			this->_size = other._size;
			for (size_t i=0;i<other._size;++i)
			{
				this->_pdata[i] = other._pdata[i];
			}
			//
		}
		else
		{
			this->_pdata = nullptr;
			this->_capacity = 0;
			this->_size = 0;
		}
	}

	
	//���乹�죺ͨ�õ����������е�����������
	template<class InputIterator,class = typename enable_if<_Is_iterator<InputIterator>::value,void>::type>
	myvector(InputIterator first, InputIterator last)
	{
		
		size_t count = last- first;
		InputIterator pt;
		

		if(count > 0)
		{
			_pdata = new T[count];
			_capacity = count;
			_size = count;
			size_t i = 0;
			for(pt = first; pt != last; ++pt)
			{
				_pdata[i++] = *pt;
			}
		}
		else
		{
			_pdata = nullptr;
			_capacity = 0;
			_size = 0;
		}


	}
	
	
	
	~myvector()
	{
		//_size = 0;
		//_capacity = 0; ��������ֵ�Ѿ�����Ҫ�ˣ���Ϊ��������Ѿ������ˡ�
		SAFE_DELARR(_pdata);
	}

	//��ֵ����
	myvector& operator=(myvector<T>const& other)
	{
		SAFE_DELARR(this->_pdata);
		this->capacity = 0;
		this->size = 0;


		if (other._size > 0)
		{
			this->_pdata = new T[other._size];
			this->_capacity = other._size;
			this->_size = other._size;
			for (size_t i = 0; i < other._size; ++i)
			{
				this->_pdata[i] = other._pdata[i];
			}
		}
		else
		{
			this->_pdata = nullptr;
			this->_capacity = 0;
			this->_size = 0;
		}
	}

	//
public:

	void assign(size_t count, const T& val)
	{
		SAFE_DELARR(_pdata);
		_capacity = 0;
		_size = 0;
		if (count > 0)
		{
			_pdata = new T[count];
			_capacity = count;
			_size = count;
			for (size_t i = 0; i < count; ++i)
			{
				_pdata[i] = val;
			}
		}
		else
		{
			_pdata = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	template<class InputIterator, 
		class = typename enable_if<_Is_iterator<InputIterator>::value, void>::type>
	void assign(InputIterator first, InputIterator last)
	{
		SAFE_DELARR(_pdata);
		_capacity = 0;
		_size = 0;
		size_t count = last - first;
		if (count > 0)
		{
			_pdata = new T[count];
			_capacity = count;
			_size = count;
			InputIterator pt = nullptr;
			size_t i = 0;
			for (pt = first; pt!=last; ++pt)
			{
				_pdata[i++] = *pt;
			}
		}
		else
		{
			_pdata = nullptr;
			_capacity = 0;
			_size = 0;
		}
	
		
	}

	T& at(size_t pos)//ע������������
	{
		if (pos >= _size)
		{
			throw "incalid indes";
		}
		return _pdata[pos];
	}

	T const& at(size_t pos) const
	{
		if (pos > _size)
		{
			throw "incalid indes";
		}
		return _pdata[pos];
	}

	T& back()
	{
		return _pdata[_size - 1];
	}
	T const& back() const
	{
		return _pdata[_size - 1];
	}

	const_iterator begin() const
	{
		const_iterator ret;
		ret.pt = _pdata;
		return ret;
	}
	iterator begin()
	{
		iterator ret;
		ret.pt = _pdata;
		return ret;
	}

	size_t capacity() const
	{
		return _capacity;
	}

	void clear()
	{
		_size=0;
	}

	bool empty() const
	{
		return _size == 0;
	}




	iterator end()
	{
		iterator ret;
		ret.pt = _pdata + _size;
		return ret;
	}
	const_iterator end() const  //֮ǰ����һ��const���º������س������壻
	{
		const_iterator ret;
		ret.pt = _pdata + _size;
		return ret;
	}

	iterator erase(iterator pos)
	{
		T* endpos = _pdata + _size - 1;
		T* pt;
		for (pt = pos.pt; pt != endpos; ++pt)
		{
			*pt = *(pt + 1);
		}
		--_size;
	}
	iterator erase(iterator first,iterator last)
	{
		size_t count = last - first;

		if (count > 0)
		{
			T* fpt = first.pt;
			T* bpt = last.pt;
			for (;bpt != _pdata + _size; ++fpt,++bpt)
			{
				*fpt = *bpt;
			}
			_size -= count;
		}
		else
		{
			throw "invalide index";
		}


		return first;
	}


	T & front()
	{
		return _pdata[0];
	}
	T const& front() const
	{
		return _pdata[0];
	}

	iterator insert(iterator pos, const T& val)
	{
		if (_size >= _capacity)
		{
			int posindex = pos - begin();

			size_t newcapacity = _capacity + (((_capacity / 2) > 0) ? (_capacity / 2) : 1);
			T* pnewdata = new T[newcapacity];
			for (size_t i = 0; i < _size; ++i)
			{
				pnewdata[i] = _pdata[i];
			}

			SAFE_DELARR(_pdata);
			_pdata = pnewdata;
			pnewdata = nullptr;
			_capacity = newcapacity;

			pos = begin() + posindex;
		}
		T* pt = _pdata + _size;
		for (; pt != pos.pt; --pt)
		{
			*pt = *(pt - 1);
		}
		*pt = val;
		++_size;

		return pos;
	}
	void insert(iterator pos,size_t count,T const & val)
	{
		if (count > 0)
		{
			if (_size + count > _capacity)//�ж������Ƿ񹻣�������Ҫ����
			{
				int posindex = pos - begin();//��ֹ������ʧЧ

				size_t newcapacity = _size + count;//��������ݺ�push_back�������ݷ�ʽ��һ����
				T* pnewdata = new T[newcapacity];
				for (size_t i = 0; i < _size; i++)
				{
					pnewdata[i] = _pdata[i];
				}
				SAFE_DELARR(_pdata);
				_pdata = pnewdata;
				pnewdata = nullptr;
				_capacity = newcapacity;

				pos = begin() + posindex;//����ֹ������ʧЧ
			}

			T* pt = _pdata + _size - 1;//ԭ��������һ����Чλ��
			T* endpos = pos.pt - 1;
			for (; pt != endpos; --pt)
			{
				*(pt + count) = *pt;	//��Ԫ�غ��ƣ��ڳ�pos��pos+count-1��λ��
			}

			pt = pos.pt;
			for (size_t i = 0; i < count; ++i)
			{
				*(pt++) = val;
			}

			_size += count;
			
		}
		else
		{
			throw "invalid index";
		}
	}
	template<class InputIterator, class = typename enable_if<_Is_iterator<InputIterator>::value, void>::type>
	void insert(iterator pos,InputIterator first,InputIterator last)
	{
		size_t count = last - first;

		if (count > 0)
		{
			//�Ƿ�Ҫ����
			if (_size + count > _capacity)//�ж������Ƿ񹻣�������Ҫ����
			{
				int posindex = pos - begin();//��ֹ������ʧЧ

				size_t newcapacity = _size + count;//��������ݺ�push_back�������ݷ�ʽ��һ����
				T* pnewdata = new T[newcapacity];
				for (size_t i = 0; i < _size; i++)
				{
					pnewdata[i] = _pdata[i];
				}
				SAFE_DELARR(_pdata);
				_pdata = pnewdata;
				pnewdata = nullptr;
				_capacity = newcapacity;

				pos = begin() + posindex;//����ֹ������ʧЧ
			}
			//�ڳ��ռ�
			T* pt = _pdata + _size - 1;
			T* endpos = pos.pt - 1;
			for (; pt != endpos; --pt)
			{
				*(pt + count) = *pt;	//��Ԫ�غ��ƣ��ڳ�pos��pos+count-1��λ��
			}
			//����������
			InputIterator ipt = first;
			pt = pos.pt;
			for (size_t i = 0; i < count; ++i)
			{
				*(pt++) = *(ipt++);
			}
			//
			_size += count;
		}
		else
		{
			throw "invalid index";
		}
	}

	size_t max_size()const
	{
		return 0xffffffff / sizeof(T);
	}


	void pop_back()
	{
		--_size;
	}

	void push_back(T const& val)
	{
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity + (((_capacity / 2) > 0) ? (_capacity / 2) : 1);
			//T* pnewdata = nullptr;
			T* pnewdata = new T[newcapacity];
			for (size_t i = 0; i < _size; ++i)
			{
				pnewdata[i] = _pdata[i];
			}

			SAFE_DELARR(_pdata);
			_pdata = pnewdata;
			//SAFE_DELARR(pnewdata);
			pnewdata = nullptr;
			_capacity = newcapacity;
		}
		_pdata[_size++] = val;
	}

	reverse_iterator rbegin()
	{
		reverse_iterator ret;
		ret.pt = _pdata + _size - 1;
		return ret;
	}
	const_reverse_iterator rbegin() const
	{
		const_reverse_iterator ret;
		ret.pt = _pdata + _size - 1;
		return ret;
	}
	reverse_iterator rend()
	{
		reverse_iterator ret;
		ret.pt = _pdata - 1;
		return ret;
	}
	const_reverse_iterator rend() const
	{
		const_reverse_iterator ret;
		ret.pt = _pdata - 1;
		return ret;
	}
	


	//reserve()���ÿռ亯����������ÿռ��ֵ�����пռ�С������ʲô���飻
	void reserve(size_t count)
	{
		if (count > _capacity)
		{
			T *pnewdata = new T[count];
			for (size_t i = 0; i < _size; ++i)
			{
				pnewdata[i] = _pdata[i];
			}
			SAFE_DELARR(_pdata);
			_pdata = pnewdata;
			pnewdata = nullptr;
			_capacity = count;
		}
	}
	size_t size() const
	{
		return _size;
	}
	void swap(myvector& other)
	{
		T* pswap=nullptr;
		size_t iswap=0;

		pswap = this->_pdata;
		this->_pdata = other._pdata;
		other._pdata = pswap;

		iswap = this->_capacity;
		this->_capacity = other._capacity;
		other._capacity = iswap;

		iswap = this->_size;
		this->_size = other._size;
		other._size = iswap;
	}
	friend void swap(myvector<T>& left, myvector<T>& right)
	{
		T* pswap = nullptr;
		size_t iswap = 0;

		pswap = left._pdata;
		left._pdata = right._pdata;
		right._pdata = pswap;

		iswap = left._capacity;
		left._capacity = right._capacity;
		right._capacity = iswap;

		iswap = left._size;
		left._size = right._size;
		right._size = iswap;

	}


	T& operator[](size_t pos)
	{
		if (pos > _size)
		{
			throw "incalid indes";
		}
		return _pdata[pos];
	}
	T const& operator[](size_t pos) const
	{
		if (pos > _size)
		{
			throw "incalid indes";
		}
		return _pdata[pos];
	}

};
#endif // MYVECTOR_H