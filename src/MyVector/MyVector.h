#pragma once
#define NULL nullptr

double g_nNewSpaceRatio = 1.5;      			// ÿ�ο����¿ռ�ı���

template <typename T>
class MyVector {
private:
	T* m_pVector;       			// ָ���ڴ�Σ����ڼ�¼�洢���ݵ��׵�ַ
	int m_nElemNum;		    		// ���ڼ�¼��ǰ���ݵ�����
	int m_nCapacity;				// ���ڼ�¼��ǰ���������ɵ����Ԫ�ظ���
public:
	MyVector()
	{
		m_pVector = NULL;
		m_nElemNum = 0;
		m_nCapacity = 0;			// Ĭ��ֵ�ȸ���0
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
	void push_back(const T& nData_);		// �� Vector ĩβ��������
	void pop_back();						// ɾ�� Vector ĩβ������

	int size() const;						// Vector �����ݸ���
	int capacity() const;					// Vector ������

	bool empty() const;						// Vector �Ƿ�Ϊ��

	T at(size_t index_) const;				// ���ʵ� index ��Ԫ��
	T front() const;						// ���ʵ� 1 ��Ԫ��
	T back() const;							// ������� 1 ��Ԫ��

	T &operator[](size_t pos_);
	//T &operator[] =(size_t pos_, const T& nData_);

};

template <typename T>
void MyVector<T>::push_back(const T& nData_)
{
	// û��������ռ�ʱ����ռ�
	if (m_pVector == NULL)
	{
		if (m_nCapacity == 0)
			m_nCapacity = 1;

		m_pVector = new T[m_nCapacity];

		if (m_pVector == NULL)
			throw("����ռ�ʧ��");
	}

	// �����ռ䲻�����ˣ���Ҫ�����µĿռ�
	if (m_nElemNum >= m_nCapacity)
	{
		// 1 ����m_nCapacityΪԭ����g_nNewSpaceRatio��������g_nNewSpaceRatioȡ1.5
		m_nCapacity = (int)(ceil)(m_nCapacity * g_nNewSpaceRatio);

		// 2 �����¿ռ�
		T* pNew = new T[m_nCapacity];

		// 3 ����ԭ�����ݲ��ͷ�ԭ�ڴ�
		memcpy(pNew, m_pVector, sizeof(T*) * m_nElemNum);
		delete[] m_pVector;

		// 4 m_pVectorָ���¿����ڴ�
		m_pVector = pNew;
	}

	// ��������ݽ�������������1
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
T MyVector<T>::at(size_t index_) const
{
	if (index_ >= 0 && index_ < m_nElemNum)
		return *(this->m_pVector + index_);
	
	throw std::out_of_range("Out of range");
}

template<typename T>
T MyVector<T>::front() const
{
	if (empty())
		throw("vector is empty");

	return *(this->m_pVector);
}

template<typename T>
T MyVector<T>::back() const
{
	if (empty())
		throw("vector is empty");

	return *(this->m_pVector + (m_nElemNum - 1));
}

template<typename T>
T &MyVector<T>::operator[](size_t pos_)
{
	if (pos_ >= 0 && pos_ < m_nElemNum)
		return *(this->m_pVector + pos_);
	
	throw std::out_of_range("Out of range");
}



