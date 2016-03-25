#include "csit_class.h"
csit_class::csit_class (const int& courseNumber, const int& sectionNumber) {
	m_courseNumber = courseNumber;
	m_sectionNumber = sectionNumber;
}
int csit_class::courseNumber () const {
	return m_courseNumber;
}
int csit_class::sectionNumber () const {
	return m_sectionNumber;
}