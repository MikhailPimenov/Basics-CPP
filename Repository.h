#pragma once

#include <iostream>
#include <memory>

// TODO: add constructor which takes temporary object

template <typename T>
class Repository_base {
protected:
	T m_data;

public:
	Repository_base();
	Repository_base(const T& data);
	virtual ~Repository_base();

public:
	virtual void print() const;
};



template <typename T>
class Repository : public Repository_base <T> {
public:
	Repository(const T& data);
};

template <typename T>
class Repository < T* > : public Repository_base < T* > {
public:
	Repository(const T* data);
	virtual ~Repository() override;

	virtual void print() const override;
};




template <>
class Repository < char* > : public Repository_base < char*> {
public:
	Repository(char* cstring);
	virtual ~Repository() override;
};