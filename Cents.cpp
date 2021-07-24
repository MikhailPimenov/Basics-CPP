#include "Cents.h"

Cents::Cents() : m_cents(0) {

}

Cents::Cents(int cents) : m_cents(cents) {

}

Cents::operator Dollars() const {
	return Dollars(m_cents / 100);
}