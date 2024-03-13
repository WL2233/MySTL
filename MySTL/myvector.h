//myvector比vector在基本数据类型上会慢一点，因为vector在基础数据类型上会使用内存拷贝；在自定义数据类型上myvector更高效；

//少写了==及其他符号的重载；

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
	T* _pdata;                   //vector是动态数组，所以这里要用指针
	size_t _capacity;			//容量
	size_t _size;				//有效元素个数
	bool _isbasetype;

public:
	//迭代器：模板中的模板
	struct iterator   //在C++中模板和结构体不区分这里其实是类。默认属性是public的类；
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
		iterator& operator++()//前置++
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
		iterator& operator--()//前置--
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
		//自定义功能，系统迭代器所没有的功能
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
		//!自定义功能

		~iterator()
		{
			pt = nullptr;
		}
	};
	//常量迭代器
	struct const_iterator   //在C++中模板和结构体不区分这里其实是类。默认属性是public的类；
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
		const_iterator& operator++()//前置++
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
		const_iterator& operator--()//前置--
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
		//自定义功能，系统迭代器所没有的功能
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
		//!自定义功能

		~const_iterator()
		{
			pt = nullptr;
		}
	};
	
	//逆向迭代器
	struct reverse_iterator   //在C++中模板和结构体不区分这里其实是类。默认属性是public的类；
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
		reverse_iterator& operator++()//前置++
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
		reverse_iterator& operator--()//前置--
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
		//自定义功能，系统迭代器所没有的功能
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
		//!自定义功能

		~reverse_iterator()
		{
			pt = nullptr;
		}
	};
	//常量逆向迭代器
	struct const_reverse_iterator   //在C++中模板和结构体不区分这里其实是类。默认属性是public的类；
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
		const_reverse_iterator& operator++()//前置++
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
		const_reverse_iterator& operator--()//前置--
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
		//自定义功能，系统迭代器所没有的功能
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
		//!自定义功能

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
				_pdata[i] = T();  //任意种类型的无参构造
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
	//拷贝构造
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

	
	//区间构造：通用迭代器：所有迭代器都可以
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
		//_capacity = 0; 这里两个值已经不重要了，因为这个对象已经销毁了。
		SAFE_DELARR(_pdata);
	}

	//赋值运算
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

	T& at(size_t pos)//注意这里是引用
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
	const_iterator end() const  //之前少了一个const导致函数重载出现歧义；
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
			if (_size + count > _capacity)//判断容量是否够，不够就要扩容
			{
				int posindex = pos - begin();//防止迭代器失效

				size_t newcapacity = _size + count;//这里的扩容和push_back处的扩容方式不一样了
				T* pnewdata = new T[newcapacity];
				for (size_t i = 0; i < _size; i++)
				{
					pnewdata[i] = _pdata[i];
				}
				SAFE_DELARR(_pdata);
				_pdata = pnewdata;
				pnewdata = nullptr;
				_capacity = newcapacity;

				pos = begin() + posindex;//！防止迭代器失效
			}

			T* pt = _pdata + _size - 1;//原数组的最后一个有效位置
			T* endpos = pos.pt - 1;
			for (; pt != endpos; --pt)
			{
				*(pt + count) = *pt;	//将元素后移，腾出pos到pos+count-1的位置
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
			//是否要扩容
			if (_size + count > _capacity)//判断容量是否够，不够就要扩容
			{
				int posindex = pos - begin();//防止迭代器失效

				size_t newcapacity = _size + count;//这里的扩容和push_back处的扩容方式不一样了
				T* pnewdata = new T[newcapacity];
				for (size_t i = 0; i < _size; i++)
				{
					pnewdata[i] = _pdata[i];
				}
				SAFE_DELARR(_pdata);
				_pdata = pnewdata;
				pnewdata = nullptr;
				_capacity = newcapacity;

				pos = begin() + posindex;//！防止迭代器失效
			}
			//腾出空间
			T* pt = _pdata + _size - 1;
			T* endpos = pos.pt - 1;
			for (; pt != endpos; --pt)
			{
				*(pt + count) = *pt;	//将元素后移，腾出pos到pos+count-1的位置
			}
			//填充插入数据
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
	


	//reserve()重置空间函数，如果重置空间的值比已有空间小，则不做什么事情；
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