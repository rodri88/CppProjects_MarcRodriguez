#include "DynArray.hh"

DynArray::DynArray(void)
{
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size, const int & value)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[m_capacity];
}

DynArray::DynArray(int *arr, size_t size)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[m_capacity];
}

DynArray &DynArray::operator=(const DynArray &x)
{
	m_size = x.m_size;
	m_capacity = x.m_capacity;

	for () {
		m_data = x.m_data;
	}
	return DynArray(m_capacity, m_size, m_data);
}

bool operator==(const DynArray &lhs, const DynArray &rhs)
{
	if (lhs.m_capacity != rhs.m_capacity) {
		return false;
	}
	else if (lhs.m_size != rhs.m_size) {
		return false;
	}
	for (){
		if lhs.m_data == rhs.m_data;
}
