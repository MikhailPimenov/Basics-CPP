#pragma once

template <typename T>
class Auto_ptr_base {
protected:
	T* m_data;
public:
	Auto_ptr_base(T* data = nullptr);
	virtual ~Auto_ptr_base();

	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T* operator->() const;

	bool isNull() const;
};
