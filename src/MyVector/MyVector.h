#pragma once
#define NULL nullptr

double g_nNewSpaceRatio = 1.5;      			// 每次开辟新空间的倍数

template <typename T>
class MyVector {
private:
	T* m_pVector;       			// 指向内存段，用于记录存储数据的首地址
	int m_nElemNum;		    		// 用于记录当前数据的数量
	int m_nCapacity;				// 用于记录当前容器能容纳的最大元素个数
public:
	MyVector()
	{
		m_pVector = NULL;
		m_nElemNum = 0;
		m_nCapacity = 0;			// 默认值先给个0
	}

	~MyVector()
	{
		if (m_pVector != NULL)
		{
			delete[] m_pVector;
			m_pVector = NULL;
		}
	}

public:
	void push_back(const T& nData_);		// 向 Vector 末尾插入数据
	void pop_back();						// 删除 Vector 末尾的数据
	
	int size() const;						// Vector 的数据个数
	int capacity() const;					// Vector 的容量
	
	bool empty() const;						// Vector 是否为空
	
	T at(size_t index_) const;				// 访问第 index 个元素
	T front() const;						// 访问第 1 个元素
	T back() const;							// 访问最后 1 个元素

	T &operator[](size_t pos_);

};

template <typename T>
void MyVector<T>::push_back(const T& nData_)
{
	// 没有申请过空间时申请空间
	if (m_pVector == NULL)
	{
		if (m_nCapacity == 0)
			m_nCapacity = 1;

		m_pVector = new T[m_nCapacity];

		if (m_pVector == NULL)
			throw("分配空间失败");
	}

	// 表明空间不够用了，需要开辟新的空间
	if (m_nElemNum >= m_nCapacity)
	{
		// 1 扩大m_nCapacity为原来的g_nNewSpaceRatio倍；这里g_nNewSpaceRatio取1.5
		m_nCapacity = (int)(ceil)(m_nCapacity * g_nNewSpaceRatio);

		// 2 开辟新空间
		T* pNew = new T[m_nCapacity];

		// 3 拷贝原有数据并释放原内存
		memcpy(pNew, m_pVector, sizeof(T*) * m_nElemNum);
		delete[] m_pVector;

		// 4 m_pVector指向新开的内存
		m_pVector = pNew;
	}

	// 添加新数据进来。数据量增1
	m_pVector[m_nElemNum++] = nData_;

	return;
}

template<typename T>
void MyVector<T>::pop_back()
{
	if (empty())
		return;

	m_nElemNum--;
	return;
}

template<typename T>
int MyVector<T>::size() const
{
	return m_nElemNum;
}

template<typename T>
int MyVector<T>::capacity() const
{
	return m_nCapacity;
}

template<typename T>
bool MyVector<T>::empty() const 
{
	return (m_nElemNum == 0);
}

template<typename T>
T &MyVector<T>::operator[](size_t pos_) 
{
	if (pos_ >= 0 && pos_ < m_nElemNum)
		return *(this->m_pVector + pos_);
	throw std::out_of_range("Out of bounds element access");
}

//template<typename T>
//T &MyVector<T>::operator[]=(size_t pos_) 
//{
//	if (pos_ >= 0 && pos_ < m_nElemNum)
//		return *(this->m_pVector + pos_);
//	throw std::out_of_range("Out of bounds element access");
//}


